#include "qtexception.h"
#include "exmessagebox.h"
#include "ITranslateService.h"
#include "NetworkManager.h"
#include "GoogleTranslate.h"
#include <QUrl>

GoogleTranslate::GoogleTranslate()
{
    setName("Google Translate");
    setServiceUrl("http://translate.google.com/translate_a/t?");
    setServiceParams("client=qlt&sl=auto&tl=ru&text=%27hello%27");
}

GoogleTranslate::~GoogleTranslate()
{

}

bool GoogleTranslate::Translate(QString text, QString &result)
{
    setServiceParams("client=qlt&sl=auto&tl=ru&text=%27"+text+"%27");
    try
    {
        result="Ok.Try translate.";
    }
    catch(QtException ex)
    {
        result = "Error.Connection problem.";
        ExMessageBox(ex,"GoogleTranslate::Translate").exec();
        return false;
    }

    if(result!="")
        return true;
    else
        return false;
}

bool GoogleTranslate::isAvailible()
{
    return Network::NetworkManager().isOnline();
}
