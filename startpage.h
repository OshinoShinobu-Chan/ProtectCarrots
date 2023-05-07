
#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>
#include "mainpage.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Startpage; }
QT_BEGIN_NAMESPACE

class Startpage : public QWidget

{
    Q_OBJECT

public:
    Startpage(QWidget *parent = nullptr);
    ~Startpage();

private slots:
    void on_ExitButton_clicked(bool checked);

    void on_StartButton_clicked();

private:
    Ui::Startpage *ui;
};

#endif // STARTPAGE_H
