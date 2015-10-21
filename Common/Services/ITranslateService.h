#ifndef TranslateService_H
#define TranslateService_H
#include "QString"
class ITranslateService
{
protected:
    QString _name;
public:
    ITranslateService();

    virtual ~ITranslateService();
    virtual bool Translate(QString text, QString &result) = 0;
    virtual bool isAvailible() = 0;
    QString name() const;
    void setName(const QString &name);
};

#endif // TranslateService_H
