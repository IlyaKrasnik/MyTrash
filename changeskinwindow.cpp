#include "changeskinwindow.h"
#include "ui_changeskinwindow.h"

ChangeSkinWindow::ChangeSkinWindow(GameWindow* prev, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ChangeSkinWindow),
        prev_(prev) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);
    this->setWindowModality(Qt::ApplicationModal);
}

ChangeSkinWindow::~ChangeSkinWindow() {
    //std::cout << "ChangeSkinWindow" << std::endl;
    delete ui;
}

void ChangeSkinWindow::on_goback_button_clicked() {
    this->close();
}

void ChangeSkinWindow::on_snuswasher_button_clicked() {
    prev_->ChangeSkin("шайба");
}

void ChangeSkinWindow::on_coin_button_clicked() {
    prev_->ChangeSkin("coin");
}

void ChangeSkinWindow::on_heart_button_clicked() {
    prev_->ChangeSkin("heart");
}
