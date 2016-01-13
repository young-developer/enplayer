#include "GoogleTranslate.h"
#include "commonexception.h"

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
    Network::Request reqUrl;
    reqUrl.setAddress(getServiceUrl());
    reqUrl.addParam("client","qlt");
    reqUrl.addParam("sl","auto");
    reqUrl.addParam("tl","ru");
    reqUrl.addParam("text",text);

    try
    {
        result="";
        QByteArray resData;
        if(isLocked())
        {
            /*QWebView *qWebView = new QWebView();

            QWebPage *page = qWebView->page();
            QNetworkAccessManager *networkManager = new QNetworkAccessManager();
            page->setNetworkAccessManager(networkManager);

            qWebView->setPage(page);

            qWebView->load(QUrl("..."));*/

            QString url = getServiceUrl().append(getServiceParams());
            resData = Network::NetworkManager().GET(reqUrl);
            if(resData.size())
            {
                result = QString().fromStdString(resData.toStdString());
                QJsonDocument jsonResponse = QJsonDocument::fromJson(result.toUtf8());
                QString transWord = jsonResponse.object().find("sentences").value().toString();
                qDebug()<<"Word: "<<text<<" - translation: "<<transWord;
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
