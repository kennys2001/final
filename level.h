#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>

namespace Ui {
class Level;
}

class Level : public QWidget
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();
    void paintEvent(QPaintEvent *event);
private slots:
    void on_p1_clicked();

    void on_exit_clicked();

    void on_p2_clicked();

private:
    Ui::Level *ui;
};

#endif // LEVEL_H
