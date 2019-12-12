#include "dayet_window.h"
#include "ui_dayet_window.h"

dayet_window::dayet_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dayet_window)
{
    ui->setupUi(this);
}

dayet_window::~dayet_window()
{
    delete ui;
}
