#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MAX_CARDS (100)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tblWants->setColumnCount(3);
    QStringList header;
    header << "Card Name" << "Edition" << "";
    ui->tblWants->setHorizontalHeaderLabels(header);
    ui->tblWants->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tblWants->setColumnWidth(2, 20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSearch_clicked()
{

    MkmCardParser parser;
    QStringList cards = parser.getCardURLs(ui->txtCardName->text());
    foreach(QString card, cards){
        QTableWidgetItem *item;

        ui->tblWants->insertRow(ui->tblWants->rowCount());

        item = new QTableWidgetItem();
        item->setText(parser.getCurrentCardName());
        ui->tblWants->setItem(ui->tblWants->rowCount()-1,0,item);

        item = new QTableWidgetItem();
        item->setText(card);
        ui->tblWants->setItem(ui->tblWants->rowCount()-1,1,item);

        item = new QTableWidgetItem();
        item->setIcon(QIcon(":/images/delete.ico"));
        ui->tblWants->setItem(ui->tblWants->rowCount()-1,2,item);

    }




}
