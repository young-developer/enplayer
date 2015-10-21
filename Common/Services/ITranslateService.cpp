#include "ITranslateService.h"

QString ITranslateService::name() const
{
    return _name;
}

void ITranslateService::setName(const QString &name)
{
    _name = name;
}

ITranslateService::ITranslateService()
{
}

ITranslateService::~ITranslateService()
{

}
