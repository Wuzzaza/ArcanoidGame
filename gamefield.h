#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include <QObject>
#include <QList>

class GameField: public QObject
{
public:
    struct Brick{
        int x1, y1, x2, y2;
        bool isDestructible;

        Brick(int x1, int y1, int x2, int y2, bool isDestructible){
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
            this->isDestructible = isDestructible;
        }
    };

    struct Ball{
        int x, y;
        double angle, speed;

        Ball(){
            x = 400;
            y = 500;
            angle = -45.0;
            speed = 5;
        }
        int next_x(){
            return this->x + (cos(3.14 * angle / 180) * speed);
        }

        int next_y(){
            return this->y + (sin(3.14 * angle / 180) * speed);
        }

        void move(){
            this->x = next_x();
            this->y = next_y();
        }
    };

public:
    GameField(QObject *parent);
    ~GameField();

    QList<Brick> brickList;
    Ball *ball;

    void update();
    void checkBorders();
    void checkCollisions();
    bool isInMid(int n1, int mid, int n2);


};

#endif // GAMEFIELD_H
