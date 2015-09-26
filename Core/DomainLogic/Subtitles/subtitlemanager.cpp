#include "Subtitles/subtitlepanel.h"
#include <SubtitleParser.h>
#include <SubtitleParserFactory.h>

#include "subtitlemanager.h"

SubtitleManager::SubtitleManager(SubtitlePanel *subPanel, QObject *parent):QObject(parent)
{
    _subPanel = subPanel;
}

void SubtitleManager::updateSubtitles()
{

}

void SubtitleManager::clearSubtitles()
{

}

void SubtitleManager::loadSubtitleFile(std::string fileName)
{
    SubtitleParserFactory subParserFactory(fileName);
    _subParser = subParserFactory.getParser();
}

SubtitleManager::~SubtitleManager()
{
    if(_subParser)
       delete _subParser;
}

