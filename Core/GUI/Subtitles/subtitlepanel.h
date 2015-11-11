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
    QFont getFont() const;
    void setFont(QFont font);
    unsigned short getOpacity() const;
    void setOpacity(unsigned short opacity);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
signals:
    void mouseEntered();
    void mouseLeaved();
public slots:
    void togglePanel();
private:
    bool _fixed;
    QFont _subFont;
    unsigned short _opacity;
    QPoint _currentDragPosition;
    QSize _dragSize;
    QList<SubtitleLabel*> _subtitles;
private:
    void Init();
    void renderSubtitles();
    void clearSubtitles();
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // SUBTITLEPANEL_H
