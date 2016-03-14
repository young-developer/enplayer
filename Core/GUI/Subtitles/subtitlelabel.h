#ifndef SUBTITLELABEL_H
#define SUBTITLELABEL_H

#include <QLabel>
#include <QDebug>
#include "CustomTooltip.h"

class SubtitleItem;
class CustomTooltip;
class SubtitleLabel : public QLabel
{
    Q_OBJECT
    void Init();
public:
    explicit SubtitleLabel(QWidget *parent = 0);
    explicit SubtitleLabel(QString text, QWidget *parent = 0);
    void setToolTip(const QString &text);
    bool isTranslated();
signals:
    void clicked();
    void doubleClicked();
    void hovered();
    void mouseEntered();
    void mouseLeaved();
public slots:
    void showTooltip();
    void hideTooltip();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
private:
    CustomTooltip *toolTip;
    QString translatedText;
    void setTranslatedText(const QString &text);
    QString getTranslatedText() const;
};

#endif // SUBTITLELABEL_H
