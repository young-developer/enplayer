#include "ITranslateService.h"
#include "YandexTranslate.h"

YandexTranslate::YandexTranslate()
{
    setName("Yandex");
}

bool YandexTranslate::Translate(QString text, QString &result)
{
    result = "translation";
    return true;
}

bool YandexTranslate::isAvailible()
{
    //YandexTranslate::HelloWorld;
    return true;
}
