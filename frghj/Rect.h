#ifndef RECT_H
#define RECT_H
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
class Rect : public QWidget
{
public:
      Rect(QWidget *parent = 0);
      int GetPoint_x(){
          return point_x;
      }
      int GetPoint_y(){
          return point_y;
      }
      int GetHeigth(){
          return heigth;
      }
      int GetWidth(){
          return width;
      }
      virtual void doDrawing(QPainter *painter);
private:
     const static int heigth = 200;
     const static int width = 300;
     int point_x = 0;
     int point_y = 100;
};

#endif // RECT_H
