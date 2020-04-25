#-------------------------------------------------
#
# Project created by QtCreator 2019-10-24T13:54:47
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pezeshk_plus
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    sabtenam.cpp \
    doctor_sabtenam.cpp \
    doctor_firstpage.cpp \
    changepassword.cpp \
    user_firstpage.cpp \
    doctor_showallcomments.cpp \
    user_addcomment.cpp \
    admin_firstpage.cpp \
    admin_showallnews.cpp \
    user_seecomment.cpp \
    user_showallnews.cpp

HEADERS += \
        mainwindow.h \
    sabtenam.h \
    doctor_sabtenam.h \
    doctor_firstpage.h \
    changepassword.h \
    user_firstpage.h \
    doctor_showallcomments.h \
    user_addcomment.h \
    admin_firstpage.h \
    admin_showallnews.h \
    user_seecomment.h \
    user_showallnews.h

FORMS += \
        mainwindow.ui \
    sabtenam.ui \
    doctor_sabtenam.ui \
    doctor_firstpage.ui \
    changepassword.ui \
    user_firstpage.ui \
    doctor_showallcomments.ui \
    user_addcomment.ui \
    admin_firstpage.ui \
    admin_showallnews.ui \
    user_seecomment.ui \
    user_showallnews.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
