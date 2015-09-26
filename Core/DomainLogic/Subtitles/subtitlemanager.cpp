#include "Subtitles/subtitlepanel.h"
#include "Subtitles/subtitlelabel.h"
#include <SubtitleParser.h>
#include <SubtitleParserFactory.h>

#include "subtitlemanager.h"

SubtitleManager::SubtitleManager(SubtitlePanel *subPanel, QObject *parent):QObject(parent)
{
    _subPanel = subPanel;
}

void SubtitleManager::updateSubtitles(float position)
{
    SubtitleLabel *label = new SubtitleLabel(QString::number(position));
    QList<SubtitleLabel *> _subs;
    _subs.push_back(label);
    _subPanel->setSubtitles(_subs);
}

void SubtitleManager::clearSubtitles()
{

}

void SubtitleManager::loadSubtitleFile(QString fileName)
{
    SubtitleParserFactory subParserFactory(fileName.toStdString());
    if(_subParser)
        delete _subParser;
    _subParser = subParserFactory.getParser();
    QList<SubtitleItem *> _subItemList = convertToQList(_subParser->getSubtitles());
    SubtitleLabel *label = new SubtitleLabel(QString(_subItemList[0]->getText().c_str()));
    QList<SubtitleLabel *> _subs;
    _subs.push_back(label);
    _subPanel->setSubtitles(_subs);
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

