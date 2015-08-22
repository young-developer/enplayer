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
    void updateSubtitles();
    QList<SubtitleLabel*> getSubtitles();
    void setSubtitles(QList<SubtitleLabel*> subs);
signals:

public slots:
    void onResize();
private:
    //SubtitleParser *_parser;
    QPoint currentDragPosition;
    QSize dragSize;
    QList<SubtitleLabel*> _subtitles;
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
};

#endif // SUBTITLEPANEL_H
