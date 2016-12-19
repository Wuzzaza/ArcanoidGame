#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->setFixedSize(802, 602);

    mainScene = new QGraphicsScene(ui->graphicsView);

    mainScene->setSceneRect(0, 0, 800, 600);

    ui->graphicsView->setScene(mainScene);

    gameField = new GameField(this);

    this->draw();

    gameTimer.setInterval(10);

    connect(&gameTimer, SIGNAL(timeout()), this, SLOT(update()));

    gameTimer.start();

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::draw()
{
    mainScene->clear();
    for (int i = 0; i < gameField->brickList.size(); i++)
        mainScene->addRect(gameField->brickList[i].x1, gameField->brickList[i].y1, 50, 20, QPen(Qt::black), QBrush(Qt::blue, Qt::SolidPattern));

    mainScene->addEllipse(gameField->ball->x - 10, gameField->ball-> y - 10, 20, 20, QPen(Qt::black), QBrush(Qt::red, Qt::SolidPattern));


}

void GameWindow::update()
{
    gameField->update();
    draw();
}
