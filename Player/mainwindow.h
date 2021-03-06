#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QTimer>

namespace Ui {
class MainWindow;
class AboutDialog;
}

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;
class VlcVideo;
class VlcControlVideo;
class VlcMetaManager;
class ENPlayer;
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

    bool isFullScreen();
    ENPlayer *Player() const;
    void setPlayer(ENPlayer *enPlayer);
signals:
    void resized();
private slots:
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionRead_Me_triggered();

    void on_Idle();

    void toggleFullScreen();
    void on_actionAdd_Subtitles_triggered();

    void on_actionShow_log_triggered();

    void on_actionAbout_triggered();

private:
    QTimer *_idleTimer;
    Ui::MainWindow *ui;
    Ui::AboutDialog *aboutDialogUI;
    QDialog *aboutDialog;
    ENPlayer *_enPlayer;
    SubtitlePanel *_subPanel;
    bool event(QEvent *event);
protected:

};

#endif // MAINWINDOW_H
