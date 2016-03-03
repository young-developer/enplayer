#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H
#include "qtexception.h"
#include "qobject.h"
#include <typeinfo>

#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
    { static const char* name; } ; const char* TypeParseTraits<X>::name = #X

template<class ObjectType>
class NullPointerException : public QtException
{
public:
    NullPointerException(ObjectType argumentType,QString msg="");
    NullPointerException();
};

template<class ObjectType>
NullPointerException<ObjectType>::NullPointerException()
{
    NullPointerException(QString("Undefined type"));
}

template<class ObjectType>
NullPointerException<ObjectType>::NullPointerException(ObjectType argumentType,QString msg)
{
    if(argumentType == nullptr || argumentType == NULL)
    {
        setType(ExceptionType::Error);
        setMessage(QString("NullPointer exception::").append(typeid(argumentType).name()).append(msg));
        QtException(Type(),what());
    }
    else
    {
        throw QtException(ExceptionType::Error,"Null pointer exception check.Something went wrong!");
    }
}
#endif // NULLPOINTEREXCEPTION_H
