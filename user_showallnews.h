#ifndef USER_SHOWALLNEWS_H
#define USER_SHOWALLNEWS_H

#include <QWidget>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <changepassword.h>

namespace Ui {
class user_showallnews;
}

class user_showallnews : public QWidget
{
    Q_OBJECT

public:
    explicit user_showallnews(QWidget *parent = nullptr);
    ~user_showallnews();

private:
    Ui::user_showallnews *ui;
    QSqlQueryModel *model;
};

#endif // USER_SHOWALLNEWS_H
