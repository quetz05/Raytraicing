#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsObject>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    

public slots:
    void save_image();
    void show_image();
    void add_image(QImage scene){image = scene;}

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



    
private:
    Ui::MainWindow *ui;
    QString saving_file_name;
    QImage image;
};

#endif // MAINWINDOW_H
