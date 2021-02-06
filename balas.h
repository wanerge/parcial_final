#ifndef BALAS_H
#define BALAS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <math.h>
#include <QDebug>

class balas: public QGraphicsItem, public QObject
{
public:
    balas(float r_, float x, float y);
    ~balas();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void num1(float Dx, float diametro_canon);
    void num2(float Dx, float diametro_canon);
    void num3(float Vo_, float angle_);
    void num4();
    void num5();

    QTimer *time1;
    float posx, posy;
    float tiempo, Vo, Vx, Vy, angle;

private:
    float r;
    float pi=3.1416, gravedad = 9.81;

public slots:
    void movimiento();
};

#endif // BALAS_H
