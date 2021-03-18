#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "my_methods.h"

#include <windows.h>
#include <QMessageBox>
#include <cctype>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->name->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->surname->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->login->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

}

MainWindow::~MainWindow() {
    //std::cout << "MainWindow" << std::endl;
    delete ui;
}

void MainWindow::on_login_clicked() {
    std::string name = ui->name->text().toStdString();
    std::string surname = ui->surname->text().toStdString();
    DeleteSpaces(name);
    DeleteSpaces(surname);
    int name_error_code = IsValidName(name);
    if (name_error_code) {
        QMessageBox::critical(this, "Error", GenerateErrorMessage("Name", name_error_code));
        return;
    }
    int surname_error_code = IsValidName(surname);
    if (surname_error_code) {
        QMessageBox::critical(this, "Error", GenerateErrorMessage("Surname", surname_error_code));
        return;
    }
    gw = new GameWindow(name, surname, this);
    this->hide();
    gw->show();
}
