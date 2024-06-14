#include <QMainWindow>
#include <QGraphicsView>

#include "include/GMainWindow.h"

GMainWindow::GMainWindow(QString title, int width, int height, QWidget* parent)
    : QMainWindow(parent)
{
    // Setting Windows Title
    setWindowTitle(title);
    // Set fixed size to avoid resizability
    setFixedSize(width, height);
    // Set geometry to be used to size GScenes
    _gWindowGeometry = QRect(WINDOW_X_ORIGIN, WINDOW_Y_ORIGIN, width, height);
    // Set the QGraphicsView as the central widget of the QMainWindow
    _graphicsViewPtr = std::make_shared<QGraphicsView>();
    _graphicsViewPtr->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    _graphicsViewPtr->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _graphicsViewPtr->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(_graphicsViewPtr.get());
    // Handle all created scenes for the game
    handleGScenes();
}

void GMainWindow::handleGScenes()
{
    /**********************************
    Game Sample code starts here

    ToDo:

        Improve adding scenes to GMainWindow
            make _gScenes a QMap
            bool SetScene
            GScenePtr GetScene
        Create an entity class and add a map to them into the GScene class

    **********************************/
    // Delete this code for deployment

    _gScenes.push_back(std::make_shared<GScene>(_gWindowGeometry));
    setGScene(_gScenes.front());

    _gSpritePtr = std::make_shared<GSprite>(108, 140, ":/assets/sample_sprite.png");
    _gSpritePtr->addAnimationId("run_right", 0);
    _gSpritePtr->addAnimationId("run_left", 1);
    _gSpritePtr->setAnimation("run_left");
    _gSpritePtr->setPos(0, 0);

    _gScenes.front()->addSpriteToSceneGUI(_gSpritePtr);


    /*********************************
        Game Sample code ends here
    **********************************/
}

void GMainWindow::setGScene(GScenePtr gScenePtr)
{
    _graphicsViewPtr->setScene(gScenePtr.get());
}