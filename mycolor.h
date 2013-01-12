/**nagłówek zawierający implementację klasy MyColor tworzącej własną klasę koloru*/
#ifndef MYCOLOR_H
#define MYCOLOR_H
#include <QColor>

/**klasa MyColor tworząca kolor RGB*/
class MyColor{

    public:

        /**bezargumentowy konstruktor tworzący kolor (0,0,0)*/
        MyColor(){r=0;g=0;b=0;}
        /**konstruktor tworzący kolor (nr,ng,nb)*/
        MyColor(double nr, double ng, double nb): r(nr), g(ng), b(nb) {}
        /**konstruktor tworzący kolor z koloru klasy QColor*/
        MyColor(const QColor &color){r=color.red()/255.0; g=color.green()/255.0, b=color.blue()/ 255.0;}
        /**konstruktor kopiujący obiekt klasy MyColor*/
        MyColor(const MyColor &c): r(c.r),g(c.g),b(c.b){}

        /**przeciążenie operatora dodawania dwóch kolorów*/
        MyColor operator +(const MyColor &col1){return MyColor(col1.r + this->r, col1.g + this->g, col1.b + this->b);}
        /**przeciążenie operatora mnożenia koloru przez liczbę*/
        MyColor operator *(double val){return MyColor(this->r * val, this->g  * val, this->b  * val); }
        /**przeciążenie operatora mnożenia dwóch kolorów*/
        MyColor operator *(const MyColor &col1){return MyColor(col1.r * this->r, col1.g * this->g, col1.b * this->b);}
        /**przeciążenie operatora dzielenia koloru przez liczbę*/
        MyColor operator /(double val){return MyColor(this->r /val, this->g  /  val, this->b  / val);}


        /**metoda "obcinająca" kolor jeśli przekracza zakres i zwracająca obiekt klasy QColor*/
        static QColor strip_color(MyColor color){

            //sprawdzenie koloru red
            if(color.r<0)
                color.r=0;
            else if (color.r>1)
                color.r=1;
            //sprawdzenie koloru green
            if(color.g<0)
                color.g=0;
            else if (color.g>1)
                color.g=1;
            //sprawdzenie koloru blue
            if(color.b<0)
                color.b=0;
            else if (color.b>1)
                color.b=1;

            return QColor((color.r * 255),(color.g * 255),(color.b * 255));
        }


        /**zmienna przechowująca wartość koloru czerwonego (0 - 1)*/
        double r;
         /**zmienna przechowująca wartość koloru zielonego (0 - 1)*/
        double g;
         /**zmienna przechowująca wartość koloru niebieskiego (0 - 1)*/
        double b;


};

#endif // MYCOLOR_H
