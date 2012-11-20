#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tblWants->setColumnCount(2);
    QStringList header;
    header << "Card Name" << "Edition";
    ui->tblWants->setHorizontalHeaderLabels(header);
    ui->tblWants->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSearch_clicked()
{
    QString mRequestURL = "https://www.magickartenmarkt.de/?mainPage=showSearchResult&searchFor=";

    mRequestURL.append(ui->txtCardName->text());


    QEventLoop mLoop;
    QNetworkAccessManager mNetworkManager;
    const QNetworkRequest mRequest(mRequestURL);
    QNetworkReply *mReply = mNetworkManager.get(mRequest);
    connect(mReply,SIGNAL(finished()),&mLoop,SLOT(quit()));
    mLoop.exec();
    QByteArray mData = mReply->readAll();

    qDebug() << mData;
    qDebug() << "Error: " << mReply->errorString();

    QVariant replyStatus = mReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if (replyStatus == 301)
    {
        QString redirectUrl = mReply->attribute(QNetworkRequest::RedirectionTargetAttribute).toString();
    }

    if (!mData.contains("availTable")){
        QStringList mEditionsFound;
        int pos = 0;
        while(1){
            QRegExp mRegex("(<a href=\")(.{0,100}\\.prod)(\">)");
            pos = mRegex.indexIn(mData,pos);
            if (pos > -1) {
                 qDebug() << mRegex.cap(2);
                 mEditionsFound.append(mRegex.cap(2));
            }else break;
            pos += mRegex.cap(0).length();
        }
        mEditionsFound.removeDuplicates();
        qDebug() << mEditionsFound;
    }





}
