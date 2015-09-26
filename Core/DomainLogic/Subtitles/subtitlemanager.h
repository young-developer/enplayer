#ifndef SUBTITLEMANAGER_H
#define SUBTITLEMANAGER_H
#include <QObject>

class SubtitleParser;
class SubtitlePanel;

class SubtitleManager : public QObject
{
    Q_OBJECT
signals:

public slots:
    void updateSubtitles();
private:
    SubtitleManager();
    SubtitlePanel *_subPanel;
    SubtitleParser *_subParser;
public:
    void clearSubtitles();
    void loadSubtitleFile(std::string fileName);
    SubtitleManager(SubtitlePanel *subPanel,QObject *parent = 0);
    ~SubtitleManager(void);
};

#endif // SUBTITLEMANAGER_H
