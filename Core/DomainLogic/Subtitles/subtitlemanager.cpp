#include "Subtitles/subtitlepanel.h"
#include "Subtitles/subtitlelabel.h"
#include <SubtitleParser.h>
#include <SubtitleParserFactory.h>
#include <QHash>
#include "subtitlemanager.h"

void SubtitleManager::updateSubtitles(int position)
{
    foreach(SubtitleItem *item, _subtitles)
    {
        if(item->getStartTime() <= position && item->getEndTime() >= position )
        {
            _subPanel->setSubtitles(splitSubtitleToWords(item));
        }
    }
}

void SubtitleManager::clearSubtitles()
{
    if(_subParser)
        delete _subParser;

    foreach (SubtitleItem* item, _subtitles) {
        if(item)
            delete item;
    }
}

QList<SubtitleLabel*> SubtitleManager::splitSubtitleToWords(SubtitleItem *sub)
{
    QList<SubtitleLabel*> subWordList;
    foreach(QString word, QString(sub->getText().c_str()).split(" ", QString::SkipEmptyParts))
    {
        subWordList.append(new SubtitleLabel(word));
    }
    return subWordList;
}

void SubtitleManager::loadSubtitleFile(QString fileName)
{
    clearSubtitles();
    SubtitleParserFactory subParserFactory(fileName.toStdString());
    _subParser = subParserFactory.getParser();
    _subtitles = convertToQList(_subParser->getSubtitles());
}

void SubtitleManager::setSubPanel(SubtitlePanel *panel)
{
    _subPanel = panel;
}

QList<SubtitleItem*> SubtitleManager::convertToQList(std::vector<SubtitleItem*> vector)
{
    QList<SubtitleItem *> _QList;
    foreach (SubtitleItem* Item, vector) {
        _QList.push_back(Item);
    }
    return _QList;
}

SubtitleManager::SubtitleManager(QObject *parent):QObject(parent)
{
    _subParser = nullptr;
    _subPanel = nullptr;
}

SubtitleManager::~SubtitleManager()
{
    if(_subParser)
       delete _subParser;
}

