#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QObject>
#include <QtWidgets>

class VlcWidgetSeek;
class VlcWidgetVolumeSlider;
class VlcMediaPlayer;
class QPushButton;
class SubtitlePanel;

class ControlPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlPanel(QWidget *parent = 0);
    void setMediaPlayer(VlcMediaPlayer *player);
    void setSubtitlePanel(SubtitlePanel *subPanel);
    void hidePanel();
    void showPanel();
signals:
    void toggleFullScreen();
public slots:
    void onStateChanged();
    void onToggleSubtitlesBtnClicked();
    void onPlayButtonClicked();
    void onToggleFullScreenBtnClicked();
private:
    QPushButton *_playButton; //play/pause button
    QPushButton *_toggleFullscreen;
    QPushButton *_toggleSubtitles;
    VlcWidgetSeek *_positionSlider;
    VlcWidgetVolumeSlider *_volumeSlider;
    VlcMediaPlayer *_player;
    SubtitlePanel *_subPanel;
};

#endif // CONTROLPANEL_H
