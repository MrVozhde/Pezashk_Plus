#ifndef USER_ADDCOMMENT_H
#define USER_ADDCOMMENT_H

#include <QWidget>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <changepassword.h>

namespace Ui {
class user_addcomment;
}

class user_addcomment : public QWidget
{
    Q_OBJECT

public:

    static QString DoctorID;
    explicit user_addcomment(QWidget *parent = nullptr);
    ~user_addcomment();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::user_addcomment *ui;
    QSqlQueryModel *model ;
};

#endif // USER_ADDCOMMENT_H
