#include <QString>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include "qtexception.h"


ExceptionType QtException::Type() const
{
    return _exType;
}

void QtException::setType(const ExceptionType &exType)
{
    _exType = exType;
}

QtException::QtException(ExceptionType exType,QString msg):exception(msg.toStdString().c_str())
{
    setType(exType);

    if(exType != ExceptionType::Information)
        qCritical()<<getTypeAsString()<<" "<<what();
    else
        qInfo()<<getTypeAsString()<<"::"<<msg;
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
