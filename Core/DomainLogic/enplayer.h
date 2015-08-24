#ifndef ENPLAYER_H
#define ENPLAYER_H

#include <QWidget>

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;
class VlcVideo;
class VlcControlVideo;
class VlcMetaManager;
class VlcVideoDelegate;

class ENPlayer : public QObject
{
    Q_OBJECT
public:
    explicit ENPlayer(QObject *parent = 0);
    ~ENPlayer();
private:
    QStringList ENPlayer::args();
    VlcInstance *_instance;
    VlcVideo *_vlcVideo;
    VlcMedia *_media;
public:
    void openFile(QString fileName);
    VlcMediaPlayer *_vlcPlayer;
    void setVideoWidget(VlcVideoDelegate *widget);
    VlcMediaPlayer *vlcPlayer() const;
};

#endif // ENPLAYER_H
