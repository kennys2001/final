#ifndef NEW_H
#define NEW_H

#include <QWidget>
#include<position.h>
#include<tower.h>
#include<bullet.h>
#include<QLabel>
#include<archer.h>
#include<giant.h>
#include<QPainter>
#include<QLabel>
namespace Ui {
class New;
}

class New : public QWidget
{
    Q_OBJECT

public:
    explicit New(QWidget *parent = nullptr);
    ~New();
    QVector<tower> T;
    QVector<enemy> E;
    QVector<archer> A;
    QVector<bullet> B;
    QVector<giant> G;
    headquarter head;
    void paintEvent(QPaintEvent *);
    QList<QLabel *> label_list;
    void createenemy();
    int money;
    int tt[3];
    int day;
    int di[3][3]={{1,2,0},{2,4,0},{3,4,0}};
private:
    Ui::New *ui;
private slots:

    void on_levelup_clicked();

    void on_tower1_clicked();

    void on_tower2_clicked();

    void on_pushButton_clicked();

    void on_tower3_clicked();

    void on_delete1_clicked();
    void on_next_clicked();
};

#endif // NEW_H
