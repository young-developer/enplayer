#include "Subtitles/subtitlepanel.h"
#include "Subtitles/subtitlelabel.h"
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
    this->setMaximumHeight(80);
    this->setMinimumHeight(40);
    this->setMinimumWidth(static_cast<MainWindow*>(parent())->width()-40);
    move(static_cast<MainWindow*>(parent())->geometry().bottomLeft().rx()+20,
         static_cast<MainWindow*>(parent())->geometry().bottomLeft().ry()-100);
    this->setMouseTracking(true);

    _label = new SubtitleLabel(this);
    _label->setStyleSheet("color:black;font-size:25px;");
    _label->setText("OK");

    connect(static_cast<MainWindow*>(parent()),SIGNAL(resized()),SLOT(onResize()));
    connect(_label,SIGNAL(mouseEntered()),SLOT(onMouseEnter_Translate()));
    connect(_label,SIGNAL(mouseLeaved()),SLOT(onMouseLeave_Translate()));
}

void SubtitlePanel::togglePanel()
{
    if(this->isHidden())
    {
        show();
    }
    else
    {
        hide();
    }
}

void SubtitlePanel::onMouseEnter_Translate()
{
   SubtitleLabel *sub = static_cast<SubtitleLabel*>(sender());
   sub->setStyleSheet("color:red;font-size:26px;text-decoration:underline;");
}

void SubtitlePanel::onMouseLeave_Translate()
{
   SubtitleLabel *sub = static_cast<SubtitleLabel*>(sender());
   sub->setStyleSheet("color:black;font-size:26px;");
}

void SubtitlePanel::onResize()
{
    qInfo()<<"Main window resized!";
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

