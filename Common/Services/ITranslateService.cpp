#include "ITranslateService.h"

QString ITranslateService::name() const
{
    return _name;
}


QString ITranslateService::getServiceParams() const
{
    return _params;
}

void ITranslateService::setServiceParams(const QString &params)
{
    _params = params;
}
void ITranslateService::setName(const QString &name)
{
    _name = name;
}

QString ITranslateService::getServiceUrl() const
{
    return _url;
}

void ITranslateService::setServiceUrl(const QString &url)
{
    _url = url;
}
ITranslateService::ITranslateService()
{
}

ITranslateService::~ITranslateService()
{

}
