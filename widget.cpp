
#include "widget.h"
#include "ui_widget.h"
#include<math.h>
#include<bullet.h>
#include<enemy.h>
#include<tower.h>
#include <QPainter>
#include <QTimer>
#include<QTime>
#include<QtDebug>
#include<QMovie>
#include<QLabel>
#include<QString>
#include<form.h>
#include<headquarter.h>
#include<archer.h>
#include <QBoxLayout>
#include<level.h>
#include<towering.h>
int i,j,k;
int wave;
int di[3][3]={{1,3,0},{2,4,1},{4,5,2}};

int ll=400;
int ff=30;
int temp=0;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
     ui->lineEdit->setFocusPolicy(Qt::NoFocus);
     ui->groupBox->hide();
     ui->groupBox_2->hide();
     ui->end->hide();
//    QMovie *pm=new QMovie(":/resource/testing.gif");




   // G.append(giant(position(1000,140)));
//    for(i=0;i<5;i++)
//    {
//        label_list[i]->setMovie(pm);
//        pm->start();
//    }

head=headquarter(position(0,340));

day=-1;

    QTimer *time=new QTimer(this);
    time->start(50);
    money=0;



    for(i=0;i<3;i++)
    {
        tt[i]=0;
    }
        connect(time,&QTimer::timeout,[=]()
    {
            if(E.size()+A.size()+G.size()==0&&day==2)
            {
                ui->end->show();
                time->stop();
            }

            if(head.health<=0)
            {
                time->stop();
                Level *p=new Level;
                p->show();
                this->close();
            }
        if (E.size()+A.size()+G.size()==0&&day<2)
        {

            if(day!=-1)
            {
                QVector<archer>().swap(A);
                QVector<enemy>().swap(E);
                QVector<bullet>().swap(B);


            }

            day++;
            createenemy();


        }
        else if(E.size()+A.size()+G.size()>0)
        {
            for(i=0;i<T.size();i++)
            {
                for(j=0;j<E.size();j++)
                {
                    if(T[i].p.length(E[j].p)<=200&&T[i].canattack>0)
                    {

                            B.append(bullet(T[i],E[j].p.seefuture(1,E[j].p)));
                            T[i].change_state();
                            break;
                    }
                    else
                    {
                        if(T[i].canattack>0)
                            ;
                        else T[i].canattack++;

                    }

                }
            }
            for(i=0;i<T.size();i++)
            {
                for(j=0;j<A.size();j++)
                {
                    if(T[i].p.length(A[j].p)<=200&&T[i].canattack>0)
                    {
                        B.append(bullet(T[i],A[j].p.seefuture(1,A[j].p)));
                        T[i].change_state();
                        break;
                    }
                    else
                    {
                        if(T[i].canattack>0)
                            ;
                        else T[i].canattack++;

                    }

                }
            }

            for(i=0;i<T.size();i++)
            {
                for(j=0;j<G.size();j++)
                {
                    if(T[i].p.length(G[j].p)<=200&&T[i].canattack>0)
                    {
                        B.append(bullet(T[i],G[j].p.seefuture(1.5,G[j].p)));
                        T[i].change_state();
                        break;
                    }
                    else
                    {
                        if(T[i].canattack>0)
                            ;
                        else T[i].canattack++;

                    }

                }
            }

            for(auto i=B.begin();i!=B.end();)
            {
                 (*i).move();
                 if((*i).p.get_positionX()>750||(*i).p.get_positionY()>600||(*i).p.get_positionX()<0||(*i).p.get_positionY()<0)
                 {
                        i=B.erase(i);
                 }
                 else ++i;

            }
            for(auto i=E.begin();i!=E.end();)
            {

                (*i).move();
                for(auto j=TT.begin();j!=TT.end();)
                {
                    if((*j).p.length((*i).p)<50)
                    {
                        (*i).life=(*i).life-5;
                        break;
                    }
                    else j++;
                }
                for(auto j=B.begin();j!=B.end();)
                {
                    if((*i).p.length((*j).p)<14.414)
                    {
                        (*i).life=(*i).life-(*j).damage;
                        j=B.erase(j);

                    }
                    else
                    ++j;
                }
                if((*i).life<=0||(*i).p.get_positionX()<=10)
                {

                    if((*i).life<=0)
                    money=(*i).money+money;
                    else
                    {
                        head.health=head.health-10;
                    }
                    i=E.erase(i);

                }
                else ++i;

           }

            for(auto i=A.begin();i!=A.end();)
            {

                (*i).move();
                for(auto j=TT.begin();j!=TT.end();)
                {
                    if((*j).p.length((*i).p)<50)
                    {
                        (*i).life=(*i).life-5;
                        break;
                    }
                    else j++;
                }
                for(auto j=B.begin();j!=B.end();)
                {
                    if((*i).p.length((*j).p)<14.414)
                    {
                        (*i).life=(*i).life-(*j).damage;
                        j=B.erase(j);
                    }
                    else
                    ++j;
                }
                if((*i).life<=0||(*i).p.get_positionX()<=10)
                {

                    if((*i).life<=0)
                    money=(*i).money+money;
                    else
                    {
                        head.health=head.health-20;
                    }
                    i=A.erase(i);
                }
                else ++i;
           }

            for(auto i=G.begin();i!=G.end();)
            {

                (*i).move();
                for(auto j=TT.begin();j!=TT.end();)
                {
                    if((*j).p.length((*i).p)<50)
                    {
                        (*i).life=(*i).life-5;
                        break;
                    }
                    else j++;
                }
                for(auto j=B.begin();j!=B.end();)
                {
                    if((*i).p.length((*j).p)<14.414)
                    {
                        (*i).life=(*i).life-(*j).damage;
                        j=B.erase(j);
                    }
                    else
                    ++j;
                }
                if((*i).life<=0)
                {
                    money=(*i).money+money;
                    i=G.erase(i);
                }
                else ++i;
           }
            for(auto i=G.begin();i!=G.end();)
            {

                if((*i).p.length(head.p)<=50&&(*i).canattack>0)
                {
                    (*i).speed=0.01;

                    (*i).attack();
                    head.health=head.health-50;

                    (*i).change_state();

                }
                else if((*i).canattack>0)
                {
                    ;
                }
                else (*i).canattack++;

                i++;
            }


        }
        else if(A.size()+E.size()+G.size()&&day==2)
        {

            time->stop();
        }

        update();

    });


    connect(ui->start,&QPushButton::clicked,[=]()
    {
        time->start();
    });

    connect(ui->pause,&QPushButton::clicked,[=]()
    {
        time->stop();

    });

}
void Widget::createenemy()
{
    for(i=0;i<di[day][0];i++)
    {   
        E.append(enemy(position(1080+10*3*i,140)));
    }

    for(i=0;i<di[day][1];i++)
    {
        A.append(archer(position(1080+10*3*(i+di[day][0]),140)));
    }
    for(i=0;i<di[day][2];i++)
    {
        G.append(giant(position(1080+30*(i+di[day][0]+di[day][1])+50,140)));
    }

}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
    //ui->lineEdit->setStyleSheet("background-color:transparent");
    //ui->lineEdit->setFrame(QFrame::NoFrame);

    QPainter painter(this);
    painter.drawPixmap(0,0,1080,600,QPixmap(":/resource/map1.jpg"));

    for(i=0;i<TT.size();i++)
    {

           painter.drawPixmap(TT[i].p.get_positionX()-80,TT[i].p.get_positionY()-40,180,100,QPixmap(":/resource/posion.png"));
           painter.drawPixmap(TT[i].p.get_positionX(),TT[i].p.get_positionY(),20,20,QPixmap(":/resource/2.png"));
    }
       for(i=0;i<T.size();i++)
       {
              painter.drawPixmap(T[i].p.get_positionX(),T[i].p.get_positionY(),20,20,QPixmap(":/resource/enemy.png"));
       }
       for(i=0;i<G.size();i++)
       {
           if(G[i].life<250)
            painter.drawPixmap(G[i].p.get_positionX(),G[i].p.get_positionY()-10,40,40,QPixmap(":/resource/tower.png"));
           else
             painter.drawPixmap(G[i].p.get_positionX(),G[i].p.get_positionY()-10,40,40,QPixmap(":/resource/enemy 2.png"));
       }
       for(i=0;i<E.size();i++)
       {
            painter.drawPixmap(E[i].p.get_positionX(),E[i].p.get_positionY(),20,20,QPixmap(":/resource/enemy.png"));
//           else if(Enemy[i].life==100)
//               painter.drawPixmap(Enemy[i].seeposition().get_positionX()-10,Enemy[i].seeposition().get_positionY()-10,20,20,QPixmap(":/resource/tower.png"));

 //              label_list[i]->setGeometry(Enemy[i].seeposition().get_positionX()-10,Enemy[i].seeposition().get_positionY()-10,20,20);
//           else label_list[i]->setGeometry(-100,-100,20,20);
       }
       for(i=0;i<A.size();i++)
       {
            painter.drawPixmap(A[i].p.get_positionX(),A[i].p.get_positionY(),20,20,QPixmap(":/resource/1.png"));
       }
       for(i=0;i<B.size();i++)
       {
            painter.drawPixmap(B[i].p.get_positionX()-5,B[i].p.get_positionY()-5,20,10,QPixmap(":/resource/bullet.png"));
       }
       painter.drawPixmap(750,10,20,20,QPixmap(":/resource/exit.jpeg"));

       switch(head.health/10)
       {
        case 0:break;
        case 1:painter.drawPixmap(ll,ff,20*head.health/10,10,QPixmap(":/resource/1.png"));break;
        case 2:painter.drawPixmap(ll,ff,20*head.health/10,10,QPixmap(":/resource/2.png"));break;
        case 3:painter.drawPixmap(ll,ff,20*head.health/10,10,QPixmap(":/resource/3.png"));break;
        case 4:painter.drawPixmap(ll,ff,20*head.health/10,10,QPixmap(":/resource/4.png"));break;
        case 5:painter.drawPixmap(ll,ff,20*head.health/10,10,QPixmap(":/resource/5.png"));break;
        case 6:painter.drawPixmap(ll,ff,20*head.health/10,10,QPixmap(":/resource/6.png"));break;
        case 7:painter.drawPixmap(ll,ff,20*head.health/10,10,QPixmap(":/resource/7.png"));break;
        case 8:painter.drawPixmap(ll,ff,20*head.health/10,10,QPixmap(":/resource/8.png"));break;
        case 9:painter.drawPixmap(ll,ff,20*head.health/10,10,QPixmap(":/resource/9.png"));break;
        case 10:painter.drawPixmap(ll,ff,20*head.health/10,10,QPixmap(":/resource/10.png"));break;
       }
      ui->lineEdit->setText(QString::number(money));
}


