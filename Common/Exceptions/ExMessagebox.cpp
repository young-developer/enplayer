#include "QtException.h"
#include "ExMessagebox.h"
#include <QDebug>

ExMessageBox::ExMessageBox(QtException ex, QString title,QWidget* parent):QMessageBox(parent)
{
    setText(ex.what());
    setInformativeText(ex.getTypeAsString().append(QString(" ")).append(title));
}
