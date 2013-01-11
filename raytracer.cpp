#include "raytracer.h"
#include<QColor>
#include"mycolor.h"

QColor Raytracer::shaderay(World world, VRay ray){

        HitInfo info = world.TraceRay(ray);

        if (info.hit_object == NULL)
           return world.get_bg_color();



        QList<PointLight> light_list = world.get_lights();


        Material *material = info.hit_object->get_material();

        double r,g,b;


        for(int i=0; i<light_list.size();i++){
            if (world.obstacles(info.hit_point, light_list[i].get_position()))
                continue;

            r += material->radiance(light_list[i], info).red();
            g += material->radiance(light_list[i], info).green();
            b += material->radiance(light_list[i], info).blue();
        }

        return QColor(r,g,b);
}


/**definicja metody RayTrace*/
QImage Raytracer::RayTrace(World world, Vcamera &camera, QSize image_size,Sampler distributor){

    //tworzenie zmiennej przechowującej mapę
    QImage image = QImage(image_size.width(), image_size.height(),QImage::Format_RGB32);

    //zapełnianie mapy
    for(int i = 0; i < image_size.width(); i++)
        for (int j = 0; j < image_size.height(); j++)
        {
          /*  // przeskalowanie i oraz j do zakresu od -1 do 1
            Vector2 picture_coordinates((double)(((i + 0.5)/image_size.width())*2-1),
                                                      (double)(((j + 0.5)/image_size.height())*2-1));
            // sprawdzenie na co trafił promień
            VRay ray = camera.GetRayTo(picture_coordinates);

            image.setPixel(i, j, (shaderay(world, ray)).rgb());
            */
            //dodajemy sampling
            QColor Color;
            Vector3 final(0,0,0);
            for(int k=0;k<distributor.getSampleCout();++k){
                Vector2 sample=distributor.Single();
                Vector2 pic_coords(
                            ((double)(i+sample.x)/(double)image_size.width())*2-1,
                            ((double)(j+sample.x)/(double)image_size.height())*2-1);
                VRay rayt= camera.GetRayTo(pic_coords);
                Color=shaderay(world,rayt);
                final=final+Vector3(Color.red(),Color.green(),Color.blue())/(double)distributor.getSampleCout();
            }
            Color.setRgb((int)final.getX(),(int)final.getY(),(int)final.getZ());
            image.setPixel(i,j,Color.rgb());

        }

       return image;
}




