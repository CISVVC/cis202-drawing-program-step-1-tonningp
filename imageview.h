#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
enum Operation {noop,ellipse,rectangle,line};
class ImageView : public QGraphicsView
{
       Q_OBJECT
   public:
       // http://en.cppreference.com/w/cpp/language/explicit
       explicit ImageView(QWidget *parent = 0);

   signals:

   public slots:
       void mousePressEvent(QMouseEvent * e);
       // void mouseReleaseEvent(QMouseEvent * e);
       // void mouseDoubleClickEvent(QMouseEvent * e);
       void mouseMoveEvent(QMouseEvent * e);
       void addingEllipse(bool);
       void addingLine(bool);
       void addingRectangle(bool);
   private:
       QGraphicsScene * scene;
       QPointF last_position;
       Operation current_op;
};
#endif // IMAGEVIEW_H
