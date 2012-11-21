#include "networkmanager.h"

NetworkManager::NetworkManager(QObject *parent) :
    QObject(parent)
{

}

QByteArray NetworkManager::getURL(QString url)
{
    request.setUrl(url);
    reply = manager.get(request);
    connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();

    replyStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if (replyStatus != 200)
        qDebug() << "HttpStatusCode: " << replyStatus;

    if (replyStatus == 302)
    {
        QString redirectUrl = "https://www.magickartenmarkt.de/" + reply->rawHeader("Location");
        return getURL(redirectUrl);
    }

    return reply->readAll();
}

NetworkManager::~NetworkManager(){
}

