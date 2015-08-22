#include "Subtitles/subtitlepanel.h"
#include "Subtitles/subtitlelabel.h"
#include "Layout/flowlayout.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <QPainterPath>
#include <QtWidgets>
#include <QStyleOption>
#include <QDragEnterEvent>

SubtitlePanel::SubtitlePanel(QWidget *parent) : QWidget(parent)
{
    Init();
}

void SubtitlePanel::Init()
{
    setCursor(Qt::PointingHandCursor);
    setAutoFillBackground(false);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute( Qt::WA_QuitOnClose, false );
    setMouseTracking(true);

    setMaximumHeight(80);
    setMinimumHeight(static_cast<MainWindow*>(parent())->height()-250);
    setMinimumWidth(static_cast<MainWindow*>(parent())->width()-40);
    setMaximumWidth(400);
    move(static_cast<MainWindow*>(parent())->geometry().bottomLeft().rx()+20,
         static_cast<MainWindow*>(parent())->geometry().bottomLeft().ry()-120);

    FlowLayout *flayout = new FlowLayout(this);
    setLayout(flayout);
}

void SubtitlePanel::togglePanel()
{
    isHidden()?show():hide();
}

void SubtitlePanel::onResize()
{
    qInfo()<<"Main window resized!";
}

void SubtitlePanel::updateSubtitles()
{
    foreach(SubtitleLabel *sub, _subtitles)
    {
        layout()->addWidget(sub);
        sub->show();
    }
}

QList<SubtitleLabel *> SubtitlePanel::getSubtitles()
{
    return _subtitles;
}

void SubtitlePanel::setSubtitles(QList<SubtitleLabel *> subs)
{
    _subtitles = subs;
}

void SubtitlePanel::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - currentDragPosition);
        event->accept();
    }
    else
    if (event->buttons() & Qt::RightButton)
    {
        int x = dragSize.width() - currentDragPosition.x() + event->globalPos().x();
        int y = dragSize.height() - currentDragPosition.y() + event->globalPos().y();

        resize(x, y);
        event->accept();
    }
}

void SubtitlePanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        currentDragPosition = event->globalPos() - frameGeometry().topLeft();

        event->accept();
    }
    else
    if (event->buttons() & Qt::RightButton)
    {
        currentDragPosition = event->globalPos();
        dragSize = size();
        setMaximumWidth(static_cast<MainWindow*>(parent())->width()-50);
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

