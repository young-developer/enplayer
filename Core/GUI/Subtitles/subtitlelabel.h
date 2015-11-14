#ifndef SUBTITLELABEL_H
#define SUBTITLELABEL_H

#include <QLabel>

class SubtitleItem;

class SubtitleLabel : public QLabel
{
    Q_OBJECT
    void Init();
public:
    explicit SubtitleLabel(QWidget *parent = 0);
    explicit SubtitleLabel(QString text, QWidget *parent = 0);
    explicit SubtitleLabel(SubtitleItem *item, QWidget *parent = 0);
signals:
    void clicked();
    void doubleClicked();
    void hovered();
    void mouseEntered();
    void mouseLeaved();
public slots:

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
private:
    SubtitleItem* _subItem;
};

#endif // SUBTITLELABEL_H
