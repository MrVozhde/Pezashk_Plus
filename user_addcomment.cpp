#include "user_addcomment.h"
#include "ui_user_addcomment.h"

user_addcomment::user_addcomment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_addcomment)
{
    ui->setupUi(this);

    QSqlQuery qry;
    qry.prepare("Select ClinicPhone , Province , City , Address , WorkTime , Rate , RateCount from [pezashk_plus].[dbo].[tblDoctor] where PersonalID = :id");
    qry.bindValue(":id", DoctorID);
    qry.exec();

    this->model = new QSqlQueryModel();
    model->setQuery(qry);
    ui->tableView->setModel(model);


}

user_addcomment::~user_addcomment()
{
    delete ui;
}

void user_addcomment::on_pushButton_2_clicked()
{
    this->close();
}

void user_addcomment::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    QString userid;
    QString docid;
    QString fullname;

    QSqlQuery qry1;
    qry1.prepare("select ID from [pezashk_plus].[dbo].[tblPerson] where Username = :user");
    qry1.bindValue(":user" , changepassword::username);
    qry1.exec();
    while (qry1.next()) {
        userid=qry1.value(0).toString();
    }

    QSqlQuery qry3;
    qry3.prepare("select ID from [pezashk_plus].[dbo].[tblUser] where PersonalID = :id");
    qry3.bindValue(":id" , userid);
    qry3.exec();
    while (qry3.next()) {
        userid=qry3.value(0).toString();
    }

//    QMessageBox::information(this , "userID" , userid);


    QSqlQuery qry2;
    qry2.prepare("select ID from [pezashk_plus].[dbo].[tblDoctor] where PersonalID = :id");
    qry2.bindValue(":id" , user_addcomment::DoctorID);
    qry2.exec();
    while (qry2.next()) {
        docid=qry2.value(0).toString();
    }


    QSqlQuery qry4;
    qry4.prepare("Select FirstName + ' ' + LastName from [pezashk_plus].[dbo].[tblPerson] where Username=:id");
    qry4.bindValue(":id" , changepassword::username);
    qry4.exec();
    while (qry4.next()) {
        fullname=qry4.value(0).toString();
    }

    QSqlQuery qry;
    qry.prepare("insert into [pezashk_plus].[dbo].[tblComment] (UserID , DoctorID , Text , WriterName ) Values (:userid ,:docid , :text , :fname ) ");
    qry.bindValue(":text",text);
    qry.bindValue(":docid" , docid);
    qry.bindValue(":userid" , userid);
    qry.bindValue(":fname" , fullname);
    if(qry.exec()){
        QMessageBox::information(this , "Done" , "نظر شما با موفقیت اصافه شد");
    }
}
