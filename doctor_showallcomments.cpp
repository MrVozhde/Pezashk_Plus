#include "doctor_showallcomments.h"
#include "ui_doctor_showallcomments.h"

doctor_showallcomments::doctor_showallcomments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doctor_showallcomments)
{
    ui->setupUi(this);

    QString ID;
    QString docID;

    QSqlQuery qry;
    qry.prepare("Select ID from pezashk_plus.dbo.tblPerson where Username=:user");
    qry.bindValue(":user",changepassword::username);
    qry.exec();
    while (qry.next()) {
        ID = qry.value(0).toString();
    }




    QSqlQuery qry1;
    qry1.prepare("Select ID from pezashk_plus.dbo.tblDoctor where PersonalID= :id");
    qry1.bindValue(":id" , ID);
    qry1.exec();
    while (qry1.next()) {
        docID =qry1.value(0).toString();
    }


    QSqlQuery qry2;
    qry2.prepare("Select Text as 'متن نظر' , WriterName as 'نام نویسنده' from pezashk_plus.dbo.tblComment where DoctorID=:docID");
    qry2.bindValue(":docID", docID);
    qry2.exec();


    this->model = new QSqlQueryModel();
    model->setQuery(qry2);
    ui->tableView_comments->setModel(model);


}

doctor_showallcomments::~doctor_showallcomments()
{
    delete ui;
}
