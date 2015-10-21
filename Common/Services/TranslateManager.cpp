#include "ITranslateService.h"
#include "YandexTranslate.h"
#include "GoogleTranslate.h"
#include "BingTranslate.h"
#include "TranslateManager.h"

TranslateManager::TranslateManager()
{
    setDefaultTranslateService(new YandexTranslate());
}

TranslateManager::TranslateManager(ITranslateService* defaultTranslateService)
{
    setDefaultTranslateService(defaultTranslateService);
}

ITranslateService *TranslateManager::defaultTranslateService() const
{
    return _defaultTranslateService;
}

void TranslateManager::setDefaultTranslateService(ITranslateService *defaultTranslateService)
{
    _defaultTranslateService = defaultTranslateService;
}

void TranslateManager::AltTranslate(QString text, QString &result/*out param*/)
{
    foreach(ITranslateService *translator, translateServices())
    {
        if(translator->isAvailible())
        {
            if(translator->Translate(text, result))
                return;
        }
    }
}

void TranslateManager::AddTranslateService(ITranslateService *translateService)
{
    translateServices().push_back(translateService);
}

QList<ITranslateService *> TranslateManager::translateServices() const
{
    return _translateServices;
}

void TranslateManager::Translate(QString text, QString &result)
{
    result = "Error.Try again later.";
    if(!defaultTranslateService()->isAvailible())
    {
        qInfo("%s",defaultTranslateService()->name().append(" translate service is not availiable."));
        AltTranslate(text,result);
    }
    else
    {
        defaultTranslateService()->Translate(text, result);
    }
}

TranslateManager::~TranslateManager()
{
    if(_defaultTranslateService)
        delete _defaultTranslateService;

    foreach(ITranslateService *translator, translateServices())
    {
        if(translator)
            delete translator;
    }
}
