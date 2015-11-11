#ifndef NETWORK_REQUEST_H
#define NETWORK_REQUEST_H
#include <QObject>
#include <QMap>
class QNetworkRequest;
namespace Network
{
    class Request
    {
    public:
        Request(QString address = QString());

        QString address() const;
        void setAddress(QString address);

        void addParam(QString name, QVariant value);
        bool removeParam(QString name);

        QStringList paramsNames() const;
        QMap<QString, QString> params() const;

        QUrl url(bool withParams = true) const;
        QNetworkRequest request(bool withParams = true) const;
        QByteArray data() const;

    private:
        QString _address;
        QMap<QString, QString> _params;
    };
}

#endif // NETWORK_REQUEST_H
