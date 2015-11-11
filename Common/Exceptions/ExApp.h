#ifndef EXAPP_H
#define EXAPP_H

class QApplication;

class ExApplication : public QApplication
{
public:
    ExApplication(int &argc, char ** argv);
    // ~MyApplication();
private:
    bool notify(QObject *receiver_, QEvent *event_);
};

#endif // EXAPP_H
