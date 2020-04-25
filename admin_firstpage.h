#ifndef ADMIN_FIRSTPAGE_H
#define ADMIN_FIRSTPAGE_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include <changepassword.h>
#include <admin_showallnews.h>

namespace Ui {
class admin_firstpage;
}

class admin_firstpage : public QWidget
{
    Q_OBJECT

public:
    int andis;
    explicit admin_firstpage(QWidget *parent = nullptr);
    ~admin_firstpage();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_savenews_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::admin_firstpage *ui;
};

#endif // ADMIN_FIRSTPAGE_H
