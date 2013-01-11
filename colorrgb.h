#ifndef COLORRGB_H
#define COLORRGB_H
#include <QColor>

class ColorRgb
{
public:

    ColorRgb(double nr, double ng, double nb){r=nr; g=ng; b=nb;}

    static ColorRgb from_qcolor(QColor color){return ColorRgb(color.red() / 255.0, color.green() / 255.0, color.blue() / 255.0);}

    //static QColor to_qcolor(ColorRgb color){return QColor (color.r*255,color.g*255,color.b*255);}
    ColorRgb operator +(ColorRgb col1, ColorRgb col2){ return ColorRgb(col1.R + col2.R, col1.G + col2.G, col1.B + col2.B); }
    ColorRgb operator *(ColorRgb col1, double val){ return ColorRgb(col1.R * val, col1.G * val, col1.B * val); }
    ColorRgb operator *(ColorRgb col1, ColorRgb col2){ return ColorRgb(col1.R * col2.R, col1.G * col2.G, col1.B * col2.B); }
    ColorRgb operator /(ColorRgb col1, double val){ return col1 * (1 / val);}

double r,g,b;



}


#endif // COLORRGB_H
