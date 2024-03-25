#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>

int Bullet::Score = 0;

Bullet::Bullet():QObject(), QGraphicsPixmapItem() {

        // *******  Setting the bullets' size ********
    QPixmap pixmap1(":/new/prefix1/Assets/laser.png");
        pixmap1 = pixmap1.scaledToWidth(30);
        pixmap1 = pixmap1.scaledToHeight(30);
    setPixmap(pixmap1);

        // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));

    timer->start(50);

}

 int Bullet::getScore(){
     return Score;

 }

// Move function is used to 1-  move the bullet upwards
                         // 2- Handle the collision of the bullets with enemies

void Bullet:: move()
{
        // *******  Getting the colliding items with the Bullet ********
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size(); ++i) {
        QGraphicsItem* item = colliding_items[i];
        Enemy* enemy = dynamic_cast<Enemy*>(item);
        if(enemy) {
            Score++;

            scene()->removeItem(enemy)  ;

            enemy->deleteLater();

            scene()->removeItem(this);
            QTimer::singleShot(0, this, SLOT(deleteLater()));
            return;
        }
    }

        // *******  Moving the bullets upward ********
        setPos(x(),y()-10);
        if(pos().y()+pixmap().height()<0)
        {
            scene()->removeItem(this);
            delete this;
        }


}
