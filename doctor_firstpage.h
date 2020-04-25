#ifndef DOCTOR_FIRSTPAGE_H
#define DOCTOR_FIRSTPAGE_H

#include <QWidget>
#include <changepassword.h>
#include <doctor_showallcomments.h>

namespace Ui {
class Doctor_FirstPage;
}

class Doctor_FirstPage : public QWidget
{
    Q_OBJECT

public:
    explicit Doctor_FirstPage(QWidget *parent = nullptr);
    ~Doctor_FirstPage();

private slots:
    void on_pushButtona_ChangePass_clicked();

    void on_pushButton_ShocComment_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Doctor_FirstPage *ui;
};

#endif // DOCTOR_FIRSTPAGE_H
