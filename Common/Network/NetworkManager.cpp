#include <QtNetwork>
#include <QNetworkInterface>
#include "NetworkManager.h"
namespace Network
{
    NetworkManager::NetworkManager()
    {
    }

    bool NetworkManager::isOnline()
    {
        QList<QNetworkInterface> iFaces = QNetworkInterface::allInterfaces();
        bool result = false;

        for (int i = 0; i < iFaces.count(); i++)
        {
            QNetworkInterface iface = iFaces.at(i);
            if ( iface.flags().testFlag(QNetworkInterface::IsUp)
                && !iface.flags().testFlag(QNetworkInterface::IsLoopBack))
            {
                   // details of connection
                   //qInfo() << "name:" << iface.name() << endl
                      //      << "ip addresses:" << endl
                     //       << "mac:" << iface.hardwareAddress() << endl;

                for (int j=0; j<iface.addressEntries().count(); j++)
                {
                     //   qInfo() << iface.addressEntries().at(j).ip().toString()
                            //<< " / " << iface.addressEntries().at(j).netmask().toString() << endl;

                   // got an interface which is up, and has an ip address
                   if (result == false)
                             result = true;
                }
            }
        }
        return result;
    }
}
