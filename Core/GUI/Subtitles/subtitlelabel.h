#ifndef SUBTITLELABEL_H
#define SUBTITLELABEL_H

#include <QLabel>

class SubtitleLabel : public QLabel
{
    Q_OBJECT
    void Init();
public:
    explicit SubtitleLabel(QWidget *parent = 0);
    SubtitleLabel(QString text, QWidget *parent = 0);
signals:
    void clicked();
    void doubleClicked();
    void hovered();
    void mouseEntered();
    void mouseLeaved();
public slots:

    // QWidget interface
protected:
    void mouseDoubleClickEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *event);

    // QWidget interface
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif // SUBTITLELABEL_H
