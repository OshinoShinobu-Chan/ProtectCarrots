#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>
#include <QUrl>

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

private slots:
    void on_toolButton_clicked();

private:
    Ui::Mainpage *ui;
    QMediaPlayer *player;
    QAudioOutput *output;
};

#endif // MAINPAGE_H
