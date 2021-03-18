#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "gamewindow.h"
#include <QWidget>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    SettingsWindow(GameWindow* game_, QWidget *parent = nullptr);
    ~SettingsWindow();

private slots:
    void on_back_to_game_button_clicked();
    void on_resolution_button_clicked();
    void on_change_account_button_clicked();
    void on_exit_button_clicked();
    void on_about_us_button_clicked();
    void on_help_button_clicked();

private:
    Ui::SettingsWindow *ui;
    GameWindow* game;
};

#endif // SETTINGSWINDOW_H
