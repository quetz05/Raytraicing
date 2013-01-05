#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgraphicsscene.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;

}

void MainWindow::show_pixmap(QPixmap& pixmap){

    QWidget* widget = centralWidget();
    QLayout* layout = new QHBoxLayout();
    QLabel* label = new QLabel(this);

    widget->setLayout(layout);
    layout->addWidget(label);
    label->setPixmap(pixmap);
}
