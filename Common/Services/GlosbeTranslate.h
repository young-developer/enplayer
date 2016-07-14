#ifndef GLOSBETRANSLATE_H
#define GLOSBETRANSLATE_H

#include <QObject>

class GlosbeTranslate : public ITranslateService
{
public:
    GlosbeTranslate();
    bool Translate(QString text, QString &result);
    bool isAvailible();
    ~GlosbeTranslate();
};

#endif // GLOSBETRANSLATE_H
