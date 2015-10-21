#ifndef TRANSLATESERVICE_H
#define TRANSLATESERVICE_H

#include <QObject>

class TranslateManager
{
private:
    ITranslateService *_defaultTranslateService;
    QList<ITranslateService *> _translateServices;
    void AddTranslateService(ITranslateService *translateService);
    void AltTranslate(QString text, QString &result);
public:
    void Translate(QString text, QString &result/*out param*/);
    TranslateManager();
    TranslateManager(ITranslateService *defaultTranslateService);
    ~TranslateManager();

    ITranslateService *defaultTranslateService() const;
    void setDefaultTranslateService(ITranslateService *defaultTranslateService);
    QList<ITranslateService *> translateServices() const;
};

#endif // TRANSLATESERVICE_H
