#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgraphicsscene.h"
#include <iostream>


using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);


    initial_settings();
    hide_adding();


    connect(ui->save_butt, SIGNAL(clicked()), this, SLOT(save_image()));
    connect(ui->save_text, SIGNAL(textChanged(const QString &)), this, SLOT(change_save_text(const QString &)));
    connect(ui->objects_list, SIGNAL(activated(QString)), this, SLOT(change_adding(const QString &)));
    connect(ui->material_list, SIGNAL(activated(QString)), this, SLOT(change_material(const QString &)));
    connect(ui->camera, SIGNAL(activated(QString)), this, SLOT(change_camera(const QString &)));
    connect(ui->create_obj, SIGNAL(clicked()), this, SLOT(add_object()));
    connect(ui->create_world, SIGNAL(clicked()), this, SLOT(world_renew()));
    connect(ui->delete_world, SIGNAL(clicked()), this, SLOT(new_world()));

    connect(ui->sampler, SIGNAL(valueChanged(int)), this, SLOT(change_sampler(int)));

    connect(ui->sp_x, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsx(double)));
    connect(ui->sp_y, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsy(double)));
    connect(ui->sp_z, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsz(double)));
    connect(ui->sp_rad, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsr(double)));


    connect(ui->mat_r, SIGNAL(valueChanged(int)), this, SLOT(change_mat_r(int)));
    connect(ui->mat_g, SIGNAL(valueChanged(int)), this, SLOT(change_mat_g(int)));
    connect(ui->mat_b, SIGNAL(valueChanged(int)), this, SLOT(change_mat_b(int)));

    connect(ui->pl_x, SIGNAL(valueChanged(double)), this, SLOT(change_pl_statsx(double)));
    connect(ui->pl_y, SIGNAL(valueChanged(double)), this, SLOT(change_pl_statsy(double)));
    connect(ui->pl_z, SIGNAL(valueChanged(double)), this, SLOT(change_pl_statsz(double)));
    connect(ui->pl_nx, SIGNAL(valueChanged(double)), this, SLOT(change_pl_statsnx(double)));
    connect(ui->pl_ny, SIGNAL(valueChanged(double)), this, SLOT(change_pl_statsny(double)));
    connect(ui->pl_nz, SIGNAL(valueChanged(double)), this, SLOT(change_pl_statsnz(double)));

    connect(ui->li_r, SIGNAL(valueChanged(int)), this, SLOT(change_li_statsr(int)));
    connect(ui->li_g, SIGNAL(valueChanged(int)), this, SLOT(change_li_statsg(int)));
    connect(ui->li_b, SIGNAL(valueChanged(int)), this, SLOT(change_li_statsb(int)));
    connect(ui->li_x, SIGNAL(valueChanged(double)), this, SLOT(change_li_statsx(double)));
    connect(ui->li_y, SIGNAL(valueChanged(double)), this, SLOT(change_li_statsy(double)));
    connect(ui->li_z, SIGNAL(valueChanged(double)), this, SLOT(change_li_statsz(double)));



}

MainWindow::~MainWindow(){
    delete ui;

}

