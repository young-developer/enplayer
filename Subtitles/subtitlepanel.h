#ifndef SUBTITLEPANEL_H
#define SUBTITLEPANEL_H

#include <QWidget>
class MainWindow;
class SubtitleLabel;
class SubtitlePanel : public QWidget
{
    Q_OBJECT
public:
    explicit SubtitlePanel(QWidget *parent = 0);
    void Init();
    void togglePanel();
signals:

public slots:
    void onMouseEnter_Translate();
    void onMouseLeave_Translate();
    void onResize();
private:
    //SubtitleParser *_parser;
    QPoint currentDragPosition;
    QSize dragSize;
    QList<SubtitleLabel*> subtitleWords;
    SubtitleLabel *_label;
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
};

#endif // SUBTITLEPANEL_H
