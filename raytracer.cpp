#include "raytracer.h"

/**wyłuskanie koloru*/
QColor strip_color(QColor color){

    int red = color.red();
    int green = color.green();
    int blue =  color.blue();

        red = red < 0 ? 0 : red > 1 ? 1 : red;
        green = green < 0 ? 0 : green > 1 ? 1 : green;
        blue = blue < 0 ? 0 : blue > 1 ? 1 :blue;

        return QColor((red * 255),(green * 255),(blue * 255));
}

QColor Raytracer::shaderay(World world, VRay ray){

        HitInfo info = world.TraceRay(ray);



       // if (info.hit_object == NULL)
          //  return world.get_bg_color().rgb();

        QRgb final_color(0);

        QList<PointLight> light_list = world.get_lights();

        if (light_list.empty())
            return QColor(255,255,255);

       // Material *material = info.hit_object->get_material();

        PerfectDiffuse material(QColor(255,0,0));


        for(int i=0; i<light_list.size();i++)
           final_color += (material.radiance(light_list[i], info)).rgb();


        return QColor(final_color);
}


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

            image.setPixel(i, j, (strip_color((shaderay(world, ray)))).rgb());

            //HitInfo info = world.TraceRay(ray);


        }

       return image;
}




