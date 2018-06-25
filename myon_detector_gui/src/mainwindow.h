#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <tcpconnection.h>
#include <QStandardItemModel>
#include "../shared/tcpconnection.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void closeConnection();
    void setI2CProperties(quint8 pcaChann, QVector<float> dacThresh, float biasVoltage,
                          bool biasPowerOn, bool setProperties = true);
    void requestI2CProperties();

public slots:
    void makeConnection(QString ipAddress, quint16 port);
    void updateI2CProperties(quint8 pcaChann, QVector<float> dacThresh,
                             float biasVoltage, bool biasPowerOn, bool setProperties);

private slots:
    void updateUiProperties(int uartBufferValue = -1, int discr1SliderValue = -1,
                                        int discr2SliderValue = -1);
    // only those properties with value >= 0 will be updated!
    void on_ipButton_clicked();
    void connected();

private:
    Ui::MainWindow *ui;
    void uiSetDisconnectedState();
    int verbose = 0;
    TcpConnection *tcpConnection = nullptr;
    QStandardItemModel *addresses;
    QList<QStandardItem *> *addressColumn;
    bool saveSettings(QString fileName, QStandardItemModel* model);
    bool loadSettings(QString fileName, QStandardItemModel* model);
    bool eventFilter(QObject *object, QEvent *event);
    bool connectedToDemon = false;
};

#endif // MAINWINDOW_H
