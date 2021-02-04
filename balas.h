#ifndef BALAS_H
#define BALAS_H

#include <QGraphicsItem>
#include <QPainter>

class balas: public QGraphicsItem
{
public:
    balas(int r_, int x, int y);
    ~balas();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private:
    int r;
    int posx, posy;

};

#endif // BALAS_H
