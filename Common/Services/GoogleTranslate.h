#ifndef GOOGLETRANSLATE_H
#define GOOGLETRANSLATE_H

#include <QObject>
class ITranslateService;
class FileDownloader;
class GoogleTranslate : public ITranslateService
{
    FileDownloader *_pImgCtrl;
public:
    GoogleTranslate();
    ~GoogleTranslate();
    bool Translate(QString text, QString &result);
    bool isAvailible();
};

#endif // GOOGLETRANSLATE_H
