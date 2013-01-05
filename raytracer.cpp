#include "raytracer.h"


/**definicja metody RayTrace*/
QImage RayTrace(World world, Vcamera &camera, QSize image_size){

    //tworzenie zmiennej przechowującej mapę
    QImage pixmap = QImage(image_size.width(), image_size.height(),QImage::Format_RGB32);

    //zapełnianie mapy
    for(int i = 0; i < image_size.width(); i++)
        for (int j = 0; j < image_size.height(); j++)
        {
            // przeskalowanie i oraz j do zakresu od -1 do 1
            Vector2 picture_coordinates((double)(((i + 0.5)/image_size.width())*2-1),
                                                      (double)(((j + 0.5)/image_size.height())*2-1));
            // sprawdzenie na co trafił promień
            VRay ray = camera.GetRayTo(picture_coordinates);
            HitInfo info = world.TraceRay(ray);

            // ustawienie odpowiedniego koloru w obrazie wynikowym
            QColor color;
            if (info.hit_object)
                color = info.color;
            else
                color = world.get_bg_color();

            pixmap.setPixel(i, j, color.rgb());
        }

       return pixmap;
}


