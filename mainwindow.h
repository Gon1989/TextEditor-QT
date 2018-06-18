#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionMore_Info_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_Developer_triggered();

    void on_actionColor_2_triggered();

    void on_actionType_triggered();

    void on_actionBackground_Color_triggered();

    void on_actionPrint_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
