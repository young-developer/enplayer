#ifndef SUBTITLEPANEL_H
#define SUBTITLEPANEL_H

#include <QWidget>
class MainWindow;
class SubtitleLabel;
class SubtitleItem;
class FlowLayout;
class SubtitlePanel : public QWidget
{
    Q_OBJECT
public:
    explicit SubtitlePanel(QWidget *parent = 0, bool isFixed = true);
    QList<SubtitleLabel*> getSubtitles() const;
    void setSubtitles(QList<SubtitleLabel*> subs);
    void panelSizeMove();
    bool isFixed();
    ~SubtitlePanel();
    FlowLayout *getFlowLayout() const;

signals:

public slots:
    void togglePanel();
private:
    bool _fixed;
    QPoint currentDragPosition;
    QSize dragSize;
    QLayout *_flayout;
    QList<SubtitleLabel*> _subtitles;
    QImage *image;
private:
    void Init();
    void renderSubtitles();
    void clearSubtitles();
    void drawPanel();
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
};

#endif // SUBTITLEPANEL_H
