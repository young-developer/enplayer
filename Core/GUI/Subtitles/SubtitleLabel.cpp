#include "SubtitleLabel.h"

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

void SubtitleLabel::setToolTip(const QString &text)
{
    QString trText = "";
    if(isTranslated())
    {
        trText = getTranslatedText();
    }
    else
    {
        trText = translatedText = text;
    }

    QToolTip::showText(QWidget::mapToGlobal(this->rect().topRight()),trText,this,this->rect(),100000);
}

void SubtitleLabel::Init()
{
    setMouseTracking(true);
    QFont serifFont("Arial", 14, QFont::Normal);
    setFont(serifFont);
    toolTip = new CustomTooltip(this);
    connect(toolTip,SIGNAL(mouseOverParent()),this,SLOT(hideTooltip()));
    hideTooltip();
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

    qDebug()<<"SubtitleLabel:'"<<this->text()<<"' enter event was fired!";

    emit mouseEntered();
}

void SubtitleLabel::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    setStyleSheet("color:white;");
    emit mouseLeaved();
}

bool SubtitleLabel::isTranslated()
{
    return !getTranslatedText().isEmpty();
}

void SubtitleLabel::showCustomTooltip()
{
    QToolTip::showText(QWidget::mapToGlobal(this->rect().topRight()),getTranslatedText(),this,this->rect(),100000);
}

void SubtitleLabel::hideTooltip()
{
    QToolTip::hideText();
    qDebug()<<"tooltip text ="<<toolTip->text();
}

void SubtitleLabel::setTranslatedText(const QString &text)
{
    translatedText = text;
}

QString SubtitleLabel::getTranslatedText() const
{
    return translatedText;
}

