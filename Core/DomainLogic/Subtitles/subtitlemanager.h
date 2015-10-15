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
    void updateSubtitles(int position);
private:
    SubtitlePanel *_subPanel;
    SubtitleParser *_subParser;
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
