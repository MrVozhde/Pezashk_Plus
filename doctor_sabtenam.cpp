#include "doctor_sabtenam.h"
#include "ui_doctor_sabtenam.h"

Doctor_sabtenam::Doctor_sabtenam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Doctor_sabtenam)
{
    ui->setupUi(this);
}

Doctor_sabtenam::~Doctor_sabtenam()
{
    delete ui;
}

void Doctor_sabtenam::on_pushButton_clicked()
{
    QString add = ui->lineEdit_Address->text();
    QString city =  ui->lineEdit_City->text();
    QString Clinic = ui->lineEdit_ClinicPhone->text();
    QString Province = ui->lineEdit_Province->text();
    QString time = ui->lineEdit_Time->text();
    if(ui->lineEdit_City->text().isEmpty() || ui->lineEdit_ClinicPhone->text().isEmpty() || ui->lineEdit_Province->text().isEmpty()\
            || ui->lineEdit_Address->text().isEmpty() ||ui->lineEdit_Time->text().isEmpty()){
        QMessageBox::information(this , "Error" , "فیلد های خالی را پر کنید");
    }
    else{

        QSqlQuery qry ;
        qry.prepare("insert into pezashk_plus.dbo.tblDoctor (PersonalID , ClinicPhone , Province , City , Address , WorkTime ) \
                    Values (:PersonalID ,:clinic , :province , :town , :add , :time)");
        qry.bindValue(":PersonalID" , user_id);
        qry.bindValue(":clinic", Clinic);
        qry.bindValue(":province" , Province);
        qry.bindValue(":town" , city);
        qry.bindValue(":add" , add);
        qry.bindValue(":time" , time);
        if(qry.exec()){
            QMessageBox::information(this , "Nice" , "Seccessed");
            this->close();
        }
        else{
            QMessageBox::information(this , "Error" , "Wrong");
        }
    }
}
