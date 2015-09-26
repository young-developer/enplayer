#ifndef SUBTITLEMANAGER_H
#define SUBTITLEMANAGER_H
#include <QObject>

class SubtitleParser;
class SubtitlePanel;
class SubtitleLabel;
class SubtitleItem;
class SubtitleManager : public QObject
{
    Q_OBJECT
signals:

public slots:
    void updateSubtitles(float position);
private:
    SubtitlePanel *_subPanel;
    SubtitleParser *_subParser;
public:
    void clearSubtitles();
    void loadSubtitleFile(QString fileName);
    void setSubPanel(SubtitlePanel* panel);
    SubtitleManager(QObject *parent = 0);
    SubtitleManager(SubtitlePanel *subPanel,QObject *parent = 0);
    ~SubtitleManager(void);
    QList<SubtitleItem *> convertToQList(std::vector<SubtitleItem *> vector);
};

#endif // SUBTITLEMANAGER_H
