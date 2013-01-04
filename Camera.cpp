
#include"Camera.h"
#include<math.h>

Orthogonal::GetRayTo(Vector2 pictureLocation) {
    //kierunek w kt�rym jest skierowane s� promienie wychodz�ce
    // z kamery 
    Vector3 direction(sin(angle), 0, cos(angle));
    //normalizujemy kierunek
    direction = direction.normalized();
    //oddalenie pocz�tku kamery od jej po�o�enia
    Vector2 offset_center(pictureLocation.x * camera_size.x,
            pictureLocation.y * camera_size.y);

    //obliczanie finalnego po�o�enia pocz�tku promienia 
    Vector3 position(eye_position.getX() + offset_center.x * cos(angle),
            eye_position.getY() + offset_center.y,
            eye_position.getZ() + offset_center.x * sin(angle));

    return VRayy(position, direction);
}

Orthogonal::orthogonal(Vector3 eye, double angle1, Vector2 size) {
    eye_position = eye;
    camera_size = size;
    angle = angle1;
}
