#ifndef BINGTRANSLATE_H
#define BINGTRANSLATE_H

#include <QObject>
class ITranslateService;
class BingTranslate : public ITranslateService
{
public:
    BingTranslate();
    bool Translate(QString text, QString &result);
};

#endif // BINGTRANSLATE_H
