#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,980,580);
    ui->graphicsView->setScene(scene);

    canon_ofensivo = new cuerpo(15, 50, 500);
    canon_defensivo = new cuerpo(15, 930, 500);

    d = (canon_defensivo->x()-canon_ofensivo->x());
    bala_O = new balas((0.05*d),canon_ofensivo->x(),canon_ofensivo->y());
    //bala_O = new balas(10,canon_ofensivo->x(),canon_ofensivo->y());
    bala_D = new balas((0.025*d),canon_defensivo->x(),canon_defensivo->y());

    scene->addItem(canon_ofensivo);
    scene->addItem(canon_defensivo);
    scene->addItem(bala_O);
    scene->addItem(bala_D);

    bala_O->setPos(-40,-40);
    bala_D->setPos(-80,-80);

    time = new QTimer;
    time->start(30);
    connect(time, &QTimer::timeout, this, &MainWindow::colision);
}

void MainWindow::on_pushButton_clicked()
{
    bala_O->setPos(bala_O->posx,bala_O->posy);
    bala_D->setPos(-80,-80);
    bala_O->num1(canon_defensivo->x()-15, (canon_ofensivo->r*2));
}

void MainWindow::on_pushButton_2_clicked()
{
    bala_D->setPos(bala_D->posx,bala_D->posy);
    bala_O->setPos(-40,-40);
    bala_D->num2(canon_ofensivo->x()-15, (canon_defensivo->r*2));
}

void MainWindow::on_pushButton_3_clicked()
{
    float angulo;
    bala_O->setPos(bala_O->posx,bala_O->posy);
    bala_D->setPos(bala_D->posx,bala_D->posy);
    bala_O->num1(canon_defensivo->x()-15, (canon_ofensivo->r*2));
    angulo = (bala_O->angle*180/3.1416);
    angulo = (180-angulo);
    angulo = (angulo*3.1416/180);
    bala_D->num3(bala_O->Vo, angulo);
}

void MainWindow::on_pushButton_4_clicked()
{
    float angulo;
    bala_O->setPos(bala_O->posx,bala_O->posy);
    bala_D->setPos(bala_D->posx,bala_D->posy);
    bala_O->num1(canon_defensivo->x()-15, (canon_ofensivo->r*2));
    angulo = (bala_O->angle*180/3.1416);
    angulo = (180-angulo);
    angulo = (angulo*3.1416/180);
    bala_D->num3(bala_O->Vo, angulo);
}

void MainWindow::on_pushButton_5_clicked()
{

}

void MainWindow::on_pushButton_6_clicked()
{

}

void MainWindow::colision()
{
    if (bala_O->collidesWithItem(canon_defensivo)) {
        bala_O->time1->stop();
    }
    if (bala_D->collidesWithItem(canon_ofensivo)) {
        bala_D->time1->stop();
    }
    if (bala_D->collidesWithItem(bala_O)) {
        bala_O->time1->stop();
        bala_D->time1->stop();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
