#include "botones.h"

botones::botones(QString text)
{
    this->setText(text);
    this->resize(50,50);
    this->setFlat(true);
    this->setAutoFillBackground(true);

    QPalette pal;
    pal.setColor(QPalette::Button, QColor(79, 79, 79));
    pal.setColor(QPalette::ButtonText, QColor(111, 3, 3));
    this->setPalette(pal);

    QFont font;
    font.setFamily("OCR A Extended");
    font.setBold(true);
    font.setPixelSize(35);
    this->setFont(font);
}

botones::~botones()
{

}
