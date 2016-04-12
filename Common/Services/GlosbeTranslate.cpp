#include "CommonException.h"
#include "ITranslateService.h"
#include "NetworkManager.h"
#include "GlosbeTranslate.h"
#include "Request.h"
#include <QUrl>
#include <QDebug>
#include <QUrl>
#include <QtXml>

GlosbeTranslate::GlosbeTranslate()
{
    setName("Glosbe");
    setServiceUrl("https://glosbe.com/gapi/translate?");
}

GlosbeTranslate::~GlosbeTranslate()
{

}

bool GlosbeTranslate::Translate(QString text, QString &result)
{
    Network::Request reqUrl;
    reqUrl.setAddress(getServiceUrl());
    reqUrl.addParam("from","eng");
    reqUrl.addParam("dest","rus");
    reqUrl.addParam("format","json");
    reqUrl.addParam("pretty","true");//pretty output
    reqUrl.addParam("phrase",text);
    try
    {
        result="";
        QByteArray resData;

        resData = Network::NetworkManager().POST(reqUrl);
        if(resData.size())
        {
            qDebug()<<reqUrl.url();
            qDebug()<<resData;
        }
    }
    catch(QtException ex)
    {
        ExMessageBox(ex,"Yandex::Translate: "+result).exec();
        return false;
    }
    return true;
}

bool GlosbeTranslate::isAvailible()
{
    //YandexTranslate::HelloWorld;
    return true;
}
