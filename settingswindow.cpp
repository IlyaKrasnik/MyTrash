#include "settingswindow.h"
#include "ui_settingswindow.h"

#include <QMessageBox>

SettingsWindow::SettingsWindow(GameWindow* game_, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow),
    game(game_) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);
    this->setWindowModality(Qt::ApplicationModal);
}

SettingsWindow::~SettingsWindow() {
    delete ui;
    //std::cout << "SettingsWindow" << std::endl;
}

void SettingsWindow::on_back_to_game_button_clicked() {
    this->close();
}

void SettingsWindow::on_resolution_button_clicked() {
    if (game->isFullScreen()) {
        game->showNormal();
        this->raise();
    } else {
        game->showFullScreen();
        this->raise();
    }
}

void SettingsWindow::on_change_account_button_clicked() {
    QMainWindow* qmw = game->getRegistrationWindow();
    //game->setStop(true);
    this->close();
    game->close();
    qmw->show();
}



void SettingsWindow::on_exit_button_clicked() {
    this->close();
    game->close();
}


void SettingsWindow::on_about_us_button_clicked() {
    QMessageBox::information(this, "About us", "DAVIDIK and ILUSHA)");
}

void SettingsWindow::on_help_button_clicked() {
    QMessageBox::information(this, "Help", "In this game you have to try "
    "to score maximum points to become the coolest clicker. "
    "To do this, just click in the center of the screen on the click button, "
    "the longer you press, the greater the bonus per click. Try to buy boosts, "
    "as they will help you accumulate a large number of points faster. Good game.");
}
