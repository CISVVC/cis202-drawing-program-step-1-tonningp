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
        connect(parent,SIGNAL(addingEllipse(bool)),this,SLOT(addingEllipse(bool)));
        connect(parent,SIGNAL(addingLine(bool)),this,SLOT(addingLine(bool)));
        connect(parent,SIGNAL(addingRectangle(bool)),this,SLOT(addingRectangle(bool)));
        rubberBand = NULL;

}

void ImageView::mousePressEvent(QMouseEvent * e)
{
    origin = e->pos();
    if (!rubberBand)
            rubberBand = new QRubberBand(QRubberBand::Line, this);
    rubberBand->setGeometry(QRect(origin, QSize()));
    if(current_op != Operation::noop)
        rubberBand->show();

}

void ImageView::mouseReleaseEvent(QMouseEvent *event)
{
   rubberBand->hide();
   // determine selection, for example using QRect::intersects()
   // and QRect::contains().
   auto pos = mapToScene(origin); // This maps "real world" coordinates to the Scene coordinates
   if(current_op == Operation::ellipse )
   {
        QGraphicsEllipseItem *ellipse = scene->addEllipse(pos.x(),pos.y(),		//x,y position of the upper left hand corner
                  rubberBand->width(),rubberBand->height(),				// width and height of the rectangle
                  QPen(Qt::blue),		// the pen used for the outline
                  QBrush(Qt::blue)); 	// the brush used for the inside of the ellipse
        ellipse->setFlag(QGraphicsItem::ItemIsMovable);
        //ellipse->setFlag(QGraphicsItem::ItemIsSelectable);
        //last_position = pos;
   }
}

void ImageView::mouseMoveEvent(QMouseEvent *event)
{
    if(current_op != Operation::noop)
        rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
    QGraphicsView::mouseMoveEvent(event);
}

void ImageView::addingEllipse(bool toggled)
{
    if(toggled)
    {
        current_op = Operation::ellipse;
    }
    else
    {
       current_op = Operation::noop;
    }
}

void ImageView::addingLine(bool toggled)
{
    if(toggled)
    {
        current_op = Operation::line;
    }
}

void ImageView::addingRectangle(bool toggled)
{
    if(toggled)
    {
        current_op = Operation::rectangle;
    }
}
