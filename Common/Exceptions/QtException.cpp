#include <QString>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include "QtException.h"
#include "NullPointerException.h"


ExceptionType QtException::Type() const
{
    return _exType;
}

void QtException::setType(const ExceptionType &exType)
{
    _exType = exType;
}

void QtException::setMessage(QString msg)
{
    exception();
}

QtException::QtException():exception()
{
    QtException(ExceptionType::Undefined,QString("Undefined exception::").append(what()));
}

QtException::QtException(ExceptionType exType,QString msg):exception()
{
    setType(exType);
    setMessage(msg);
    if(exType != ExceptionType::Information)
        qCritical()<<getTypeAsString()<<"::"<<what();
    else
        qDebug()<<getTypeAsString()<<"::"<<what();
}

QString QtException::getTypeAsString() const
{
    switch(Type())
    {
        case 0:
            return "Information";
        break;
        case 1:
            return "Warning";
        break;
        case 2:
            return "Error";
        break;
        default:
            return "Undefined";
        break;
    }
}
