#include "mainpage.h"
#include "ui_mainpage.h"

Mainpage::Mainpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainpage)
{
    ui->setupUi(this);

    //设置“设置”按钮
    output = new QAudioOutput(this);

    player = new QMediaPlayer(this);
    player->setAudioOutput(output);
    output->setVolume(0.5);
    player->setLoops(1);
    player->setSource(QUrl("qrc:/src/Never Gonna Give You Up.mp3"));
    player->play();

    //窗口大小位置初始化
    this->setGeometry(QRect(100,100,800,600));

    //种植植物初始化
    plant_name = {"bottle_tower","sunflower","star_tower"};

    //边栏数据初始化
    ui->money_bar->setText(QString::number(money));

    //种植菜单初始化
    window = new QWidget();
    window->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

    for(int k = 0; k < plant_name.count(); k++){
        QPushButton *button = new QPushButton(plant_name[k]);
        button->installEventFilter(this);
        plants.append(button);
    }

    QVBoxLayout *layout = new QVBoxLayout;
    for(int k = 0; k < plant_name.count(); k++){
        layout->addWidget(plants[k]);
    }

    window->setLayout(layout);
    window->show();
    window->setVisible(false);

    //炮塔菜单初始化
    tower_window = new QWidget();
    tower_window->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

    QVBoxLayout *tower_layout = new QVBoxLayout;

    shovel = new QPushButton("Shovel");
    shovel->installEventFilter(this);
    tower_layout->addWidget(shovel);

    tower_window->setLayout(tower_layout);
    tower_window->show();
    tower_window->setVisible(false);

    //网格初始化
    int w = 40, h = 40, gap = 8, start = 80;

    for (int x = start; x + w + 2 * gap< this->width();x += w + gap)
        for (int y = start; y + h + 2 * gap< this->height();y += h + gap){
            empty_grid* new_grid = new empty_grid(QRect(x, y, w, h), this);
            new_grid->setTarget(window);
            grid.append(new_grid);
            new_grid->installEventFilter(this);
        }
    this->installEventFilter(this);


}


bool Mainpage::eventFilter(QObject* watched,QEvent* event){

    if(event->type() == QEvent::MouseButtonPress){
        qDebug() << "Clicked";
        if(grid.contains(watched)){
            qDebug() << "Grid Clicked";
            empty_grid* cur = (empty_grid*)watched;
            cur->body->setStyleSheet(
                "background-color:rgba(0,0,0,5%);"
                "border:1px dashed rgb(0,0,0);");
            qDebug() << "pressed!";
            int x = cur->x(), y = cur->y();
            qDebug() << x << y;
            if(cur->planted){
                tower_window->setGeometry(QRect(x+tower_window->width(),y+tower_window->height(),tower_window->width(),tower_window->height()));
                tower_window->setVisible(true);
                clicked_grid = cur;
            }
            else{
                window->setGeometry(QRect(x,y,window->width(),window->height()));
                window->setVisible(true);
                clicked_grid = cur;
            }
        }
        else if(plants.contains(watched)){
            qDebug() << "Select Plants";
            QPushButton* cur = (QPushButton*)watched;
            QPixmap p;
            QString url = QCoreApplication::applicationDirPath() + "/../../ProtectCarrots/src/plant/" + cur->text() + ".jpg";
            qDebug() << url;
            p.load(url);
            clicked_grid->body->setPixmap(p);
            clicked_grid->body->setScaledContents(true);
            clicked_grid->planted = true;
            money -= 75;
            ui->money_bar->setText(QString::number(money));
            window->setVisible(false);
        }
        else if(watched == shovel){
            qDebug() << "Shovel Plant!";
            clicked_grid->body->setPixmap(QPixmap(""));
            clicked_grid->planted = false;
            money += 50;
            ui->money_bar->setText(QString::number(money));
            tower_window->setVisible(false);
        }
        else{
            qDebug() << "Empty Clicked";
            window->setVisible(false);
            clicked_grid = nullptr;
        }
        return true;
    }
    if(event->type() == QEvent::MouseButtonRelease){
        if(grid.contains(watched)){
            empty_grid* cur = (empty_grid*)watched;
            cur->body->setStyleSheet(
                "background-color:rgba(0,0,0,1%);"
                "border:1px dashed rgb(0,0,0);");
            return true;
        }
    }

    //一定注意！！！这里返回父类的filter
    return QWidget::eventFilter(watched,event);
}


void Mainpage::closeEvent(QCloseEvent* e){
    //实现关闭主窗口的同时关掉其他窗口
    window->close();
    tower_window->close();
    e->accept();
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
