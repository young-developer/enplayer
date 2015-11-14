#include <QtNetwork>

#include "Request.h"
#include "RequestSender.h"
#include "qtexception.h"

namespace Network
{
    RequestSender::RequestSender(qint64 maxWaitTime /*= 5000*/)//maxWaitTime 5sec
    {
        setMaxWaitTime(maxWaitTime);
        _error = NoError;
    }

    RequestSender::~RequestSender()
    {

    }

    void RequestSender::setProxy(const QNetworkProxy& proxy)
    {
        _proxy = proxy;
    }

    QByteArray RequestSender::get(Request& request)
    {
        return sendRequest(request, true);
    }

    QByteArray RequestSender::post(Request& request)
    {
        return sendRequest(request, false);
    }

    QByteArray RequestSender::getWhileSuccess(Request& request, int maxCount /*= 2*/)
    {
        return sendWhileSuccess(request, maxCount, true);
    }

    QByteArray RequestSender::postWhileSuccess(Request& request, int maxCount /*= 2*/)
    {
        return sendWhileSuccess(request, maxCount, false);
    }

    void RequestSender::setMaxWaitTime(qint64 max)
    {
        _maxWaitTime = max;
    }

    qint64 RequestSender::maxWaitTime() const
    {
        return _maxWaitTime;
    }

    RequestSender::RequestError RequestSender::error() const
    {
        return _error;
    }

    QByteArray RequestSender::sendRequest(Request& request, bool getRequest /*= true*/)
    {
        QTimer timer;
        timer.setInterval(_maxWaitTime);
        timer.setSingleShot(true);

        QEventLoop loop;
        QSharedPointer<QNetworkAccessManager> manager(new QNetworkAccessManager);
        manager->setProxy(_proxy);

        QNetworkReply* reply = getRequest ? manager->get(request.request()) :
                                            manager->post(request.request(false), request.data());

#ifdef QT_DEBUG
        if (getRequest)
            qInfo() << "[GET] " <<  request.request().url().toString();
        else
            qInfo() << "[POST]" << request.request(false).url().toString() << request.data();
#endif

        QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        QObject::connect(&timer, &QTimer::timeout, reply, &QNetworkReply::abort);

        timer.start();
        loop.exec();

        QByteArray data;

        if (reply->isFinished() && reply->error() == QNetworkReply::NoError)
        {
            data = reply->readAll();
            _error = RequestSender::NoError;
        }
        else
        {
            _error = RequestSender::TimeoutError;
            throw QtException(ExceptionType::Error,"RequestSender error: "+reply->errorString());
        }

        reply->deleteLater();

#ifdef QT_DEBUG
        qInfo() << "[ANSWER]" << data;
#endif

        return data;
    }

    QByteArray RequestSender::sendWhileSuccess(Request& request, int maxCount /*= 2*/, bool getRequest /*= true*/)
    {
        if (maxCount < 0)
            throw QString(__LINE__ + " " __FILE__);

        int c = 0;
        QByteArray answer;

        while (c < maxCount)
        {
            c++;
            answer = getRequest ? get(request) : post(request);

            if (error() == NoError)
                break;

            qDebug() << "Error.Code - " << error() << ". next try after 2 sec";
            QThread::currentThread()->msleep(2000);
        }

        return answer;
    }

}
