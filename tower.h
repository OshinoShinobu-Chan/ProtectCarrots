
#ifndef TOWER_H
#define TOWER_H

#include "coordinate.h"

class Tower
{
public:
    virtual void animeProcess() = 0;//没有攻击时的动画
    virtual void animeAttack() = 0;
    virtual void Attack() = 0;//攻击
    virtual int getLevel()= 0;
    virtual void setLevel(int _level)= 0;
    virtual int getType()= 0;
    virtual void setTpye(int _type)= 0;
    virtual double getHurt()= 0;
    virtual void setHurt(double _hurt)= 0;
    virtual double getFreq() = 0;
    virtual void setFreq(double _freq) = 0;
    virtual int getTarget(Coordinate* dest) = 0;
    virtual void renewTarget() = 0;//更新目标列表
    virtual string getImgpath() = 0;
    virtual void setImgpath(string path) = 0;
    

private:
    int level;//等级
    int type;//类型,使用类型常量
    int value;//价值，即需要花费的金钱
    double hurt;//造成的伤害值
    double freq;//攻击的频率，单位暂定为次/分
    Coordinate* targets;//攻击的目标的坐标列表，可以考虑是否需要坐标类
    int targetNum;//攻击目标的数量
    string imgpath;//图片的路径
};

#endif // TOWER_H
