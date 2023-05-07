#include "mainpage.h"
#include "ui_mainpage.h"

Mainpage::Mainpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainpage)
{
    ui->setupUi(this);
    output = new QAudioOutput(this);

    player = new QMediaPlayer(this);
    player->setAudioOutput(output);
    output->setVolume(0.5);
    player->setLoops(1);
    player->setSource(QUrl("qrc:/src/Never Gonna Give You Up.mp3"));
    player->play();
}

Mainpage::~Mainpage()
{
    delete ui;


}

void Mainpage::on_toolButton_clicked()
{
    MainSettings *settingpage = new MainSettings(player, output, this);
    settingpage -> show();
}
