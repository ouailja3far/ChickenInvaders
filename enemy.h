#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject ,public QGraphicsPixmapItem
{ Q_OBJECT
    static int health;
    bool hasCrossedThreshold = false;
public:
    Enemy();

public slots:
    void move();

};

#endif // ENEMY_H
