#include "colisiones.h"

bool Colision::esColision(Colision& obj)const {
    return getBounds().intersects(obj.getBounds());
}
