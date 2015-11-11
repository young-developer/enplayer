#ifndef TranslateService_H
#define TranslateService_H
#include "QString"
#include <QObject>
class ITranslateService : public QObject
{
    Q_OBJECT
protected:
    QString _name;
    QString _url;
    QString _params;
    void setName(const QString &name);

    void setServiceUrl(const QString &url);

    void setServiceParams(const QString &params);
public:
    ITranslateService();

    virtual ~ITranslateService();
    virtual bool Translate(QString text, QString &result) = 0;
    virtual bool isAvailible() = 0;
    QString name() const;
    QString getServiceParams() const;
    QString getServiceUrl() const;
};

#endif // TranslateService_H
