#include <QtDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QTimer>

#include "exmessagebox.h"
#include "qtexception.h"
#include "enplayer.h"
#include "controlpanel.h"
#include "Subtitles/subtitlepanel.h"
#include "ui_aboutdialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    aboutDialog = nullptr;
    aboutDialogUI = nullptr;
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
#ifdef QT_DEBUG
    qInfo()<<("Application was closed");
#endif
    delete _subPanel;
    delete _enPlayer;
    delete aboutDialogUI;
    delete aboutDialog;
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
    try
    {
        _enPlayer->openFile(fileName);
    }
    catch(QtException ex)
    {
        ExMessageBox(ex,"Open video file exception").exec();
    }
    catch( ... )
    {
        ExMessageBox(QtException(ExceptionType::Undefined,"Undefined open video file exception"),"exception").exec();
    }
#ifdef QT_DEBUG
    qInfo()<<("Open file: "+fileName);
#endif
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
        _enPlayer->refreshFrame();
#ifdef QT_DEBUG
        qInfo()<<"Idle mode";
#endif
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
#ifdef QT_DEBUG
    qInfo()<<("Sub file was added : "+fileName);
#endif
}

void MainWindow::on_actionShow_log_triggered()
{
    ExMessageBox(QtException(ExceptionType::Information,"Application log file"),"log file",this).exec();
}

void MainWindow::on_actionAbout_triggered()
{
    if(aboutDialog == nullptr)
    {
       aboutDialog = new QDialog(this);
       aboutDialogUI = new Ui::AboutDialog;
       aboutDialogUI->AppName->setText(APP_NAME);
       aboutDialogUI->Version->setText(VERSION_NUMBER);
       aboutDialogUI->DescText->setText("EN Player - simple video player which plays all formats video (based on VLC player) and helps user to watch videos in english with subtitles and understand each word and sentence.");
       aboutDialogUI->setupUi(aboutDialog);
    }
    aboutDialog->exec();
}
