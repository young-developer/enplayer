#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QObject>
#include <QtWidgets>

class VlcWidgetSeek;
class VlcWidgetVolumeSlider;
class VlcMediaPlayer;
class QPushButton;

class ControlPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlPanel(QWidget *parent = 0);
    void setMediaPlayer(VlcMediaPlayer *player);
    void hidePanel();
    void showPanel();
signals:

public slots:
    void onStateChanged();
    void onPlayButtonClicked();
    void onToggleFullScreen();
private:
    QPushButton *_playButton; //play/pause button
    QPushButton *_toggleFullscreen;
    QPushButton *_toggleSubtitles;
    VlcWidgetSeek *_positionSlider;
    VlcWidgetVolumeSlider *_volumeSlider;
    VlcMediaPlayer *_player;
};

#endif // CONTROLPANEL_H
