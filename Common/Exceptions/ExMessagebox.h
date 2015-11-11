#ifndef EXMESSAGEBOX_H
#define EXMESSAGEBOX_H
#include <QtWidgets/QMessageBox>
class QtException;
class ExMessageBox : public QMessageBox
{
public:
    ExMessageBox(QtException ex, QString title="", QWidget *parent=0);
};

#endif // EXMESSAGEBOX_H
