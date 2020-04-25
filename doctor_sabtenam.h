#ifndef DOCTOR_SABTENAM_H
#define DOCTOR_SABTENAM_H

#include <QWidget>
#include <QSql>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class Doctor_sabtenam;
}

class Doctor_sabtenam : public QWidget
{
    Q_OBJECT

public:

    static QString user_id;
    explicit Doctor_sabtenam(QWidget *parent = nullptr);
    ~Doctor_sabtenam();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Doctor_sabtenam *ui;
};

#endif // DOCTOR_SABTENAM_H
