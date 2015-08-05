#include <QPushButton>
#include "vlc-qt/WidgetSeek.h"
#include "vlc-qt/WidgetVolumeSlider.h"
#include <vlc-qt/MediaPlayer.h>
#include "vlc-qt/WidgetVideo.h"
#include "controlpanel.h"

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent),
    _playButton(0),
    _positionSlider(0),
    _volumeSlider(0),
    _toogleFullscreen(0),
    _toogleSubtitles(0),
    _player(0)
{
    _playButton = new QPushButton(this);
    _positionSlider = new VlcWidgetSeek(this);
    _volumeSlider = new VlcWidgetVolumeSlider(this);
    _toogleSubtitles = new QPushButton(this);
    _toogleFullscreen = new QPushButton(this);

    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->addWidget(_playButton);
    hlayout->addWidget(_positionSlider);
    hlayout->addWidget(_volumeSlider);
    hlayout->addWidget(_toogleSubtitles);
    hlayout->addWidget(_toogleFullscreen);
    this->setLayout(hlayout);

    _playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    _toogleSubtitles->setIcon(style()->standardIcon(QStyle::SP_TitleBarMinButton));
    _toogleFullscreen->setIcon(style()->standardIcon(QStyle::SP_TitleBarMaxButton));

    connect(_playButton,SIGNAL(clicked(bool)),SLOT(onPlayButtonClicked()));
    connect(_toogleFullscreen,SIGNAL(clicked(bool)),SLOT(onToogleFullScreen()));
    this->_volumeSlider->setVolume(50);
    this->_toogleSubtitles->setDisabled(true);
    this->setMinimumHeight(30);
    this->setMaximumHeight(60);
}

void ControlPanel::setMediaPlayer(VlcMediaPlayer *player)
{
    _positionSlider->setMediaPlayer(player);
    _volumeSlider->setMediaPlayer(player);
    _player = player;
    connect(_player,SIGNAL(stateChanged()),SLOT(onStateChanged()));
}

void ControlPanel::hidePanel()
{

}

void ControlPanel::showPanel()
{

}

void ControlPanel::onStateChanged()
{
    switch(_player->state())
    {
        case Vlc::State::Playing:
            _playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
            break;
        default:
            _playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            break;
    }
}

void ControlPanel::onPlayButtonClicked()
{
    _player->togglePause();
    qInfo()<<"onPlayButtonClicked::togglePause";
}

void ControlPanel::onToogleFullScreen()
{
    switch(windowState())
    {
        case Qt::WindowFullScreen:
            qInfo()<<"onToogleFullScreen::Normal mode";
            break;
        default:
            qInfo()<<"onToogleFullScreen::Fullscreen mode";
        break;
    }
}

