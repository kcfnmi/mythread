#include "widget.h"
#include "controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qDebug() << QThread::currentThreadId() << Q_FUNC_INFO;

    QApplication a(argc, argv);

    Controller controller;

    Widget widget{controller};
    widget.show();

    return a.exec();
}
