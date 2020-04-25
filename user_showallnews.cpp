#include "user_showallnews.h"
#include "ui_user_showallnews.h"

user_showallnews::user_showallnews(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_showallnews)
{
    ui->setupUi(this);

    QSqlQuery qry;
    qry.prepare("Select Topic , Text from [pezashk_plus].[dbo].[tblNews]");
    qry.exec();

    this->model = new QSqlQueryModel();
    model->setQuery(qry);
    ui->tableView->setModel(model);
}

user_showallnews::~user_showallnews()
{
    delete ui;
}
