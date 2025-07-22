/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_add;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_search;
    QTextBrowser *Title;
    QLabel *name;
    QLabel *phone;
    QLabel *email;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_phone;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_search;
    QTableWidget *tableWidget_contacts;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(20, 340, 141, 41));
        pushButton_delete = new QPushButton(centralwidget);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(510, 480, 141, 41));
        pushButton_search = new QPushButton(centralwidget);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setGeometry(QRect(280, 480, 141, 41));
        Title = new QTextBrowser(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(290, 10, 171, 51));
        name = new QLabel(centralwidget);
        name->setObjectName("name");
        name->setGeometry(QRect(20, 140, 131, 41));
        phone = new QLabel(centralwidget);
        phone->setObjectName("phone");
        phone->setGeometry(QRect(20, 200, 131, 41));
        email = new QLabel(centralwidget);
        email->setObjectName("email");
        email->setGeometry(QRect(20, 260, 131, 41));
        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(130, 140, 221, 41));
        lineEdit_phone = new QLineEdit(centralwidget);
        lineEdit_phone->setObjectName("lineEdit_phone");
        lineEdit_phone->setGeometry(QRect(130, 200, 221, 41));
        lineEdit_email = new QLineEdit(centralwidget);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(130, 260, 221, 41));
        lineEdit_search = new QLineEdit(centralwidget);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setGeometry(QRect(20, 480, 221, 41));
        tableWidget_contacts = new QTableWidget(centralwidget);
        if (tableWidget_contacts->columnCount() < 3)
            tableWidget_contacts->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_contacts->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_contacts->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_contacts->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_contacts->setObjectName("tableWidget_contacts");
        tableWidget_contacts->setGeometry(QRect(390, 100, 391, 331));
        tableWidget_contacts->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tableWidget_contacts->setColumnCount(3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "DELETE", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainWindow", "SEARCH", nullptr));
        Title->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\353\247\221\354\235\200 \352\263\240\353\224\225'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:700;\">Phone Book</span></p></body></html>", nullptr));
        name->setText(QCoreApplication::translate("MainWindow", "Name : ", nullptr));
        phone->setText(QCoreApplication::translate("MainWindow", "Phone Number : ", nullptr));
        email->setText(QCoreApplication::translate("MainWindow", "Email : ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_contacts->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_contacts->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Phone Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_contacts->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
