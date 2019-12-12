#include "regist.h"
#include "ui_regist.h"
#include "widget.h"
#include <QDialog>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QRegExp>
#include<QDebug>
regist::regist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regist)
{
    ui->setupUi(this);
}

regist::~regist()
{
    delete ui;
}

void regist::on_pushButton_2_clicked()
{
    emit  sendsignal();
    this->close();
}

void regist::on_pushButton_clicked()
{

    QSqlQuery query;
    query.exec("START TRANSACTION");
    QString name=ui->lineEdit->text();

    if(name.size()<5){
        QString dlgTitle="错误";
        QString strInfo="用户名必须大于5位";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
    };
    QString email=ui->lineEdit_2->text();
    QRegExp regExpPsw("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$");
    qDebug() << "regExpPsw.isValid():" << regExpPsw.isValid();//判断正则表达式是否合法，合法返回true，否则返回false。
    qDebug() << "regExpPsw.isValid():" << regExpPsw.pattern();//获得正则本
    int ret_value = regExpPsw.indexIn(email);
    qDebug() << "ret_value:" << ret_value;
    if(ret_value==-1){
        QString dlgTitle="错误";
        QString strInfo="请使用正确的邮箱";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
    };
    QString password=ui->lineEdit_3->text();
    if(password.size()<5){
        QString dlgTitle="错误";
        QString strInfo="密码必须大于5位";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
    };
    QString password1=ui->lineEdit_4->text();
    if(password!=password1){
        QString dlgTitle="错误";
        QString strInfo="俩次密码不一致，请重新输入";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
    };
    query.exec("select * from user");
    int a=1;
    while (query.next()) {
       qDebug()<< query.value(0).toInt()
               << query.value(1).toString()
               << query.value(2).toString()
               << query.value(3).toString()
               << query.value(4).toInt();
       if(query.value(1).toString()==name){
          a=0;
          QString dlgTitle="错误";
          QString strInfo="用户已注册";
          QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
          break;
       }else if (query.value(2).toString()==email) {
          a=0;
          QString dlgTitle="错误";
          QString strInfo="邮箱已被使用";
          QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
          break;
       }
    }
    QString sql=QString("insert into user(u_name,u_email,u_password,u_quanxian) values('%1','%2','%3',0)").arg(name,email,password);
    //QSqlDatabase::database().transaction();

    query.exec(sql);

    if(name.size()>=5 and ret_value!=-1 and password==password1 and password.size()>=5 and a==1 ){
        query.exec("COMMIT");
        QString dlgTitle="成功";
        QString strInfo="注册完成";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
    }else{

        query.exec("ROLLBACK");
        QString dlgTitle="失败";
        QString strInfo="注册失败";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
    }

}
