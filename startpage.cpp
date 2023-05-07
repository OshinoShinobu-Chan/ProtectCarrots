
#include "startpage.h"
#include "./ui_startpage.h"


Startpage::Startpage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Startpage)
{
    ui->setupUi(this);
}

Startpage::~Startpage()
{
    delete ui;
}



void Startpage::on_ExitButton_clicked(bool checked)
{
    exit(0);
}


void Startpage::on_StartButton_clicked()
{
    this -> hide();
    Mainpage *main = new Mainpage();
    main -> show();
}

