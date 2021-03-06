#include "CommonException.h"
#include "ITranslateService.h"
#include "NetworkManager.h"
#include "YandexTranslate.h"
#include "Request.h"
#include <QUrl>
#include <QDebug>
#include <QUrl>
#include <QtXml>

YandexTranslate::YandexTranslate()
{
    setName("Yandex");
    setServiceUrl("https://translate.yandex.net/api/v1.5/tr/translate?");
}

 YandexTranslate::~YandexTranslate()
 {

 }

bool YandexTranslate::Translate(QString text, QString &result)
{
    Network::Request reqUrl;
    reqUrl.setAddress(getServiceUrl());
    reqUrl.addParam("key","trnsl.1.1.20141020T114648Z.8c94969d0ac72513.493cab67239ebc6be4623dfcefa8f1cef3a20aa7");
    reqUrl.addParam("lang","ru");
    reqUrl.addParam("text",text);
    try
    {
        result="";
        QByteArray resData;

        resData = Network::NetworkManager().POST(reqUrl);
        if(resData.size())
        {
            qDebug()<<reqUrl.url();
            QDomDocument doc;

            QString data = QString::fromUtf8(resData);
            doc.setContent(data);
            QDomNodeList list=doc.elementsByTagName("text");
            qDebug()<<"Word: "<<text<<" - translate: "<<list.at(0).toElement().text();
            result = list.at(0).toElement().text();
        }
    }
    catch(QtException ex)
    {
        ExMessageBox(ex,"Yandex::Translate: "+result).exec();
        return false;
    }
    return true;
}

bool YandexTranslate::isAvailible()
{
    //YandexTranslate::HelloWorld;
    return true;
}
