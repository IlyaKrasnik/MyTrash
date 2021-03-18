#ifndef ACHIEVEMENTSWINDOW_H
#define ACHIEVEMENTSWINDOW_H

#include "gamewindow.h"
#include <QWidget>

namespace Ui {
class AchievementsWindow;
}

class AchievementsWindow : public QWidget
{
    Q_OBJECT

public:
    AchievementsWindow(GameWindow* prev, QWidget *parent = nullptr);
    ~AchievementsWindow();

private:
    Ui::AchievementsWindow *ui;
    GameWindow* prev_;
};

#endif // ACHIEVEMENTSWINDOW_H
