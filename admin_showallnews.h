#ifndef ADMIN_SHOWALLNEWS_H
#define ADMIN_SHOWALLNEWS_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include <changepassword.h>

namespace Ui {
class admin_showallnews;
}

class admin_showallnews : public QWidget
{
    Q_OBJECT

public:
    int number_of_row;
    QString id_of_newstable;

    explicit admin_showallnews(QWidget *parent = nullptr);
    ~admin_showallnews();

private slots:
    void on_tableView_News_clicked(const QModelIndex &index);

    void on_pushButton_savechange_clicked();

    void on_pushButton_savechange_2_clicked();

    void on_pushButton_savechange_3_clicked();

private:
    Ui::admin_showallnews *ui;
    QSqlQueryModel *model ;
};

#endif // ADMIN_SHOWALLNEWS_H
