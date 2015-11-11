#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
enum ExceptionType
{
    Undefined = -1,
    Information,
    Warning,
    Error
};

class QString;
class QMessageBox;
class QtException : public std::exception
{
private:
    ExceptionType _exType;
public:
    QtException(ExceptionType exType, QString msg);
    ExceptionType Type() const;
    QString getTypeAsString() const;
    void setType(const ExceptionType &exType);
};

#endif // EXCEPTIONS_H
