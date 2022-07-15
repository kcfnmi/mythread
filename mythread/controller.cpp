#include "controller.h"

#include <QCoreApplication>

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    m_worker = new Worker;
    m_worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, m_worker, &QObject::deleteLater);
    connect(this, &Controller::operate, m_worker, &Worker::doWork);
    connect(m_worker, &Worker::resultReady, this, &Controller::handleResults);

    connect(&workerThread, &QThread::started, m_worker, &Worker::start);

    workerThread.start();

}

Controller::~Controller()
{
    workerThread.quit();
    workerThread.wait();
}

void Controller::start()
{
    QTimer::singleShot(0, this, [this](){emit operate();});
}

QString Controller::getName()
{
    auto s = m_worker->getName();
    qDebug() << QThread::currentThreadId() << Q_FUNC_INFO;
    return s;
}

void Controller::handleResults(const quint32 value)
{
    emit result(value);
}
