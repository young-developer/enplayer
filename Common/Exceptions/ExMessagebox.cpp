#include "qtexception.h"
#include "exmessagebox.h"
#include <QDebug>

ExMessageBox::ExMessageBox(QtException ex, QString title,QWidget* parent):QMessageBox(parent)
{
    setText(ex.what());
    setInformativeText(ex.getTypeAsString().append(QString(" ")).append(title));
}
