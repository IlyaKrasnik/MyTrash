#include "gamewindow.h"
#include "settingswindow.h"
#include "changeskinwindow.h"
#include "ui_gamewindow.h"
#include "achievementswindow.h"

#include <windows.h>
#include <QDialog>
#include <QPixmap>

GameWindow::GameWindow(std::string& name, std::string& surname, QMainWindow* prev, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow),
    prev_(prev),
    player_(name, surname)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);
    player_.Read();

    ui->account->setText("Account: " +
       QString::fromStdString(name) + " " + QString::fromStdString(surname));

    ChangeSkin(player_.getSkin().getSkinName());
    ui->click->setFixedSize(200, 200);

    stop = false;
    future_per_second = std::async([=](){
        while (true) {
            UpdateAvailebleButtons();
            if (stop)
                break;
            player_.GivePerSecond();
            ui->tap_factor->setText("Time click-bonus: x" + QString::fromStdString(std::to_string(player_.getTapFactor())));
            UpdatePoints();          
            Sleep(1000);
        }
    });

//    ui->boost1_button->setSizePolicy(QSizePolicy(QSizePolicy::Maximum,
//                                      QSizePolicy::Fixed,
//                                      QSizePolicy::ToolButton));
//    ui->boost2_button->setSizePolicy(QSizePolicy(QSizePolicy::Maximum,
//                                      QSizePolicy::Fixed,
//                                      QSizePolicy::ToolButton));
}

void GameWindow::UpdatePoints() {
    ui->points->setText("<b>" + QString::fromStdString(player_.getPoints().ToShortString())
          + " " + QString::fromStdString(player_.getSkin().getPointsName() + "</b>")
    );
}

void GameWindow::UpdateBoostButtons() {
    ui->boost1_button->setText(player_.PassiveBoostInfo(0));
    ui->boost2_button->setText(player_.PassiveBoostInfo(1));
    ui->boost3_button->setText(player_.PassiveBoostInfo(2));
    ui->boost4_button->setText(player_.PassiveBoostInfo(3));
    ui->boost5_button->setText(player_.PassiveBoostInfo(4));
    ui->boost6_button->setText(player_.PassiveBoostInfo(5));
    ui->boost7_button->setText(player_.PassiveBoostInfo(6));
    ui->boost8_button->setText(player_.PassiveBoostInfo(7));
    ui->boost9_button->setText(player_.PassiveBoostInfo(8));
    ui->boost10_button->setText(player_.PassiveBoostInfo(9));
    ui->click_boost->setText(player_.ClickBoostInfo());
}

void GameWindow::UpdatePerSecond() {
    ui->per_second_label->setText("Per sec: "
            + QString::fromStdString(player_.getPerSecond().ToShortString()) + " "
            + QString::fromStdString(player_.getSkin().getPointsName())
    );
}

GameWindow::~GameWindow() {
    delete ui;
    //std::cout << "GameWindow" << std::endl;
    stop = true;
    player_.Write();
}

void GameWindow::on_click_clicked() {
    player_.Click();
    Animation();
    UpdatePoints();
}

void GameWindow::ChangeSkin(const std::string& skin) {
    player_.getSkin().Change(skin);
    UpdatePoints();
    UpdatePerSecond();
    UpdateBoostButtons();
    UpdatePerClick();
    ui->click->setStyleSheet("border-image:url(pics/" +
                             QString::fromStdString(player_.getSkin().getPic()) + ");");
}

void GameWindow::on_click_boost_clicked() {
    player_.BuyClickBoost();
    UpdatePoints();
    UpdatePerClick();
    UpdateClickButton();
}

void GameWindow::UpdatePerClick() {
    ui->per_click->setText("Per click: " + QString::fromStdString(player_.getPerClick().ToShortString())
                     + " " + QString::fromStdString(player_.getSkin().getPointsName())
    );

}

void GameWindow::UpdateClickButton() {
    ui->click_boost->setText(player_.ClickBoostInfo());
}

void GameWindow::on_settings_button_clicked() {
    SettingsWindow* sw = new SettingsWindow(this);
    sw->show();
}

QMainWindow* GameWindow::getRegistrationWindow() {
    return prev_;
}

void GameWindow::Animation() {
    if (ui->click->width() == 200)
        ui->click->setFixedSize(210, 210);
    else
        ui->click->setFixedSize(200, 200);
}

void GameWindow::UpdateAvailebleButtons() {
    ui->click_boost->setEnabled(player_.getPoints() >= player_.getBoostPrice(0));
    ui->boost1_button->setEnabled(player_.getPoints() >= player_.getBoostPrice(1));
    ui->boost2_button->setEnabled(player_.getPoints() >= player_.getBoostPrice(2));
    ui->boost3_button->setEnabled(player_.getPoints() >= player_.getBoostPrice(3));
    ui->boost4_button->setEnabled(player_.getPoints() >= player_.getBoostPrice(4));
    ui->boost5_button->setEnabled(player_.getPoints() >= player_.getBoostPrice(5));
    ui->boost6_button->setEnabled(player_.getPoints() >= player_.getBoostPrice(6));
    ui->boost7_button->setEnabled(player_.getPoints() >= player_.getBoostPrice(7));
    ui->boost8_button->setEnabled(player_.getPoints() >= player_.getBoostPrice(8));
    ui->boost9_button->setEnabled(player_.getPoints() >= player_.getBoostPrice(9));
    ui->boost10_button->setEnabled(player_.getPoints() >= player_.getBoostPrice(10));
}

void GameWindow::on_changeskin_button_clicked() {
    ChangeSkinWindow* csw = new ChangeSkinWindow(this);
    csw->show();
}

void GameWindow::on_achieve_button_clicked()
{
    AchievementsWindow* aw = new AchievementsWindow(this);
    aw->show();
}
