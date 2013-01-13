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
#include "camera.h"
#include "raytracer.h"

enum materials{
    perfect_diffuse, phong, reflective, transparent
};

enum camera{
    orthogonal, pinhole, lens
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    

public slots:
     void show_image();

private slots:
    void save_image();

    void change_save_text(const QString &text);
    void change_adding(const QString &text);
    void add_sphere();
    void world_renew();
    void change_material(const QString&text);
    void change_camera(const QString&text);
    void change_sp_statsr(double val);
    void change_sp_statsx(double val);
    void change_sp_statsy(double val);
    void change_sp_statsz(double val);
    void change_sampler(int val);
    void change_mat_r(int val);
    void change_mat_g(int val);
    void change_mat_b(int val);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void adding_things(QImage &scene, World new_world){image = scene; world = new_world;}




private:
    Ui::MainWindow *ui;
    QString saving_file_name;
    QImage image;
    World world;
    materials material_type;
    camera camera_type;
    int obj_counter;
    Raytracer tracer;

    void initial_settings();
    void sphere_stats(bool);
    void hide_adding();
    void started_adding_sphere();
    void started_adding_plane();
    void started_adding_light();
    Material* create_material();
    void create_camera();
    Vcamera* our_camera;



    int samples;

    int mat_r;
    int mat_g;
    int mat_b;

    double sph_centerX;
    double sph_centerY;
    double sph_centerZ;
    double sph_radius;

};

#endif // MAINWINDOW_H
