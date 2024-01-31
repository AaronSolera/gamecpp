#ifndef GMAINWINDOW_H
#define GMAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QScreen>
#include <memory>
#include <QList>

#include "include/GSprite.h"
#include "include/GScene.h"
#include "include/defines/QGameDefines.h"

class GMainWindow : public QMainWindow
{
    Q_OBJECT

public:

    GMainWindow(QString title, int width, int height, QWidget *parent = nullptr);
    ~GMainWindow() = default;

private:

    /**
     * @brief Set the GScene to the central view
     * @param gScenePtr 
     */
    void setGScene(GScenePtr gScenePtr);

    /**
     * @brief Handle those GScenes created for the GMainWindow
     */
    void handleGScenes();

    std::shared_ptr<QGraphicsView> _graphicsViewPtr;
    QList<GScenePtr> _gScenes;
    QRect _gWindowGeometry;

    GSpritePtr _gSpritePtr;
};
#endif // GMAINWINDOW_H
