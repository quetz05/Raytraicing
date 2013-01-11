#ifndef MYCOLOR_H
#define MYCOLOR_H
#include <QColor>

class MyColor{

public:
    //konstruktory
    MyColor(){r=0;g=0;b=0;}
    MyColor(double nr, double ng, double nb){r=nr; g=ng; b=nb;}
    MyColor(QColor color){r=color.red()/255.0; g=color.green()/255.0, b=color.blue()/ 255.0;}
    MyColor(const MyColor &c): r(c.r),g(c.g),b(c.b){}

    MyColor operator +(const MyColor &col1){return MyColor(col1.r + this->r, col1.g + this->g, col1.b + this->b); }
    MyColor operator *(double val){return MyColor(this->r * val, this->g  * val, this->b  * val); }
    MyColor operator *(const MyColor &col1){return MyColor(col1.r * this->r, col1.g * this->g, col1.b * this->b); }
    MyColor operator /(double val){return MyColor(this->r /val, this->g  /  val, this->b  / val); }

    //DO ZMIANY!!
    static QColor strip_color(MyColor colorInfo){

        colorInfo.r = colorInfo.r < 0 ? 0 : colorInfo.r > 1 ? 1 : colorInfo.r;
        colorInfo.g = colorInfo.g < 0 ? 0 : colorInfo.g > 1 ? 1 : colorInfo.g;
        colorInfo.b = colorInfo.b < 0 ? 0 : colorInfo.b > 1 ? 1 : colorInfo.b;

        return QColor((int)(colorInfo.r * 255),(int)(colorInfo.g * 255),(int)(colorInfo.b * 255));
    }

    //zmienne
    double r,g,b;


};

#endif // MYCOLOR_H
