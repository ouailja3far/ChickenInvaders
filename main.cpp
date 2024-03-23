#include <QGraphicsView>
#include<QGraphicsScene>
#include <QApplication>
#include <QScrollBar>
#include <QGraphicsRectItem>>
using namespace Qt;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView View;
    View.setFixedSize(800,600);
    QGraphicsScene Scene;
    Scene.setSceneRect(0,0,800,600);
    View.setScene(&Scene);
    View.show();
    //Disabling Scroll Bars
    View.setVerticalScrollBarPolicy(ScrollBarAlwaysOff);
    View.setHorizontalScrollBarPolicy(ScrollBarAlwaysOff);

    //Creating Item
    QGraphicsRectItem *rect = new QGraphicsRectItem;
    rect->setRect(100,300,200,200);
    Scene.addItem(rect);
    View.setScene(&Scene);
    View.show();



    return a.exec();
}
