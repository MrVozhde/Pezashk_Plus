#include "changepassword.h"
#include "ui_changepassword.h"

changepassword::changepassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changepassword)
{
    ui->setupUi(this);
}

changepassword::~changepassword()
{
    delete ui;
}

void changepassword::on_pushButton_2_clicked()
{
    this->close();
}

void changepassword::on_pushButton_clicked()
{

    if(Password == ui->lineEdit_oldPass->text()){
        if(ui->lineEdit_newPass->text() == ui->lineEdit_repeatNewPass->text()){
            QSqlQuery qry;
            qry.prepare("Update [pezashk_plus].[dbo].[tblPerson] set Password = :pass where Username = :username");
            qry.bindValue(":pass" , ui->lineEdit_newPass->text());
            qry.bindValue(":username" , username);
            if(qry.exec()){
                QMessageBox::information(this , "Successful" , "تغییر رمز با موفقیت انجام شد.");
                Password = ui->lineEdit_newPass->text();
                this->close();
            }
            else {
                QMessageBox::information(this , "Error" , "تغییر رمز یا مشکل مواجه شد.");
            }
        }
        else {
            QMessageBox::information(this , "ERROR" , "رمز وارد شده جدید ، با تکرار آن تطابق ندارد.");
        }
    }
    else {
        QMessageBox::information(this , "ERROR" , "رمز فعلی خود را اشتباه وارد کرده اید.");
    }
}
