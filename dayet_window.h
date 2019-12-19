#ifndef DAYET_WINDOW_H
#define DAYET_WINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QWindow>
#include <Windows.h>
#include <TlHelp32.h>
#include <QMessageBox>
#include <QtDebug>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextCodec>
#include <QByteArray>
#include <QLibrary>
#include <QProcess>
namespace Ui {
class dayet_window;
}

class dayet_window : public QWidget
{
    Q_OBJECT

public:
    explicit dayet_window(QWidget *parent = nullptr);
    ~dayet_window();
    QString dllName;
    DWORD PrcoID;

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_toolButton_clicked();
     void itemTextSolt();
private:
    Ui::dayet_window *ui;
};

#endif // DAYET_WINDOW_H
