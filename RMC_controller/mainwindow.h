#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

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
    void on_pushButton_clicked();
//    void readPendingDatagrams();

private:
    Ui::MainWindow *ui;
    QUdpSocket * udp;
    uint8_t dir[3] = {0};//FB,LR,UD
    uint8_t CS = 0;
    uint8_t DA = 0;
    uint8_t mess[5] = {0};
};

#endif // MAINWINDOW_H
