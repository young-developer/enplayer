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
    toolTip->setText(trText);
    toolTip->show();
    if(!toolTip->isVisible())
    {
        qWarning()<<"Warning: Show default tooltip!";
        QLabel::setToolTip(trText);
    }
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

void SubtitleLabel::showTooltip()
{
    toolTip->show();
}

void SubtitleLabel::hideTooltip()
{
    toolTip->hide();
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

