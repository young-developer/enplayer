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
            r.setRawHeader( "User-Agent", "Mozilla/5.0 (X11; U; Linux i686 (x86_64); "
                                       "en-US; rv:1.9.0.1) Gecko/2008070206 Firefox/3.0.1" );
            r.setRawHeader( "charset", "utf-8" );
            r.setRawHeader( "Connection", "keep-alive" );
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
