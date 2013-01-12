#include "raytracer.h"
#include<QColor>
#include"mycolor.h"

MyColor Raytracer::shaderay(World world, VRay ray, int current_depth){

    if (current_depth > max_depth)
        return MyColor(0,0,0);

        HitInfo info = world.TraceRay(ray);
        info.depth = current_depth + 1;

        if (info.hit_object == NULL)
           return world.get_bg_color();

        Material *material = info.hit_object->get_material();

        return material->shade(*this, info);
}


/**definicja metody RayTrace*/
QImage Raytracer::RayTrace(World world, Vcamera &camera, QSize image_size, Sampler *distributor){

    //tworzenie zmiennej przechowującej mapę
    QImage image = QImage(image_size.width(), image_size.height(),QImage::Format_RGB32);
    int sampleCout=distributor->getSampleCout();
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

            Vector3 final(0,0,0);
            MyColor total_color;
            for(int k=0;k<distributor->getSampleCout();++k){
                Vector2 sample=distributor->Single();
                Vector2 pic_coords(
                            ((double)(i+sample.x)/(double)image_size.width())*2-1,
                            ((double)(j+sample.x)/(double)image_size.height())*2-1);
                VRay rayt= camera.GetRayTo(pic_coords);


                total_color= total_color + shaderay(world,rayt,0)/(double)sampleCout;
                //final=final+Vector3(Color.red(),Color.green(),Color.blue())
            }
            //Color.setRgb((int)final.getX(),(int)final.getY(),(int)final.getZ());
            image.setPixel(i,j,(MyColor::strip_color(total_color)).rgb());

        }

       return image;
}