void Widget::on_levelup_clicked()
{
    if(money>=1000)
    {
        for(auto i=0;i<T.size();i++)
        {
            if(T[i].p.get_positionX()==ui->groupBox->pos().x()+45)
            {
                T[i].levelup();
                if(T[i].levelup()==2)
                money=money-1000;
                break;
            }
        }
        for(auto i=0;i<TT.size();i++)
        {
            if(TT[i].p.get_positionX()==ui->groupBox->pos().x()+45)
            {
                TT[i].levelup();
                if(TT[i].levelup()==2)
                money=money-1000;
                break;
            }
        }
    }
}

void Widget::on_tower1_clicked()
{
       if(tt[0]==0)
       {
       //T.append(tower(position(450,310)));
       ui->groupBox_2->setGeometry(470,292,501,372);
       ui->groupBox_2->show();
       ui->tower1->setStyleSheet("background-color:transparent");
       tt[0]=1;
       }
       else
       {
           ui->groupBox->setGeometry(405,340,495,401);
           ui->groupBox->show();
       }
}

void Widget::on_tower2_clicked()
{
    if(tt[1]==0)
    {
        ui->groupBox_2->setGeometry(550,332,581,412);
        ui->groupBox_2->show();
   //T.append(tower(position(530,350)));
    ui->tower2->setStyleSheet("background-color:transparent");
    tt[1]=1;
    }
    else
    {
        ui->groupBox->setGeometry(485,380,575,441);
        ui->groupBox->show();
    }
}


