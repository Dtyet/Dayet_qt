#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"regist.h"
#include"dayet_window.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void reshow();
    void on_radioButton_clicked();
    
private:
    Ui::Widget *ui;
    regist *reg=new regist;
    dayet_window *dayet=new dayet_window;
};

#endif // WIDGET_H
