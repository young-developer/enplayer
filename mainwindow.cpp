#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("EN Player v."+QString(VERSION_NUMBER));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
     qDebug()<<("Open file");
}

void MainWindow::on_actionExit_triggered()
{
    qDebug()<<("Application was closed");
    QApplication::quit();
}

void MainWindow::on_actionRead_Me_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/young-developer/enplayer/wiki", QUrl::TolerantMode));
}
