#include "cuerpo.h"

cuerpo::cuerpo(float r_, float x, float y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx, posy);
}

QRectF cuerpo::boundingRect() const
{
    return QRectF(-r,-r, 2*r, 2*r);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

cuerpo::~cuerpo()
{

}
