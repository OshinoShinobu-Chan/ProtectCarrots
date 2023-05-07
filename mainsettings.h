#ifndef MAINSETTINGS_H
#define MAINSETTINGS_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>>


namespace Ui {
class MainSettings;
}

class MainSettings : public QWidget
{
    Q_OBJECT

public:
    explicit MainSettings(QMediaPlayer* _player, QAudioOutput *_output, QWidget *parent = nullptr);
    ~MainSettings();

private slots:
    void on_MusicPause_clicked();

    void on_SettingsExit_clicked();

    void on_GameExit_clicked();

    void on_MusicController_valueChanged(int value);

private:
    Ui::MainSettings *ui;
    QMediaPlayer *player;
    QAudioOutput *output;
};

#endif // MAINSETTINGS_H
