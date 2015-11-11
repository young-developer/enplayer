#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include <QObject>

namespace Network
{
    class NetworkManager : public QObject
    {

    public:
        NetworkManager();
        bool isOnline();
    };
}

#endif // NETWORKMANAGER_H
