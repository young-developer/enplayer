#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include <QObject>

namespace Network
{
class Request;
    class NetworkManager : public QObject
    {

    public:
        NetworkManager();
        QByteArray GET(QString url);
        QByteArray POST(QString url);
        QByteArray GET(Request reqUrl);
        QByteArray POST(Request reqUrl);
        bool isOnline();
    };
}

#endif // NETWORKMANAGER_H
