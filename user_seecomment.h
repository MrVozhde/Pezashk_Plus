#ifndef USER_SEECOMMENT_H
#define USER_SEECOMMENT_H

#include <QWidget>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <changepassword.h>
#include <user_addcomment.h>

namespace Ui {
class user_seecomment;
}

class user_seecomment : public QWidget
{
    Q_OBJECT

public:
    explicit user_seecomment(QWidget *parent = nullptr);
    ~user_seecomment();

private:
    Ui::user_seecomment *ui;
    QSqlQueryModel *model ;
    QSqlQueryModel *mdl ;
};

#endif // USER_SEECOMMENT_H
