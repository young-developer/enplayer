#ifndef ENPLAYER_H
#define ENPLAYER_H

#include <QWidget>
#include <vlc-qt/WidgetVideo.h>
class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;
class VlcVideo;
class VlcControlVideo;
class VlcMetaManager;
class VlcWidgetVideo;
class ControlPanel;
class SubtitlePanel;
class SubtitleManager;

class ENPlayer : public QObject
{
    Q_OBJECT
public:
    explicit ENPlayer(VlcWidgetVideo *videoWidget,QObject *parent = 0);
    ~ENPlayer();
private:
    SubtitlePanel *_subPanel;
    ControlPanel *_ctrlPanel;
    VlcMediaPlayer *_vlcPlayer;
    VlcInstance *_instance;
    VlcVideo *_vlcVideo;
    VlcMedia *_media;
    SubtitleManager *_subManager;
signals:
    void stateChanged(Vlc::State);
public slots:
    void onStateChanged();
private:
    QStringList args();
public:
    void setControlPanel(ControlPanel *ctrlPanel);
    void setSubtitlePanel(SubtitlePanel *subPanel);
    void openFile(QString fileName, bool autoPlay = true);

    VlcMediaPlayer *vlcPlayer() const;
};

#endif // ENPLAYER_H
