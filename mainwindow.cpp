#include <QtDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QTimer>

#include <vlc-qt/Common.h>
#include <vlc-qt/Instance.h>
#include <vlc-qt/Media.h>
#include <vlc-qt/MediaPlayer.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _media(0)
{
    ui->setupUi(this);
    setWindowTitle("EN Player v."+QString(VERSION_NUMBER));

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->videoWidget);
    _idleTimer = new QTimer(this);
    _idleTimer->setInterval(3000);//idle interval 3sec
    connect(_idleTimer, SIGNAL(timeout()), this, SLOT(on_Idle()));
    _idleTimer->start();
    centralWidget()->setMouseTracking(true);
    this->setMouseTracking(true);
    ui->videoWidget->setMouseTracking(true);

    ui->videoWidget->setMediaPlayer(_player);
    ui->controlPanel->setMediaPlayer(_player);
}

MainWindow::~MainWindow()
{
    qInfo()<<("Application was closed");
    delete _player;
    delete _media;
    delete _instance;
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
    _media = new VlcMedia(fileName, true, _instance);

    _player->open(_media);
    _player->play();
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

bool MainWindow::isFullScreen()
{
    if(windowState() == Qt::WindowFullScreen)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::on_Idle()
{
    if(isFullScreen())
    {
        _idleTimer->stop();
        ui->controlPanel->hidePanel();
        ui->menuBar->hide();
        qInfo()<<"Idle mode";
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    _idleTimer->stop(); // reset timer
    _idleTimer->start();
    ui->controlPanel->showPanel();
    ui->menuBar->show();
}

void MainWindow::toogleFullScreen()
{
    if(isFullScreen())
    {
        showNormal();
        qInfo()<<"onToogleFullScreen::Normal mode";
    }
    else
    {
        showFullScreen();
        qInfo()<<"onToogleFullScreen::Fullscreen mode";
    }
}

void MainWindow::mouseDoubleClickEvent( QMouseEvent *)
{
    toogleFullScreen();
}
