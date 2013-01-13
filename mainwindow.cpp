#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgraphicsscene.h"
#include <iostream>
#include "camera.h"
#include "raytracer.h"

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
    connect(ui->create_obj, SIGNAL(clicked()), this, SLOT(add_sphere()));
    connect(ui->create_world, SIGNAL(clicked()), this, SLOT(world_renew()));


    connect(ui->sp_x, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsx(double)));
    connect(ui->sp_y, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsy(double)));
    connect(ui->sp_z, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsz(double)));
    connect(ui->sp_rad, SIGNAL(valueChanged(double)), this, SLOT(change_sp_statsr(double)));
    connect(ui->sampler, SIGNAL(valueChanged(int)), this, SLOT(change_sampler(int)));


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

    ui->sp_x->setVisible(true);
    ui->sp_y->setVisible(true);
    ui->sp_z->setVisible(true);
    ui->sp_rad->setVisible(true);
    cout<<"Bede tworzył kule"<<endl;
}

void MainWindow::started_adding_plane(){

    hide_sphere_stats();

    cout<<"Bede tworzył plaszczyzne"<<endl;
}

void MainWindow::started_adding_light(){

    hide_sphere_stats();
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

void MainWindow::add_sphere(){

    world.add(new Sphere(Vector3(sph_centerX, sph_centerY, sph_centerZ), sph_radius,  new Reflective(QColor(173,255,47), 0.4, 1, 300, 0.6)));
}

void MainWindow::world_renew(){

    JitteredGenerator gener(0);
    DiskDistributor dist;
    Sampler distributor(gener,dist,samples,60,0);

    LensCamera camera(Vector3(0,1,-10),Vector3(0,0,0),Vector3(0,-1,0),Vector2(2,1.5),2,&distributor,0.5,11);
    Raytracer tracer(5);


    image = tracer.RayTrace(world, camera, QSize(800, 600),&distributor);

    this->show_image();


}

void MainWindow::initial_settings(){

    saving_file_name = "raytracer";
    samples = 1;
    sph_centerX = 1;
    sph_centerY = 1;
    sph_centerZ = 1;
    sph_radius = 1;



    ui->sampler->setRange(1,512);
    ui->sp_x->setRange(-30,30);
    ui->sp_y->setRange(-30,30);
    ui->sp_z->setRange(-30,30);
    ui->sp_rad->setRange(-30,30);

}

void MainWindow::hide_sphere_stats(){

    ui->sp_x->setVisible(false);
    ui->sp_y->setVisible(false);
    ui->sp_z->setVisible(false);
    ui->sp_rad->setVisible(false);
    ui->t_sp_x->setVisible(false);
    ui->t_sp_y->setVisible(false);
    ui->t_sp_z->setVisible(false);
    ui->t_sp_rad->setVisible(false);


}

void MainWindow::show_sphere_stats(){

    ui->sp_x->setVisible(true);
    ui->sp_y->setVisible(true);
    ui->sp_z->setVisible(true);
    ui->sp_rad->setVisible(true);
    ui->t_sp_x->show();
    ui->t_sp_y->show();
    ui->t_sp_z->show();
    ui->t_sp_rad->show();


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
}


void MainWindow::change_sp_statsr(double val){sph_radius = val;}
void MainWindow::change_sp_statsx(double val){sph_centerX = val;}
void MainWindow::change_sp_statsy(double val){sph_centerY = val;}
void MainWindow::change_sp_statsz(double val){sph_centerZ = val;}
void MainWindow::change_sampler(int val){samples=val;}

