#include <vlc-qt/Common.h>
#include <vlc-qt/VideoDelegate.h>
#include <vlc-qt/Instance.h>
#include <vlc-qt/Media.h>
#include <vlc-qt/Video.h>
#include <vlc-qt/MediaPlayer.h>

#include "enplayer.h"

ENPlayer::ENPlayer(QObject *parent): QObject(parent),
    _media(0)
{
    _instance = new VlcInstance(ENPlayer::args(),this);
    _vlcPlayer = new VlcMediaPlayer(_instance);
    _vlcVideo = new VlcVideo(_vlcPlayer);
}

ENPlayer::~ENPlayer()
{
    if(_media)
        delete _media;
    if(_vlcVideo)
        delete _vlcVideo;
    if(_vlcPlayer)
        delete _vlcPlayer;
    if(_instance)
        delete _instance;
}

QStringList ENPlayer::args()
{
    QStringList args;

    args << "--intf=dummy"
         << "--no-media-library"
         << "--no-stats"
         << "--no-osd"
         << "--no-sub-autodetect-file"
         << "--no-loop"
         << "--no-video-title-show"
#if defined(Q_OS_DARWIN)
         << "--vout=macosx"
#endif
         << "--drop-late-frames";

    return args;
}

void ENPlayer::openFile(QString fileName)
{
    _media = new VlcMedia(fileName, true, _instance);
    _vlcPlayer->open(_media);
    _vlcPlayer->play();
}

void ENPlayer::setVideoWidget(VlcVideoDelegate *widget)
{
    _vlcPlayer->setVideoWidget(widget);
}

VlcMediaPlayer *ENPlayer::vlcPlayer() const
{
    return _vlcPlayer;
}
