#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include<QPainter>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~Form();
signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

private slots:

    void on_playButton_clicked();

    void on_setButton_clicked();

    void on_introButton_clicked();

    void on_exitButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
