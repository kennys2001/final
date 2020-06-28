#include "new.h"
#include "ui_new.h"
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
#include <level.h>
#include<widget.h>
New::New(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::New)
{
    ui->setupUi(this);
    QTimer *time=new QTimer(this);
    time->start(50);
    money=0;
ui->groupBox->hide();
ui->groupBox_2->hide();

ui->next->hide();

day=-1;
head=headquarter(position(930,350));
    for(int i=0;i<3;i++)
    {
        tt[i]=0;
    }
        connect(time,&QTimer::timeout,[=]()
    {
             if(A.size()+E.size()+G.size()==0&&day==2)
            {
                ui->next->show();

            }

           else if(head.health<=0)
            {
                time->stop();
                Level *p=new Level;
                p->show();
                this->close();
            }
      else  if (E.size()+A.size()+G.size()==0&&day<2)
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
            for(int i=0;i<T.size();i++)
            {
                for(int j=0;j<E.size();j++)
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
            for(int i=0;i<T.size();i++)
            {
                for(int j=0;j<A.size();j++)
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

            for(int i=0;i<T.size();i++)
            {
                for(int j=0;j<G.size();j++)
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

                (*i).move1();
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
                if((*i).life<=0||(*i).p.get_positionX()>=930)
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

                (*i).move1();
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
                if((*i).life<=0||(*i).p.get_positionX()>=930)
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

                (*i).move1();
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
void New::createenemy()
{
    for(int i=0;i<di[day][0];i++)
    {
        E.append(enemy(position(510,-10*3*i)));
    }

    for(int i=0;i<di[day][1];i++)
    {
        A.append(archer(position(510,-10*3*(i+di[day][0]))));
    }
    for(int i=0;i<di[day][2];i++)
    {
        G.append(giant(position(510,-30*(i+di[day][0]+di[day][1])+50)));
    }

}
void New::paintEvent(QPaintEvent *)
{
    //ui->lineEdit->setStyleSheet("background-color:transparent");
    //ui->lineEdit->setFrame(QFrame::NoFrame);

    QPainter painter(this);
    painter.drawPixmap(0,0,1080,600,QPixmap(":/resource/level2.jpg"));

        ui->lineEdit->setText(QString::number(money));


       for(int i=0;i<T.size();i++)
       {
              painter.drawPixmap(T[i].p.get_positionX(),T[i].p.get_positionY(),20,20,QPixmap(":/resource/enemy.png"));
       }
       for(int i=0;i<G.size();i++)
       {
           if(G[i].life<250)
            painter.drawPixmap(G[i].p.get_positionX(),G[i].p.get_positionY()-10,40,40,QPixmap(":/resource/tower.png"));
           else
             painter.drawPixmap(G[i].p.get_positionX(),G[i].p.get_positionY()-10,40,40,QPixmap(":/resource/enemy 2.png"));
       }
       for(int i=0;i<E.size();i++)
       {
            painter.drawPixmap(E[i].p.get_positionX(),E[i].p.get_positionY(),20,20,QPixmap(":/resource/enemy.png"));
//           else if(Enemy[i].life==100)
//               painter.drawPixmap(Enemy[i].seeposition().get_positionX()-10,Enemy[i].seeposition().get_positionY()-10,20,20,QPixmap(":/resource/tower.png"));

 //              label_list[i]->setGeometry(Enemy[i].seeposition().get_positionX()-10,Enemy[i].seeposition().get_positionY()-10,20,20);
//           else label_list[i]->setGeometry(-100,-100,20,20);
       }
       for(int i=0;i<A.size();i++)
       {
            painter.drawPixmap(A[i].p.get_positionX(),A[i].p.get_positionY(),20,20,QPixmap(":/resource/1.png"));
       }
       for(int i=0;i<B.size();i++)
       {
            painter.drawPixmap(B[i].p.get_positionX()-5,B[i].p.get_positionY()-5,20,10,QPixmap(":/resource/bullet.png"));
       }
       painter.drawPixmap(750,10,20,20,QPixmap(":/resource/exit.jpeg"));

       int ll=400;
       int ff=30;
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



//ui->lineEdit->setText(QString::number(ui->groupBox->pos().x()+45));



}

void New::on_levelup_clicked()
{
    if(money>=1000)
    {
        for(auto i=0;i<T.size();i++)
        {
            if(T[i].p.get_positionX()==ui->groupBox->pos().x()+45)
            {
                T[i].levelup();
                money=money-1000;
                break;
            }
        }
    }

}

void New::on_tower1_clicked()
{
       if(tt[0]==0)
       {
       T.append(tower(position(500,360)));
       ui->tower1->setStyleSheet("background-color:transparent");
       tt[0]=1;
       }
       else
       {
           ui->groupBox->setGeometry(455,390,535,451);
           ui->groupBox->show();
       }
}

void New::on_tower2_clicked()
{
    if(tt[1]==0)
    {
    T.append(tower(position(640,360)));
    ui->tower2->setStyleSheet("background-color:transparent");
    tt[1]=1;
    }
    else
    {
        ui->groupBox->setGeometry(595,390,685,451);
        ui->groupBox->show();
    }
}


void New::on_pushButton_clicked()
{
    ui->groupBox->setGeometry(0,0,90,61);
    ui->groupBox->hide();
}

void New::on_tower3_clicked()
{
    if(tt[2]==0)
    {
    T.append(tower(position(550,450)));
    ui->tower3->setStyleSheet("background-color:transparent");
    tt[2]=1;
    }
    else
    {
        ui->groupBox->setGeometry(505,480,595,541);
        ui->groupBox->show();
    }
}


void New::on_delete1_clicked()
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
}


New::~New()
{
    delete ui;
}

void New::on_next_clicked()
{
    Widget *p=new Widget;
    p->show();
    this->close();
}
