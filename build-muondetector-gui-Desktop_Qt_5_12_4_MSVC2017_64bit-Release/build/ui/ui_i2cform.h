/********************************************************************************
** Form generated from reading UI file 'i2cform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_I2CFORM_H
#define UI_I2CFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_I2cForm
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *statisticsGroupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *nrDevicesLabel;
    QLabel *bytesReadLabel;
    QLabel *bytesWrittenLabel;
    QGroupBox *devicesGroupBox;
    QGridLayout *gridLayout;
    QTableWidget *devicesTableWidget;
    QPushButton *statsQueryPushButton;
    QPushButton *scanBusPushButton;

    void setupUi(QWidget *I2cForm)
    {
        if (I2cForm->objectName().isEmpty())
            I2cForm->setObjectName(QString::fromUtf8("I2cForm"));
        I2cForm->resize(432, 445);
        gridLayout_3 = new QGridLayout(I2cForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        statisticsGroupBox = new QGroupBox(I2cForm);
        statisticsGroupBox->setObjectName(QString::fromUtf8("statisticsGroupBox"));
        gridLayout_2 = new QGridLayout(statisticsGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        nrDevicesLabel = new QLabel(statisticsGroupBox);
        nrDevicesLabel->setObjectName(QString::fromUtf8("nrDevicesLabel"));

        verticalLayout->addWidget(nrDevicesLabel);

        bytesReadLabel = new QLabel(statisticsGroupBox);
        bytesReadLabel->setObjectName(QString::fromUtf8("bytesReadLabel"));

        verticalLayout->addWidget(bytesReadLabel);

        bytesWrittenLabel = new QLabel(statisticsGroupBox);
        bytesWrittenLabel->setObjectName(QString::fromUtf8("bytesWrittenLabel"));

        verticalLayout->addWidget(bytesWrittenLabel);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(statisticsGroupBox, 0, 0, 1, 1);

        devicesGroupBox = new QGroupBox(I2cForm);
        devicesGroupBox->setObjectName(QString::fromUtf8("devicesGroupBox"));
        gridLayout = new QGridLayout(devicesGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        devicesTableWidget = new QTableWidget(devicesGroupBox);
        if (devicesTableWidget->columnCount() < 3)
            devicesTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        devicesTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        devicesTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        devicesTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        devicesTableWidget->setObjectName(QString::fromUtf8("devicesTableWidget"));
        devicesTableWidget->setAutoFillBackground(true);
        devicesTableWidget->setAlternatingRowColors(true);
        devicesTableWidget->setSortingEnabled(false);
        devicesTableWidget->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(devicesTableWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(devicesGroupBox, 1, 0, 1, 1);

        statsQueryPushButton = new QPushButton(I2cForm);
        statsQueryPushButton->setObjectName(QString::fromUtf8("statsQueryPushButton"));

        gridLayout_3->addWidget(statsQueryPushButton, 2, 0, 1, 1);

        scanBusPushButton = new QPushButton(I2cForm);
        scanBusPushButton->setObjectName(QString::fromUtf8("scanBusPushButton"));

        gridLayout_3->addWidget(scanBusPushButton, 3, 0, 1, 1);


        retranslateUi(I2cForm);

        QMetaObject::connectSlotsByName(I2cForm);
    } // setupUi

    void retranslateUi(QWidget *I2cForm)
    {
        I2cForm->setWindowTitle(QApplication::translate("I2cForm", "Form", nullptr));
        statisticsGroupBox->setTitle(QApplication::translate("I2cForm", "Statistics", nullptr));
        nrDevicesLabel->setText(QApplication::translate("I2cForm", "Nr. of devices:", nullptr));
        bytesReadLabel->setText(QApplication::translate("I2cForm", "total bytes read: ", nullptr));
        bytesWrittenLabel->setText(QApplication::translate("I2cForm", "total bytes written:", nullptr));
        devicesGroupBox->setTitle(QApplication::translate("I2cForm", "I2C devices", nullptr));
        QTableWidgetItem *___qtablewidgetitem = devicesTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("I2cForm", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = devicesTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("I2cForm", "Designation", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = devicesTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("I2cForm", "Status", nullptr));
        statsQueryPushButton->setText(QApplication::translate("I2cForm", "Read", nullptr));
        scanBusPushButton->setText(QApplication::translate("I2cForm", "Scan Bus for extra devices", nullptr));
    } // retranslateUi

};

namespace Ui {
    class I2cForm: public Ui_I2cForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_I2CFORM_H
