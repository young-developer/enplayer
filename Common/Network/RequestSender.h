#ifndef NETWORK_REQUESTSENDER_H
#define NETWORK_REQUESTSENDER_H
#include<QObject>
#include <QNetworkProxy>

class Request;
namespace Network
{
    class RequestSender : public QObject
    {
        Q_OBJECT
    public:

        enum RequestError
        {
            NoError,
            TimeoutError
        };

        RequestSender(qint64 maxWaitTime = 5000);
        ~RequestSender();

        void setProxy(const QNetworkProxy& proxy);

        QByteArray get(const Request &request);
        QByteArray post(const Request &request);
        QByteArray getWhileSuccess(const Request& request, int maxCount = 2);
        QByteArray postWhileSuccess(const Request& request, int maxCount = 2);

        void setMaxWaitTime(qint64 max);

        qint64 maxWaitTime() const;
        RequestError error() const;

    private:
        QByteArray sendRequest(const Request& request, bool getRequest = true);
        QByteArray sendWhileSuccess(const Request& request, int maxCount = 2, bool getRequest = true);

    private:
        qint64 _maxWaitTime;
        RequestError _error;
        QNetworkProxy _proxy;
    };
}


#endif // NETWORK_REQUESTSENDER_H
