#include <vlc-qt/Common.h>
#include <vlc-qt/Instance.h>
#include <vlc-qt/Media.h>
#include <vlc-qt/Video.h>
#include <vlc-qt/MediaPlayer.h>

#include "Subtitles/subtitlepanel.h"
#include "Subtitles/subtitlemanager.h"
#include "controlpanel.h"

#include "enplayer.h"

ENPlayer::ENPlayer(VlcWidgetVideo *videoWidget ,QObject *parent): QObject(parent),
    _media(0)
{
    _instance = new VlcInstance(ENPlayer::args(),this);
    _vlcPlayer = new VlcMediaPlayer(_instance);
    _vlcVideo = new VlcVideo(_vlcPlayer);
    _vlcPlayer->setVideoWidget(videoWidget);
    _subManager = new SubtitleManager(_subPanel);
    videoWidget->setMediaPlayer(vlcPlayer());
    connect(vlcPlayer(),SIGNAL(stateChanged()),SLOT(onStateChanged())) ;
    connect(vlcPlayer(),SIGNAL(positionChanged(float)),_subManager,SLOT(updateSubtitles()));
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

void ENPlayer::onStateChanged()
{
    emit stateChanged(vlcPlayer()->state());
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

void ENPlayer::setControlPanel(ControlPanel *ctrlPanel)
{
    _ctrlPanel = ctrlPanel;
    _ctrlPanel->setMediaPlayer(vlcPlayer());
    connect(_ctrlPanel,SIGNAL(playButtonClicked()),vlcPlayer(),SLOT(togglePause()));
    connect(this,SIGNAL(stateChanged(Vlc::State)),_ctrlPanel,SLOT(onStateChanged(Vlc::State)));
}

void ENPlayer::setSubtitlePanel(SubtitlePanel *subPanel)
{
    _subPanel = subPanel;
    connect(_ctrlPanel,SIGNAL(toggleSubtitlePanel()),_subPanel,SLOT(togglePanel()));
}

void ENPlayer::openFile(QString fileName,bool autoPlay)
{
    _media = new VlcMedia(fileName, true, _instance);
    _vlcPlayer->open(_media);
    if(true == autoPlay)
        _vlcPlayer->play();
}

VlcMediaPlayer *ENPlayer::vlcPlayer() const
{
    return _vlcPlayer;
}
