
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
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    void renewTarget() override;
    Monster* getTarget() override;
    void animeAttack() override;
    void Attack() override;
    Monster* getNearest();
    qreal getAngle(QPoint a);//用于计算炮口的角度
    static const int BOTTLE_SPEED;
};

#endif // BOTTELTOWER_H
