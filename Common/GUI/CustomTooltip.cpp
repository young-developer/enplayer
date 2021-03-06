#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include "CustomTooltip.h"

CustomTooltip::~CustomTooltip()
{
//TODO: Implement Custom tooltip
    setMouseTracking(true);
    QFont serifFont("Arial", 14, QFont::Normal);
    setFont(serifFont);
    setStyleSheet("color:blue;");
}

CustomTooltip::CustomTooltip(QWidget *parent) : QLabel(parent)
{

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
    Q_UNUSED(event);
    QPainter painter(this);
    QFont font=painter.font() ;
    font.setPointSize ( 14 );
    //font.setWeight(QFont::DemiBold);
    painter.setFont(font);
    painter.drawText(event->rect(),text());
}
