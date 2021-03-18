#include "gamewindow.h"
#include "ui_gamewindow.h"

void GameWindow::on_boost1_button_clicked() {
    player_.BuyPassiveBoost(0);
    ui->boost1_button->setText(player_.PassiveBoostInfo(0));
    UpdatePerSecond();
    UpdatePoints();
}

void GameWindow::on_boost2_button_clicked() {
    player_.BuyPassiveBoost(1);
    ui->boost2_button->setText(player_.PassiveBoostInfo(1));
    UpdatePerSecond();
    UpdatePoints();
}

void GameWindow::on_boost3_button_clicked() {
    player_.BuyPassiveBoost(2);
    ui->boost3_button->setText(player_.PassiveBoostInfo(2));
    UpdatePerSecond();
    UpdatePoints();
}

void GameWindow::on_boost4_button_clicked() {
    player_.BuyPassiveBoost(3);
    ui->boost4_button->setText(player_.PassiveBoostInfo(3));
    UpdatePerSecond();
    UpdatePoints();
}

void GameWindow::on_boost5_button_clicked() {
    player_.BuyPassiveBoost(4);
    ui->boost5_button->setText(player_.PassiveBoostInfo(4));
    UpdatePerSecond();
    UpdatePoints();
}

void GameWindow::on_boost6_button_clicked() {
    player_.BuyPassiveBoost(5);
    ui->boost6_button->setText(player_.PassiveBoostInfo(5));
    UpdatePerSecond();
    UpdatePoints();
}

void GameWindow::on_boost7_button_clicked() {
    player_.BuyPassiveBoost(6);
    ui->boost7_button->setText(player_.PassiveBoostInfo(6));
    UpdatePerSecond();
    UpdatePoints();
}

void GameWindow::on_boost8_button_clicked() {
    player_.BuyPassiveBoost(7);
    ui->boost8_button->setText(player_.PassiveBoostInfo(7));
    UpdatePerSecond();
    UpdatePoints();
}

void GameWindow::on_boost9_button_clicked() {
    player_.BuyPassiveBoost(8);
    ui->boost9_button->setText(player_.PassiveBoostInfo(8));
    UpdatePerSecond();
    UpdatePoints();
}

void GameWindow::on_boost10_button_clicked() {
    player_.BuyPassiveBoost(9);
    ui->boost10_button->setText(player_.PassiveBoostInfo(9));
    UpdatePerSecond();
    UpdatePoints();
}
