/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionmeasurement;
    QAction *actionsettings;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *ipLabel;
    QComboBox *ipBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ipButton;
    QSpacerItem *horizontalSpacer_4;
    QLabel *ipStatusLabel;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *discr1Layout;
    QLabel *discr1Label;
    QSlider *discr1Slider;
    QLineEdit *discr1Edit;
    QVBoxLayout *discr2Layout;
    QLabel *discr2Label;
    QSlider *discr2Slider;
    QLineEdit *discr2Edit;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QComboBox *biasControlTypeComboBox;
    QSlider *biasVoltageSlider;
    QDoubleSpinBox *biasVoltageDoubleSpinBox;
    QLabel *biasPowerLabel;
    QPushButton *biasPowerButton;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *XORHit;
    QLabel *ANDHit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *rate1;
    QLabel *rate2;
    QTabWidget *tabWidget;
    QWidget *widget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(816, 720);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionmeasurement = new QAction(MainWindow);
        actionmeasurement->setObjectName(QString::fromUtf8("actionmeasurement"));
        actionsettings = new QAction(MainWindow);
        actionsettings->setObjectName(QString::fromUtf8("actionsettings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ipLabel = new QLabel(centralWidget);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));

        horizontalLayout->addWidget(ipLabel);

        ipBox = new QComboBox(centralWidget);
        ipBox->setObjectName(QString::fromUtf8("ipBox"));
        ipBox->setMinimumSize(QSize(200, 22));
        ipBox->setFocusPolicy(Qt::WheelFocus);
        ipBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        ipBox->setEditable(true);
        ipBox->setCurrentText(QString::fromUtf8(""));
        ipBox->setInsertPolicy(QComboBox::InsertAlphabetically);
        ipBox->setMinimumContentsLength(1);

        horizontalLayout->addWidget(ipBox);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        ipButton = new QPushButton(centralWidget);
        ipButton->setObjectName(QString::fromUtf8("ipButton"));

        horizontalLayout->addWidget(ipButton);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        ipStatusLabel = new QLabel(centralWidget);
        ipStatusLabel->setObjectName(QString::fromUtf8("ipStatusLabel"));
        ipStatusLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(ipStatusLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 1, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        discr1Layout = new QVBoxLayout();
        discr1Layout->setSpacing(6);
        discr1Layout->setObjectName(QString::fromUtf8("discr1Layout"));
        discr1Label = new QLabel(centralWidget);
        discr1Label->setObjectName(QString::fromUtf8("discr1Label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(discr1Label->sizePolicy().hasHeightForWidth());
        discr1Label->setSizePolicy(sizePolicy1);
        discr1Label->setMinimumSize(QSize(53, 0));
        discr1Label->setAlignment(Qt::AlignCenter);

        discr1Layout->addWidget(discr1Label);

        discr1Slider = new QSlider(centralWidget);
        discr1Slider->setObjectName(QString::fromUtf8("discr1Slider"));
        discr1Slider->setMaximum(8191);
        discr1Slider->setOrientation(Qt::Vertical);

        discr1Layout->addWidget(discr1Slider);

        discr1Edit = new QLineEdit(centralWidget);
        discr1Edit->setObjectName(QString::fromUtf8("discr1Edit"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(discr1Edit->sizePolicy().hasHeightForWidth());
        discr1Edit->setSizePolicy(sizePolicy2);
        discr1Edit->setMinimumSize(QSize(65, 24));
        discr1Edit->setBaseSize(QSize(51, 0));
        discr1Edit->setAlignment(Qt::AlignCenter);

        discr1Layout->addWidget(discr1Edit);


        horizontalLayout_2->addLayout(discr1Layout);

        discr2Layout = new QVBoxLayout();
        discr2Layout->setSpacing(6);
        discr2Layout->setObjectName(QString::fromUtf8("discr2Layout"));
        discr2Label = new QLabel(centralWidget);
        discr2Label->setObjectName(QString::fromUtf8("discr2Label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(discr2Label->sizePolicy().hasHeightForWidth());
        discr2Label->setSizePolicy(sizePolicy3);
        discr2Label->setMinimumSize(QSize(53, 0));
        discr2Label->setAlignment(Qt::AlignCenter);

        discr2Layout->addWidget(discr2Label);

        discr2Slider = new QSlider(centralWidget);
        discr2Slider->setObjectName(QString::fromUtf8("discr2Slider"));
        discr2Slider->setMaximum(8191);
        discr2Slider->setOrientation(Qt::Vertical);

        discr2Layout->addWidget(discr2Slider);

        discr2Edit = new QLineEdit(centralWidget);
        discr2Edit->setObjectName(QString::fromUtf8("discr2Edit"));
        discr2Edit->setEnabled(true);
        sizePolicy2.setHeightForWidth(discr2Edit->sizePolicy().hasHeightForWidth());
        discr2Edit->setSizePolicy(sizePolicy2);
        discr2Edit->setMinimumSize(QSize(65, 24));
        discr2Edit->setBaseSize(QSize(51, 0));
        discr2Edit->setAlignment(Qt::AlignCenter);

        discr2Layout->addWidget(discr2Edit);


        horizontalLayout_2->addLayout(discr2Layout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        biasControlTypeComboBox = new QComboBox(centralWidget);
        biasControlTypeComboBox->addItem(QString());
        biasControlTypeComboBox->addItem(QString());
        biasControlTypeComboBox->setObjectName(QString::fromUtf8("biasControlTypeComboBox"));

        verticalLayout->addWidget(biasControlTypeComboBox);

        biasVoltageSlider = new QSlider(centralWidget);
        biasVoltageSlider->setObjectName(QString::fromUtf8("biasVoltageSlider"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(biasVoltageSlider->sizePolicy().hasHeightForWidth());
        biasVoltageSlider->setSizePolicy(sizePolicy4);
        biasVoltageSlider->setValue(10);
        biasVoltageSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(biasVoltageSlider);

        biasVoltageDoubleSpinBox = new QDoubleSpinBox(centralWidget);
        biasVoltageDoubleSpinBox->setObjectName(QString::fromUtf8("biasVoltageDoubleSpinBox"));
        biasVoltageDoubleSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        biasVoltageDoubleSpinBox->setMaximum(3.300000000000000);
        biasVoltageDoubleSpinBox->setSingleStep(0.010000000000000);
        biasVoltageDoubleSpinBox->setValue(0.700000000000000);

        verticalLayout->addWidget(biasVoltageDoubleSpinBox);


        verticalLayout_2->addLayout(verticalLayout);

        biasPowerLabel = new QLabel(centralWidget);
        biasPowerLabel->setObjectName(QString::fromUtf8("biasPowerLabel"));
        biasPowerLabel->setFrameShape(QFrame::Box);
        biasPowerLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(biasPowerLabel);

        biasPowerButton = new QPushButton(centralWidget);
        biasPowerButton->setObjectName(QString::fromUtf8("biasPowerButton"));

        verticalLayout_2->addWidget(biasPowerButton);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        XORHit = new QLabel(centralWidget);
        XORHit->setObjectName(QString::fromUtf8("XORHit"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(54);
        sizePolicy5.setVerticalStretch(24);
        sizePolicy5.setHeightForWidth(XORHit->sizePolicy().hasHeightForWidth());
        XORHit->setSizePolicy(sizePolicy5);
        XORHit->setMinimumSize(QSize(54, 24));
        XORHit->setFrameShape(QFrame::Box);
        XORHit->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(XORHit);

        ANDHit = new QLabel(centralWidget);
        ANDHit->setObjectName(QString::fromUtf8("ANDHit"));
        sizePolicy5.setHeightForWidth(ANDHit->sizePolicy().hasHeightForWidth());
        ANDHit->setSizePolicy(sizePolicy5);
        ANDHit->setMinimumSize(QSize(54, 24));
        ANDHit->setFrameShape(QFrame::Box);
        ANDHit->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(ANDHit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        rate1 = new QLabel(centralWidget);
        rate1->setObjectName(QString::fromUtf8("rate1"));
        sizePolicy5.setHeightForWidth(rate1->sizePolicy().hasHeightForWidth());
        rate1->setSizePolicy(sizePolicy5);
        rate1->setMinimumSize(QSize(54, 24));
        rate1->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(rate1);

        rate2 = new QLabel(centralWidget);
        rate2->setObjectName(QString::fromUtf8("rate2"));
        sizePolicy5.setHeightForWidth(rate2->sizePolicy().hasHeightForWidth());
        rate2->setSizePolicy(sizePolicy5);
        rate2->setMinimumSize(QSize(54, 24));
        rate2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(rate2);


        verticalLayout_2->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setUsesScrollButtons(false);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        tabWidget->addTab(widget, QString());

        gridLayout->addWidget(tabWidget, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "muondetector-gui", nullptr));
        actionmeasurement->setText(QApplication::translate("MainWindow", "data acquisition mode", nullptr));
        actionsettings->setText(QApplication::translate("MainWindow", "settings", nullptr));
        ipLabel->setText(QApplication::translate("MainWindow", "connect to:", nullptr));
        ipButton->setText(QApplication::translate("MainWindow", "connect", nullptr));
        ipStatusLabel->setText(QApplication::translate("MainWindow", "not connected", nullptr));
        discr1Label->setText(QApplication::translate("MainWindow", "thres1", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        discr1Slider->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        discr2Label->setText(QApplication::translate("MainWindow", "thres2", nullptr));
        biasControlTypeComboBox->setItemText(0, QApplication::translate("MainWindow", "Bias DAC Control", nullptr));
        biasControlTypeComboBox->setItemText(1, QApplication::translate("MainWindow", "Bias Voltage", nullptr));

        biasVoltageDoubleSpinBox->setSuffix(QApplication::translate("MainWindow", "V", nullptr));
        biasPowerLabel->setText(QApplication::translate("MainWindow", "Bias OFF", nullptr));
        biasPowerButton->setText(QApplication::translate("MainWindow", "Enable Bias", nullptr));
        XORHit->setText(QApplication::translate("MainWindow", "XOR", nullptr));
        ANDHit->setText(QApplication::translate("MainWindow", "AND", nullptr));
        rate1->setText(QApplication::translate("MainWindow", "xRate", nullptr));
        rate2->setText(QApplication::translate("MainWindow", "aRate", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget), QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
