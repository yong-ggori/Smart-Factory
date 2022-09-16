#include <QDebug>
#include "socketclient.h"
#define Kor(str)  QString::fromLocal8Bit(str)

SocketClient::SocketClient(QWidget *parent, Qt::WindowFlags flags)
        : QWidget(parent, flags)
{
    bool ok;
    pQTcpSocket = new QTcpSocket();

    connect(pQTcpSocket, SIGNAL(connected()), this, SLOT(slotConnectServer()));
    connect(pQTcpSocket, SIGNAL(disconnected()), this, SLOT(slotClosedByServer()));
    connect(pQTcpSocket, SIGNAL(readyRead()), this, SLOT(slotSocketReadData()));
    connect(pQTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotSocketError()));
//  slotConnectToServer(ok);
}

void SocketClient::slotConnectToServer(bool& ok){
    //서버 연결 요청
    QString strHostIp;
    strHostIp = QInputDialog::getText(this,"HostIP","Input Server IP:",QLineEdit::Normal,SERVERIP,&ok);
    if(ok)
    {
        if(strHostIp.isEmpty()) {
            socketState = !socketState;
            pQTcpSocket->connectToHost(SERVERIP, SERVERPOT);

        }
        else {
            if(strHostIp == SERVERIP){
                socketState = !socketState;
                pQTcpSocket->connectToHost(strHostIp, SERVERPOT);
            }
            else {
                QString Str = "Unknown server";
                qDebug() << "error : " <<Str;
                emit sigerr(Str);
            }
        }
    }
}

void SocketClient::slotConnectServer()
{
    QString Str = "["+LOGID+":"+LOGPW+"]";
    QByteArray byteStr = Str.toLocal8Bit();
    pQTcpSocket->write(byteStr);
    QString err = pQTcpSocket->errorString();
    socketState = pQTcpSocket->waitForConnected();
}

void SocketClient::slotClosedByServer()
{
        pQTcpSocket->close();
        socketState = pQTcpSocket->waitForDisconnected();
}

void SocketClient::slotSocketReadData(){
    QString strRecvData;
    QByteArray qByteArray;

    if (pQTcpSocket->bytesAvailable() > BLOCK_SIZE)
        return;
    qByteArray = pQTcpSocket->read(BLOCK_SIZE);
    strRecvData = QString::fromUtf8(qByteArray);
    emit sigSocketRecv(strRecvData);
}

void SocketClient::slotSocketError()
{
    QString Str = pQTcpSocket->errorString();
    qDebug() << "error : " <<Str;
    emit sigerr(Str);
}

void SocketClient::slotSocketSendData(QString strSendData)
{
    if(!strSendData.isEmpty()) {
        strSendData = strSendData+"\n";
        QByteArray bCmd = strSendData.toLocal8Bit();
        //pQTcpSocket->write(bCmd);
    }
}

SocketClient::~SocketClient()
{
    pQTcpSocket->close();
}
