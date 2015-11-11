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
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setMouseTracking(true);

    setMinimumHeight(static_cast<QMainWindow*>(parent())->height()-250);
    setMinimumWidth(static_cast<QMainWindow*>(parent())->width()-40);
    setMaximumHeight(80);
    setMaximumWidth(400);

    QFont defaultFont( "Arial", 14, QFont::Normal);//default font Arial,14px,Normal
    setFont(defaultFont);
    setOpacity(50);//opacity 50%

    QLayout *flayout = new QHBoxLayout();
    flayout->setAlignment(flayout,Qt::AlignLeft);
    setLayout(flayout);
}

void SubtitlePanel::panelSizeMove()
{
    this->setWindowOpacity(1); // Show the widget

    resize(parentWidget()->size());
    setMaximumWidth(parentWidget()->width()*0.9);//90% of the player size

    int x = parentWidget()->pos().rx() + (parentWidget()->width() - this->width()) / 2;
    int y = parentWidget()->pos().ry() + (parentWidget()->height() - this->height()) / 1.15;//margin 15%

    this->move(x,y);
    this->raise();
}

bool SubtitlePanel::isFixed()
{
    return _fixed;
}

void SubtitlePanel::togglePanel()
{
    isHidden()?show():hide();
}

unsigned short SubtitlePanel::getOpacity() const
{
    return _opacity;
}

void SubtitlePanel::setOpacity(unsigned short int opacity)
{
    if(opacity <= 100)
    {
        float percent = opacity/100.0;
        _opacity = static_cast<unsigned short>(255*percent);
        this->update();
    }
    else
    {
        qWarning()<<"Incorect opacity value for subtitle panel has been set!";
    }
}

void SubtitlePanel::enterEvent(QEvent *)
{
    emit mouseEntered();
}

void SubtitlePanel::leaveEvent(QEvent *)
{
    emit mouseLeaved();
}

QFont SubtitlePanel::getFont() const
{
    return _subFont;
}

void SubtitlePanel::setFont(QFont font)
{
    _subFont = font;
    foreach(SubtitleLabel *sub, _subtitles)
    {
        sub->setFont(_subFont);
    }
}

QList<SubtitleLabel *> SubtitlePanel::getSubtitles() const
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
            sub->deleteLater();
    }
    _subtitles.clear();
}

void SubtitlePanel::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && !isFixed())
    {
        move(event->globalPos() - _currentDragPosition);
        event->accept();
    }
    else
    if (event->buttons() & Qt::RightButton && !isFixed())
    {
        int x = _dragSize.width() - _currentDragPosition.x() + event->globalPos().x();
        int y = _dragSize.height() - _currentDragPosition.y() + event->globalPos().y();

        resize(x, y);
        event->accept();
    }
}

void SubtitlePanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !isFixed())
    {
        _currentDragPosition = event->globalPos() - frameGeometry().topLeft();

        event->accept();
    }
    else
    if (event->buttons() & Qt::RightButton && !isFixed())
    {
        _currentDragPosition = event->globalPos();
        _dragSize = size();
        event->accept();
    }
}

void SubtitlePanel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255,255,255, getOpacity()));
    painter.drawRect(event->rect());
}

SubtitlePanel::~SubtitlePanel()
{
    clearSubtitles();
}
