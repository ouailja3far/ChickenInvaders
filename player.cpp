#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QMessageBox>
#include "enemy.h"
#include <QPixmap>
Player::Player() {
    QPixmap pixmap1(":/new/prefix1/Assets/player.png");
    pixmap1 = pixmap1.scaledToWidth(100);
    pixmap1 = pixmap1.scaledToHeight(100);
    setPixmap(pixmap1);

}

// setPlainText(QString(“The message “you want to display”) +
//              QString::number(The_name_of_the_variable));



void Player::keyPressEvent(QKeyEvent *event)

{
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);

    }


}
 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy();
  scene()->addItem(enemy);

}
