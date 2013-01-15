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

/** @brief objects typy obiektów */
enum objects{
    sphere, plane, light
};

/** @brief materials typy materiałów */
enum materials{
    perfect_diffuse, phong, reflective, transparent
};

/** @brief camera typy kamer */
enum camera{
    orthogonal, pinhole, lens
};

/** @brief MainWindow klasa głównego okna programu */
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    

public slots:
     /** @brief show_image pokazuje scenę na ekranie  */
     void show_image();
     /** @brief new_world tworzy nowy świat  */
     void new_world();

private slots:
    /** @brief save_image zapisuje scenę do pliku */
    void save_image();

    /** @brief change_save_text zmienia nazwę pliku do zapisania*/
    void change_save_text(const QString &text);
    /** @brief change_adding zmienia typ dodawanego obiektu*/
    void change_adding(const QString &text);
    /** @brief add_object dodaje obiekt*/
    void add_object();
    /** @brief world_renew odświeżenie świata */
    void world_renew();
    /** @brief change_material zmiana typu materiału */
    void change_material(const QString&text);
    /** @brief change_camera zmiana typu kamery */
    void change_camera(const QString&text);

    /** @brief change_sp_statsr zmiana danej zmiennej*/
    void change_sp_statsr(double val);
    /** @brief change_sp_statsx zmiana danej zmiennej */
    void change_sp_statsx(double val);
    /** @brief change_sp_statsy zmiana danej zmiennej */
    void change_sp_statsy(double val);
    /** @brief change_sp_statsz  zmiana danej zmiennej*/
    void change_sp_statsz(double val);
    /** @brief change_pl_statsx   zmiana danej zmiennej*/
    void change_pl_statsx(double val);
    /** @brief change_pl_statsy   zmiana danej zmiennej*/
    void change_pl_statsy(double val);
    /** @brief change_pl_statsz   zmiana danej zmiennej*/
    void change_pl_statsz(double val);
    /** @brief change_pl_statsnx  zmiana danej zmiennej */
    void change_pl_statsnx(double val);
    /** @brief change_pl_statsny  zmiana danej zmiennej */
    void change_pl_statsny(double val);
    /** @brief change_pl_statsnz  zmiana danej zmiennej */
    void change_pl_statsnz(double val);
    /** @brief change_sampler  zmiana danej zmiennej */
    void change_sampler(int val);
    /** @brief change_mat_r  zmiana danej zmiennej */
    void change_mat_r(int val);
    /** @brief change_mat_g  zmiana danej zmiennej*/
    void change_mat_g(int val);
    /** @brief change_mat_b  zmiana danej zmiennej */
    void change_mat_b(int val);
    /** @brief change_li_statsr  zmiana danej zmiennej */
    void change_li_statsr(int val);
    /** @brief change_li_statsg zmiana danej zmiennej  */
    void change_li_statsg(int val);
    /** @brief change_li_statsb  zmiana danej zmiennej */
    void change_li_statsb(int val);
    /** @brief change_li_statsz  zmiana danej zmiennej */
    void change_li_statsz(double val);
    /** @brief change_li_statsx  zmiana danej zmiennej */
    void change_li_statsx(double val);
    /** @brief change_li_statsy   zmiana danej zmiennej*/
    void change_li_statsy(double val);
    /** @brief change_li_statsrad   zmiana danej zmiennej*/
    void change_li_statsrad(double val);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /** @brief copy_world  */
    void copy_world(QImage &scene, World new_world){image = scene; world = new_world;}




private:

    Ui::MainWindow *ui;
    /** @brief saving_file_name  nazwa pliku do zapisania*/
    QString saving_file_name;
    /** @brief image scena */
    QImage image;
    /** @brief world świat przedstawiony */
    World world;
    /** @brief material_type obecny typ materiału */
    materials material_type;
    /** @brief camera_type obecny typ kamery*/
    camera camera_type;
    /** @brief obj_counter zliczacz obiektów do wyświetlenia */
    int obj_counter;
    /** @brief tracer tracer */
    Raytracer tracer;
    /** @brief adding_object dodawany obecnie obiekt */
    objects adding_object;

    /** @brief initial_settings inicjalizowanie domyślnych danych */
    void initial_settings();
    /** @brief sphere_stats  opcje dodawania sfery*/
    void sphere_stats(bool);
    /** @brief plane_stats  opcje dodawania płaszczyzny*/
    void plane_stats(bool);
    /** @brief light_stats  opcje dodawania światła */
    void light_stats(bool);
    /** @brief hide_adding  ukryj przycisk dodawania obiektów*/
    void hide_adding();
    /** @brief create_camera tworzenie kamery o danym typie */
    void create_camera();
    /** @brief started_adding_sphere dodawanie sfery  */
    void started_adding_sphere();
    /** @brief started_adding_plane dodawanie płaszczyzny */
    void started_adding_plane();
    /** @brief started_adding_light dodawanie światła */
    void started_adding_light();

    /** @brief create_material tworzenie materiału */
    Material* create_material();

    /** @brief our_camera obecna kamera */
    Vcamera* our_camera;
    /** @brief get_sampler pobierz nowy sampler */
    void get_sampler();

    /** @brief get_lens_sampler pobierz nowy sampler dla kamery */
    void get_lens_sampler();

    /** @brief sampler obecny sampler */
    Sampler* sampler;

    /** @brief sampler obecny sampler kamery */
    Sampler* lens_sampler;

    /** @brief samples ilość próbek */
    int samples;

    /** @brief mat_r zmienna koloru materiału */
    int mat_r;
    /** @brief mat_g  zmienna koloru materiału*/
    int mat_g;
    /** @brief mat_b  zmienna koloru materiału*/
    int mat_b;

    /** @brief sph_centerX  zmienna sfery*/
    double sph_centerX;
    /** @brief sph_centerY  zmienna sfery*/
    double sph_centerY;
    /** @brief sph_centerZ zmienna sfery */
    double sph_centerZ;
    /** @brief sph_radius  zmienna sfery*/
    double sph_radius;

    /** @brief pl_x  zmienna płaszczyzny*/
    double pl_x;
    /** @brief pl_y  zmienna płaszczyzny*/
    double pl_y;
    /** @brief pl_z  zmienna płaszczyzny*/
    double pl_z;
    /** @brief pl_nx zmienna płaszczyzny*/
    double pl_nx;
    /** @brief pl_ny  zmienna płaszczyzny*/
    double pl_ny;
    /** @brief pl_nz  zmienna płaszczyzny*/
    double pl_nz;

    /** @brief li_x zmienna światła*/
    double li_x;
    /** @brief li_y  zmienna światła*/
    double li_y;
    /** @brief li_z zmienna światła */
    double li_z;
    /** @brief li_r zmienna światła */
    int li_r;
    /** @brief li_g  zmienna światła*/
    int li_g;
    /** @brief li_b  zmienna światła*/
    int li_b;
    /** @brief li_b  zmienna światła*/
    double li_rad;



};

#endif // MAINWINDOW_H
