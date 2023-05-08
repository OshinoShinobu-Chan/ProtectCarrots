#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>
#include <QUrl>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QCloseEvent>
#include "empty_grid.h"


#include "mainsettings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Mainpage;
}
QT_BEGIN_NAMESPACE

class Mainpage : public QWidget
{
    Q_OBJECT

public:
    Mainpage(QWidget *parent = nullptr);
    ~Mainpage();

    virtual void closeEvent(QCloseEvent* );
    bool eventFilter(QObject*,QEvent*);


private slots:
    void on_toolButton_clicked();

private:
    Ui::Mainpage *ui;
    QMediaPlayer *player;
    QAudioOutput *output;

    QList<empty_grid*> grid;
    QList<QPushButton*> plants;
    QWidget* window;
    QWidget* tower_window;
    empty_grid* clicked_grid;
    QStringList plant_name;
    QPushButton* shovel;
    int money = 1000;

};

#endif // MAINPAGE_H
