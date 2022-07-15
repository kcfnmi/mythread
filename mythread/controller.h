#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>

#include "worker.h"

class Controller : public QObject
{
    Q_OBJECT

    QThread workerThread;

    Worker* m_worker = nullptr;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    void start();

    QString getName();

signals:
    void operate();

    void result(quint32 value);

public slots:
    void handleResults(const quint32 value);

};

#endif // CONTROLLER_H
