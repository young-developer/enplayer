#ifndef GOOGLETRANSLATE_H
#define GOOGLETRANSLATE_H

#include <QObject>
class ITranslateService;
class FileDownloader;
class GoogleTranslate : public ITranslateService
{
    FileDownloader *_pImgCtrl;
    bool _isLocked;
public:
    GoogleTranslate();
    ~GoogleTranslate();
    bool Translate(QString text, QString &result);
    bool isAvailible();
    bool isLocked() const;
    void setLocked(bool isLocked);
};

#endif // GOOGLETRANSLATE_H
