#include "Subtitles/subtitlelabel.h"
#include <QDebug>

SubtitleLabel::SubtitleLabel(QWidget *parent) : QLabel(parent)
{
    Init();
    setText("Empty label");
}

SubtitleLabel::SubtitleLabel(QString text, QWidget *parent):QLabel(parent)
{
    Init();
    setText(text);
}

void SubtitleLabel::Init()
{
    setMouseTracking(true);
    QFont serifFont("Arial", 14, QFont::Normal);
    setFont(serifFont);
}

void SubtitleLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit doubleClicked();
}

void SubtitleLabel::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked();
}

void SubtitleLabel::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit hovered();
}

void SubtitleLabel::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    setStyleSheet("color:red;");

    qInfo()<<"SubtitleLabel:'"<<this->text()<<"' enter event was fired!";

    emit mouseEntered();
}

void SubtitleLabel::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    setStyleSheet("color:white;");
    emit mouseLeaved();
}

