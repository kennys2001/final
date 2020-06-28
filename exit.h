#ifndef EXIT_H
#define EXIT_H

#include <QWidget>

namespace Ui {
class exit;
}

class exit : public QWidget
{
    Q_OBJECT

public:
    explicit exit(QWidget *parent = nullptr);
    ~exit();

private:
    Ui::exit *ui;
};

#endif // EXIT_H
