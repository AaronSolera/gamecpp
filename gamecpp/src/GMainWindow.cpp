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
}

void GMainWindow::setGScene(GScenePtr gScenePtr)
{
    _graphicsViewPtr->setScene(gScenePtr.get());
}