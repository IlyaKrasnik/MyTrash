#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include <QWidget>
#include <QMainWindow>
#include <player.h>
#include <future>
#include <QPushButton>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(std::string& name, std::string& surname, QMainWindow* prev, QWidget *parent = nullptr);
    ~GameWindow();

    void UpdatePoints();
    void UpdatePerSecond();
    void UpdateBoostButtons();
    void UpdateClickButton();
    void UpdatePerClick();
    void ChangeSkin(const std::string& skin);

    void Animation();

    void UpdateAvailebleButtons();

    QMainWindow* getRegistrationWindow();

private slots:
    void on_click_clicked();

    void on_boost1_button_clicked();
    void on_boost2_button_clicked();
    void on_boost3_button_clicked();
    void on_boost4_button_clicked();
    void on_boost5_button_clicked();
    void on_boost6_button_clicked();
    void on_boost7_button_clicked();
    void on_boost8_button_clicked();
    void on_boost9_button_clicked();
    void on_boost10_button_clicked();

    void on_click_boost_clicked();

    void on_settings_button_clicked();
    void on_changeskin_button_clicked();

    void on_achieve_button_clicked();

private:
    QString Property() {
        return "border-image:url(pics/" +
                                     QString::fromStdString(player_.getSkin().getPic()) + ");";
    }

    Ui::GameWindow *ui;
    QMainWindow* prev_;
    Player player_;

    std::future<void> future_per_second, future_available_buttons;
    bool stop;
};

#endif // GAMEWINDOW_H
