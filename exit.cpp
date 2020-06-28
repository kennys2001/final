#include "exit.h"
#include "ui_exit.h"
#include <QDebug>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QTextEdit>
exit::exit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exit)
{
    ui->setupUi(this);
    setFixedSize(1080,600);
    //QGridLayout *gridLayout = new QGridLayout;
    QDialog *mainwindow=new QDialog;
    QHBoxLayout *topLayout = new QHBoxLayout;
    QLabel *lbl = new QLabel(QWidget::tr("&Input:"), mainwindow);
    QLineEdit *lineEdt = new QLineEdit(mainwindow);
    lbl->setBuddy(lineEdt);
    topLayout->addWidget(lbl);
    topLayout->addWidget(lineEdt);
    QHBoxLayout *bomLayout = new QHBoxLayout;
    QPushButton *btn_ok = new QPushButton(QWidget::tr("OK"), mainwindow);
    btn_ok->setDefault(true);
    QPushButton *btn_cancel = new QPushButton(QWidget::tr("Cancel"), mainwindow);
    bomLayout->addStretch();
    bomLayout->addWidget(btn_ok);
    bomLayout->addStretch();
        bomLayout->addWidget(btn_cancel);
        bomLayout->addStretch();

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addLayout(topLayout);
        mainLayout->addLayout(bomLayout);

        mainwindow->setLayout(mainLayout);

        mainwindow->resize(300, 100);
        mainwindow->setWindowTitle(QWidget::tr("Qt Test"));
        mainwindow->show();



}

exit::~exit()
{
    delete ui;
}
