#ifndef DAYET_WINDOW_H
#define DAYET_WINDOW_H

#include <QWidget>

namespace Ui {
class dayet_window;
}

class dayet_window : public QWidget
{
    Q_OBJECT

public:
    explicit dayet_window(QWidget *parent = nullptr);
    ~dayet_window();

private:
    Ui::dayet_window *ui;
};

#endif // DAYET_WINDOW_H
