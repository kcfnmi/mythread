#include "worker.h"

#include <QRandomGenerator>

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qDebug() << QThread::currentThreadId() << Q_FUNC_INFO;
}

Worker::~Worker()
{
    stop();
}

void Worker::start()
{
    timer = new QTimer;
    timer->start(1000);
}

void Worker::stop()
{
    disconnect(timer, &QTimer::timeout, this, &Worker::compute);
    delete timer;
    timer = nullptr;
}

QString Worker::getName()
{
    QString s = m_name;
    qDebug() << QThread::currentThreadId() << Q_FUNC_INFO;
    return s;
}

void Worker::doWork()
{
    auto conn = connect(timer, &QTimer::timeout, this, &Worker::compute, Qt::UniqueConnection);
    if (!conn)
    {
        disconnect(timer, &QTimer::timeout, this, &Worker::compute);
    }
}

void Worker::compute()
{
    qDebug() << QThread::currentThreadId() << Q_FUNC_INFO;

    quint32 value = QRandomGenerator::global()->generate();

    emit resultReady(value);

//    qDebug() << value;
}
