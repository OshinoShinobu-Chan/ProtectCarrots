#include "mainsettings.h"
#include "ui_mainsettings.h"

MainSettings::MainSettings(QMediaPlayer *_player, QAudioOutput *_output, QWidget *parent) :
    player(_player),
    output(_output),
    QWidget(parent),
    ui(new Ui::MainSettings)
{
    ui->setupUi(this);
    this -> setFixedSize((parent -> size()));
    ui -> MusicController -> setValue(output -> volume() * 100);
    if(!player -> isPlaying()){
        ui -> MusicPause -> setText("播放音乐");
    }
}

MainSettings::~MainSettings()
{
    delete ui;
}

void MainSettings::on_MusicPause_clicked()
{
    if(player->isPlaying()){
        player -> pause();
        ui -> MusicPause -> setText("播放音乐");
    }
    else {
        player -> play();
        ui -> MusicPause -> setText("暂停音乐");
    }
}


void MainSettings::on_SettingsExit_clicked()
{
    this -> close();
}


void MainSettings::on_GameExit_clicked()
{
    exit(0);
}


void MainSettings::on_MusicController_valueChanged(int value)
{
    this -> output -> setVolume(value / 100.0);
}

