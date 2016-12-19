#include "gamefield.h"
#include <iostream>

GameField::GameField(QObject *parent):QObject(parent)
{
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 14; j++){
            brickList.append(Brick(50 + j * 50, 100 + i * 20, 100 + j * 50, 120 + i * 20, true ));
        }
    }

    ball = new Ball;

}

GameField::~GameField()
{
    brickList.clear();
    delete ball;

}

void GameField::update()
{
    checkBorders();
    checkCollisions();
    ball->move();
}

void GameField::checkBorders()
{
    if(ball->next_x() < 10 || ball->next_x() > 790) {
        ball->angle = 180 - ball->angle;
        std::cout << ball->angle << std::endl;
    }
    if(ball->next_y() < 10 || ball->next_y() > 590) {
        ball->angle = 0 - ball->angle;
        std::cout << ball->angle << std::endl;
    }
}

void GameField::checkCollisions()
{
    for (int i = 0; i < brickList.size(); i++){

        if (ball->next_x()> brickList[i].x1 - 11 && ball->next_x() < brickList[i].x2 + 11 && ball->next_y()> brickList[i].y1 - 11 && ball->next_y() < brickList[i].y2 + 11){
            if (ball->x < brickList[i].x1)ball->angle = 180 - ball->angle;
            if (ball->x > brickList[i].x2)ball->angle = 180 - ball->angle;

            if (ball->y < brickList[i].y1)ball->angle = 0 - ball->angle;
            if (ball->y > brickList[i].y2)ball->angle = 0 - ball->angle;

            brickList.removeAt(i);
        }
    }

    if (ball->angle > 360) ball->angle -= 360;
    if (ball->angle < -360) ball->angle += 360;
}





