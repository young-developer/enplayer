#ifndef SUBTITLEMANAGER_H
#define SUBTITLEMANAGER_H
#include <QObject>

class SubtitleLabel;
class VlcMediaPlayer;
//class SubtitleParser;
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
    VlcMediaPlayer *_player;
    //SubtitleParser *_subParser;
public:
    void setMediaPlayer(VlcMediaPlayer *player);
    void clearSubtitles();
    void loadSubtitleFile(std::string fileName);
    SubtitleManager(SubtitlePanel *subPanel,VlcMediaPlayer *player);
    ~SubtitleManager(void);
};

#endif // SUBTITLEMANAGER_H
