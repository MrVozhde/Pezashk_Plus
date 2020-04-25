#ifndef USER_FIRSTPAGE_H
#define USER_FIRSTPAGE_H

#include <QWidget>
#include <changepassword.h>
#include <user_addcomment.h>
#include <user_seecomment.h>
#include <user_showallnews.h>

namespace Ui {
class user_firstpage;
}

class user_firstpage : public QWidget
{
    Q_OBJECT

public:
    explicit user_firstpage(QWidget *parent = nullptr);
    ~user_firstpage();

private slots:
    void on_pushButtonchangePassword_clicked();

    void on_pushButton_clicked();

    void on_pushButton_AllNews_2_clicked();

    void on_pushButton_AllNews_clicked();

private:
    Ui::user_firstpage *ui;
};

#endif // USER_FIRSTPAGE_H
