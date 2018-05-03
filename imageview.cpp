#include "imageview.h"
#include <QDebug>

ImageView::ImageView(QWidget *parent) :
        QGraphicsView(parent)
{
        scene = new QGraphicsScene();
        //this->setSceneRect(50, 50, 350, 350);
        //this->setSceneRect(-200, -200, 400, 400);
        scene->setSceneRect(QRectF(-200,-200,400,400));
        this->setScene(scene);
        last_position.setX(0);
        last_position.setY(0);
        this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void ImageView::mousePressEvent(QMouseEvent * e)
{
    auto pos = mapToScene(e->pos()); // This maps "real world" coordinates to the Scene coordinates

    scene->addEllipse(pos.x(),pos.y(),		//x,y position of the upper left hand corner
                      10,10,				// width and height of the rectangle
                      QPen(Qt::black),		// the pen used for the outline
                      QBrush(Qt::black)); 	// the brush used for the inside of the ellipse
    if(last_position.x() != 0 && last_position.y() != 0)
    {
        scene->addLine(last_position.x(),
                       last_position.y(),
                        pos.x(),
                        pos.y(),
                        QPen(Qt::black)
                       );
    }
    last_position = pos;
    //qDebug() << e->pos();
}
