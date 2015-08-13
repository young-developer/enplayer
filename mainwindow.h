#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mouseDoubleClickEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *event);
    void toggleFullScreen();
    bool isFullScreen();
private slots:
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionRead_Me_triggered();

    void on_Idle();
private:
    QTimer *_idleTimer;
    Ui::MainWindow *ui;
    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;
};

#endif // MAINWINDOW_H
