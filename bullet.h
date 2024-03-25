#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet: public QObject,public QGraphicsPixmapItem
{
private:
    static int Score;

    Q_OBJECT
public:
    Bullet();

public slots:
    void move();
    int getScore();
};
// int Bullet::Score = 0;
#endif // BULLET_H
