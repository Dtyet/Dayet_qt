#ifndef REGIST_H
#define REGIST_H

#include <QWidget>
#include<QPushButton>
namespace Ui {
class regist;
}

class regist : public QWidget
{
    Q_OBJECT

public:
    explicit regist(QWidget *parent = nullptr);
    ~regist();
    //void sendsignal();
signals:
    void sendsignal();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::regist *ui;
    //QPushButton b;
    //Widget w;
};

#endif // REGIST_H
