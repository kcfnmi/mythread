#ifndef WORKER_H
#define WORKER_H

#include <QDebug>
#include <QTimer>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT

    QTimer* timer = nullptr;

    QString m_name{"TheName"};

public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

    void start();
    void stop();

    QString getName();

public slots:
    void doWork();

private:
    void compute();

signals:
    void resultReady(const quint32 value);

};

#endif // WORKER_H
