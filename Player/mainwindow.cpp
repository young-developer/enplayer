#include <QtDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QTimer>

#include "enplayer.h"
#include "controlpanel.h"
#include "Subtitles/subtitlepanel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("EN Player v."+QString(VERSION_NUMBER));

    centralWidget()->setMouseTracking(true);
    setMouseTracking(true);
    ui->videoWidget->setMouseTracking(true);

    _idleTimer = new QTimer(this);
    _idleTimer->setInterval(3000);//idle interval 3sec
    connect(_idleTimer, SIGNAL(timeout()), this, SLOT(on_Idle()));
    _idleTimer->start();

    _enPlayer = new ENPlayer(ui->videoWidget);
    _subPanel = new SubtitlePanel(this);
    _enPlayer->setControlPanel(ui->controlPanel);
    _enPlayer->setSubtitlePanel(_subPanel);
    connect(ui->controlPanel,SIGNAL(toggleFullScreen()),SLOT(toggleFullScreen()));
}

MainWindow::~MainWindow()
{
    qInfo()<<("Application was closed");
    delete _subPanel;
    delete _enPlayer;
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

    _enPlayer->openFile(fileName);
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
    return windowState() == Qt::WindowFullScreen?true:false;
}

bool MainWindow::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::WindowActivate:
    case QEvent::WindowStateChange:
    case QEvent::Resize:
    case QEvent::Move:
    case QEvent::MouseButtonRelease:
    case QEvent::MouseButtonDblClick:
        _subPanel->panelSizeMove();
        break;
    default:
        break;
    }

    return QMainWindow::event(event);
}

void MainWindow::on_Idle()
{
    if(isFullScreen())
    {
        _idleTimer->stop();
        ui->controlPanel->hidePanel();
        ui->menuBar->hide();
        setCursor(Qt::BlankCursor);
        qInfo()<<"Idle mode";
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *)
{
    _idleTimer->stop(); // reset timer
    _idleTimer->start();
    ui->controlPanel->showPanel();
    ui->menuBar->show();
    setCursor(Qt::ArrowCursor);
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    emit resized();
}

void MainWindow::toggleFullScreen()
{
    isFullScreen()?showNormal():showFullScreen();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
    toggleFullScreen();
}

void MainWindow::on_actionAdd_Subtitles_triggered()
{
    QString fileName =
                QFileDialog::getOpenFileName(this, tr("Add Subtitles"),
                                             QDir::homePath(),
                                             tr("Subtitle files(*)"));
    if (fileName.isEmpty())
            return;

    _enPlayer->addSubtitles(fileName);
    qInfo()<<("Sub file was added : "+fileName);
}
