#include "sabtenam.h"
#include "ui_sabtenam.h"

SabteNam::SabteNam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SabteNam)
{
    ui->setupUi(this);
}

SabteNam::~SabteNam()
{
    delete ui;
}

void SabteNam::on_pushButton_clicked()
{

    QString ID;
    QString name = ui->lineEdit_name->text();
    QString family = ui->lineEdit_family->text();
    QString username = ui->lineEdit_username->text();
    QString nationalcode = ui->lineEdit_nationalcode->text() ;
    QString Email = ui->lineEdit_email->text();
    QString Password=ui->lineEdit_pass->text();
    QString Phone = ui->lineEdit_phone->text();

    if(ui->lineEdit_name->text().isEmpty() || ui->lineEdit_family->text().isEmpty() ||ui->lineEdit_username->text().isEmpty() ||\
            ui->lineEdit_nationalcode->text().isEmpty() ||ui->lineEdit_email->text().isEmpty() ||ui->lineEdit_phone->text().isEmpty()||\
            ui->lineEdit_pass->text().isEmpty()||ui->lineEdit_repeatpass->text().isEmpty()){
        QMessageBox::information(this , "Error" , "PLease Fill all Field");
    }
    else {
        if(ui->lineEdit_pass->text() != ui->lineEdit_repeatpass->text()){
            QMessageBox::information(this , "Error" , "PLease Check the Password");
        }
        else{
            QSqlQuery qry;

            qry.prepare("insert into pezashk_plus.dbo.tblPerson (FirstName , LastName , Username , NationalCode ,PhoneNumber , Email , Password )\
                        Values (:name , :family , :username, :nationalcode , :phone , :email , :password)");
            qry.bindValue(":name" , name);
            qry.bindValue(":family" , family);
            qry.bindValue(":nationalcode" , nationalcode);
            qry.bindValue(":phone" , Phone);
            qry.bindValue(":email" , Email);
            qry.bindValue(":password" , Password);
            qry.bindValue(":username" , username);
            qry.exec();

            QSqlQuery qry1;
            qry1.prepare("select ID from pezashk_plus.dbo.tblPerson where NationalCode = :national ");
            qry1.bindValue(":national" , nationalcode);
            qry1.exec();
            while(qry1.next()){
                Doctor_sabtenam::user_id = ID = qry1.value(0).toString();
            }

            if(ui->radioButton_Doctor->isChecked()){
                Doctor_sabtenam *x = new Doctor_sabtenam();
                x->show();
            }
            else if(ui->radioButton_User->isCheckable()){
                //QMessageBox::information(this , "Configuration", "حساب کاربری شما با موفقیت ساخته شد");

                QSqlQuery qryuser;
                qryuser.prepare("insert into pezashk_plus.dbo.tblUser (PersonalID) values (:id) ");
                qryuser.bindValue(":id" , ID);
                if(qryuser.exec()){
                    QMessageBox::information(this , "Configuration", "حساب کاربری شما با موفقیت ساخته شد");
                }
            }
            else{
                QMessageBox::information(this , "Error" , "Please Select Doctor Or User ");
            }
        }
    }
}