void MainWindow::show_image(){

    ui->graph1->resize(image.width()+2, image.height()+2);
    QGraphicsScene* scene = new QGraphicsScene();
    ui->graph1->setScene(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->graph1->show();


}

void MainWindow::save_image(){
    image.save(saving_file_name+".png");
}

void MainWindow::change_save_text(const QString &text){
    saving_file_name = text;
}

void MainWindow::started_adding_sphere(){
    hide_adding();
    sphere_stats(true);
    adding_object = sphere;

}

void MainWindow::started_adding_plane(){
    hide_adding();
    plane_stats(true);
    adding_object = plane;
}

void MainWindow::started_adding_light(){
    hide_adding();
    light_stats(true);
    adding_object = light;

}

void MainWindow::change_adding(const QString &text){
    if(text=="Sfera")
        started_adding_sphere();
    else if(text=="Płaszczyzna")
        started_adding_plane();
    else if(text=="Punkt światła")
        started_adding_light();
    else
        hide_adding();
}

void MainWindow::change_material(const QString &text){

    if(text=="Idealnie rozpraszający")
        material_type = perfect_diffuse;
    else if(text=="Phonga")
        material_type = phong;
    else if(text=="Przezroczysty")
        material_type = transparent;
    else if(text=="Modelujący odbicie")
        material_type = reflective;
}



void MainWindow::change_camera(const QString&text){

    if(text=="Ortogonalna")
         our_camera= new Orthogonal (Vector3(0, 1, -10), 0, Vector2(5, 5));
    else if(text=="Perspektywiczna")
        our_camera = new PinholeCamera(Vector3(0,1,-8),Vector3(0,0,0),Vector3(0,-1,0),Vector2(1,0.75),1);
    else if(text=="Soczewkowa")
        our_camera = new LensCamera(Vector3(0,1,-10),Vector3(0,0,0),Vector3(0,-1,0),Vector2(2,1.5),2,sampler,0.5,11);

}

void MainWindow::add_object(){

    switch(adding_object)
    {
        case sphere:
            world.add(new Sphere(Vector3(sph_centerX, sph_centerY, sph_centerZ), sph_radius,  create_material()));
            obj_counter++;
            ui->ob_counter->display(obj_counter);
            break;

        case plane:
            world.add(new Plane(Vector3(pl_x,pl_y,pl_z),Vector3(pl_nx,pl_ny,pl_nz),create_material()));
            obj_counter++;
            ui->ob_counter->display(obj_counter);
            break;


       case light:
            world.add_light(PointLight(Vector3(li_x,li_y,li_z), MyColor(QColor(li_r,li_g,li_b)), sampler,0.5));
            obj_counter++;
            ui->ob_counter->display(obj_counter);
            break;

       case cube:

            break;
    }
}

void MainWindow::world_renew(){


    image = tracer.RayTrace(world, *our_camera, QSize(800, 600),sampler);

    obj_counter=0;
    ui->ob_counter->display(obj_counter);

    this->show_image();

}

void MainWindow::initial_settings(){

    ///wartości początkowe zmiennych

    //nazwa pliku defaulotwa
    saving_file_name = "raytracer";
    //początkowa ilość sampli
    samples = 1;
    //defaultowy materiał
    material_type = perfect_diffuse;

    //tworzenie samplera
    sampler = get_sampler();

    //tworzenie tracer'a
    tracer = Raytracer(5);

    //zerowanie zmiennych płaszczyzny
    pl_x = 0;
    pl_y = 0;
    pl_z = 0;
    pl_nx = 0;
    pl_ny = 0;
    pl_nz = 0;

    //zerowanie zmiennych światła
    li_x = 0;
    li_y = 0;
    li_z = 0;
    li_r = 0;
    li_g = 0;
    li_b = 0;

    //zerowanie zmiennych sfery
    sph_centerX = 0;
    sph_centerY = 0;
    sph_centerZ = 0;
    sph_radius = 0;

    //zerowanie zmiennych materiału
    mat_r = 0;
    mat_g = 0;
    mat_b = 0;

    //defaultowa kamera
    our_camera= new PinholeCamera(Vector3(0,1,-8),Vector3(0,0,0),Vector3(0,-1,0),Vector2(1,0.75),1);

    //ustawienie zakeresów
    ui->mat_r->setRange(0,255);
    ui->mat_g->setRange(0,255);
    ui->mat_b->setRange(0,255);
    ui->sampler->setRange(1,512);
    ui->sp_x->setRange(-30,30);
    ui->sp_y->setRange(-30,30);
    ui->sp_z->setRange(-30,30);
    ui->sp_rad->setRange(0,30);
    ui->pl_x->setRange(-30,30);
    ui->pl_y->setRange(-30,30);
    ui->pl_z->setRange(-30,30);
    ui->pl_nx->setRange(-30,30);
    ui->pl_ny->setRange(-30,30);
    ui->pl_nz->setRange(-30,30);

    ui->li_x->setRange(-30,30);
    ui->li_y->setRange(-30,30);
    ui->li_z->setRange(-30,30);
    ui->li_r->setRange(0,255);
    ui->li_g->setRange(0,255);
    ui->li_b->setRange(0,255);


    obj_counter = 0;

}

void MainWindow::sphere_stats(bool state){

    ui->sp_x->setVisible(state);
    ui->sp_y->setVisible(state);
    ui->sp_z->setVisible(state);
    ui->sp_rad->setVisible(state);
    ui->t_sp_x->setVisible(state);
    ui->t_sp_y->setVisible(state);
    ui->t_sp_z->setVisible(state);
    ui->t_sp_rad->setVisible(state);
    ui->create_obj->setVisible(state);
    ui->mat_r->setVisible(state);
    ui->mat_g->setVisible(state);
    ui->mat_b->setVisible(state);
    ui->material_list->setVisible(state);
    ui->t_mat_r->setVisible(state);
    ui->t_mat_g->setVisible(state);
    ui->t_mat_b->setVisible(state);
    ui->t_mat->setVisible(state);
}

void MainWindow::plane_stats(bool state){

    ui->pl_x->setVisible(state);
    ui->pl_y->setVisible(state);
    ui->pl_z->setVisible(state);
    ui->pl_nx->setVisible(state);
    ui->pl_ny->setVisible(state);
    ui->pl_nz->setVisible(state);
    ui->t_pl_x->setVisible(state);
    ui->t_pl_y->setVisible(state);
    ui->t_pl_z->setVisible(state);
    ui->t_pl_nx->setVisible(state);
    ui->t_pl_ny->setVisible(state);
    ui->t_pl_nz->setVisible(state);
    ui->create_obj->setVisible(state);
    ui->mat_r->setVisible(state);
    ui->mat_g->setVisible(state);
    ui->mat_b->setVisible(state);
    ui->material_list->setVisible(state);
    ui->t_mat_r->setVisible(state);
    ui->t_mat_g->setVisible(state);
    ui->t_mat_b->setVisible(state);
    ui->t_mat->setVisible(state);
}

void MainWindow::light_stats(bool state){

    ui->li_x->setVisible(state);
    ui->li_y->setVisible(state);
    ui->li_z->setVisible(state);
    ui->li_r->setVisible(state);
    ui->li_g->setVisible(state);
    ui->li_b->setVisible(state);
    ui->t_li_x->setVisible(state);
    ui->t_li_y->setVisible(state);
    ui->t_li_z->setVisible(state);
    ui->t_li_r->setVisible(state);
    ui->t_li_g->setVisible(state);
    ui->t_li_b->setVisible(state);
    ui->create_obj->setVisible(state);
}

void MainWindow::hide_adding(){

    plane_stats(false);
    sphere_stats(false);
    light_stats(false);
}

Material* MainWindow::create_material(){

    switch(material_type){

        case perfect_diffuse:
            return new PerfectDiffuse(QColor(mat_r,mat_g,mat_b));
        case phong:
            return new Phong(QColor(mat_r,mat_g,mat_b) , 0.8, 1, 30);
        case reflective:
            return new Reflective(QColor(mat_r,mat_g,mat_b), 0.4, 1, 300, 0.6);
        case transparent:
            return new Transparent(QColor(mat_r,mat_g,mat_b), 0.1, 0, 0, 0.3, 1.05, 0.9);
        default:
            return new PerfectDiffuse(QColor(mat_r,mat_g,mat_b));

    }

}

Sampler *MainWindow::get_sampler(){

    JitteredGenerator gener(0);
    SquareDistributor dist;
    Sampler* distributor = new Sampler(gener,dist,samples,60,0);

    return distributor;

}

void MainWindow::new_world(){

    world = World(QColor(135, 206, 250));

    world_renew();
}


void MainWindow::change_sp_statsr(double val){sph_radius = val;}
void MainWindow::change_sp_statsx(double val){sph_centerX = val;}
void MainWindow::change_sp_statsy(double val){sph_centerY = val;}
void MainWindow::change_sp_statsz(double val){sph_centerZ = val;}
void MainWindow::change_sampler(int val){samples=val;}
void MainWindow::change_mat_r(int val){mat_r=val;}
void MainWindow::change_mat_g(int val){mat_g=val;}
void MainWindow::change_mat_b(int val){mat_b=val;}
void MainWindow::change_pl_statsx(double val){pl_x = val;}
void MainWindow::change_pl_statsy(double val){pl_y = val;}
void MainWindow::change_pl_statsz(double val){pl_z = val;}
void MainWindow::change_pl_statsnx(double val){pl_nx = val;}
void MainWindow::change_pl_statsny(double val){pl_ny = val;}
void MainWindow::change_pl_statsnz(double val){pl_nz = val;}
void MainWindow::change_li_statsx(double val){li_x = val;}
void MainWindow::change_li_statsy(double val){li_y = val;}
void MainWindow::change_li_statsz(double val){li_z = val;}
void MainWindow::change_li_statsr(int val){li_r = val;}
void MainWindow::change_li_statsg(int val){li_g = val;}
void MainWindow::change_li_statsb(int val){li_b = val;}

