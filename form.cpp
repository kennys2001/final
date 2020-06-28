#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPainter>
#include <level.h>
#include<QSound>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    //ui->words->setStyleSheet("background-color:transparent");
            //ui->lineEdit->setStyleSheet("background-color:transparent");
            //ui->lineEdit->setFrame(QFrame::NoFrame);
    ui->words->setStyleSheet("background-color:white");
    ui->words->hide();  
    ui->pushButton->hide();

}

Form::~Form()
{
    delete ui;
}



void Form::on_playButton_clicked()
{
    Level *p=new Level;
    p->show();
    this->close();
}

void Form::on_setButton_clicked()
{

}

void Form::on_introButton_clicked()
{
    ui->words->show();
    ui->pushButton->show();
    ui->exitButton->hide();
    ui->playButton->hide();
    ui->setButton->hide();
    ui->introButton->hide();
}

void Form::on_exitButton_clicked()
{
    QApplication *app;
    app->exit();
}

void Form::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->words->hide();
    ui->exitButton->show();
    ui->playButton->show();
    ui->setButton->show();
    ui->introButton->show();
}
void Form::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,1080,600,QPixmap(":/resource/rush.jpg"));


}
