/********************************************************************************
** Form generated from reading UI file 'status.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUS_H
#define UI_STATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "custom_histogram_widget.h"
#include "plotcustom.h"

QT_BEGIN_NAMESPACE

class Ui_Status
{
public:
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *ratePlotGroupBox;
    QGridLayout *gridLayout_8;
    QPushButton *resetRatePushButton;
    PlotCustom *ratePlot;
    QComboBox *ratePlotPresetComboBox;
    QLineEdit *ratePlotBufferEdit;
    QGroupBox *pulseHeightHistogramGroupBox;
    QGridLayout *gridLayout_5;
    CustomHistogram *pulseHeightHistogram;
    QCheckBox *histoLogYCheckBox;
    QSpacerItem *horizontalSpacer;
    QLabel *PulseHeightHistogramEntriesLabel;
    QPushButton *resetHistoPushButton;
    QGroupBox *statusValuesGroupBox;
    QGridLayout *gridLayout_6;
    QGroupBox *ADCGroupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *ADCLabel1;
    QLabel *ADCLabel2;
    QLabel *ADCLabel3;
    QLabel *ADCLabel4;
    QGroupBox *DACGroupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *DACLabel1;
    QLabel *DACLabel2;
    QLabel *DACLabel3;
    QLabel *DACLabel4;
    QGroupBox *switchesGroupBox;
    QGridLayout *gridLayout_9;
    QGroupBox *InputSelectGroupBox;
    QGridLayout *gridLayout_3;
    QRadioButton *InputSelectRadioButton0;
    QRadioButton *InputSelectRadioButton4;
    QRadioButton *InputSelectRadioButton1;
    QRadioButton *InputSelectRadioButton5;
    QRadioButton *InputSelectRadioButton2;
    QRadioButton *InputSelectRadioButton6;
    QRadioButton *InputSelectRadioButton3;
    QRadioButton *InputSelectRadioButton7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QCheckBox *biasEnableCheckBox;
    QCheckBox *highGainCheckBox;
    QCheckBox *preamp1CheckBox;
    QCheckBox *preamp2CheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *triggerSelectionComboBox;
    QLabel *temperatureLabel;
    QLabel *timePulseLabel;

    void setupUi(QWidget *Status)
    {
        if (Status->objectName().isEmpty())
            Status->setObjectName(QStringLiteral("Status"));
        Status->resize(571, 438);
        gridLayout_7 = new QGridLayout(Status);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ratePlotGroupBox = new QGroupBox(Status);
        ratePlotGroupBox->setObjectName(QStringLiteral("ratePlotGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ratePlotGroupBox->sizePolicy().hasHeightForWidth());
        ratePlotGroupBox->setSizePolicy(sizePolicy);
        ratePlotGroupBox->setMinimumSize(QSize(200, 130));
        ratePlotGroupBox->setCheckable(true);
        gridLayout_8 = new QGridLayout(ratePlotGroupBox);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        resetRatePushButton = new QPushButton(ratePlotGroupBox);
        resetRatePushButton->setObjectName(QStringLiteral("resetRatePushButton"));

        gridLayout_8->addWidget(resetRatePushButton, 1, 2, 1, 1);

        ratePlot = new PlotCustom(ratePlotGroupBox);
        ratePlot->setObjectName(QStringLiteral("ratePlot"));

        gridLayout_8->addWidget(ratePlot, 0, 0, 1, 3);

        ratePlotPresetComboBox = new QComboBox(ratePlotGroupBox);
        ratePlotPresetComboBox->setObjectName(QStringLiteral("ratePlotPresetComboBox"));

        gridLayout_8->addWidget(ratePlotPresetComboBox, 1, 0, 1, 1);

        ratePlotBufferEdit = new QLineEdit(ratePlotGroupBox);
        ratePlotBufferEdit->setObjectName(QStringLiteral("ratePlotBufferEdit"));

        gridLayout_8->addWidget(ratePlotBufferEdit, 1, 1, 1, 1);


        horizontalLayout_2->addWidget(ratePlotGroupBox);

        pulseHeightHistogramGroupBox = new QGroupBox(Status);
        pulseHeightHistogramGroupBox->setObjectName(QStringLiteral("pulseHeightHistogramGroupBox"));
        sizePolicy.setHeightForWidth(pulseHeightHistogramGroupBox->sizePolicy().hasHeightForWidth());
        pulseHeightHistogramGroupBox->setSizePolicy(sizePolicy);
        pulseHeightHistogramGroupBox->setMinimumSize(QSize(200, 130));
        pulseHeightHistogramGroupBox->setCheckable(true);
        gridLayout_5 = new QGridLayout(pulseHeightHistogramGroupBox);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pulseHeightHistogram = new CustomHistogram(pulseHeightHistogramGroupBox);
        pulseHeightHistogram->setObjectName(QStringLiteral("pulseHeightHistogram"));

        gridLayout_5->addWidget(pulseHeightHistogram, 0, 0, 1, 4);

        histoLogYCheckBox = new QCheckBox(pulseHeightHistogramGroupBox);
        histoLogYCheckBox->setObjectName(QStringLiteral("histoLogYCheckBox"));

        gridLayout_5->addWidget(histoLogYCheckBox, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 1, 1, 1, 1);

        PulseHeightHistogramEntriesLabel = new QLabel(pulseHeightHistogramGroupBox);
        PulseHeightHistogramEntriesLabel->setObjectName(QStringLiteral("PulseHeightHistogramEntriesLabel"));
        PulseHeightHistogramEntriesLabel->setMinimumSize(QSize(110, 0));

        gridLayout_5->addWidget(PulseHeightHistogramEntriesLabel, 1, 2, 1, 1);

        resetHistoPushButton = new QPushButton(pulseHeightHistogramGroupBox);
        resetHistoPushButton->setObjectName(QStringLiteral("resetHistoPushButton"));

        gridLayout_5->addWidget(resetHistoPushButton, 1, 3, 1, 1);


        horizontalLayout_2->addWidget(pulseHeightHistogramGroupBox);


        gridLayout_7->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        statusValuesGroupBox = new QGroupBox(Status);
        statusValuesGroupBox->setObjectName(QStringLiteral("statusValuesGroupBox"));
        statusValuesGroupBox->setMinimumSize(QSize(350, 190));
        statusValuesGroupBox->setMaximumSize(QSize(16777215, 210));
        gridLayout_6 = new QGridLayout(statusValuesGroupBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        ADCGroupBox = new QGroupBox(statusValuesGroupBox);
        ADCGroupBox->setObjectName(QStringLiteral("ADCGroupBox"));
        ADCGroupBox->setMinimumSize(QSize(100, 110));
        gridLayout = new QGridLayout(ADCGroupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ADCLabel1 = new QLabel(ADCGroupBox);
        ADCLabel1->setObjectName(QStringLiteral("ADCLabel1"));

        verticalLayout->addWidget(ADCLabel1);

        ADCLabel2 = new QLabel(ADCGroupBox);
        ADCLabel2->setObjectName(QStringLiteral("ADCLabel2"));

        verticalLayout->addWidget(ADCLabel2);

        ADCLabel3 = new QLabel(ADCGroupBox);
        ADCLabel3->setObjectName(QStringLiteral("ADCLabel3"));

        verticalLayout->addWidget(ADCLabel3);

        ADCLabel4 = new QLabel(ADCGroupBox);
        ADCLabel4->setObjectName(QStringLiteral("ADCLabel4"));

        verticalLayout->addWidget(ADCLabel4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_6->addWidget(ADCGroupBox, 0, 0, 1, 1);

        DACGroupBox = new QGroupBox(statusValuesGroupBox);
        DACGroupBox->setObjectName(QStringLiteral("DACGroupBox"));
        DACGroupBox->setMinimumSize(QSize(100, 110));
        gridLayout_2 = new QGridLayout(DACGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        DACLabel1 = new QLabel(DACGroupBox);
        DACLabel1->setObjectName(QStringLiteral("DACLabel1"));

        verticalLayout_2->addWidget(DACLabel1);

        DACLabel2 = new QLabel(DACGroupBox);
        DACLabel2->setObjectName(QStringLiteral("DACLabel2"));

        verticalLayout_2->addWidget(DACLabel2);

        DACLabel3 = new QLabel(DACGroupBox);
        DACLabel3->setObjectName(QStringLiteral("DACLabel3"));

        verticalLayout_2->addWidget(DACLabel3);

        DACLabel4 = new QLabel(DACGroupBox);
        DACLabel4->setObjectName(QStringLiteral("DACLabel4"));

        verticalLayout_2->addWidget(DACLabel4);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_6->addWidget(DACGroupBox, 0, 1, 1, 1);

        switchesGroupBox = new QGroupBox(statusValuesGroupBox);
        switchesGroupBox->setObjectName(QStringLiteral("switchesGroupBox"));
        switchesGroupBox->setMinimumSize(QSize(260, 150));
        switchesGroupBox->setMaximumSize(QSize(16777215, 180));
        gridLayout_9 = new QGridLayout(switchesGroupBox);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        InputSelectGroupBox = new QGroupBox(switchesGroupBox);
        InputSelectGroupBox->setObjectName(QStringLiteral("InputSelectGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(InputSelectGroupBox->sizePolicy().hasHeightForWidth());
        InputSelectGroupBox->setSizePolicy(sizePolicy1);
        InputSelectGroupBox->setMinimumSize(QSize(135, 100));
        InputSelectGroupBox->setMaximumSize(QSize(16777215, 110));
        InputSelectGroupBox->setCheckable(false);
        gridLayout_3 = new QGridLayout(InputSelectGroupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        InputSelectRadioButton0 = new QRadioButton(InputSelectGroupBox);
        InputSelectRadioButton0->setObjectName(QStringLiteral("InputSelectRadioButton0"));
        InputSelectRadioButton0->setChecked(false);

        gridLayout_3->addWidget(InputSelectRadioButton0, 0, 0, 1, 1);

        InputSelectRadioButton4 = new QRadioButton(InputSelectGroupBox);
        InputSelectRadioButton4->setObjectName(QStringLiteral("InputSelectRadioButton4"));
        InputSelectRadioButton4->setChecked(false);

        gridLayout_3->addWidget(InputSelectRadioButton4, 0, 1, 1, 1);

        InputSelectRadioButton1 = new QRadioButton(InputSelectGroupBox);
        InputSelectRadioButton1->setObjectName(QStringLiteral("InputSelectRadioButton1"));
        InputSelectRadioButton1->setChecked(true);

        gridLayout_3->addWidget(InputSelectRadioButton1, 1, 0, 1, 1);

        InputSelectRadioButton5 = new QRadioButton(InputSelectGroupBox);
        InputSelectRadioButton5->setObjectName(QStringLiteral("InputSelectRadioButton5"));
        InputSelectRadioButton5->setChecked(false);

        gridLayout_3->addWidget(InputSelectRadioButton5, 1, 1, 1, 1);

        InputSelectRadioButton2 = new QRadioButton(InputSelectGroupBox);
        InputSelectRadioButton2->setObjectName(QStringLiteral("InputSelectRadioButton2"));
        InputSelectRadioButton2->setChecked(false);

        gridLayout_3->addWidget(InputSelectRadioButton2, 2, 0, 1, 1);

        InputSelectRadioButton6 = new QRadioButton(InputSelectGroupBox);
        InputSelectRadioButton6->setObjectName(QStringLiteral("InputSelectRadioButton6"));
        InputSelectRadioButton6->setChecked(false);

        gridLayout_3->addWidget(InputSelectRadioButton6, 2, 1, 1, 1);

        InputSelectRadioButton3 = new QRadioButton(InputSelectGroupBox);
        InputSelectRadioButton3->setObjectName(QStringLiteral("InputSelectRadioButton3"));
        InputSelectRadioButton3->setChecked(false);

        gridLayout_3->addWidget(InputSelectRadioButton3, 3, 0, 1, 1);

        InputSelectRadioButton7 = new QRadioButton(InputSelectGroupBox);
        InputSelectRadioButton7->setObjectName(QStringLiteral("InputSelectRadioButton7"));
        InputSelectRadioButton7->setChecked(false);

        gridLayout_3->addWidget(InputSelectRadioButton7, 3, 1, 1, 1);


        gridLayout_9->addWidget(InputSelectGroupBox, 0, 0, 1, 1);

        groupBox = new QGroupBox(switchesGroupBox);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 100));
        groupBox->setMaximumSize(QSize(16777215, 110));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        biasEnableCheckBox = new QCheckBox(groupBox);
        biasEnableCheckBox->setObjectName(QStringLiteral("biasEnableCheckBox"));
        biasEnableCheckBox->setChecked(false);

        gridLayout_4->addWidget(biasEnableCheckBox, 0, 0, 1, 1);

        highGainCheckBox = new QCheckBox(groupBox);
        highGainCheckBox->setObjectName(QStringLiteral("highGainCheckBox"));

        gridLayout_4->addWidget(highGainCheckBox, 1, 0, 1, 1);

        preamp1CheckBox = new QCheckBox(groupBox);
        preamp1CheckBox->setObjectName(QStringLiteral("preamp1CheckBox"));

        gridLayout_4->addWidget(preamp1CheckBox, 2, 0, 1, 1);

        preamp2CheckBox = new QCheckBox(groupBox);
        preamp2CheckBox->setObjectName(QStringLiteral("preamp2CheckBox"));

        gridLayout_4->addWidget(preamp2CheckBox, 3, 0, 1, 1);


        gridLayout_9->addWidget(groupBox, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(switchesGroupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        triggerSelectionComboBox = new QComboBox(switchesGroupBox);
        triggerSelectionComboBox->setObjectName(QStringLiteral("triggerSelectionComboBox"));

        horizontalLayout->addWidget(triggerSelectionComboBox);


        gridLayout_9->addLayout(horizontalLayout, 1, 0, 1, 2);


        gridLayout_6->addWidget(switchesGroupBox, 0, 2, 3, 1);

        temperatureLabel = new QLabel(statusValuesGroupBox);
        temperatureLabel->setObjectName(QStringLiteral("temperatureLabel"));
        temperatureLabel->setFrameShape(QFrame::Box);
        temperatureLabel->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(temperatureLabel, 1, 0, 1, 2);

        timePulseLabel = new QLabel(statusValuesGroupBox);
        timePulseLabel->setObjectName(QStringLiteral("timePulseLabel"));
        timePulseLabel->setFrameShape(QFrame::Box);
        timePulseLabel->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(timePulseLabel, 2, 0, 1, 2);


        gridLayout_7->addWidget(statusValuesGroupBox, 1, 0, 1, 1);


        retranslateUi(Status);

        QMetaObject::connectSlotsByName(Status);
    } // setupUi

    void retranslateUi(QWidget *Status)
    {
        Status->setWindowTitle(QApplication::translate("Status", "Form", nullptr));
        ratePlotGroupBox->setTitle(QApplication::translate("Status", "Rate", nullptr));
        resetRatePushButton->setText(QApplication::translate("Status", "Reset", nullptr));
        pulseHeightHistogramGroupBox->setTitle(QApplication::translate("Status", "Pulse Height Histogram", nullptr));
        histoLogYCheckBox->setText(QApplication::translate("Status", "log Y", nullptr));
        PulseHeightHistogramEntriesLabel->setText(QApplication::translate("Status", "0 entries", nullptr));
        resetHistoPushButton->setText(QApplication::translate("Status", "Reset", nullptr));
        statusValuesGroupBox->setTitle(QApplication::translate("Status", "Status", nullptr));
        ADCGroupBox->setTitle(QApplication::translate("Status", "ADC Voltages", nullptr));
        ADCLabel1->setText(QApplication::translate("Status", "Ch1: ", nullptr));
        ADCLabel2->setText(QApplication::translate("Status", "Ch2: ", nullptr));
        ADCLabel3->setText(QApplication::translate("Status", "Ch3: ", nullptr));
        ADCLabel4->setText(QApplication::translate("Status", "Ch4: ", nullptr));
        DACGroupBox->setTitle(QApplication::translate("Status", "DAC Voltages", nullptr));
        DACLabel1->setText(QApplication::translate("Status", "Ch1: ", nullptr));
        DACLabel2->setText(QApplication::translate("Status", "Ch2: ", nullptr));
        DACLabel3->setText(QApplication::translate("Status", "Ch3: ", nullptr));
        DACLabel4->setText(QApplication::translate("Status", "Ch4: ", nullptr));
        switchesGroupBox->setTitle(QApplication::translate("Status", "Configuration", nullptr));
        InputSelectGroupBox->setTitle(QApplication::translate("Status", "Timing Input", nullptr));
        InputSelectRadioButton0->setText(QApplication::translate("Status", "AND", nullptr));
        InputSelectRadioButton4->setText(QApplication::translate("Status", "IN4", nullptr));
        InputSelectRadioButton1->setText(QApplication::translate("Status", "XOR", nullptr));
        InputSelectRadioButton5->setText(QApplication::translate("Status", "IN5", nullptr));
        InputSelectRadioButton2->setText(QApplication::translate("Status", "DISCR1", nullptr));
        InputSelectRadioButton6->setText(QApplication::translate("Status", "IN6", nullptr));
        InputSelectRadioButton3->setText(QApplication::translate("Status", "DISCR2", nullptr));
        InputSelectRadioButton7->setText(QApplication::translate("Status", "IN7", nullptr));
        groupBox->setTitle(QApplication::translate("Status", "Switches", nullptr));
        biasEnableCheckBox->setText(QApplication::translate("Status", "Bias On", nullptr));
        highGainCheckBox->setText(QApplication::translate("Status", "High Gain", nullptr));
        preamp1CheckBox->setText(QApplication::translate("Status", "Preamp 1", nullptr));
        preamp2CheckBox->setText(QApplication::translate("Status", "Preamp 2", nullptr));
        label->setText(QApplication::translate("Status", "ADC Trigger Input:", nullptr));
        temperatureLabel->setText(QApplication::translate("Status", "Temperature:", nullptr));
        timePulseLabel->setText(QApplication::translate("Status", "Time Pulse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Status: public Ui_Status {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUS_H
