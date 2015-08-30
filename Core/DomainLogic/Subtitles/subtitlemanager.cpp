#include <vlc-qt/MediaPlayer.h>
#include "Subtitles/subtitlelabel.h"
#include "Subtitles/subtitlepanel.h"
#include "subtitlemanager.h"

SubtitleManager::SubtitleManager(SubtitlePanel *subPanel, VlcMediaPlayer *player)
{
    _player = player;
    _subPanel = subPanel;
    connect(_player,SIGNAL(positionChanged(float)),SLOT(updateSubtitles()));
}


void SubtitleManager::setMediaPlayer(VlcMediaPlayer *player)
{
    _player = player;
}

void SubtitleManager::clearSubtitles()
{
    foreach(SubtitleLabel *sub, _subPanel->getSubtitles())
    {
        delete sub;
    }
    _subPanel->getSubtitles().clear();
}

void SubtitleManager::loadSubtitleFile(std::string fileName)
{
    //SubtitleParserFactory subParserFactory(fileName);
    //_subParser = subParserFactory.getParser();
}

SubtitleManager::~SubtitleManager()
{
    //if(_subParser)
       // delete _subParser;
}

