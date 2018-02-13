#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageparse.h"

#include <QFileDialog>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>

#include <stdexcept>

typedef ImageParser::Shape Shape;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString fileName = QFileDialog::getOpenFileName();

   QVector<QPolygonF> shapes;

   QImage img;
   try{
       img = QImage(fileName);

       for(int i=0; i<img.height(); i++)
       {
           for(int j=0; j<img.width(); j++)
           {
               img.setPixelColor(j, i, qGray(img.pixelColor(j, i).rgb()) > 125?QColor(255, 255, 255) : QColor(0, 0, 0));
           }
       }
       shapes = ImageParser::parseImage(fileName);
       //img.save(fileName.insert(fileName.indexOf("."), "_bw"));

   }catch(std::exception& ex){
       qDebug() << "Unable to load image" << fileName;
   }

   QGraphicsScene* scene = new QGraphicsScene(this);
   QGraphicsView* view = new QGraphicsView(this);

   view->setScene(scene);
   ui->viewLayout->addWidget(view);

   //scene->addPixmap(QPixmap::fromImage(img));

   for(QPolygonF& p : shapes)
   {
       scene->addPolygon(p);
   }

}

MainWindow::~MainWindow()
{
    delete ui;
}
