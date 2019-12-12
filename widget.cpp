#include "widget.h"
#include "ui_widget.h"
#include "regist.h"
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QSettings>
#include"dayet_window.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("jishubu@123");
    db.setDatabaseName("dayet");
    if(!db.open()){
        QString dlgTitle="失败";
        QString strInfo="服务器连接失败";
        QMessageBox::information(this, dlgTitle, strInfo,
                                 QMessageBox::Ok,QMessageBox::NoButton);
    }else if (db.open()) {
        QString dlgTitle="成功";
        QString strInfo="服务器连接成功";
        QMessageBox::information(this, dlgTitle, strInfo,
                                 QMessageBox::Ok,QMessageBox::NoButton);
    };
    //QSqlQuery query;
    //    query.prepare("insert into user(u_name,u_email,u_passward,u_quanxian) values(?,?,?,?)");
    //    QVariantList nameList;
    //    nameList<<"chenhui"<<"tanqing";
    //    QVariantList emailList;
    //    emailList<<"296577630@qq.com"<<"88888888@qq.com";
    //    QVariantList passList;
    //    passList<<"chenhui@123"<<"jishubu@123";
    //    QVariantList quanxList;
    //    quanxList<<0<<0;

    //    query.addBindValue(nameList);
    //    query.addBindValue(emailList);
    //    query.addBindValue(passList);
    //    query.addBindValue(quanxList);

    //    query.execBatch();

    //    query.exec("select * from user");
    //    while (query.next()) {
    //       qDebug()<< query.value(0).toInt()
    //               << query.value(1).toString()
    //               << query.value(2).toString()
    //               << query.value(3).toString()
    //               << query.value(4).toInt();


    //    }
}


Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    //regist *r=new regist(this);
    this->hide();
    connect(reg,SIGNAL(sendsignal()),this,SLOT(reshow()));
    reg->show();

}

void Widget::on_pushButton_clicked()
{
    QSqlQuery query;
    bool a=false;
    QString name=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    if(name.size()<5){
        QString dlgTitle="错误";
        QString strInfo="用户名必须大于5位";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
    }else if(password.size()<5){
        QString dlgTitle="错误";
        QString strInfo="密码必须大于5位";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
    }else if (password.size()>=5 and name.size()>=5){
        query.exec("select * from user");
        while (query.next()) {
            qDebug()<< query.value(0).toInt()
                    << query.value(1).toString()
                    << query.value(2).toString()
                    << query.value(3).toString()
                    << query.value(4).toInt();
            if(query.value(1).toString()==name and query.value(3).toString()==password ){
                a=true;
                break;
            }
        }
    }
    if(a==true){
        QString dlgTitle="成功";
        QString strInfo="登录成功";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
        this->close();
        dayet->show();
    }else {
        QString dlgTitle="失败";
        QString strInfo="用户名或密码错误";
        QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
    }
}
void Widget::reshow(){
    this->show();  
}

/**登录初始化的时候处理这部分操作*/
//QSettings cfg("user.ini",QSettings::IniFormat);
//        usersname= cfg.value("usersname").toString();
//        passswd= cfg.value("passswd").toString();
//        RemeberPasswd= cfg.value("remeberPasswd").toString();
//        ui->cBox_account->setItemText(0,usersname);
//        ui->lineEdit_passwd->setText(passswd);
//        if(RemeberPasswd== "true")
//        {
//            ui->checkBox_rPasswd->setChecked(true);
//        }
/**勾选记住密码,定义一个标志位*/
//void Widget::on_radioButton_clicked()
//{
//    if(ui->radioButton->isChecked())
//    {
//        remeberPasswd= true;
//    } else {
//        ui->lineEdit_2->clear();
//        remeberPasswd= false;
//    }
//}
/**保存登录信息**/
//void Login::savecfg()
//{
//    QSettings cfg("user.ini",QSettings::IniFormat);
//    usersname= ui->cBox_account->currentText();
//    passswd= ui->lineEdit_passwd->text();
//    cfg.setValue("usersname",usersname);
//    cfg.setValue("passswd",passswd);
//    cfg.setValue("remeberPasswd",remeberPasswd);
//    cfg.sync();
//}

void Widget::on_radioButton_clicked()
{

}
