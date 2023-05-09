
#ifndef TOWER_H
#define TOWER_H

#include "coordinate.h"
#include <string>

class Tower
{
public:
    Tower(int _type);
    ~Tower();
    virtual void animeProcess() = 0;//没有攻击时的动画
    virtual void animeAttack() = 0;
    virtual void Attack() = 0;//攻击
    int getLevel();
    void setLevel(int _level);
    int getType();
    void setTpye(int _type);
    double getHurt();
    void setHurt(double _hurt);
    double getFreq();
    void setFreq(double _freq);
    void getTarget(Coordinate* dest);
    int getTargetNum();
    virtual void renewTarget() = 0;//更新目标列表
    std::string getImgpath();
    void setImgpath(std::string path);
    static const int TYPE_BOTTLE_TOWER = 1;
    static const int TPYE_SUNTOWER = 2;
    

private:
    int level;//等级
    int type;//类型,使用类型常量
    int value;//价值，即需要花费的金钱
    double hurt;//造成的伤害值
    double freq;//攻击的频率，单位暂定为次/分
    Coordinate* targets;//攻击的目标的坐标列表，可以考虑是否需要坐标类
    int targetNum;//攻击目标的数量
    std::string imgpath;//图片的路径

};

#endif // TOWER_H
