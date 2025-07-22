#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_add, &QPushButton::clicked, this, &MainWindow::on_add_button_clicked);
    connect(ui->pushButton_delete, &QPushButton::clicked, this, &MainWindow::on_delete_button_clicked);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &MainWindow::on_search_button_clicked);

    // 열 비율 조정
    int totalWidth = ui->tableWidget_contacts->viewport()->width();
    ui->tableWidget_contacts->setColumnWidth(0, totalWidth * 0.8);
    ui->tableWidget_contacts->setColumnWidth(1, totalWidth * 1.2);
    ui->tableWidget_contacts->setColumnWidth(2, totalWidth * 1.95);
}

void MainWindow::on_add_button_clicked()
{
    QString name = ui->lineEdit_name->text().trimmed();
    QString phone = ui->lineEdit_phone->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();

    if (name.isEmpty()) return;

    Contact contact(name, phone, email);
    contactList.add_contact(contact);

    // 테이블에 추가
    int row = ui->tableWidget_contacts->rowCount();
    ui->tableWidget_contacts->insertRow(row);
    ui->tableWidget_contacts->setItem(row, 0, new QTableWidgetItem(name));
    ui->tableWidget_contacts->setItem(row, 1, new QTableWidgetItem(phone));
    ui->tableWidget_contacts->setItem(row, 2, new QTableWidgetItem(email));

    ui->lineEdit_name->clear();
    ui->lineEdit_phone->clear();
    ui->lineEdit_email->clear();
}


void MainWindow::on_delete_button_clicked()
{
    QList<int> rowsToDelete;
    QString nameToDelete;

    // 선택된 셀에서 이름 추출
    int currentRow = ui->tableWidget_contacts->currentRow();
    if (currentRow >= 0)
        nameToDelete = ui->tableWidget_contacts->item(currentRow, 0)->text();
    else
        return;

    // 이름이 같은 모든 row 찾기
    for (int i = 0; i < ui->tableWidget_contacts->rowCount(); ++i) {
        if (ui->tableWidget_contacts->item(i, 0)->text() == nameToDelete) {
            rowsToDelete.prepend(i);  // 뒤에서부터 지우기 위해 prepend
        }
    }

    // contactList에서 삭제
    contactList.delete_contact(nameToDelete);

    // UI에서 삭제
    for (int row : rowsToDelete) {
        ui->tableWidget_contacts->removeRow(row);
    }
}


void MainWindow::on_search_button_clicked()
{
    QString keyword = ui->lineEdit_search->text().trimmed();

    if (keyword.isEmpty()) return;

    QStringList matches;

    for (const Contact &c : contactList.getAllContacts()) {
        if (c.getName().contains(keyword, Qt::CaseSensitive) ||
            c.getPhone_num().contains(keyword, Qt::CaseSensitive) ||
            c.getEmail().contains(keyword, Qt::CaseSensitive)) {
            matches << c.toString();
        }
    }

    if (!matches.isEmpty()) {
        QMessageBox::information(this, "Results", matches.join("\n"));
    } else {
        QMessageBox::warning(this, "Not Found", "No contacts matching the keyword.");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
