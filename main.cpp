
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView view;

    // ******* Create the Scene ********
    QGraphicsScene scene;
    view.setScene(&scene);

    // *******  Create the Player ********
    Player *player = new Player();
    scene.addItem(player);

    // *******  Setting the foucs to the Player ********
    player->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********
    player->setPos(view.width()/2 - player->boundingRect().width()/2,view.height()/2 - player->boundingRect().height()/2);


   // *******   Assign scene to the view   ***************
    view.setScene(&scene);

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);


    return a.exec();
}
