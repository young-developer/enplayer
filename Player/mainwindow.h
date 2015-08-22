#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;
class VlcVideo;
class VlcControlVideo;
class VlcMetaManager;
class SubtitlePanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mouseDoubleClickEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);
    void toggleFullScreen();
    bool isFullScreen();
signals:
       void resized();
private slots:
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionRead_Me_triggered();

    void on_Idle();
private:
    QTimer *_idleTimer;
    Ui::MainWindow *ui;
    VlcInstance *_instance;
    VlcVideo *_vlcVideo;
    VlcControlVideo *_controlVideo;
    VlcMedia *_media;
    VlcMediaPlayer *_player;
    SubtitlePanel *_subPanel;

    // QWidget interface
protected:

};

#endif // MAINWINDOW_H
