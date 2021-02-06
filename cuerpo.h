#ifndef CUERPO_H
#define CUERPO_H

#include <QGraphicsItem>
#include <QPainter>

class cuerpo: public QGraphicsItem
{
public:
    cuerpo(float r_, float x, float y);
    ~cuerpo();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    float r;

private:

    float posx, posy;

};

#endif // CUERPO_H
