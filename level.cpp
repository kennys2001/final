#include "level.h"
#include "ui_level.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPainter>
#include <form.h>
#include <widget.h>
#include <new.h>
Level::Level(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Level)
{
    ui->setupUi(this);
}

Level::~Level()
{
    delete ui;
}
void Level::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,1080,600,QPixmap(":/resource/level.jpeg"));
}

void Level::on_p1_clicked()
{
    New *p=new  New;
    p->show();
    this->close();
}

void Level::on_exit_clicked()
{
    Form *p=new Form;
    p->show();
    this->close();
}

void Level::on_p2_clicked()
{
    Widget *p=new Widget;
    p->show();
    this->close();
}
