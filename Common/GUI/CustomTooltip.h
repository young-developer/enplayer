#ifndef CUSTOMTOOLTIP_H
#define CUSTOMTOOLTIP_H

#include <QLabel>
#include <QObject>
#include <qevent.h>

class CustomTooltip : public QLabel
{
    Q_OBJECT
public:
    ~CustomTooltip();
    explicit CustomTooltip(QWidget *parent = 0);
    void attachTo(QWidget *parent);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
signals:
    void mouseOverParent();
    void mouseOutParent();

};

#endif // CUSTOMTOOLTIP_H
