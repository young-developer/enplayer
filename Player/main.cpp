#include "mainwindow.h"
#include <QApplication>
#include "exapp.h"
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

inline QTextStream& qStdout()
{
    static QTextStream r{stdout};
    return r;
}

void fileMessageHandler(QtMsgType type,  const QMessageLogContext &context, const QString &msg)
{
    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug: %1 (%2 %3 %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtInfoMsg:
        txt = QString("Info: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1 (%2 %3 %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function);
    break;
    case QtCriticalMsg:
        txt = QString("Critical: %1 (%2 %3 %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function);
    break;
    case QtFatalMsg:
        txt = QString("Fatal: %1 (%2 %3 %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function);
    break;
    }
    qStdout()<<txt<<endl;
    QFile outFile("log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts <<QDateTime().currentDateTime().toString()<<" : "<< txt << endl;
    if(type == QtFatalMsg)
    {
        abort();
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(fileMessageHandler);
    ExApplication a(argc, argv);
    a.setApplicationName("enplayer");
    a.setApplicationVersion(VERSION_NUMBER);
    MainWindow w;
    w.show();

    try
    {
        return a.exec();
    }
    catch( std::exception& e )
    {
        qDebug()<<"Exception::"<<e.what();
    }
}
