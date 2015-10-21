#ifndef YANDEXTRANSLATE_H
#define YANDEXTRANSLATE_H

#include <QObject>
class ITranslateService;
class YandexTranslate : public ITranslateService
{
public:
    YandexTranslate();
    virtual bool Translate(QString text,QString &result);
    virtual bool isAvailible();
};

#endif // YANDEXTRANSLATE_H
