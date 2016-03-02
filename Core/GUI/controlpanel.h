#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QObject>
#include <QtWidgets>
#include "vlc-qt/WidgetVideo.h"
#include "vlc-qt/WidgetSeek.h"
#include "vlc-qt/WidgetVolumeSlider.h"
#include <vlc-qt/MediaPlayer.h>
#include "Subtitles/subtitlepanel.h"

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
    void toggleFullScreen();
    void toggleSubtitlePanel();
    void playButtonClicked();
    void stopButtonClicked();
public slots:
    void onStateChanged(Vlc::State state);
    void onToggleSubtitlesBtnClicked();
    void onPlayButtonClicked();
    void onToggleFullScreenBtnClicked();
    void onStopButtonClicked();
private:
    QPushButton *_playButton; //play/pause button
    QPushButton *_stopButton;
    QPushButton *_toggleFullscreen;
    QPushButton *_toggleSubtitles;
    VlcWidgetSeek *_positionSlider;
    VlcWidgetVolumeSlider *_volumeSlider;
};

#endif // CONTROLPANEL_H
