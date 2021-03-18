#ifndef CHANGESKINWINDOW_H
#define CHANGESKINWINDOW_H

#include "gamewindow.h"
#include <QWidget>

namespace Ui {
class ChangeSkinWindow;
}

class ChangeSkinWindow : public QWidget
{
    Q_OBJECT

public:
     ChangeSkinWindow(GameWindow* prev, QWidget *parent = nullptr);
    ~ChangeSkinWindow();

private slots:
    void on_goback_button_clicked();

    void on_snuswasher_button_clicked();

    void on_coin_button_clicked();

    void on_heart_button_clicked();

private:
    Ui::ChangeSkinWindow *ui;
    GameWindow* prev_;
};

#endif // CHANGESKINWINDOW_H