void Widget::on_pushButton_clicked()
{
    ui->groupBox->setGeometry(0,0,90,61);
    ui->groupBox->hide();
}

void Widget::on_tower3_clicked()
{
    if(tt[2]==0)
    {
        ui->groupBox_2->setGeometry(620,352,671,432);
        ui->groupBox_2->show();
    //T.append(tower(position(600,370)));
    ui->tower3->setStyleSheet("background-color:transparent");
    tt[2]=1;
    }
    else
    {
        ui->groupBox->setGeometry(555,400,645,461);
        ui->groupBox->show();
    }
}


void Widget::on_delete1_clicked()
{
    for(auto i=T.begin();i!=T.end();)
    {
        if((*i).p.get_positionX()==ui->groupBox->pos().x()+45)
        {

            i=T.erase(i);
            tt[i-T.begin()]=0;
        }
        else ++i;
    }
    for(auto i=TT.begin();i!=TT.end();)
    {
        if((*i).p.get_positionX()==ui->groupBox->pos().x()+45)
        {
            i=TT.erase(i);
            tt[i-TT.begin()]=0;
        }
        else ++i;
    }
}

void Widget::on_pushButton_3_clicked()
{
    TT.append(towering(position(ui->groupBox_2->pos().x()-20,ui->groupBox_2->pos().y()+18)));
    ui->groupBox_2->hide();
}

void Widget::on_pushButton_2_clicked()
{
    T.append(tower(position(ui->groupBox_2->pos().x()-20,ui->groupBox_2->pos().y()+18)));
    ui->groupBox_2->hide();
}

void Widget::on_end_clicked()
{
    Level *p=new Level;
    this->close();
    p->show();
}
