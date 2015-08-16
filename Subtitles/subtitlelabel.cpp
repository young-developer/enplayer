#include "Subtitles/subtitlelabel.h"
#include <QDebug>

SubtitleLabel::SubtitleLabel(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);
}

void SubtitleLabel::mouseDoubleClickEvent(QMouseEvent *)
{
    emit doubleClicked();
}

void SubtitleLabel::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}

void SubtitleLabel::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit hovered();
}

void SubtitleLabel::enterEvent(QEvent *)
{
    emit mouseEntered();
}

void SubtitleLabel::leaveEvent(QEvent *)
{
    emit mouseLeaved();
}

