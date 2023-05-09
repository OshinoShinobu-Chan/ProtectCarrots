
#ifndef SUNTOWER_H
#define SUNTOWER_H


#include <QWidget>
#include "tower.h"
#include "coordinate.h"

namespace Ui {
class SunTower;
}

class SunTower : public QWidget, public Tower
{
    Q_OBJECT
public:
    explicit SunTower(Coordinate location, QWidget *parent = nullptr);

signals:

private:
    Ui::SunTower *ui;

};

#endif // SUNTOWER_H
