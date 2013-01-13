#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsObject>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QString>
#include <QLineEdit>
#include "world.h"
#include "geometric_objects.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    

public slots:
    void save_image();
    void show_image();
    void change_save_text(const QString &text);
    void change_adding(const QString &text);
    void add_sphere();
    void world_renew();

    void change_sp_statsr(double val);
    void change_sp_statsx(double val);
    void change_sp_statsy(double val);
    void change_sp_statsz(double val);
    void change_sampler(int val);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void adding_things(QImage &scene, World new_world){image = scene; world = new_world;}




private:
    Ui::MainWindow *ui;
    QString saving_file_name;
    QImage image;
    World world;

    void initial_settings();
    void hide_sphere_stats();
    void show_sphere_stats();
    void hide_adding();
    void started_adding_sphere();
    void started_adding_plane();
    void started_adding_light();


    int samples;
    double sph_centerX;
    double sph_centerY;
    double sph_centerZ;
    double sph_radius;

};

#endif // MAINWINDOW_H
