#include "doctor_firstpage.h"
#include "ui_doctor_firstpage.h"

Doctor_FirstPage::Doctor_FirstPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Doctor_FirstPage)
{
    ui->setupUi(this);


    QString name , family;
    QSqlQuery qry;
    qry.prepare("select FirstName , LastName From [pezashk_plus].[dbo].[tblPerson] where Username = :user");
    qry.bindValue(":user",changepassword::username);
    qry.exec();
    while (qry.next()) {
        name = qry.value(0).toString();
        family = qry.value(1).toString();
    }

    ui->label->setText(name + " " + family);
}

Doctor_FirstPage::~Doctor_FirstPage()
{
    delete ui;
}

void Doctor_FirstPage::on_pushButtona_ChangePass_clicked()
{
    changepassword *x = new changepassword();
    x->show();
}

void Doctor_FirstPage::on_pushButton_ShocComment_clicked()
{
    doctor_showallcomments *x = new doctor_showallcomments();
    x->show();
}

void Doctor_FirstPage::on_pushButton_2_clicked()
{
    if(ui->lineEdit_Address->text().isEmpty()||ui->lineEdit_City->text().isEmpty()||ui->lineEdit_ClinicPhone->text().isEmpty()||ui->lineEdit_Province->text().isEmpty()||ui->lineEdit_Time->text().isEmpty()){
        QMessageBox::information(this , "Error" , "Please Fill All Fields");
    }
    else{
        QString add = ui->lineEdit_Address->text();
        QString city =  ui->lineEdit_City->text();
        QString Clinic = ui->lineEdit_ClinicPhone->text();
        QString Province = ui->lineEdit_Province->text();
        QString time = ui->lineEdit_Time->text();
        QString ID;


        QSqlQuery qry1;
        qry1.prepare("select ID from pezashk_plus.dbo.tblPerson where Username =:user");
        qry1.bindValue(":user",changepassword::username);
        qry1.exec();
        while (qry1.next()) {
            ID = qry1.value(0).toString();
        }

        QSqlQuery qry ;
        qry.prepare("Update pezashk_plus.dbo.tblDoctor set ClinicPhone = :clinic , Province=:province , City=:town , Address=:add , WorkTime=:time \
                    where PersonalID= :id");
        qry.bindValue(":PersonalID" , changepassword::username);
        qry.bindValue(":clinic", Clinic);
        qry.bindValue(":province" , Province);
        qry.bindValue(":town" , city);
        qry.bindValue(":add" , add);
        qry.bindValue(":time" , time);
        qry.bindValue(":id" , ID);
        if(qry.exec()){
            QMessageBox::information(this , "Done" , "Update Done");
            this->close();
        }
        else{
            QMessageBox::information(this , "Error" , "Wrong");
        }
    }

}
