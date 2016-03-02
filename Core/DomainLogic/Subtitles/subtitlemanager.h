#ifndef SUBTITLEMANAGER_H
#define SUBTITLEMANAGER_H
#include <QObject>
#include "TranslateManager.h"
#include "Subtitles/subtitlepanel.h"
#include "Subtitles/subtitlelabel.h"
#include <SubtitleParser.h>
#include <SubtitleParserFactory.h>
#include "customtooltip.h"
#include <QHash>
#include <QPointer>

class SubtitleParser;
class SubtitlePanel;
class SubtitleLabel;
class SubtitleItem;
class TranslateManager;

class SubtitleManager : public QObject
{
    Q_OBJECT
signals:

public slots:
    void updateSubtitles(int position);
    void Translate();
private:
    SubtitlePanel *_subPanel;
    SubtitleParser *_subParser;
    TranslateManager *_translateMgr;
    QList<SubtitleItem *> _subtitles;
private:
    QList<SubtitleItem *> convertToQList(std::vector<SubtitleItem *> vector);
    QList<SubtitleLabel *> splitSubtitleToWords(SubtitleItem *sub);

public:
    void clearSubtitles();
    void loadSubtitleFile(QString fileName);
    void setSubPanel(SubtitlePanel* panel);
    SubtitleManager(QObject *parent = 0);
    ~SubtitleManager(void);
};

#endif // SUBTITLEMANAGER_H
