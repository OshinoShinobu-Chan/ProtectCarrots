
#include "suntower.h"
#include "./ui_suntower.h"


SunTower::SunTower(Coordinate _location, QWidget *parent)
    : QWidget{parent},
    Tower(Tower::TPYE_SUNTOWER, _location),
    ui(new Ui::SunTower)
{
    setLevel(1);
    setHurt(100);
    setFreq(6);
    std::string imgpath = std::string("/");
    setImgpath(imgpath);
}

