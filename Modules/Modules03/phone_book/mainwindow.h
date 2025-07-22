#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "contact.h"
#include "contact_list.h"
#include "ui_mainwindow.h"  // 반드시 포함

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_button_clicked();
    void on_delete_button_clicked();
    void on_search_button_clicked();

private:
    Ui::MainWindow *ui;
    Contact_list contactList;
};

#endif // MAINWINDOW_H
