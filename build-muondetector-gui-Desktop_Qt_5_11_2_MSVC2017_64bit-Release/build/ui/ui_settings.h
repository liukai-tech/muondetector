/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout;
    QGroupBox *gnssConfigGroupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *numTrkChannelsLabel;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *gnssGpsCheckBox;
    QCheckBox *gnssGalCheckBox;
    QCheckBox *gnssGlnsCheckBox;
    QCheckBox *gnssBeidCheckBox;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *gnssSbasCheckBox;
    QCheckBox *gnssQzssCheckBox;
    QCheckBox *gnssImesCheckBox;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *timePulseGroupBox;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *antDelayLineEdit;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *groupDelayLineEdit;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *userDelayLineEdit;
    QLabel *label_9;
    QGroupBox *syncedPulseGroupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QLineEdit *freqPeriodLockLineEdit;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_16;
    QLineEdit *pulseLenLockLineEdit;
    QLabel *label_17;
    QCheckBox *tpActiveCheckBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_18;
    QComboBox *timeGridComboBox;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *lockGpsCheckBox;
    QCheckBox *lockOtherCheckBox;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_19;
    QCheckBox *tpPolarityCheckBox;
    QCheckBox *tpAlignTowCheckBox;
    QGroupBox *unsyncedPulseGroupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLineEdit *freqPeriodLineEdit;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QLineEdit *pulseLenLineEdit;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_5;
    QPushButton *saveConfigPushButton;
    QPushButton *ubxResetPushButton;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QDialogButtonBox *settingsButtonBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QTableWidget *ubloxSignalStates;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QProgressBar *rxBufProgressBar;
    QLabel *rxPeakLabel;
    QProgressBar *txBufProgressBar;
    QLabel *txPeakLabel;
    QButtonGroup *tpConfigButtonGroup;
    QButtonGroup *gnssConfigButtonGroup;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->setWindowModality(Qt::ApplicationModal);
        Settings->resize(622, 548);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        Settings->setSizeGripEnabled(true);
        Settings->setModal(true);
        gridLayout_6 = new QGridLayout(Settings);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gnssConfigGroupBox = new QGroupBox(Settings);
        gnssConfigGroupBox->setObjectName(QStringLiteral("gnssConfigGroupBox"));
        gnssConfigGroupBox->setMaximumSize(QSize(16777215, 140));
        gridLayout = new QGridLayout(gnssConfigGroupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(gnssConfigGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        numTrkChannelsLabel = new QLabel(gnssConfigGroupBox);
        numTrkChannelsLabel->setObjectName(QStringLiteral("numTrkChannelsLabel"));
        numTrkChannelsLabel->setFrameShape(QFrame::Box);
        numTrkChannelsLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(numTrkChannelsLabel);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gnssGpsCheckBox = new QCheckBox(gnssConfigGroupBox);
        gnssConfigButtonGroup = new QButtonGroup(Settings);
        gnssConfigButtonGroup->setObjectName(QStringLiteral("gnssConfigButtonGroup"));
        gnssConfigButtonGroup->setExclusive(false);
        gnssConfigButtonGroup->addButton(gnssGpsCheckBox);
        gnssGpsCheckBox->setObjectName(QStringLiteral("gnssGpsCheckBox"));

        verticalLayout_2->addWidget(gnssGpsCheckBox);

        gnssGalCheckBox = new QCheckBox(gnssConfigGroupBox);
        gnssConfigButtonGroup->addButton(gnssGalCheckBox);
        gnssGalCheckBox->setObjectName(QStringLiteral("gnssGalCheckBox"));

        verticalLayout_2->addWidget(gnssGalCheckBox);

        gnssGlnsCheckBox = new QCheckBox(gnssConfigGroupBox);
        gnssConfigButtonGroup->addButton(gnssGlnsCheckBox);
        gnssGlnsCheckBox->setObjectName(QStringLiteral("gnssGlnsCheckBox"));

        verticalLayout_2->addWidget(gnssGlnsCheckBox);

        gnssBeidCheckBox = new QCheckBox(gnssConfigGroupBox);
        gnssConfigButtonGroup->addButton(gnssBeidCheckBox);
        gnssBeidCheckBox->setObjectName(QStringLiteral("gnssBeidCheckBox"));

        verticalLayout_2->addWidget(gnssBeidCheckBox);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 2, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gnssSbasCheckBox = new QCheckBox(gnssConfigGroupBox);
        gnssConfigButtonGroup->addButton(gnssSbasCheckBox);
        gnssSbasCheckBox->setObjectName(QStringLiteral("gnssSbasCheckBox"));

        verticalLayout_3->addWidget(gnssSbasCheckBox);

        gnssQzssCheckBox = new QCheckBox(gnssConfigGroupBox);
        gnssConfigButtonGroup->addButton(gnssQzssCheckBox);
        gnssQzssCheckBox->setObjectName(QStringLiteral("gnssQzssCheckBox"));

        verticalLayout_3->addWidget(gnssQzssCheckBox);

        gnssImesCheckBox = new QCheckBox(gnssConfigGroupBox);
        gnssConfigButtonGroup->addButton(gnssImesCheckBox);
        gnssImesCheckBox->setObjectName(QStringLiteral("gnssImesCheckBox"));

        verticalLayout_3->addWidget(gnssImesCheckBox);


        gridLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        verticalLayout->addWidget(gnssConfigGroupBox);

        timePulseGroupBox = new QGroupBox(Settings);
        timePulseGroupBox->setObjectName(QStringLiteral("timePulseGroupBox"));
        gridLayout_4 = new QGridLayout(timePulseGroupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(timePulseGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        antDelayLineEdit = new QLineEdit(timePulseGroupBox);
        antDelayLineEdit->setObjectName(QStringLiteral("antDelayLineEdit"));
        antDelayLineEdit->setMinimumSize(QSize(35, 0));
        antDelayLineEdit->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(antDelayLineEdit);

        label_5 = new QLabel(timePulseGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(30, 16777215));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);


        gridLayout_4->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(timePulseGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        groupDelayLineEdit = new QLineEdit(timePulseGroupBox);
        groupDelayLineEdit->setObjectName(QStringLiteral("groupDelayLineEdit"));
        groupDelayLineEdit->setMinimumSize(QSize(30, 0));
        groupDelayLineEdit->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(groupDelayLineEdit);

        label_7 = new QLabel(timePulseGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(30, 16777215));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_7);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(timePulseGroupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        userDelayLineEdit = new QLineEdit(timePulseGroupBox);
        userDelayLineEdit->setObjectName(QStringLiteral("userDelayLineEdit"));
        userDelayLineEdit->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_4->addWidget(userDelayLineEdit);

        label_9 = new QLabel(timePulseGroupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(30, 16777215));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_9);


        gridLayout_4->addLayout(horizontalLayout_4, 1, 2, 1, 1);

        syncedPulseGroupBox = new QGroupBox(timePulseGroupBox);
        syncedPulseGroupBox->setObjectName(QStringLiteral("syncedPulseGroupBox"));
        gridLayout_2 = new QGridLayout(syncedPulseGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_12 = new QLabel(syncedPulseGroupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        QFont font;
        font.setPointSize(8);
        label_12->setFont(font);

        horizontalLayout_6->addWidget(label_12);

        freqPeriodLockLineEdit = new QLineEdit(syncedPulseGroupBox);
        freqPeriodLockLineEdit->setObjectName(QStringLiteral("freqPeriodLockLineEdit"));
        freqPeriodLockLineEdit->setMinimumSize(QSize(0, 16));

        horizontalLayout_6->addWidget(freqPeriodLockLineEdit);

        label_13 = new QLabel(syncedPulseGroupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_13);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_16 = new QLabel(syncedPulseGroupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);

        horizontalLayout_8->addWidget(label_16);

        pulseLenLockLineEdit = new QLineEdit(syncedPulseGroupBox);
        pulseLenLockLineEdit->setObjectName(QStringLiteral("pulseLenLockLineEdit"));
        pulseLenLockLineEdit->setMinimumSize(QSize(0, 16));

        horizontalLayout_8->addWidget(pulseLenLockLineEdit);

        label_17 = new QLabel(syncedPulseGroupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_17);


        gridLayout_2->addLayout(horizontalLayout_8, 1, 0, 1, 1);


        gridLayout_4->addWidget(syncedPulseGroupBox, 2, 2, 1, 1);

        tpActiveCheckBox = new QCheckBox(timePulseGroupBox);
        tpConfigButtonGroup = new QButtonGroup(Settings);
        tpConfigButtonGroup->setObjectName(QStringLiteral("tpConfigButtonGroup"));
        tpConfigButtonGroup->setExclusive(false);
        tpConfigButtonGroup->addButton(tpActiveCheckBox);
        tpActiveCheckBox->setObjectName(QStringLiteral("tpActiveCheckBox"));

        gridLayout_4->addWidget(tpActiveCheckBox, 3, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_18 = new QLabel(timePulseGroupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setLayoutDirection(Qt::LeftToRight);
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_18);

        timeGridComboBox = new QComboBox(timePulseGroupBox);
        timeGridComboBox->addItem(QString());
        timeGridComboBox->addItem(QString());
        timeGridComboBox->addItem(QString());
        timeGridComboBox->addItem(QString());
        timeGridComboBox->addItem(QString());
        timeGridComboBox->addItem(QString());
        timeGridComboBox->addItem(QString());
        timeGridComboBox->addItem(QString());
        timeGridComboBox->addItem(QString());
        timeGridComboBox->addItem(QString());
        timeGridComboBox->setObjectName(QStringLiteral("timeGridComboBox"));
        timeGridComboBox->setMinimumSize(QSize(55, 0));

        horizontalLayout_9->addWidget(timeGridComboBox);


        gridLayout_4->addLayout(horizontalLayout_9, 3, 2, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        lockGpsCheckBox = new QCheckBox(timePulseGroupBox);
        tpConfigButtonGroup->addButton(lockGpsCheckBox);
        lockGpsCheckBox->setObjectName(QStringLiteral("lockGpsCheckBox"));

        horizontalLayout_10->addWidget(lockGpsCheckBox);

        lockOtherCheckBox = new QCheckBox(timePulseGroupBox);
        tpConfigButtonGroup->addButton(lockOtherCheckBox);
        lockOtherCheckBox->setObjectName(QStringLiteral("lockOtherCheckBox"));

        horizontalLayout_10->addWidget(lockOtherCheckBox);


        gridLayout_4->addLayout(horizontalLayout_10, 4, 0, 1, 2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_19 = new QLabel(timePulseGroupBox);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_19);

        tpPolarityCheckBox = new QCheckBox(timePulseGroupBox);
        tpConfigButtonGroup->addButton(tpPolarityCheckBox);
        tpPolarityCheckBox->setObjectName(QStringLiteral("tpPolarityCheckBox"));

        horizontalLayout_11->addWidget(tpPolarityCheckBox);


        gridLayout_4->addLayout(horizontalLayout_11, 5, 0, 1, 1);

        tpAlignTowCheckBox = new QCheckBox(timePulseGroupBox);
        tpConfigButtonGroup->addButton(tpAlignTowCheckBox);
        tpAlignTowCheckBox->setObjectName(QStringLiteral("tpAlignTowCheckBox"));

        gridLayout_4->addWidget(tpAlignTowCheckBox, 5, 2, 1, 1);

        unsyncedPulseGroupBox = new QGroupBox(timePulseGroupBox);
        unsyncedPulseGroupBox->setObjectName(QStringLiteral("unsyncedPulseGroupBox"));
        unsyncedPulseGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        unsyncedPulseGroupBox->setFlat(false);
        unsyncedPulseGroupBox->setCheckable(false);
        gridLayout_3 = new QGridLayout(unsyncedPulseGroupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_10 = new QLabel(unsyncedPulseGroupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_5->addWidget(label_10);

        freqPeriodLineEdit = new QLineEdit(unsyncedPulseGroupBox);
        freqPeriodLineEdit->setObjectName(QStringLiteral("freqPeriodLineEdit"));
        freqPeriodLineEdit->setMinimumSize(QSize(0, 16));

        horizontalLayout_5->addWidget(freqPeriodLineEdit);

        label_11 = new QLabel(unsyncedPulseGroupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_11);


        gridLayout_3->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_14 = new QLabel(unsyncedPulseGroupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        horizontalLayout_7->addWidget(label_14);

        pulseLenLineEdit = new QLineEdit(unsyncedPulseGroupBox);
        pulseLenLineEdit->setObjectName(QStringLiteral("pulseLenLineEdit"));
        pulseLenLineEdit->setMinimumSize(QSize(0, 16));

        horizontalLayout_7->addWidget(pulseLenLineEdit);

        label_15 = new QLabel(unsyncedPulseGroupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_15);


        gridLayout_3->addLayout(horizontalLayout_7, 1, 0, 1, 1);


        gridLayout_4->addWidget(unsyncedPulseGroupBox, 2, 0, 1, 1);


        verticalLayout->addWidget(timePulseGroupBox);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        saveConfigPushButton = new QPushButton(Settings);
        saveConfigPushButton->setObjectName(QStringLiteral("saveConfigPushButton"));

        verticalLayout_5->addWidget(saveConfigPushButton);

        ubxResetPushButton = new QPushButton(Settings);
        ubxResetPushButton->setObjectName(QStringLiteral("ubxResetPushButton"));

        verticalLayout_5->addWidget(ubxResetPushButton);


        horizontalLayout_13->addLayout(verticalLayout_5);


        verticalLayout->addLayout(horizontalLayout_13);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        line = new QFrame(Settings);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        settingsButtonBox = new QDialogButtonBox(Settings);
        settingsButtonBox->setObjectName(QStringLiteral("settingsButtonBox"));
        settingsButtonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Discard|QDialogButtonBox::RestoreDefaults);

        verticalLayout->addWidget(settingsButtonBox);


        gridLayout_6->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(Settings);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(200);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(200, 0));
        label->setBaseSize(QSize(200, 0));
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        ubloxSignalStates = new QTableWidget(Settings);
        ubloxSignalStates->setObjectName(QStringLiteral("ubloxSignalStates"));
        ubloxSignalStates->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ubloxSignalStates->sizePolicy().hasHeightForWidth());
        ubloxSignalStates->setSizePolicy(sizePolicy2);
        ubloxSignalStates->setMinimumSize(QSize(260, 200));
        ubloxSignalStates->setSizeIncrement(QSize(0, 0));
        ubloxSignalStates->setBaseSize(QSize(320, 200));
        ubloxSignalStates->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(ubloxSignalStates);

        frame = new QFrame(Settings);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setMaximumSize(QSize(16777215, 60));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        rxBufProgressBar = new QProgressBar(frame);
        rxBufProgressBar->setObjectName(QStringLiteral("rxBufProgressBar"));
        rxBufProgressBar->setMinimumSize(QSize(40, 0));
        rxBufProgressBar->setBaseSize(QSize(100, 0));
        rxBufProgressBar->setValue(0);
        rxBufProgressBar->setAlignment(Qt::AlignCenter);
        rxBufProgressBar->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(rxBufProgressBar, 0, 0, 1, 1);

        rxPeakLabel = new QLabel(frame);
        rxPeakLabel->setObjectName(QStringLiteral("rxPeakLabel"));
        rxPeakLabel->setMinimumSize(QSize(50, 0));
        rxPeakLabel->setAutoFillBackground(false);
        rxPeakLabel->setFrameShape(QFrame::NoFrame);
        rxPeakLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(rxPeakLabel, 0, 1, 1, 1);

        txBufProgressBar = new QProgressBar(frame);
        txBufProgressBar->setObjectName(QStringLiteral("txBufProgressBar"));
        txBufProgressBar->setMinimumSize(QSize(40, 0));
        txBufProgressBar->setBaseSize(QSize(100, 0));
        txBufProgressBar->setValue(0);
        txBufProgressBar->setAlignment(Qt::AlignCenter);
        txBufProgressBar->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(txBufProgressBar, 1, 0, 1, 1);

        txPeakLabel = new QLabel(frame);
        txPeakLabel->setObjectName(QStringLiteral("txPeakLabel"));
        txPeakLabel->setMinimumSize(QSize(50, 0));
        txPeakLabel->setAutoFillBackground(false);
        txPeakLabel->setFrameShape(QFrame::NoFrame);
        txPeakLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(txPeakLabel, 1, 1, 1, 1);


        verticalLayout_4->addWidget(frame);


        gridLayout_6->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Settings", nullptr));
        gnssConfigGroupBox->setTitle(QApplication::translate("Settings", "GNSS Config", nullptr));
        label_2->setText(QApplication::translate("Settings", "Max. Tracking Channels:", nullptr));
        numTrkChannelsLabel->setText(QApplication::translate("Settings", "N/A", nullptr));
        gnssGpsCheckBox->setText(QApplication::translate("Settings", "GPS", nullptr));
        gnssGalCheckBox->setText(QApplication::translate("Settings", "Galileo", nullptr));
        gnssGlnsCheckBox->setText(QApplication::translate("Settings", "Glonass", nullptr));
        gnssBeidCheckBox->setText(QApplication::translate("Settings", "BEIDU", nullptr));
        gnssSbasCheckBox->setText(QApplication::translate("Settings", "SBAS", nullptr));
        gnssQzssCheckBox->setText(QApplication::translate("Settings", "QZSS", nullptr));
        gnssImesCheckBox->setText(QApplication::translate("Settings", "IMES", nullptr));
        timePulseGroupBox->setTitle(QApplication::translate("Settings", "Time Pulse Settings", nullptr));
        label_4->setText(QApplication::translate("Settings", "Antenna Delay", nullptr));
        label_5->setText(QApplication::translate("Settings", "ns", nullptr));
        label_6->setText(QApplication::translate("Settings", "Group Delay", nullptr));
        label_7->setText(QApplication::translate("Settings", "ns", nullptr));
        label_8->setText(QApplication::translate("Settings", "User Delay", nullptr));
        label_9->setText(QApplication::translate("Settings", "ns", nullptr));
        syncedPulseGroupBox->setTitle(QApplication::translate("Settings", "synced", nullptr));
        label_12->setText(QApplication::translate("Settings", "period", nullptr));
        label_13->setText(QApplication::translate("Settings", "us", nullptr));
        label_16->setText(QApplication::translate("Settings", "pulse len", nullptr));
        label_17->setText(QApplication::translate("Settings", "us", nullptr));
        tpActiveCheckBox->setText(QApplication::translate("Settings", "Enabled", nullptr));
        label_18->setText(QApplication::translate("Settings", "time grid", nullptr));
        timeGridComboBox->setItemText(0, QApplication::translate("Settings", "UTC", nullptr));
        timeGridComboBox->setItemText(1, QApplication::translate("Settings", "GPS", nullptr));
        timeGridComboBox->setItemText(2, QApplication::translate("Settings", "GLONASS", nullptr));
        timeGridComboBox->setItemText(3, QApplication::translate("Settings", "BeiDou", nullptr));
        timeGridComboBox->setItemText(4, QApplication::translate("Settings", "Galileo", nullptr));
        timeGridComboBox->setItemText(5, QApplication::translate("Settings", "N/A", nullptr));
        timeGridComboBox->setItemText(6, QApplication::translate("Settings", "N/A", nullptr));
        timeGridComboBox->setItemText(7, QApplication::translate("Settings", "N/A", nullptr));
        timeGridComboBox->setItemText(8, QApplication::translate("Settings", "N/A", nullptr));
        timeGridComboBox->setItemText(9, QApplication::translate("Settings", "N/A", nullptr));

        lockGpsCheckBox->setText(QApplication::translate("Settings", "lock GPS", nullptr));
        lockOtherCheckBox->setText(QApplication::translate("Settings", "lock other", nullptr));
        label_19->setText(QApplication::translate("Settings", "Polarity", nullptr));
        tpPolarityCheckBox->setText(QApplication::translate("Settings", "rising edge", nullptr));
        tpAlignTowCheckBox->setText(QApplication::translate("Settings", "align to ToW", nullptr));
        unsyncedPulseGroupBox->setTitle(QApplication::translate("Settings", "unsynced", nullptr));
        label_10->setText(QApplication::translate("Settings", "period", nullptr));
        label_11->setText(QApplication::translate("Settings", "us", nullptr));
        label_14->setText(QApplication::translate("Settings", "pulse len", nullptr));
        label_15->setText(QApplication::translate("Settings", "us", nullptr));
        saveConfigPushButton->setText(QApplication::translate("Settings", "Save Config to Flash", nullptr));
        ubxResetPushButton->setText(QApplication::translate("Settings", "Reset Ublox Chip", nullptr));
        label->setText(QApplication::translate("Settings", "Ublox message settings", nullptr));
        rxBufProgressBar->setFormat(QApplication::translate("Settings", "RX Buffer: %p%", nullptr));
        rxPeakLabel->setText(QApplication::translate("Settings", "max: ", nullptr));
        txBufProgressBar->setFormat(QApplication::translate("Settings", "TX Buffer: %p%", nullptr));
        txPeakLabel->setText(QApplication::translate("Settings", "max: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
