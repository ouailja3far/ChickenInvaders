#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include <QPixmap>
#include "player.h"
#include <QMessageBox>
int Enemy::health = 3;
Enemy::Enemy() {
    QPixmap pixmap1(":/new/prefix1/Assets/enemy.png");
    pixmap1 = pixmap1.scaledToWidth(100);
    pixmap1 = pixmap1.scaledToHeight(100);
    setPixmap(pixmap1);
        // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);

        // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}

// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{

    //collision
    QList<QGraphicsItem*> items = scene()->items();
    int bottomThreshold = scene()->height(); // Adjust based on your scene/view setup

    for (QGraphicsItem* item : items) {
        Enemy* enemy = dynamic_cast<Enemy*>(item);
        if (enemy && !hasCrossedThreshold && enemy->y() + enemy->boundingRect().height() >= bottomThreshold) {

            hasCrossedThreshold = true;
            health--;
            if (health == 0) {
                // Handle game over logic here
                QMessageBox *msg;
                msg= new QMessageBox();
                msg->setWindowTitle("Game Over");
                msg->setText("You have been defeated!");
                msg->show();
                break;
            }
        }
    }

        //motion
    setPos(x(),y()+5);
    if(y()+pixmap().height()>800)
    {
        scene()->removeItem(this);
            delete this;
    }
}
