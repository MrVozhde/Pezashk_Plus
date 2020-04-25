#include "admin_showallnews.h"
#include "ui_admin_showallnews.h"

admin_showallnews::admin_showallnews(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_showallnews)
{
    ui->setupUi(this);
    //----------------------------------------------------------------------------------------
    QSqlQuery qry;
    qry.prepare("select Topic , Text from [pezashk_plus].[dbo].[tblNews]");
    qry.exec();
    this->model = new QSqlQueryModel();
    model->setQuery(qry);
    ui->tableView_News->setModel(model);
    //----------------------------------------------------------------------------------------
}

admin_showallnews::~admin_showallnews()
{
    delete ui;
}

void admin_showallnews::on_tableView_News_clicked(const QModelIndex &index)
{
    number_of_row = index.row();

    ui->lineEdit_subject->setText(" ");
    ui->plainTextEdit->clear();


    QSqlQuery qry;
    qry.prepare("select ID , Topic, Text from [pezashk_plus].[dbo].[tblNews]");
    qry.exec();
    qry.seek(number_of_row);
    id_of_newstable = qry.value(0).toString();
    ui->lineEdit_subject->setText(qry.value(1).toString());
    ui->plainTextEdit->appendPlainText(qry.value(2).toString());
}

void admin_showallnews::on_pushButton_savechange_clicked()
{
    QString sub=ui->lineEdit_subject->text();
    QString text=ui->plainTextEdit->toPlainText();

    QSqlQuery qry;
    qry.prepare("update [pezashk_plus].[dbo].[tblNews] Set Topic = :topic , Text=:text  where ID = :id");
    qry.bindValue(":topic",sub);
    qry.bindValue(":text",text);
    qry.bindValue(":id",id_of_newstable);
    if(qry.exec()){
        QMessageBox::information(this , "Done" , "Edited successfully !");
    }
}

void admin_showallnews::on_pushButton_savechange_2_clicked()
{
    QSqlQuery qry;
    qry.prepare("select Topic , Text from [pezashk_plus].[dbo].[tblNews]");
    qry.exec();
    this->model = new QSqlQueryModel();
    model->setQuery(qry);
    ui->tableView_News->setModel(model);
}

void admin_showallnews::on_pushButton_savechange_3_clicked()
{
    QSqlQuery qry;
    qry.prepare("Delete From [pezashk_plus].[dbo].[tblNews] where ID=:id");
    qry.bindValue(":id" , id_of_newstable);
    if(qry.exec()){
        QMessageBox::information(this , "Done" , "Deleted successfully");
        ui->lineEdit_subject->clear();
        ui->plainTextEdit->clear();
    }
}
