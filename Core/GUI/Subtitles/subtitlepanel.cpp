#include "Subtitles/subtitlepanel.h"
#include "Subtitles/subtitlelabel.h"
#include "Layout/flowlayout.h"
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <QPainterPath>
#include <QtWidgets>
#include <QStyleOption>
#include <QDragEnterEvent>

SubtitlePanel::SubtitlePanel(QWidget *parent,bool isFixed) : QWidget(parent),_fixed(isFixed)
{
    Init();
}

void SubtitlePanel::Init()
{
    setCursor(Qt::PointingHandCursor);
    setAutoFillBackground(false);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_QuitOnClose, false);
    setMouseTracking(true);
    setMaximumHeight(80);
    setMinimumHeight(static_cast<QMainWindow*>(parent())->height()-250);
    setMinimumWidth(static_cast<QMainWindow*>(parent())->width()-40);
    setMaximumWidth(400);

    FlowLayout *flayout = new FlowLayout(this);
    setLayout(flayout);
}

void SubtitlePanel::panelSizeMove()
{
    if (this->width() <= parentWidget()->width() && this->height() <= parentWidget()->height())
    {
        this->setWindowOpacity(1); // Show the widget

        resize(parentWidget()->size());
        setMaximumWidth(parentWidget()->width()/1.10);

        QPoint p = parentWidget()->mapFromParent(parentWidget()->pos());
        int x = p.x() + (parentWidget()->width() - this->width()) / 2;
        int y = p.y() + (parentWidget()->height() - this->height()) / 1.15;

        this->move(x, y);
        this->raise();
    }
    else
    {
        this->setWindowOpacity(0); // Hide the widget
    }
}

bool SubtitlePanel::isFixed()
{
    return _fixed;
}

void SubtitlePanel::togglePanel()
{
    isHidden()?show():hide();
}

QList<SubtitleLabel *> SubtitlePanel::getSubtitles()
{
    return _subtitles;
}

void SubtitlePanel::setSubtitles(QList<SubtitleLabel *> subs)
{
    if(subs.count())
    {
        clearSubtitles();
    }
    _subtitles = subs;
    if(subs.count())
    {
        renderSubtitles();
    }
}

void SubtitlePanel::renderSubtitles()
{
    foreach(SubtitleLabel *sub, _subtitles)
    {
        layout()->addWidget(sub);
    }
}

void SubtitlePanel::clearSubtitles()
{
    foreach(SubtitleLabel *sub, _subtitles)
    {
        if(sub)
            delete sub;
    }
    _subtitles.clear();
}

void SubtitlePanel::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && !isFixed())
    {
        move(event->globalPos() - currentDragPosition);
        event->accept();
    }
    else
    if (event->buttons() & Qt::RightButton && !isFixed())
    {
        int x = dragSize.width() - currentDragPosition.x() + event->globalPos().x();
        int y = dragSize.height() - currentDragPosition.y() + event->globalPos().y();

        resize(x, y);
        event->accept();
    }
}

void SubtitlePanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !isFixed())
    {
        currentDragPosition = event->globalPos() - frameGeometry().topLeft();

        event->accept();
    }
    else
    if (event->buttons() & Qt::RightButton && !isFixed())
    {
        currentDragPosition = event->globalPos();
        dragSize = size();
        event->accept();
    }
}

void SubtitlePanel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255,255,255, 195));
    painter.drawRect(rect());
}

SubtitlePanel::~SubtitlePanel()
{
    clearSubtitles();
}
