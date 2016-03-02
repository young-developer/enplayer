#ifndef BINGTRANSLATE_H
#define BINGTRANSLATE_H

#include <QObject>
#include "ITranslateService.h"
class ITranslateService;
class BingTranslate : public ITranslateService
{
public:
    BingTranslate();
    bool Translate(QString text, QString &result);
    bool isAvailible();
};

#endif // BINGTRANSLATE_H
