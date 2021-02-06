#include "balas.h"

balas::balas(float r_, float x, float y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx, posy);
    time1 = new QTimer;
    connect(time1, &QTimer::timeout, this, &balas::movimiento);
}

QRectF balas::boundingRect() const
{
    return QRectF(-r,-r, 2*r, 2*r);
}

void balas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void balas::num1(float Dx, float diametro_canon)
{
    int angulo;
    angulo = (rand()%80)+5;
    angle = (angulo*pi/180);
    Dx = (rand()%(int(diametro_canon)+int(r*2)))+(Dx-int(r));
    Vo = sqrt((Dx-posx)*gravedad/(2*sin(angle)*cos(angle)));
    tiempo = 0;
    Vx = Vo*cos(angle);
    Vy = Vo*sin(angle);
    time1->start(15);
}

void balas::num2(float Dx, float diametro_canon)
{
    int angulo;
    angulo = (rand()%80)+95;
    angle = (angulo*pi/180);
    Dx = (rand()%(int(diametro_canon)+int(r*2)))+(Dx-int(r));
    Vo = sqrt((Dx-posx)*gravedad/(2*sin(angle)*cos(angle)));
    tiempo = 0;
    Vx = Vo*cos(angle);
    Vy = Vo*sin(angle);
    time1->start(15);
}

void balas::num3(float Vo_, float angle_)
{
    angle = angle_;
    Vo = Vo_;
    tiempo = 0;
    Vx = Vo*cos(angle);
    Vy = Vo*sin(angle);
    time1->start(15);
}

void balas::num4()
{

}

void balas::num5()
{

}

void balas::movimiento()
{
    float x2,y2;
    tiempo += 0.1;
    x2 = posx + Vx * tiempo;
    y2 = posy + Vy * tiempo -(0.5 * gravedad * tiempo * tiempo);
    y2 -= (y2-posy)*2;
    setPos(x2,y2);
}

balas::~balas()
{

}
