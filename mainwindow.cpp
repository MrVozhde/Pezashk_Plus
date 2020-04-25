#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


 //-------------------------------------------------------------------------------
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("vozhdedsn");
    db.open();
  //-----------------------------------------------------------------------------------
    if(!db.open()){
        ui->statusBar->showMessage("Not Connected");
        qDebug() << db.lastError();
    }

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

//QString MainWindow::password;
//QString MainWindow::username;

QString Doctor_sabtenam::user_id;
QString changepassword::username;
QString changepassword::Password;
QString user_addcomment::DoctorID;

void MainWindow::on_pushButton_clicked()
{
    QString status;
    QString realpass ;
    QString personID;
    QString ID;
    changepassword::username = ui->lineEdit_Username->text();
    changepassword::Password = ui->lineEdit_Password->text();



        QSqlQuery qry;
        qry.prepare("select ID , Password from [pezashk_plus].[dbo].[tblPerson] where Username = :username");
        qry.bindValue(":username", changepassword::username );
        qry.exec();

        while (qry.next()) {
            personID = qry.value(0).toString();
            realpass = qry.value(1).toString();
        }

        if(realpass == changepassword::Password){
            QSqlQuery qry1;
            qry1.prepare("select ID from [pezashk_plus].[dbo].[tblDoctor] where PersonalID = :id");
            qry1.bindValue(":id" , personID);
            qry1.exec();
            while (qry1.next()) {
                ID = qry1.value(0).toString();
            }

            if(ID != NULL){
                Doctor_FirstPage *x = new Doctor_FirstPage();
                x->show();
            }
            else{
                QSqlQuery qry2;
                qry2.prepare("select ID from [pezashk_plus].[dbo].[tblUser] where PersonalID = :id");
                qry2.bindValue(":id" , personID);
                qry2.exec();
                while (qry2.next()) {
                    ID = qry2.value(0).toString();
                }
                if(ID != NULL){
                    user_firstpage *x = new user_firstpage();
                    x->show();
                }
                else{
                    QSqlQuery qry3;
                    qry3.prepare("select ID from [pezashk_plus].[dbo].[tblAdmin] where PersonalID = :id");
                    qry3.bindValue(":id" , personID);
                    qry3.exec();
                    while (qry3.next()) {
                        ID = qry3.value(0).toString();
                    }
                    if(ID != NULL){
                        admin_firstpage *x = new admin_firstpage();
                        x->show();
                    }
                    else {
                        QMessageBox::information(this , "ERROR" , "لطفا نام کاربری و رمز عبور خود را مجدد چک فرمایید.");
                    }
                }
            }

        }
        else{
            QMessageBox::information(this , "ERROR" , "لطفا نام کاربری و رمز عبور خود را مجدد چک فرمایید.");
        }





}

void MainWindow::on_pushButton_Sabtenam_clicked()
{
    SabteNam *x = new SabteNam;
    x->show();
}
