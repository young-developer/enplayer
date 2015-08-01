#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("EN Player v."+QString(VERSION_NUMBER));
}

MainWindow::~MainWindow()
{
    qInfo()<<("Application was closed");
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName =
                QFileDialog::getOpenFileName(this, tr("Open file"),
                                             QDir::homePath(),
                                             tr("Multimedia files(*)"));
    if (fileName.isEmpty())
            return;
    qInfo()<<("Open file: "+fileName);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionRead_Me_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/young-developer/enplayer/wiki", QUrl::TolerantMode));
}
