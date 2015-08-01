#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

void fileMessageHandler(QtMsgType type,  const QMessageLogContext &context, const QString &msg)
{
    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
    break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
    break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
    break;
    }

    QFile outFile("log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts <<QDateTime().currentDateTime().toString()<<" : "<< txt << endl;
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(fileMessageHandler);
    QApplication a(argc, argv);
    a.setApplicationName("enplayer");
    a.setApplicationVersion(VERSION_NUMBER);
    MainWindow w;
    w.show();

    return a.exec();
}
