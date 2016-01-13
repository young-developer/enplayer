#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include "customtooltip.h"

CustomTooltip::~CustomTooltip()
{
//TODO: Implement Custom tooltip
}

CustomTooltip::CustomTooltip(QWidget *parent) : QLabel(parent)
{
    if(parent!=0)
    {
        connect(this,SIGNAL(mouseOverParent),SLOT(show()));
        connect(this,SIGNAL(mouseOutParent),SLOT(hide()));
    }
}

void CustomTooltip::attachTo(QWidget *parent)
{
    setParent(parent);
}

void CustomTooltip::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (parentWidget()->rect().contains(event->pos())) {
        qDebug()<<"mouseOverParent";
        emit mouseOverParent();
    }
    else {
        qDebug()<<"mouseOutParent";
        emit mouseOutParent();
    }
}

void CustomTooltip::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255,255,255, 140));
    painter.drawRect(event->rect());
}
