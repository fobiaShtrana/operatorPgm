#include "laboratory.h"
#include "ui_laboratory.h"


Laboratory::Laboratory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Laboratory)
{
    ui->setupUi(this);
    this->ui->buttonReset->setEnabled(false);
    this->ui->groupBoxControl->setEnabled(false);
    //this->ui->plainTextEdit->setEnabled(false);
}

Laboratory::~Laboratory()
{
    delete ui;
}

void Laboratory::on_buttonConnect_clicked()
{
    this->socket = new QTcpSocket(this);
    this->socket->connectToHost("192.168.1.47", 33333);
    connect(this->socket,SIGNAL(connected()),SLOT(sockerConnected()));
    connect(this->socket,SIGNAL(readyRead()),SLOT(sockerAuthDataReady()));
    this->ui->buttonConnect->setEnabled(false);
    this->ui->groupBoxControl->setEnabled(false);

}

void Laboratory::sockerConnected()
{
    this->ui->buttonReset->setEnabled(true);
    this->ui->groupBoxControl->setEnabled(true);
}

void Laboratory::sockerAuthDataReady()
{
    QByteArray res = this->socket->readAll();
    if(res.startsWith("Auth:"))
        this->socket->write("goodDaddy");
    qDebug()<< res;
    if(res.endsWith("Ok!"))
    {
        disconnect(this->socket,SIGNAL(readyRead()),this,SLOT(sockerAuthDataReady()));
        connect(this->socket,SIGNAL(readyRead()),SLOT(sockerDataReady()));
    }
}
void Laboratory::sockerDataReady()
{
    this->ui->plainTextEdit->appendPlainText(this->socket->readAll().simplified());
    //this->ui->plainTextEdit->set
}

void Laboratory::on_buttonReset_clicked()
{
    this->socket->write("R");
}

void Laboratory::on_buttonTuneMachine_clicked()
{
    this->socket->write("m21");
}

void Laboratory::on_buttonOpenSmallDore_clicked()
{
    this->socket->write("t10");
}

void Laboratory::on_buttonOpenDore_clicked()
{
    this->socket->write("D");
}

void Laboratory::on_buttonCloseSmallDore_clicked()
{
        this->socket->write("t11");
}

void Laboratory::on_buttonLightOn_clicked()
{
    this->socket->write("o001");
}

void Laboratory::on_buttonLightOff_clicked()
{
    this->socket->write("o000");
}

void Laboratory::on_buttonBoxOpen_clicked()
{

    this->socket->write("t51");
}

void Laboratory::on_buttonBoxClose_clicked()
{

    this->socket->write("t50");
}

void Laboratory::on_buttonBoxOff_clicked()
{
    this->socket->write("t40");
}

void Laboratory::on_buttonBoxOn_clicked()
{
    this->socket->write("t41");
}

void Laboratory::on_buttonChargeBattery_clicked()
{
    this->socket->write("B");
}
