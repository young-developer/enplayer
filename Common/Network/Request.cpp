#include <QtNetwork>
#include "Request.h"

namespace Network
{

    Request::Request(QString address /*= QString()*/)
    {
        setAddress(address);
    }

    QString Request::address() const
    {
        return _address;
    }

    void Request::setAddress(QString address)
    {
        for (QPair<QString, QString> value : QUrlQuery(QUrl(address)).queryItems())
            addParam(value.first, value.second);
        _address = address;
    }

    void Request::addParam(QString name, QVariant value)
    {
        _params[name] = value.toString();
    }

    bool Request::removeParam(QString name)
    {
        if (false == _params.contains(name))
            return false;
        _params.remove(name);
        return true;
    }

    QStringList Request::paramsNames() const
    {
        return _params.keys();
    }

    QMap<QString, QString> Request::params() const
    {
        return _params;
    }

    QUrl Request::url(bool forGetRequest /*= true*/) const
    {
        QUrl url(address());
        if (forGetRequest)
            url.setQuery(data());
        return url;
    }

    QNetworkRequest Request::request(bool forGetRequest /*= true*/) const
    {
        QNetworkRequest r(url(forGetRequest));

        if (!forGetRequest)
        {
            r.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
            r.setRawHeader("User-Agent" ,"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.2 (KHTML, like Gecko) Chrome/15.0.874.121 Safari/535.2");
        }
        else
        {
            r.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
            r.setRawHeader("User-Agent" ,"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.2 (KHTML, like Gecko) Chrome/15.0.874.121 Safari/535.2");
        }

        return r;
    }

    QByteArray Request::data() const
    {
        auto b = _params.begin();
        auto e = _params.end();

        QByteArray byteArrayData;

        while (b != e)
        {
            byteArrayData.append(b.key());
            byteArrayData.append('=');
            byteArrayData.append(b.value());
            byteArrayData.append('&');

            b++;
        }

        byteArrayData.chop(1);

        return byteArrayData;
    }

}
