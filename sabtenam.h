#ifndef SABTENAM_H
#define SABTENAM_H

#include <QWidget>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <doctor_sabtenam.h>

namespace Ui {
class SabteNam;
}

class SabteNam : public QWidget
{
    Q_OBJECT

public:
    explicit SabteNam(QWidget *parent = nullptr);
    ~SabteNam();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SabteNam *ui;
};

#endif // SABTENAM_H
