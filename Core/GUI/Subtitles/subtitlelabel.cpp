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
    setToolTip("TEST TOOLTIP");
    QFont serifFont("Arial", 14, QFont::Normal);
    setFont(serifFont);
}

void SubtitleLabel::mouseDoubleClickEvent(QMouseEvent *)
{
    emit doubleClicked();
}

void SubtitleLabel::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}

void SubtitleLabel::mouseMoveEvent(QMouseEvent *)
{
    //Q_UNUSED(event);
    emit hovered();
}

void SubtitleLabel::enterEvent(QEvent *)
{
    setStyleSheet("color:red;");
    emit mouseEntered();
}

void SubtitleLabel::leaveEvent(QEvent *)
{
    setStyleSheet("color:white;");
    emit mouseLeaved();
}

