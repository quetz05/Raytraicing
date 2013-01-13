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
    connect(ui->create_obj, SIGNAL(clicked()), this, SLOT(add_sphere()));
    connect(ui->create_world, SIGNAL(clicked()), this, SLOT(world_renew()));


    connect(ui->sp_x, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsx(double)));
    connect(ui->sp_y, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsy(double)));
    connect(ui->sp_z, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsz(double)));
    connect(ui->sp_rad, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsr(double)));
    connect(ui->sampler, SIGNAL(valueChanged(int)), this, SLOT(change_sampler(int)));
    connect(ui->mat_r, SIGNAL(valueChanged(int)), this, SLOT(change_mat_r(int)));
    connect(ui->mat_g, SIGNAL(valueChanged(int)), this, SLOT(change_mat_g(int)));
    connect(ui->mat_b, SIGNAL(valueChanged(int)), this, SLOT(change_mat_b(int)));


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

void MainWindow::started_adding_sphere(){sphere_stats(true);}

void MainWindow::started_adding_plane(){

    sphere_stats(false);

    cout<<"Bede tworzył plaszczyzne"<<endl;
}

void MainWindow::started_adding_light(){

    sphere_stats(false);
    cout<<"Bede tworzył światło"<<endl;

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

void MainWindow::add_sphere(){

    world.add(new Sphere(Vector3(sph_centerX, sph_centerY, sph_centerZ), sph_radius,  create_material()));
    obj_counter++;
    ui->ob_counter->display(obj_counter);
}

void MainWindow::world_renew(){

    JitteredGenerator gener(0);
    DiskDistributor dist;
    Sampler distributor(gener,dist,samples,60,0);


    image = tracer.RayTrace(world, *our_camera, QSize(800, 600),sampler);

    obj_counter=0;
    ui->ob_counter->display(obj_counter);

    this->show_image();


}

void MainWindow::initial_settings(){

    //wartości początkowe zmiennych
    saving_file_name = "raytracer";
    samples = 1;
    sph_centerX = 0;
    sph_centerY = 0;
    sph_centerZ = 0;
    sph_radius = 0;
    material_type = perfect_diffuse;
    obj_counter = 0;
    sampler = get_sampler();


    tracer = Raytracer(5);



    mat_r = 0;
    mat_g = 0;
    mat_b = 0;

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
}

void MainWindow::hide_adding(){

    ui->sp_x->setVisible(false);
    ui->sp_y->setVisible(false);
    ui->sp_z->setVisible(false);
    ui->sp_rad->setVisible(false);
    ui->t_sp_x->setVisible(false);
    ui->t_sp_y->setVisible(false);
    ui->t_sp_z->setVisible(false);
    ui->t_sp_rad->setVisible(false);
    ui->create_obj->setVisible(false);
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
    DiskDistributor dist;
    Sampler* distributor = new Sampler(gener,dist,samples,60,0);

    return distributor;

}


void MainWindow::change_sp_statsr(double val){sph_radius = val;}
void MainWindow::change_sp_statsx(double val){sph_centerX = val;}
void MainWindow::change_sp_statsy(double val){sph_centerY = val;}
void MainWindow::change_sp_statsz(double val){sph_centerZ = val;}
void MainWindow::change_sampler(int val){samples=val;}
void MainWindow::change_mat_r(int val){mat_r=val;}
void MainWindow::change_mat_g(int val){mat_g=val;}
void MainWindow::change_mat_b(int val){mat_b=val;}

