#include "EnPlayer.h"
#include "CommonException.h"

ENPlayer::ENPlayer(VlcWidgetVideo *videoWidget ,QObject *parent): QObject(parent),
    _media(0)
{
    Init(videoWidget);
}

void ENPlayer::Init(VlcWidgetVideo *videoWidget)
{
    _instance = new VlcInstance(ENPlayer::args(),this);
    _vlcPlayer = new VlcMediaPlayer(_instance);
    _vlcVideo = new VlcVideo(vlcPlayer());
    vlcPlayer()->setVideoWidget(videoWidget);
    videoWidget->setMediaPlayer(vlcPlayer());
    _subManager = new SubtitleManager();
    connect(vlcPlayer(),SIGNAL(timeChanged(int)),_subManager,SLOT(updateSubtitles(int)));
    connect(vlcPlayer(),SIGNAL(stateChanged()),SLOT(onStateChanged())) ;
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
#if defined(Q_OS_MAC)
         << "--vout=macosx"
#endif
         << "--drop-late-frames";

    return args;
}

void ENPlayer::refreshFrame()
{
     vlcPlayer()->videoWidget()->request();
}

void ENPlayer::setControlPanel(ControlPanel *ctrlPanel)
{
    _ctrlPanel = ctrlPanel;
    _ctrlPanel->setMediaPlayer(vlcPlayer());
    connect(_ctrlPanel,SIGNAL(playButtonClicked()),this,SLOT(tooglePlayPause()));
    connect(_ctrlPanel,SIGNAL(stopButtonClicked()),this,SLOT(stop()));
    connect(this,SIGNAL(stateChanged(Vlc::State)),_ctrlPanel,SLOT(onStateChanged(Vlc::State)));
}

void ENPlayer::setSubtitlePanel(SubtitlePanel *subPanel)
{
    _subPanel = subPanel;
    _subManager->setSubPanel(_subPanel);
    connect(_ctrlPanel,SIGNAL(toggleSubtitlePanel()),_subPanel,SLOT(togglePanel()));
    connect(_subPanel,SIGNAL(mouseEntered()),vlcPlayer(),SLOT(pause()));
    connect(_subPanel,SIGNAL(mouseLeaved()),vlcPlayer(),SLOT(play()));
}

void ENPlayer::openFile(QString fileName,bool autoPlay)
{
    _media = new VlcMedia(fileName, true, _instance);
    vlcPlayer()->open(_media);
    if(true == autoPlay)
        vlcPlayer()->play();
    clearSubtitles();
}

void ENPlayer::addSubtitles(QString fileName)
{
    _subManager->loadSubtitleFile(fileName);
    _subPanel->show();
}

void ENPlayer::clearSubtitles()
{
    _subManager->clearSubtitles();
    _subPanel->hide();
}

void ENPlayer::play()
{
    if(vlcPlayer()->state()== Vlc::State::Paused)
        vlcPlayer()->play();
}

void ENPlayer::pause()
{
    if(vlcPlayer()->state()== Vlc::State::Playing)
     vlcPlayer()->pause();
}

void ENPlayer::tooglePlayPause()
{
    (vlcPlayer()->state()== Vlc::State::Playing)?pause():play();
}

void ENPlayer::stop()
{
    if(vlcPlayer()->state()!= Vlc::State::Stopped)
         vlcPlayer()->stop();
    clearSubtitles();
}

VlcMediaPlayer *ENPlayer::vlcPlayer() const
{
    if(_vlcPlayer!=nullptr)
        return _vlcPlayer;
    else
        return nullptr;
}
