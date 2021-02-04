#ifndef CUERPO_H
#define CUERPO_H

#include <QGraphicsItem>
#include <QPainter>

class cuerpo: public QGraphicsItem
{
public:
    cuerpo(int r_, int x, int y);
    ~cuerpo();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private:
    int r;
    int posx, posy;

};

#endif // CUERPO_H
