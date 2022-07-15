#ifndef WIDGET_H
#define WIDGET_H

#include <QKeyEvent>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

#include "controller.h"

class Widget : public QWidget
{
    Q_OBJECT

    QVBoxLayout vLayout;

    QPushButton btStart;
    QPushButton btGetName;

    QLabel labelValue;
    QLabel labelName;

    Controller& m_controller;

public:
    explicit Widget(Controller& controller, QWidget *parent = nullptr);
    ~Widget();

    void showResult(quint32 value)
    {
        labelValue.setText(QString::number(value));
    }

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    void retranslateUi();

signals:
    void start();

};
#endif // WIDGET_H
