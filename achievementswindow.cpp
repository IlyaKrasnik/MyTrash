#include "achievementswindow.h"
#include "ui_achievementswindow.h"

AchievementsWindow::AchievementsWindow(GameWindow* prev, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AchievementsWindow),
    prev_(prev)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);
    this->setWindowModality(Qt::ApplicationModal);
}

AchievementsWindow::~AchievementsWindow()
{
    //std::cout << "AchievementsWindow" << std::endl;
    delete ui;
}
