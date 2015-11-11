#include <QtWidgets/QApplication>
#include <QDebug>
#include "qtexception.h"
#include "exmessagebox.h"
#include "exapp.h"

ExApplication::ExApplication(int &argc, char ** argv):QApplication(argc,argv)
{

}

bool ExApplication::notify(QObject * receiver, QEvent * event)
{
    try
    {
        return QApplication::notify(receiver, event);
    }
    catch(QtException &ex)
    {
        ExMessageBox(ex,"ExApplication::notify").exec();
        return false;
    }
    catch(std::exception &ex)
    {
        ExMessageBox(QtException(ExceptionType::Error,"Exception"),ex.what()).exec();
        return false;
    }
    catch( ... )
    {
        ExMessageBox(QtException(ExceptionType::Undefined,"Undefined exception"),"Ops...Undefined Exception").exec();
        return false;
    }
}
