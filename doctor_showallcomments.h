#ifndef DOCTOR_SHOWALLCOMMENTS_H
#define DOCTOR_SHOWALLCOMMENTS_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSql>
#include <QtCore>
#include <changepassword.h>

namespace Ui {
class doctor_showallcomments;
}

class doctor_showallcomments : public QWidget
{
    Q_OBJECT

public:
    explicit doctor_showallcomments(QWidget *parent = nullptr);
    ~doctor_showallcomments();

private:
    Ui::doctor_showallcomments *ui;
    QSqlQueryModel *model ;
};

#endif // DOCTOR_SHOWALLCOMMENTS_H
