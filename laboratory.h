#ifndef LABORATORY_H
#define LABORATORY_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>

namespace Ui {
class Laboratory;
}

class Laboratory : public QMainWindow
{
    Q_OBJECT
private:
    QTcpSocket *socket;

public:
    explicit Laboratory(QWidget *parent = 0);
    ~Laboratory();

private slots:
    void on_buttonConnect_clicked();
    void sockerAuthDataReady();
    void sockerDataReady();
    void sockerConnected();

    void on_buttonReset_clicked();

    void on_buttonTuneMachine_clicked();

    void on_buttonOpenSmallDore_clicked();

    void on_buttonOpenDore_clicked();

    void on_buttonCloseSmallDore_clicked();

    void on_buttonLightOn_clicked();

    void on_buttonLightOff_clicked();

    void on_buttonBoxOpen_clicked();

    void on_buttonBoxClose_clicked();

    void on_buttonBoxOff_clicked();

    void on_buttonBoxOn_clicked();


    void on_buttonChargeBattery_clicked();

private:
    Ui::Laboratory *ui;
};

#endif // LABORATORY_H
