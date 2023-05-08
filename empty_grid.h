
#ifndef EMPTY_GRID_H
#define EMPTY_GRID_H


#include <QWidget>
#include <QVBoxLayout>
#include <QEvent>
#include <QLabel>


class empty_grid : public QWidget
{
    Q_OBJECT
public:
    QLabel* body;
    bool planted = false;
    explicit empty_grid(QRect rec, QWidget *parent = nullptr);
    void setTarget(QWidget* _target);

private:
    QWidget* target;
signals:

};

#endif // EMPTY_GRID_H
