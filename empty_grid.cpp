
#include "empty_grid.h"

empty_grid::empty_grid(QRect rec,QWidget *parent)
    : QWidget{parent}
{
    body = new QLabel(this);
    body->setGeometry(QRect(0,0,rec.width(),rec.height()));
    this->setGeometry(rec);
//    body->setPixmap(QPixmap(R"(C:\Users\wangminqi\Desktop\recent_works\untitled2\icon.jpg)"));
//    body->setScaledContents(true);
    body->setStyleSheet(
        "background-color:rgba(0,0,0,1%);"
        "border:1px dashed rgb(0,0,0);");
    //body->installEventFilter(this);
    //qDebug() << "setup!";
}

void empty_grid::setTarget(QWidget* _target){
    target = _target;
}

