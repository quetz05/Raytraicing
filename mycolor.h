/**nagłówek zawierający implementację klasy MyColor tworzącej własną klasę koloru*/
#ifndef MYCOLOR_H
#define MYCOLOR_H
#include <QColor>

/**
 * @brief MyColor klasa tworząca własny format koloru rgb, gdzie każda ze zmiennych (r,g,b) przyjumje wartości od 0 do 1 i jest typu zmiennoprzecinkowego (double)
 */
class MyColor{

    public:

        /**
         * @brief MyColor konstruktor bezargumentowy tworzący kolor czarny (0,0,0)
         */
        MyColor(){r=0;g=0;b=0;}
        /**
         * @brief MyColor konstruktor
         * @param nr kolor red
         * @param ng kolor green
         * @param nb kolor blue
         */
        MyColor(double nr, double ng, double nb): r(nr), g(ng), b(nb) {}
        /**
         * @brief MyColor konstruktor tworzący kolor z formatu QColor
         * @param color kolor w formacie QColor
         */
        MyColor(const QColor &color){r=color.red()/255.0; g=color.green()/255.0, b=color.blue()/ 255.0;}
        /**
         * @brief MyColor konstruktor kopiujący
         * @param color kolor w formacie MyColor
         */
        MyColor(const MyColor &c): r(c.r),g(c.g),b(c.b){}

        /**
         * @brief operator + przeciążanie operatora dodawania dwóch kolorów
         */
        MyColor operator +(const MyColor &col1){return MyColor(col1.r + this->r, col1.g + this->g, col1.b + this->b);}
        /**
         * @brief operator * przeciążenie operatora mnożenia koloru przez liczbę
         */
        MyColor operator *(double val){return MyColor(this->r * val, this->g  * val, this->b  * val); }
        /**
         * @brief operator * przeciążenie operatora mnożenia dwóch kolorów
         */
        MyColor operator *(const MyColor &col1){return MyColor(col1.r * this->r, col1.g * this->g, col1.b * this->b);}
        /**
         * @brief operator / przeciążenie operatora dzielenia koloru przez liczbę
         */
        MyColor operator /(double val){return MyColor(this->r /val, this->g  /  val, this->b  / val);}



        /**
         * @brief strip_color metoda "obcinająca" kolor jeśli przekracza zakres
         * @param color kolor w formacie MyColor
         * @return zwraca obiekt klasy QColor
         */
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


        /**
         * @brief r zmienna przechowująca wartość koloru czerwonego (0-1)
         */
        double r;
        /**
         * @brief g zmienna przechowująca wartość koloru zielonego (0-1)
         */
        double g;
        /**
         * @brief b zmienna przechowująca wartość koloru niebieskiego (0-1)
         */
        double b;


};

#endif // MYCOLOR_H
