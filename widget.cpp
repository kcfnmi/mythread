#include "widget.h"

#include <QDebug>

Widget::Widget(Controller& controller, QWidget *parent)
    : QWidget(parent),
      m_controller(controller)
{
    qDebug() << QThread::currentThreadId() << Q_FUNC_INFO;

    setLayout(&vLayout);

    vLayout.addWidget(&labelValue);
    vLayout.addWidget(&labelName);

    vLayout.addWidget(&btStart);
    vLayout.addWidget(&btGetName);

    resize(400,300);

    connect(&btStart, &QPushButton::clicked, &controller, [&controller]()
    {
        controller.start();
    });

    connect(&btGetName, &QPushButton::clicked, &controller, [&controller, this]()
    {
        auto s = controller.getName();
        labelName.setText(s);
    });

    connect(&m_controller, &Controller::result, this, &Widget::showResult);

    retranslateUi();
}

Widget::~Widget()
{
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    if (event->key() != Qt::Key_Escape)
        return;
    close();
}

void Widget::retranslateUi()
{
    btStart.setText("Start");
    btGetName.setText("Get Name");
}

