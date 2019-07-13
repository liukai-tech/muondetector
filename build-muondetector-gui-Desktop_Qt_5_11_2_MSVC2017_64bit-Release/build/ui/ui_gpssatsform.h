/********************************************************************************
** Form generated from reading UI file 'gpssatsform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPSSATSFORM_H
#define UI_GPSSATSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GpsSatsForm
{
public:
    QGridLayout *gridLayout_7;
    QGroupBox *rxStatsGroupBox;
    QGridLayout *gridLayout_6;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLabel *ubxHwVersionLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLabel *ubxSwVersionLabel;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_14;
    QLabel *UBXprotLabel;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *fixTypeLabel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_17;
    QLabel *ubxUptimeLabel;
    QGroupBox *precisionGroupBox;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *timePrecisionLabel;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_15;
    QLabel *freqPrecisionLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *xyzResLabel;
    QGroupBox *lnaGroupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *lnaNoiseLabel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLabel *lnaAgcLabel;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLabel *antStatusLabel;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QLabel *antPowerLabel;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_16;
    QLabel *iqAlignmentLabel;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QProgressBar *jammingProgressBar;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLabel *intCounterLabel;
    QGroupBox *satsGroupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *nrSatsLabel;
    QCheckBox *visibleSatsCheckBox;
    QTableWidget *satsTableWidget;
    QLabel *satPosLabel;

    void setupUi(QWidget *GpsSatsForm)
    {
        if (GpsSatsForm->objectName().isEmpty())
            GpsSatsForm->setObjectName(QStringLiteral("GpsSatsForm"));
        GpsSatsForm->resize(537, 593);
        gridLayout_7 = new QGridLayout(GpsSatsForm);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        rxStatsGroupBox = new QGroupBox(GpsSatsForm);
        rxStatsGroupBox->setObjectName(QStringLiteral("rxStatsGroupBox"));
        gridLayout_6 = new QGridLayout(rxStatsGroupBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        frame = new QFrame(rxStatsGroupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::NoFrame);

        horizontalLayout_14->addWidget(label);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        ubxHwVersionLabel = new QLabel(frame);
        ubxHwVersionLabel->setObjectName(QStringLiteral("ubxHwVersionLabel"));
        ubxHwVersionLabel->setMinimumSize(QSize(80, 0));
        ubxHwVersionLabel->setFrameShape(QFrame::Box);
        ubxHwVersionLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(ubxHwVersionLabel);


        horizontalLayout_14->addLayout(horizontalLayout_9);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        ubxSwVersionLabel = new QLabel(frame);
        ubxSwVersionLabel->setObjectName(QStringLiteral("ubxSwVersionLabel"));
        ubxSwVersionLabel->setMinimumSize(QSize(95, 0));
        ubxSwVersionLabel->setFrameShape(QFrame::Box);
        ubxSwVersionLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(ubxSwVersionLabel);


        horizontalLayout_14->addLayout(horizontalLayout);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_10->addWidget(label_14);

        UBXprotLabel = new QLabel(frame);
        UBXprotLabel->setObjectName(QStringLiteral("UBXprotLabel"));
        UBXprotLabel->setMinimumSize(QSize(50, 0));
        UBXprotLabel->setFrameShape(QFrame::Box);

        horizontalLayout_10->addWidget(UBXprotLabel);


        horizontalLayout_14->addLayout(horizontalLayout_10);


        gridLayout_5->addLayout(horizontalLayout_14, 0, 0, 1, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        fixTypeLabel = new QLabel(frame);
        fixTypeLabel->setObjectName(QStringLiteral("fixTypeLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fixTypeLabel->sizePolicy().hasHeightForWidth());
        fixTypeLabel->setSizePolicy(sizePolicy);
        fixTypeLabel->setFrameShape(QFrame::Box);
        fixTypeLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(fixTypeLabel);


        horizontalLayout_18->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_4);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_17->addWidget(label_17);

        ubxUptimeLabel = new QLabel(frame);
        ubxUptimeLabel->setObjectName(QStringLiteral("ubxUptimeLabel"));
        ubxUptimeLabel->setMinimumSize(QSize(30, 0));
        ubxUptimeLabel->setFrameShape(QFrame::Box);
        ubxUptimeLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(ubxUptimeLabel);


        horizontalLayout_18->addLayout(horizontalLayout_17);


        gridLayout_5->addLayout(horizontalLayout_18, 1, 0, 1, 1);


        gridLayout_6->addWidget(frame, 0, 0, 1, 2);

        precisionGroupBox = new QGroupBox(rxStatsGroupBox);
        precisionGroupBox->setObjectName(QStringLiteral("precisionGroupBox"));
        gridLayout_4 = new QGridLayout(precisionGroupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(precisionGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        timePrecisionLabel = new QLabel(precisionGroupBox);
        timePrecisionLabel->setObjectName(QStringLiteral("timePrecisionLabel"));
        timePrecisionLabel->setFrameShape(QFrame::Box);
        timePrecisionLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(timePrecisionLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_15 = new QLabel(precisionGroupBox);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_15->addWidget(label_15);

        freqPrecisionLabel = new QLabel(precisionGroupBox);
        freqPrecisionLabel->setObjectName(QStringLiteral("freqPrecisionLabel"));
        freqPrecisionLabel->setFrameShape(QFrame::Box);
        freqPrecisionLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(freqPrecisionLabel);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(precisionGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        xyzResLabel = new QLabel(precisionGroupBox);
        xyzResLabel->setObjectName(QStringLiteral("xyzResLabel"));
        xyzResLabel->setMinimumSize(QSize(80, 0));
        xyzResLabel->setFrameShape(QFrame::Box);
        xyzResLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(xyzResLabel);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_6->addWidget(precisionGroupBox, 1, 0, 1, 1);

        lnaGroupBox = new QGroupBox(rxStatsGroupBox);
        lnaGroupBox->setObjectName(QStringLiteral("lnaGroupBox"));
        gridLayout_2 = new QGridLayout(lnaGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(lnaGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lnaNoiseLabel = new QLabel(lnaGroupBox);
        lnaNoiseLabel->setObjectName(QStringLiteral("lnaNoiseLabel"));
        sizePolicy.setHeightForWidth(lnaNoiseLabel->sizePolicy().hasHeightForWidth());
        lnaNoiseLabel->setSizePolicy(sizePolicy);
        lnaNoiseLabel->setFrameShape(QFrame::Box);
        lnaNoiseLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lnaNoiseLabel);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(lnaGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lnaAgcLabel = new QLabel(lnaGroupBox);
        lnaAgcLabel->setObjectName(QStringLiteral("lnaAgcLabel"));
        sizePolicy.setHeightForWidth(lnaAgcLabel->sizePolicy().hasHeightForWidth());
        lnaAgcLabel->setSizePolicy(sizePolicy);
        lnaAgcLabel->setFrameShape(QFrame::Box);
        lnaAgcLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lnaAgcLabel);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(lnaGroupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_11->addWidget(label_11);

        antStatusLabel = new QLabel(lnaGroupBox);
        antStatusLabel->setObjectName(QStringLiteral("antStatusLabel"));
        sizePolicy.setHeightForWidth(antStatusLabel->sizePolicy().hasHeightForWidth());
        antStatusLabel->setSizePolicy(sizePolicy);
        antStatusLabel->setFrameShape(QFrame::Box);
        antStatusLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(antStatusLabel);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_12 = new QLabel(lnaGroupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_12->addWidget(label_12);

        antPowerLabel = new QLabel(lnaGroupBox);
        antPowerLabel->setObjectName(QStringLiteral("antPowerLabel"));
        sizePolicy.setHeightForWidth(antPowerLabel->sizePolicy().hasHeightForWidth());
        antPowerLabel->setSizePolicy(sizePolicy);
        antPowerLabel->setFrameShape(QFrame::Box);
        antPowerLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(antPowerLabel);


        verticalLayout_2->addLayout(horizontalLayout_12);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_16 = new QLabel(lnaGroupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        QFont font;
        font.setPointSize(7);
        label_16->setFont(font);
        label_16->setFrameShape(QFrame::Box);
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_16);

        iqAlignmentLabel = new QLabel(lnaGroupBox);
        iqAlignmentLabel->setObjectName(QStringLiteral("iqAlignmentLabel"));
        iqAlignmentLabel->setMinimumSize(QSize(65, 65));
        iqAlignmentLabel->setFrameShape(QFrame::Box);
        iqAlignmentLabel->setScaledContents(true);

        verticalLayout_3->addWidget(iqAlignmentLabel);


        gridLayout_2->addLayout(verticalLayout_3, 0, 1, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_13 = new QLabel(lnaGroupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font1;
        font1.setPointSize(9);
        label_13->setFont(font1);
        label_13->setScaledContents(false);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setWordWrap(false);

        horizontalLayout_13->addWidget(label_13);

        jammingProgressBar = new QProgressBar(lnaGroupBox);
        jammingProgressBar->setObjectName(QStringLiteral("jammingProgressBar"));
        jammingProgressBar->setMaximum(100);
        jammingProgressBar->setValue(0);
        jammingProgressBar->setAlignment(Qt::AlignCenter);
        jammingProgressBar->setOrientation(Qt::Horizontal);
        jammingProgressBar->setTextDirection(QProgressBar::TopToBottom);

        horizontalLayout_13->addWidget(jammingProgressBar);


        gridLayout_2->addLayout(horizontalLayout_13, 1, 0, 1, 2);


        gridLayout_6->addWidget(lnaGroupBox, 1, 1, 2, 1);

        frame_2 = new QFrame(rxStatsGroupBox);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        intCounterLabel = new QLabel(frame_2);
        intCounterLabel->setObjectName(QStringLiteral("intCounterLabel"));
        intCounterLabel->setFrameShape(QFrame::Box);
        intCounterLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(intCounterLabel);


        gridLayout_3->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_2, 2, 0, 1, 1);


        gridLayout_7->addWidget(rxStatsGroupBox, 0, 0, 1, 1);

        satsGroupBox = new QGroupBox(GpsSatsForm);
        satsGroupBox->setObjectName(QStringLiteral("satsGroupBox"));
        gridLayout = new QGridLayout(satsGroupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(satsGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        nrSatsLabel = new QLabel(satsGroupBox);
        nrSatsLabel->setObjectName(QStringLiteral("nrSatsLabel"));
        nrSatsLabel->setFrameShape(QFrame::Box);
        nrSatsLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(nrSatsLabel);


        horizontalLayout_16->addLayout(horizontalLayout_3);

        visibleSatsCheckBox = new QCheckBox(satsGroupBox);
        visibleSatsCheckBox->setObjectName(QStringLiteral("visibleSatsCheckBox"));
        visibleSatsCheckBox->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_16->addWidget(visibleSatsCheckBox);


        gridLayout->addLayout(horizontalLayout_16, 0, 0, 1, 2);

        satsTableWidget = new QTableWidget(satsGroupBox);
        if (satsTableWidget->columnCount() < 11)
            satsTableWidget->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        satsTableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        satsTableWidget->setObjectName(QStringLiteral("satsTableWidget"));
        satsTableWidget->setAlternatingRowColors(true);
        satsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        satsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        satsTableWidget->setWordWrap(true);
        satsTableWidget->horizontalHeader()->setDefaultSectionSize(75);
        satsTableWidget->horizontalHeader()->setStretchLastSection(true);
        satsTableWidget->verticalHeader()->setDefaultSectionSize(24);

        gridLayout->addWidget(satsTableWidget, 1, 0, 1, 1);

        satPosLabel = new QLabel(satsGroupBox);
        satPosLabel->setObjectName(QStringLiteral("satPosLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(satPosLabel->sizePolicy().hasHeightForWidth());
        satPosLabel->setSizePolicy(sizePolicy1);
        satPosLabel->setMinimumSize(QSize(220, 220));
        satPosLabel->setAutoFillBackground(false);
        satPosLabel->setFrameShape(QFrame::Box);
        satPosLabel->setScaledContents(true);

        gridLayout->addWidget(satPosLabel, 1, 1, 1, 1);


        gridLayout_7->addWidget(satsGroupBox, 1, 0, 1, 1);


        retranslateUi(GpsSatsForm);

        QMetaObject::connectSlotsByName(GpsSatsForm);
    } // setupUi

    void retranslateUi(QWidget *GpsSatsForm)
    {
        GpsSatsForm->setWindowTitle(QApplication::translate("GpsSatsForm", "Form", nullptr));
        rxStatsGroupBox->setTitle(QApplication::translate("GpsSatsForm", "Receiver Status", nullptr));
        label->setText(QApplication::translate("GpsSatsForm", "Ublox Version", nullptr));
        label_9->setText(QApplication::translate("GpsSatsForm", "HW:", nullptr));
        ubxHwVersionLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        label_10->setText(QApplication::translate("GpsSatsForm", "SW:", nullptr));
        ubxSwVersionLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        label_14->setText(QApplication::translate("GpsSatsForm", "Protocol:", nullptr));
        UBXprotLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        label_4->setText(QApplication::translate("GpsSatsForm", "Position Fix", nullptr));
        fixTypeLabel->setText(QApplication::translate("GpsSatsForm", "No Fix", nullptr));
        label_17->setText(QApplication::translate("GpsSatsForm", "RX Uptime", nullptr));
        ubxUptimeLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        precisionGroupBox->setTitle(QApplication::translate("GpsSatsForm", "Precision", nullptr));
        label_3->setText(QApplication::translate("GpsSatsForm", "Time Precision", nullptr));
        timePrecisionLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        label_15->setText(QApplication::translate("GpsSatsForm", "Freq. Precision", nullptr));
        freqPrecisionLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        label_5->setText(QApplication::translate("GpsSatsForm", "Hor/Vert Resolution", nullptr));
        xyzResLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        lnaGroupBox->setTitle(QApplication::translate("GpsSatsForm", "LNA", nullptr));
        label_6->setText(QApplication::translate("GpsSatsForm", "Noise", nullptr));
        lnaNoiseLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        label_7->setText(QApplication::translate("GpsSatsForm", "AGC", nullptr));
        lnaAgcLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        label_11->setText(QApplication::translate("GpsSatsForm", "Ant Status", nullptr));
        antStatusLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        label_12->setText(QApplication::translate("GpsSatsForm", "Ant Power", nullptr));
        antPowerLabel->setText(QApplication::translate("GpsSatsForm", "N/A", nullptr));
        label_16->setText(QApplication::translate("GpsSatsForm", "I/Q Alignment", nullptr));
        iqAlignmentLabel->setText(QString());
        label_13->setText(QApplication::translate("GpsSatsForm", "Jamming Level", nullptr));
        jammingProgressBar->setFormat(QApplication::translate("GpsSatsForm", "%p%", nullptr));
        label_8->setText(QApplication::translate("GpsSatsForm", "Event Counter", nullptr));
        intCounterLabel->setText(QApplication::translate("GpsSatsForm", "0", nullptr));
        satsGroupBox->setTitle(QApplication::translate("GpsSatsForm", "GNSS Sat Data", nullptr));
        label_2->setText(QApplication::translate("GpsSatsForm", "Nr of received sats", nullptr));
        nrSatsLabel->setText(QApplication::translate("GpsSatsForm", "0", nullptr));
        visibleSatsCheckBox->setText(QApplication::translate("GpsSatsForm", "received sats only", nullptr));
        QTableWidgetItem *___qtablewidgetitem = satsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GpsSatsForm", "Sat ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = satsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GpsSatsForm", "GNSS Sys", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = satsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GpsSatsForm", "CNR (dBHz)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = satsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("GpsSatsForm", "Az (deg)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = satsTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("GpsSatsForm", "Elev (deg)", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = satsTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("GpsSatsForm", "Res (m)", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = satsTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("GpsSatsForm", "Quality", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = satsTableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("GpsSatsForm", "Health", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = satsTableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("GpsSatsForm", "Orbit Src", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = satsTableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("GpsSatsForm", "Used", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = satsTableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("GpsSatsForm", "Diff Corr", nullptr));
        satPosLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GpsSatsForm: public Ui_GpsSatsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPSSATSFORM_H
