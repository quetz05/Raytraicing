#include "raytracer.h"



/**definicja metody RayTrace*/
QImage Raytracer::RayTrace(World world, Vcamera &camera, QSize image_size){

    //tworzenie zmiennej przechowującej mapę
    QImage image = QImage(image_size.width(), image_size.height(),QImage::Format_RGB32);

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

            image.setPixel(i, j, color.rgb());
        }

       return image;
}

/**definicja funkcji shaderay*/
/*QColor Raytracer::shaderay(World world, VRay ray)
{
        HitInfo info = world.TraceRay(ray);

        if (info.hit_object2 == null)
            return world.background_color;

        QColor final_color(0,0,0);
        Material material = info.HitObject.Material;
            for(int i=0; i<world.lights.size();i++)
            {
                if (world.obstacle(info.hit_point, world.lights[i].position))
                    continue;

                final_color += material.radiance(world.lights[i], info);
            }

        return final_color;
}*/

