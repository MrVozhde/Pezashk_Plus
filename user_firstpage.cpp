#include "user_firstpage.h"
#include "ui_user_firstpage.h"

user_firstpage::user_firstpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_firstpage)
{
    ui->setupUi(this);

    ui->comboBox->addItem("----");
    ui->comboBox_2->addItem("----");
    //-------------------------------------------------------------------------------------
    QString name , family;
    QSqlQuery qry;
    qry.prepare("select FirstName , LastName From [pezashk_plus].[dbo].[tblPerson] where Username = :user");
    qry.bindValue(":user",changepassword::username);
    qry.exec();
    while (qry.next()) {
        name = qry.value(0).toString();
        family = qry.value(1).toString();
    }

    ui->label_username->setText(name + " " + family);

    //---------------------------------------------------------------------------------------------


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
            ui->comboBox_2->addItem(qry2.value(0).toString());
        }
    }

    //----------------------------------------------------------------------------------------


}

user_firstpage::~user_firstpage()
{
    delete ui;
}

void user_firstpage::on_pushButtonchangePassword_clicked()
{
    changepassword *x = new changepassword();
    x->show();
}

void user_firstpage::on_pushButton_clicked()
{
    if(ui->comboBox->currentText()== "----"){
        QMessageBox::information(this,"Error" , "لطفا یک مقدار معتبر انتخاب کنید.");
    }
    else{
        QString comboname = ui->comboBox->currentText();
        QString fullname ;
        QSqlQuery qry;
        qry.prepare("select FirstName + ' ' + LastName , ID from [pezashk_plus].[dbo].[tblPerson]");
        qry.exec();
        while (qry.next()) {
            fullname=qry.value(0).toString();
            if(fullname == comboname){
                user_addcomment::DoctorID = qry.value(1).toString();
                break;
            }
        }

        user_addcomment *x = new user_addcomment();
        x->show();
    }
}

void user_firstpage::on_pushButton_AllNews_2_clicked()
{
    if(ui->comboBox_2->currentText()== "----"){
        QMessageBox::information(this,"Error" , "لطفا یک مقدار معتبر انتخاب کنید.");
    }
    else{
        QString comboname = ui->comboBox_2->currentText();
        QString fullname ;
        QSqlQuery qry;
        qry.prepare("select FirstName + ' ' + LastName , ID from [pezashk_plus].[dbo].[tblPerson]");
        qry.exec();
        while (qry.next()) {
            fullname=qry.value(0).toString();
            if(fullname == comboname){
                user_addcomment::DoctorID = qry.value(1).toString();
                break;
            }
        }

        user_seecomment *x = new user_seecomment();
        x->show();
    }
}

void user_firstpage::on_pushButton_AllNews_clicked()
{
    user_showallnews *x= new user_showallnews();
    x->show();
}
