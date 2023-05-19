
#ifndef BOTTELTOWER_H
#define BOTTELTOWER_H

#include "tower.h"
#include <QGraphicsItem>
#include <QTimer>


class BottelTower : public Tower
{
public:
    BottelTower(QPointF _location);
    ~BottelTower();
    void advance(int phase);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    void renewTarget() override;
    Monster* getTarget() override;
    void animeAttack() override;
    void Attack() override;
    Monster* getNearest();
    qreal getAngle(QPoint a);//用于计算炮口的角度
    void rotateAnime();
    static const int BOTTLE_SPEED;
public:
    int frame;
    static const double FPS = 30.0;
};

#endif // BOTTELTOWER_H
