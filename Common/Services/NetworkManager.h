#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include <QNetworkAccessManager>

class NetworkManager : public QNetworkAccessManager
{
public:
    NetworkManager();
    QString Get(QString url,QString param);
    QString Post(QString url,QString param);
};

#endif // NETWORKMANAGER_H
