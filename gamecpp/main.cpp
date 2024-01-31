#include "include/GMainWindow.h"

#include <QApplication>

const int WINDOW_MAXIMUM_WIDTH = 800;
const int WINDOW_MAXIMUM_HEIGHT = 600;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GMainWindow gameMainWindow("QGame", WINDOW_MAXIMUM_WIDTH, WINDOW_MAXIMUM_HEIGHT);
    gameMainWindow.show();
    return a.exec();
}
