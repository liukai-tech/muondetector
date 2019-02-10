#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QTableWidget>
#include <QtWidgets>
#include <gnsssatellite.h>
#include <ublox_structs.h>


class UbxMsgRateTableItem : public QTableWidgetItem
{
public:
    using QTableWidgetItem::QTableWidgetItem;
	uint16_t key;
	int rate;
	QString name;
};

namespace Ui {
	class Settings;
}

class Settings : public QDialog
{
	Q_OBJECT
public:
	explicit Settings(QWidget *parent = nullptr);

signals:
    void sendSetUbxMsgRateChanges(QMap<uint16_t, int> ubxMsgRateChanges);
    void sendRequestUbxMsgRates();
    void sendUbxReset();
    void sendUbxConfigDefault();
    void setGnssConfigs(const QVector<GnssConfigStruct>& configList);


public slots:
    void addUbxMsgRates(QMap<uint16_t, int> ubxMsgRates);
    void onItemChanged(QTableWidgetItem *item);
    void onUiEnabledStateChange(bool connected);
    void onTxBufReceived(quint8 val);
    void onTxBufPeakReceived(quint8 val);
    void onGnssConfigsReceived(quint8 numTrkCh, const QVector<GnssConfigStruct>& configList);
    //void onGpsTP5Received(const UbxTimePulseStruct& tp);
    void onTP5Received(const UbxTimePulseStruct& tp);

private slots:
    void onSettingsButtonBoxClicked(QAbstractButton *button);
    void on_ubxResetPushButton_clicked();
    void on_setGnssConfigPushButton_clicked();

private:
    Ui::Settings *settingsUi;
    QMap<uint16_t, int> oldSettings;
};

#endif // SETTINGS_H
