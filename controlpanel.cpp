#include <QPushButton>
#include "vlc-qt/WidgetSeek.h"
#include "vlc-qt/WidgetVolumeSlider.h"
#include <vlc-qt/MediaPlayer.h>
#include "vlc-qt/WidgetVideo.h"
#include "controlpanel.h"
#include "mainwindow.h"

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent),
    _playButton(0),
    _positionSlider(0),
    _volumeSlider(0),
    _toggleFullscreen(0),
    _toggleSubtitles(0),
    _player(0)
{
    _playButton = new QPushButton(this);
    _positionSlider = new VlcWidgetSeek(this);
    _volumeSlider = new VlcWidgetVolumeSlider(this);
    _toggleSubtitles = new QPushButton(this);
    _toggleFullscreen = new QPushButton(this);

    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->addWidget(_playButton);
    hlayout->addWidget(_positionSlider);
    hlayout->addWidget(_volumeSlider);
    hlayout->addWidget(_toggleSubtitles);
    hlayout->addWidget(_toggleFullscreen);
    this->setLayout(hlayout);

    _playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    _toggleSubtitles->setIcon(style()->standardIcon(QStyle::SP_TitleBarMinButton));
    _toggleFullscreen->setIcon(style()->standardIcon(QStyle::SP_TitleBarMaxButton));

    connect(_playButton,SIGNAL(clicked(bool)),SLOT(onPlayButtonClicked()));
    connect(_toggleFullscreen,SIGNAL(clicked(bool)),SLOT(onToggleFullScreen()));
    this->_volumeSlider->setVolume(50);
    this->_toggleSubtitles->setDisabled(true);
    this->setMinimumHeight(30);
    this->setMaximumHeight(40);
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
    _playButton->hide();
    _positionSlider->hide();
    _volumeSlider->hide();
    _toggleFullscreen->hide();
    _toggleSubtitles->hide();
    this->hide();
}

void ControlPanel::showPanel()
{
    _playButton->show();
    _positionSlider->show();
    _volumeSlider->show();
    _toggleFullscreen->show();
    _toggleSubtitles->show();
    this->show();
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

void ControlPanel::onToggleFullScreen()
{
    static_cast<MainWindow*>(parentWidget()->parentWidget())->toggleFullScreen();
}

