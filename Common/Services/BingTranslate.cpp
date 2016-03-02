#include "qtexception.h"
#include "exmessagebox.h"
#include "ITranslateService.h"
#include "NetworkManager.h"
#include "BingTranslate.h"
#include "request.h"
#include <QUrl>
#include <QDebug>
#include <QUrl>
#include <QtXml>

BingTranslate::BingTranslate()
{
    setName("Bing");
    setServiceUrl("http://api.microsofttranslator.com/v1/soap.svc/LanguageService/Translate");
}

bool BingTranslate::Translate(QString text, QString &result)
{
    Network::Request reqUrl;
    reqUrl.setAddress(getServiceUrl());
    reqUrl.addParam("key","XG/1/slkXSdfE9Ngltb7/UAAMJ6g4RQORkzcP7dMZRg");
    reqUrl.addParam("lang","ru");
    reqUrl.addParam("text",text);
    try
    {
        result="";
        QByteArray resData;
        resData = Network::NetworkManager().GET(reqUrl);
        if(resData.size())
        {
            qDebug()<<reqUrl.url();
            QDomDocument doc;
            QString data = QString::fromUtf8(resData);
            doc.setContent(data);
            QDomNodeList list=doc.elementsByTagName("text");

            qDebug()<<"Word: "<<text<<" - translation: "<<QString::fromUtf8(list.at(0).toElement().text().toUtf8());
        }
    }
    catch(QtException ex)
    {
        ExMessageBox(ex,"Yandex::Translate: "+result).exec();
        return false;
    }
    return true;
}

bool BingTranslate::isAvailible()
{
    //BingTranslate::HelloWorld;
    return true;
}
