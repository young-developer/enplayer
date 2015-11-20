#ifndef YANDEXTRANSLATE_H
#define YANDEXTRANSLATE_H

#include <QObject>
class ITranslateService;
class QWebView;
class YandexTranslate : public ITranslateService
{
private:
public:
    YandexTranslate();
    ~YandexTranslate();
    virtual bool Translate(QString text,QString &result);
    virtual bool isAvailible();
};

#endif // YANDEXTRANSLATE_H
