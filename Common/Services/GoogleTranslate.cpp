#include "qtexception.h"
#include "exmessagebox.h"
#include "ITranslateService.h"
#include "NetworkManager.h"
#include "GoogleTranslate.h"
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

bool GoogleTranslate::isLocked() const
{
    return _isLocked;
}

void GoogleTranslate::setLocked(bool isLocked)
{
    _isLocked = isLocked;
}
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
        result="";
        QByteArray resData;
        if(isLocked())
        {
            QString url = getServiceUrl().append(getServiceParams());
            resData = Network::NetworkManager().GET(url);
            if(resData.size())
            {
                result = QString().fromStdString(resData.toStdString());
                QJsonDocument jsonResponse = QJsonDocument::fromJson(result.toUtf8());
                QString transWord = jsonResponse.object().find("sentences").value().toString();
                qInfo()<<"Word: "<<text<<" - translation: "<<transWord;
            }
        }
    }
    catch(QtException ex)
    {
        result = "Error.Connection problem.";
        ExMessageBox(ex,"GoogleTranslate::Translate: "+result).exec();
        setLocked(true);
        return false;
    }

    if(result.isEmpty())
    {
        setLocked(true);
        return false;
    }
    else
    {
        setLocked(false);
        return true;
    }
}

bool GoogleTranslate::isAvailible()
{
    return Network::NetworkManager().isOnline();
}
