#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include "networkmanager.h"
#include "mkmcardparser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    NetworkManager manager;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btnSearch_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
