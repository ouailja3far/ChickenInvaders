#include <QApplication>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QScrollBar>

using namespace Qt;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView view;
    view.setFixedSize(800,600);
    // ******* Create the Scene ********
    QGraphicsScene scene;
    scene.setSceneRect(0,0,800,600);
    view.setVerticalScrollBarPolicy(ScrollBarAlwaysOff);
    view.setHorizontalScrollBarPolicy(ScrollBarAlwaysOff);
    // *******  Create the Player ********
    Player *player = new Player();
    scene.addItem(player);

    // *******  Setting the foucs to the Player ********
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********
    player->setPos(view.width()/2,view.height() - (player->pixmap().height()+10));


   // *******   Assign scene to the view   ***************
    view.setScene(&scene);
    view.show();
    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);


   return a.exec();
}
