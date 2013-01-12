#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgraphicsscene.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->save_butt, SIGNAL(clicked()), this, SLOT(save_image()));
}

MainWindow::~MainWindow(){
    delete ui;

}

void MainWindow::show_image(){

    ui->graph1->resize(image.width()+5, image.height()+5);
    QGraphicsScene* scene = new QGraphicsScene();
    ui->graph1->setScene(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->graph1->show();


}

void MainWindow::save_image(){
        image.save("raytracer.png");
}
