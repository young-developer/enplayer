#include "mainwindow.h"
#include <QApplication>
#include "exapp.h"
#include "commonexception.h"

inline QTextStream& qStdout()
{
    static QTextStream r{stdout};
    return r;
}

void fileMessageHandler(QtMsgType type,  const QMessageLogContext &context, const QString &msg)
{
    QString txt="";
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug: %1 (%2 %3 %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function);
        break;
    /*case QtInfoMsg:
#ifdef QT_DEBUG
        txt = QString("Info: %1").arg(msg);
#endif
        break;*/
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
    if(!txt.isEmpty())
    {
        qStdout()<<txt<<endl;
        QFile outFile(APP_LOG_FILENAME);
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream ts(&outFile);
        ts <<QDateTime().currentDateTime().toString()<<" : "<< txt << endl;
    }
    if(type == QtFatalMsg)
    {
        abort();
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(fileMessageHandler);
    ExApplication a(argc, argv);
    a.setApplicationName(APP_NAME);
    a.setApplicationVersion(APP_VERSION_NUMBER);
    MainWindow w;
    w.show();

    try
    {
        return a.exec();
    }
    catch( QtException& ex )
    {
        ExMessageBox(ex,"Main exception").exec();
    }
    catch( std::exception& ex )
    {
        ExMessageBox(QtException(ExceptionType::Error,ex.what()),"Main exception").exec();
    }
}
