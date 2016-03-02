#include "subtitlemanager.h"
#include "commonexception.h"

void SubtitleManager::updateSubtitles(int position)
{
    foreach(SubtitleItem *item, _subtitles)
    {
        if(item->getStartTime() <= position && item->getEndTime() >= position )
        {
            QString currentSubText(item->getText().c_str());
            currentSubText.replace("\n"," ");
            if(_subPanel->getSubtitlesAsString().simplified() != currentSubText.simplified() && !currentSubText.simplified().isEmpty())
            {
                _subPanel->setSubtitles(splitSubtitleToWords(item));
                qDebug()<<"Subtitle were created!"<<_subPanel->getSubtitlesAsString();
            }
        }
    }
}

void SubtitleManager::Translate()
{
    if(sender()!=nullptr)
    {
        QPointer<SubtitleLabel> label = static_cast<SubtitleLabel*>(sender());
        QString result = "Error.Try again later.";
        bool isTranslated = false;
        if(_translateMgr)
            isTranslated = _translateMgr->Translate(label->text(),result/*out*/);

        if(isTranslated)
        {
            if(label)
            {
                label->setToolTip(result);
                /*CustomTooltip *toolTip = new CustomTooltip();
                toolTip->attachTo(label);
                toolTip->setText(result);
                toolTip->show();*/
            }
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
    foreach(QString word, QString(sub->getText().c_str()).replace("\n"," ").split(" ", QString::SkipEmptyParts))
    {
        subWordList.append(new SubtitleLabel(word.simplified()));
        //qInfo()<<word;
    }
    //connect TranslateManager
    foreach(SubtitleLabel *subLabel,subWordList)
    {
        connect(subLabel,SIGNAL(clicked()),SLOT(Translate()));
    }

    return subWordList;
}

void SubtitleManager::loadSubtitleFile(QString fileName)
{
    clearSubtitles();
    try
    {
        SubtitleParserFactory subParserFactory(fileName.toStdString());
        _subParser = subParserFactory.getParser();
        _subtitles = convertToQList(_subParser->getSubtitles());
    }
    catch(std::exception ex)
    {
        throw QtException(ExceptionType::Error,ex.what());
    }
}

void SubtitleManager::setSubPanel(SubtitlePanel *panel)
{
    _subPanel = panel;
}

QList<SubtitleItem*> SubtitleManager::convertToQList(std::vector<SubtitleItem*> vector)
{
    QList<SubtitleItem *> _QList;
    foreach (SubtitleItem* item, vector) {
        _QList.push_back(item);
    }
    return _QList;
}

SubtitleManager::SubtitleManager(QObject *parent):QObject(parent)
{
    _subParser = nullptr;
    _subPanel = nullptr;
    _translateMgr = new TranslateManager();
}

SubtitleManager::~SubtitleManager()
{
    if(_subParser)
       delete _subParser;
    if(_translateMgr)
        delete _translateMgr;
}

