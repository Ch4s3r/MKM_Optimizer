#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QtNetwork>

class NetworkManager : public QObject
{
    Q_OBJECT


    QNetworkAccessManager manager;
    QNetworkRequest request;
    QNetworkReply *reply;
    QEventLoop loop;
    int replyStatus;


public:
    explicit NetworkManager(QObject *parent = 0);
    ~NetworkManager();
    QByteArray getURL(QString url);
signals:
    
public slots:
    
};

#endif // NETWORKMANAGER_H
