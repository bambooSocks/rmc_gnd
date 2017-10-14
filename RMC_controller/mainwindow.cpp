#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUdpSocket>
#include <QHostAddress>
#include <QLabel>
#include <QNetworkInterface>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udp = new QUdpSocket();

//    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
//        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost)){
//             if (address.toString().startsWith("169.254.")){
//                 qDebug() << address.toString();
//                 //udp->bind(address,1488);
//             }
//        }
//    }
    udp->bind(QHostAddress::QHostAddress("169.254.241.197"),1488);
    connect(udp, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::readPendingDatagrams(){
//    //while (udp->hasPendingDatagrams()){
//        //QNetworkDatagram datagram = udp->receiveDatagram(64);
//        QByteArray buffer;
//        QHostAddress sander;
//        quint16 sPort;
//        buffer.resize(udp->pendingDatagramSize());
//        udp->readDatagram(buffer.data(),buffer.size(), &sander, &sPort);

//        qDebug() << "from: " << sander.toString();
//        qDebug() << "port: " << sPort;
//        qDebug() << "mess: " << buffer;
//    //}
//}

void MainWindow::on_pushButton_clicked()
{
    QHostAddress receiver;
    receiver.setAddress("169.254.242.224");
    mess[0]=dir[0];
    mess[1]=dir[1];
    mess[2]=dir[2];
    mess[3]=DA;
    mess[4]=dir[0]+dir[1]+dir[2]+DA;
    qDebug() << mess[4];

    udp->writeDatagram(ui->lineEdit->text().toStdString().c_str() ,ui->lineEdit->text().length(),receiver,1488);
}
