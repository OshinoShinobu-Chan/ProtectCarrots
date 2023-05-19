
#include "botteltower.h"
#include <math.h>
#include <assert.h>

double getDistance(QPointF a, QPoint b){
    //获取两点之间的距离
    return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX())
        + (a.getY() - b.getY()) * (a.getY() - n.getY()));
}

qreal BottelTower::getAngle(QPointF a){
    //获取需要旋转的角度
    QPointF loc = data(Tower::DATA_LOCATION);
    qreal angle = atan2(a.getY() - loc.getY(), a.getX() - ;oc.getX());
    return angle;
}

BottelTower::BottelTower(QPointF _location) :
    Tower(Tower::TYPE_BOTTLE_TOWER, _location){
        setData(Tower::DATA_TYPE, Tower::TYPE_BOTTLE_TOWER);
        setData(Tower::DATA_HURT, 10);
        setData(Tower::DATA_FREQ, 20);
        setData(Tower::DATA_LEVEL, 1);
        setData(Tower::DATA_VALUE, 10);
        setData(Tower::DATA_IMGPATH, "xxx");
        setData(Tower::DATA_RANGE, 20);
        setData(Tower::DATA_LOCATION, _location);
        setData(Tower::DATA_WIDTH, width);
        setData(Tower::DATA_HEIGHT, height);
}

BottelTower::~BottelTower(){ }

void BottelTower::advance(int phase){
    if(phase == 0);
    else{
        renewTarget();
        if((frame/FPS) == 60.0 / data(BottelTower::DATA_FREQ)){
            Attack();
            frame = 0;
            return;
        }
        rotateAnime();
        frame++;
    }
}

QRectF boundingRect(){
    return QRectF(data(Tower::DATA_LOCATION).getX() - data(Tower::DATA_WIDTH) / 2,
                  data(Tower::DATA_LOCATION).getY() - data(Tower::DATA_HEIGHT) / 2,
                  data(Tower::DATA_WIDTH), data(Tower::DATA_HEIGHT));
}

void BottelTower::rotateAnime(){
    qreal dest_angle = getAngle(targets -> pos());
    animeAttack(dest_angle);
}

Monster* BottelTower::getNearest(){
    //找到最近的怪物
    QList<QGraphicsItem*> list = scene() -> items();
    QGraphicsItem* minItem = list[0];
    int minDistance = 0x7ffffff;
    for(int i = 0;i < list.size(); i++){
        int tmpDistance = getDistance(list[i] -> pos(), pos());
        if(tmpDistance < minDistance && list[i] -> data(const_for_type) == const_monster){
            minDistance = tmpDistance;
            minItem = list[i];
        }
    }
    return (Monster*)minItem;
}

void BottelTower::renewTarget(){
    if(targets == nullptr){
        targets = getNearest();
        return;
    }
    else{
        int distance = getDistance(pos(), targets -> pos());
        if(distance > data(Tower::DATA_RANGE)){
            targets = getNearest();
            return;
        }
    }
}

void BottelTower::animeAttack(qreal destangle){
    setRotation(destangel);
}

void BottelTower::Attack(){
    //创建炮弹对象，获取目标对象
    Bottel *bottel = new Bottel();
    Monster *target = *targets;
    int hurt = data(Tower::DATA_HURT);
    //炮口旋转
    rotateAnime();
    //计算炮弹到达的时间，定时对目标造成伤害
    assert(BottelTower::BOTTLE_SPEED != 0);
    int time = getDistance(pos(), target -> pos()) 
            / BottelTower::BOTTLE_SPEED;
    QTimer* attack_timer = new QTimer(this);
    connect(attack_timer, SIGNAL(QTimer::timeout),
            this, SLOT([target, hurt](){target -> hurt(hurt);}));
    timer -> setSingleShot(true);
    timer -> start(time);
}