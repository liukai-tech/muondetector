/********************************************************************************
** Form generated from reading UI file 'calibform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBFORM_H
#define UI_CALIBFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "custom_plot_widget.h"

QT_BEGIN_NAMESPACE

class Ui_CalibForm
{
public:
    QGridLayout *gridLayout_6;
    QGroupBox *calibItemsGroupBox;
    QGridLayout *gridLayout;
    QLabel *eepromValidLabel;
    QLabel *calibValidLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *idLineEdit;
    QTableWidget *calibItemTableWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *readCalibPushButton;
    QPushButton *writeEepromPushButton;
    QGroupBox *measureBiasCalibGroupBox;
    QGridLayout *gridLayout_5;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    CustomPlot *biasVoltageCalibPlot;
    CustomPlot *biasCurrentCalibPlot;
    QTextEdit *fitTextEdit;
    QPushButton *doBiasCalibPushButton;
    QPushButton *transferBiasCoeffsPushButton;
    QGroupBox *biasCalibGroupBox;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *biasAdcLineEdit;
    QLineEdit *biasVoltageLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *biasFormulaLabel;
    QGroupBox *currentCalibGroupBox;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *biasCurrentLineEdit;

    void setupUi(QWidget *CalibForm)
    {
        if (CalibForm->objectName().isEmpty())
            CalibForm->setObjectName(QString::fromUtf8("CalibForm"));
        CalibForm->resize(528, 465);
        gridLayout_6 = new QGridLayout(CalibForm);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        calibItemsGroupBox = new QGroupBox(CalibForm);
        calibItemsGroupBox->setObjectName(QString::fromUtf8("calibItemsGroupBox"));
        gridLayout = new QGridLayout(calibItemsGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        eepromValidLabel = new QLabel(calibItemsGroupBox);
        eepromValidLabel->setObjectName(QString::fromUtf8("eepromValidLabel"));

        gridLayout->addWidget(eepromValidLabel, 0, 0, 1, 1);

        calibValidLabel = new QLabel(calibItemsGroupBox);
        calibValidLabel->setObjectName(QString::fromUtf8("calibValidLabel"));

        gridLayout->addWidget(calibValidLabel, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(calibItemsGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        idLineEdit = new QLineEdit(calibItemsGroupBox);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));
        idLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(idLineEdit);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        calibItemTableWidget = new QTableWidget(calibItemsGroupBox);
        if (calibItemTableWidget->columnCount() < 4)
            calibItemTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        calibItemTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        calibItemTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        calibItemTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        calibItemTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        calibItemTableWidget->setObjectName(QString::fromUtf8("calibItemTableWidget"));
        calibItemTableWidget->setAutoFillBackground(true);
        calibItemTableWidget->setAlternatingRowColors(true);
        calibItemTableWidget->horizontalHeader()->setDefaultSectionSize(100);

        gridLayout->addWidget(calibItemTableWidget, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        readCalibPushButton = new QPushButton(calibItemsGroupBox);
        readCalibPushButton->setObjectName(QString::fromUtf8("readCalibPushButton"));

        horizontalLayout_2->addWidget(readCalibPushButton);

        writeEepromPushButton = new QPushButton(calibItemsGroupBox);
        writeEepromPushButton->setObjectName(QString::fromUtf8("writeEepromPushButton"));
        writeEepromPushButton->setMaximumSize(QSize(96, 16777215));

        horizontalLayout_2->addWidget(writeEepromPushButton);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);


        gridLayout_6->addWidget(calibItemsGroupBox, 0, 0, 1, 1);

        measureBiasCalibGroupBox = new QGroupBox(CalibForm);
        measureBiasCalibGroupBox->setObjectName(QString::fromUtf8("measureBiasCalibGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(measureBiasCalibGroupBox->sizePolicy().hasHeightForWidth());
        measureBiasCalibGroupBox->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(measureBiasCalibGroupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        frame = new QFrame(measureBiasCalibGroupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        biasVoltageCalibPlot = new CustomPlot(frame);
        biasVoltageCalibPlot->setObjectName(QString::fromUtf8("biasVoltageCalibPlot"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(biasVoltageCalibPlot->sizePolicy().hasHeightForWidth());
        biasVoltageCalibPlot->setSizePolicy(sizePolicy1);
        biasVoltageCalibPlot->setMaximumSize(QSize(16777215, 180));

        gridLayout_3->addWidget(biasVoltageCalibPlot, 0, 0, 1, 1);

        biasCurrentCalibPlot = new CustomPlot(frame);
        biasCurrentCalibPlot->setObjectName(QString::fromUtf8("biasCurrentCalibPlot"));
        sizePolicy1.setHeightForWidth(biasCurrentCalibPlot->sizePolicy().hasHeightForWidth());
        biasCurrentCalibPlot->setSizePolicy(sizePolicy1);
        biasCurrentCalibPlot->setMaximumSize(QSize(16777215, 180));

        gridLayout_3->addWidget(biasCurrentCalibPlot, 1, 0, 1, 1);

        fitTextEdit = new QTextEdit(frame);
        fitTextEdit->setObjectName(QString::fromUtf8("fitTextEdit"));
        sizePolicy.setHeightForWidth(fitTextEdit->sizePolicy().hasHeightForWidth());
        fitTextEdit->setSizePolicy(sizePolicy);
        fitTextEdit->setMaximumSize(QSize(16777215, 45));

        gridLayout_3->addWidget(fitTextEdit, 2, 0, 1, 1);


        gridLayout_5->addWidget(frame, 0, 0, 1, 2);

        doBiasCalibPushButton = new QPushButton(measureBiasCalibGroupBox);
        doBiasCalibPushButton->setObjectName(QString::fromUtf8("doBiasCalibPushButton"));

        gridLayout_5->addWidget(doBiasCalibPushButton, 1, 0, 1, 1);

        transferBiasCoeffsPushButton = new QPushButton(measureBiasCalibGroupBox);
        transferBiasCoeffsPushButton->setObjectName(QString::fromUtf8("transferBiasCoeffsPushButton"));

        gridLayout_5->addWidget(transferBiasCoeffsPushButton, 1, 1, 1, 1);


        gridLayout_6->addWidget(measureBiasCalibGroupBox, 0, 1, 3, 1);

        biasCalibGroupBox = new QGroupBox(CalibForm);
        biasCalibGroupBox->setObjectName(QString::fromUtf8("biasCalibGroupBox"));
        gridLayout_4 = new QGridLayout(biasCalibGroupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(biasCalibGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(biasCalibGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        biasAdcLineEdit = new QLineEdit(biasCalibGroupBox);
        biasAdcLineEdit->setObjectName(QString::fromUtf8("biasAdcLineEdit"));
        biasAdcLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(biasAdcLineEdit);

        biasVoltageLineEdit = new QLineEdit(biasCalibGroupBox);
        biasVoltageLineEdit->setObjectName(QString::fromUtf8("biasVoltageLineEdit"));
        biasVoltageLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(biasVoltageLineEdit);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 2);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(biasCalibGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        biasFormulaLabel = new QLabel(biasCalibGroupBox);
        biasFormulaLabel->setObjectName(QString::fromUtf8("biasFormulaLabel"));

        horizontalLayout_4->addWidget(biasFormulaLabel);


        gridLayout_4->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout_6->addWidget(biasCalibGroupBox, 1, 0, 1, 1);

        currentCalibGroupBox = new QGroupBox(CalibForm);
        currentCalibGroupBox->setObjectName(QString::fromUtf8("currentCalibGroupBox"));
        gridLayout_7 = new QGridLayout(currentCalibGroupBox);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(currentCalibGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        biasCurrentLineEdit = new QLineEdit(currentCalibGroupBox);
        biasCurrentLineEdit->setObjectName(QString::fromUtf8("biasCurrentLineEdit"));

        horizontalLayout_5->addWidget(biasCurrentLineEdit);


        gridLayout_7->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        gridLayout_6->addWidget(currentCalibGroupBox, 2, 0, 1, 1);


        retranslateUi(CalibForm);

        QMetaObject::connectSlotsByName(CalibForm);
    } // setupUi

    void retranslateUi(QWidget *CalibForm)
    {
        CalibForm->setWindowTitle(QApplication::translate("CalibForm", "Form", nullptr));
        calibItemsGroupBox->setTitle(QApplication::translate("CalibForm", "Calib Items", nullptr));
        eepromValidLabel->setText(QApplication::translate("CalibForm", "EEPROM data:", nullptr));
        calibValidLabel->setText(QApplication::translate("CalibForm", "Calib data:", nullptr));
        label->setText(QApplication::translate("CalibForm", "Unique ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem = calibItemTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CalibForm", "Calib Item", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = calibItemTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CalibForm", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = calibItemTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CalibForm", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = calibItemTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CalibForm", "EEP Addr", nullptr));
        readCalibPushButton->setText(QApplication::translate("CalibForm", "Reread", nullptr));
        writeEepromPushButton->setText(QApplication::translate("CalibForm", "Write EEPROM", nullptr));
        measureBiasCalibGroupBox->setTitle(QApplication::translate("CalibForm", "Bias Voltage Calibration", nullptr));
        doBiasCalibPushButton->setText(QApplication::translate("CalibForm", "Start", nullptr));
        transferBiasCoeffsPushButton->setText(QApplication::translate("CalibForm", "Transfer to Calib", nullptr));
        biasCalibGroupBox->setTitle(QApplication::translate("CalibForm", "Bias Voltage Calculation", nullptr));
        label_2->setText(QApplication::translate("CalibForm", "ADC voltage", nullptr));
        label_4->setText(QApplication::translate("CalibForm", "Bias Voltage", nullptr));
        label_5->setText(QApplication::translate("CalibForm", "Formula:", nullptr));
        biasFormulaLabel->setText(QApplication::translate("CalibForm", "Vbias = VDIV/100 * Vadc", nullptr));
        currentCalibGroupBox->setTitle(QApplication::translate("CalibForm", "Bias Current Calculation", nullptr));
        label_3->setText(QApplication::translate("CalibForm", "Bias Current", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalibForm: public Ui_CalibForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBFORM_H
