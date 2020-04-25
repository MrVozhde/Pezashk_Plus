#include "user_seecomment.h"
#include "ui_user_seecomment.h"

user_seecomment::user_seecomment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_seecomment)
{
    ui->setupUi(this);

    QString ID;


    QSqlQuery qry1;
    qry1.prepare("Select FirstName , LastName from [pezashk_plus].[dbo].[tblPerson] where ID = :id");
    qry1.bindValue(":id", user_addcomment::DoctorID);
    qry1.exec();
    while(qry1.next()){
        ui->label_fullname->setText(qry1.value(0).toString() + " " + qry1.value(1).toString());
    }

    //------------------------------------------------------------------------------
    QSqlQuery qry;
    qry.prepare("Select ID, ClinicPhone , Province , City , Address , WorkTime , Rate , RateCount from [pezashk_plus].[dbo].[tblDoctor] where PersonalID = :id");
    qry.bindValue(":id", user_addcomment::DoctorID);
    qry.exec();

    while (qry.next()) {
        ID = qry.value(0).toString();
    }

    this->model = new QSqlQueryModel();
    model->setQuery(qry);
    ui->tableView->setModel(model);
    //------------------------------------------------------------

    QSqlQuery qry2;
    qry2.prepare("Select Text , WriterName from [pezashk_plus].[dbo].[tblComment] where DoctorID = :id");
    qry2.bindValue(":id", ID);
    qry2.exec();


    this->mdl = new QSqlQueryModel();
    mdl->setQuery(qry2);
    ui->tableView_2->setModel(mdl);

}

user_seecomment::~user_seecomment()
{
    delete ui;
}
