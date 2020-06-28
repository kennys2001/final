#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<position.h>
#include<tower.h>
#include<bullet.h>
#include<QLabel>
#include<archer.h>
#include<giant.h>
#include<towering.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //class bullet Bullet[20];
    QVector<tower> T;
    QVector<enemy> E;
    QVector<archer> A;
    QVector<bullet> B;
    QVector<giant> G;
    QVector<towering> TT;
    headquarter head;
    void paintEvent(QPaintEvent *);
    QList<QLabel *> label_list;
    void createenemy();
    int money;
    int tt[3];
    int day;
private slots:

    void on_levelup_clicked();

    void on_tower1_clicked();

    void on_tower2_clicked();

    void on_pushButton_clicked();

    void on_tower3_clicked();

    void on_delete1_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_end_clicked();

private:

    Ui::Widget *ui;
};
#endif // WIDGET_H
