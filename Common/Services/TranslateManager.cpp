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

bool TranslateManager::AltTranslate(QString text, QString &result/*out param*/)
{
    foreach(ITranslateService *translator, translateServices())
    {
        if(translator->isAvailible())
        {
            if(translator->Translate(text, result))
                return true;
        }
    }
    return false;
}

void TranslateManager::AddTranslateService(ITranslateService *translateService)
{
    translateServices().push_back(translateService);
}

QList<ITranslateService *> TranslateManager::translateServices() const
{
    return _translateServices;
}

bool TranslateManager::Translate(QString text, QString &result)
{
    result = "Error.Check your internet conection.";
    if(!defaultTranslateService()->isAvailible())
    {
        qInfo("%s",defaultTranslateService()->name().append(" translate service is not availiable."));
        return AltTranslate(text,result);
    }
    else
    {
        return defaultTranslateService()->Translate(text, result);
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
