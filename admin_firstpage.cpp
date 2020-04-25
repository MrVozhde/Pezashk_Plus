#include "admin_firstpage.h"
#include "ui_admin_firstpage.h"

admin_firstpage::admin_firstpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_firstpage)
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

//----------------------------------------------------------------------------------
    ui->comboBox->addItem("----");
    //-------------------------------------------------------------------------------------
    QString id;
    QSqlQuery qry1;
    qry1.prepare("select PersonalID from [pezashk_plus].[dbo].[tblDoctor] ");
    qry1.exec();
    while (qry1.next()) {
        id = qry1.value(0).toString();

        QSqlQuery qry2;
        qry2.prepare("select FirstName + ' ' + LastName from [pezashk_plus].[dbo].[tblPerson] where ID = :id");
        qry2.bindValue(":id" , id);
        qry2.exec();
        while (qry2.next()) {
            ui->comboBox->addItem(qry2.value(0).toString());
        }
    }



}

admin_firstpage::~admin_firstpage()
{
    delete ui;
}

void admin_firstpage::on_pushButton_clicked()
{
    QString personalID;

    if(ui->comboBox->currentText()== "----"){
        QMessageBox::information(this,"Error" , "لطفا یک مقدار معتبر انتخاب کنید.");
    }
    else{
        QString comboname = ui->comboBox->currentText();
        andis = ui->comboBox->currentIndex();
        QString fullname ;
        QSqlQuery qry;
        qry.prepare("select FirstName + ' ' + LastName , ID from [pezashk_plus].[dbo].[tblPerson]");
        qry.exec();
        while (qry.next()) {
            fullname=qry.value(0).toString();
            if(fullname == comboname){
                personalID = qry.value(1).toString();
                break;
            }
        }

        QString DOCTORID;

        QSqlQuery qry4;
        qry4.prepare("select ID from [pezashk_plus].[dbo].[tblDoctor] where PersonalID=:persid ");
        qry4.bindValue(":persid",personalID);
        qry4.exec();
        while (qry4.next()) {
            DOCTORID = qry4.value(0).toString();
        }

        QSqlQuery qry3;
        qry3.prepare("Delete from [pezashk_plus].[dbo].[tblComment] where DoctorID=:id ");
        qry3.bindValue(":id",DOCTORID);
        qry3.exec();

        QSqlQuery qry1;
        qry1.prepare("Delete from [pezashk_plus].[dbo].[tblDoctor] where PersonalID=:persid ");
        qry1.bindValue(":persid",personalID);
        qry1.exec();

        QSqlQuery qry2;
        qry2.prepare("Delete from [pezashk_plus].[dbo].[tblPerson] where ID=:persid ");
        qry2.bindValue(":persid",personalID);
        if(qry2.exec()){
            QMessageBox::information(this,"Done","Deleted Succsesfully");
            ui->comboBox->removeItem(andis);

        }

    }
}


void admin_firstpage::on_pushButton_savenews_clicked()
{

    QString text = ui->plainTextEdit->toPlainText();
    QString subject = ui->lineEdit_subject->text();
    QString persid;
    QString adminid;

    QSqlQuery qry1;
    qry1.prepare("select ID From [pezashk_plus].[dbo].[tblPerson] where Username = :user");
    qry1.bindValue(":user",changepassword::username);
    qry1.exec();
    while (qry1.next()) {
        persid = qry1.value(0).toString();
    }

    QSqlQuery qry2;
    qry2.prepare("select ID From [pezashk_plus].[dbo].[tblAdmin] where PersonalID=:id");
    qry2.bindValue(":id",persid);
    qry2.exec();
    while (qry2.next()) {
        adminid = qry2.value(0).toString();
    }



    QSqlQuery qry;
    qry.prepare("insert into [pezashk_plus].[dbo].[tblNews] (AdminID , Topic , Text) Values (:adminid , :subject , :text)");
    qry.bindValue(":adminid" , adminid);
    qry.bindValue(":subject" , subject);
    qry.bindValue(":text" , text);
    if(qry.exec()){
        QMessageBox::information(this,"Done", "Added successfully");
        ui->lineEdit_subject->clear();
        ui->plainTextEdit->clear();
    }
}

void admin_firstpage::on_pushButton_2_clicked()
{
    admin_showallnews *x=new admin_showallnews();
    x->show();
}
