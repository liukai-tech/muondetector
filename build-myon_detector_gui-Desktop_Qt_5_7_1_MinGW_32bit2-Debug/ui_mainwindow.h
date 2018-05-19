/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionmeasurement;
    QAction *actionsettings;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *ipLabel;
    QFontComboBox *ipBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *bufferUsageLabel;
    QProgressBar *uartBuffer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *discr1Layout;
    QLabel *discr1Label;
    QSlider *discr1Slider;
    QLineEdit *discr1Edit;
    QVBoxLayout *discr2Layout;
    QLabel *discr2Label;
    QSlider *discr2Slider;
    QLineEdit *discr2Edit;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuoverview;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(569, 473);
        actionmeasurement = new QAction(MainWindow);
        actionmeasurement->setObjectName(QStringLiteral("actionmeasurement"));
        actionsettings = new QAction(MainWindow);
        actionsettings->setObjectName(QStringLiteral("actionsettings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ipLabel = new QLabel(centralWidget);
        ipLabel->setObjectName(QStringLiteral("ipLabel"));

        horizontalLayout->addWidget(ipLabel);

        ipBox = new QFontComboBox(centralWidget);
        ipBox->setObjectName(QStringLiteral("ipBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ipBox->sizePolicy().hasHeightForWidth());
        ipBox->setSizePolicy(sizePolicy);
        ipBox->setMaximumSize(QSize(300, 16777215));
        ipBox->setCurrentText(QStringLiteral("localhost"));

        horizontalLayout->addWidget(ipBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        bufferUsageLabel = new QLabel(centralWidget);
        bufferUsageLabel->setObjectName(QStringLiteral("bufferUsageLabel"));

        verticalLayout->addWidget(bufferUsageLabel);

        uartBuffer = new QProgressBar(centralWidget);
        uartBuffer->setObjectName(QStringLiteral("uartBuffer"));
        uartBuffer->setValue(0);

        verticalLayout->addWidget(uartBuffer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        discr1Layout = new QVBoxLayout();
        discr1Layout->setSpacing(6);
        discr1Layout->setObjectName(QStringLiteral("discr1Layout"));
        discr1Label = new QLabel(centralWidget);
        discr1Label->setObjectName(QStringLiteral("discr1Label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(discr1Label->sizePolicy().hasHeightForWidth());
        discr1Label->setSizePolicy(sizePolicy1);
        discr1Label->setMinimumSize(QSize(53, 0));

        discr1Layout->addWidget(discr1Label);

        discr1Slider = new QSlider(centralWidget);
        discr1Slider->setObjectName(QStringLiteral("discr1Slider"));
        discr1Slider->setOrientation(Qt::Vertical);

        discr1Layout->addWidget(discr1Slider);

        discr1Edit = new QLineEdit(centralWidget);
        discr1Edit->setObjectName(QStringLiteral("discr1Edit"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(discr1Edit->sizePolicy().hasHeightForWidth());
        discr1Edit->setSizePolicy(sizePolicy2);
        discr1Edit->setBaseSize(QSize(51, 0));

        discr1Layout->addWidget(discr1Edit);


        horizontalLayout_2->addLayout(discr1Layout);

        discr2Layout = new QVBoxLayout();
        discr2Layout->setSpacing(6);
        discr2Layout->setObjectName(QStringLiteral("discr2Layout"));
        discr2Label = new QLabel(centralWidget);
        discr2Label->setObjectName(QStringLiteral("discr2Label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(discr2Label->sizePolicy().hasHeightForWidth());
        discr2Label->setSizePolicy(sizePolicy3);
        discr2Label->setMinimumSize(QSize(53, 0));

        discr2Layout->addWidget(discr2Label);

        discr2Slider = new QSlider(centralWidget);
        discr2Slider->setObjectName(QStringLiteral("discr2Slider"));
        discr2Slider->setOrientation(Qt::Vertical);

        discr2Layout->addWidget(discr2Slider);

        discr2Edit = new QLineEdit(centralWidget);
        discr2Edit->setObjectName(QStringLiteral("discr2Edit"));
        discr2Edit->setEnabled(true);
        sizePolicy2.setHeightForWidth(discr2Edit->sizePolicy().hasHeightForWidth());
        discr2Edit->setSizePolicy(sizePolicy2);
        discr2Edit->setBaseSize(QSize(51, 0));

        discr2Layout->addWidget(discr2Edit);


        horizontalLayout_2->addLayout(discr2Layout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 569, 25));
        menuoverview = new QMenu(menuBar);
        menuoverview->setObjectName(QStringLiteral("menuoverview"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuoverview->menuAction());
        menuoverview->addAction(actionmeasurement);
        menuoverview->addAction(actionsettings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "myon detector overview", Q_NULLPTR));
        actionmeasurement->setText(QApplication::translate("MainWindow", "measurement", Q_NULLPTR));
        actionsettings->setText(QApplication::translate("MainWindow", "settings", Q_NULLPTR));
        ipLabel->setText(QApplication::translate("MainWindow", "connect to:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "not connected", Q_NULLPTR));
        bufferUsageLabel->setText(QApplication::translate("MainWindow", "buffer usage:", Q_NULLPTR));
        discr1Label->setText(QApplication::translate("MainWindow", "thres1", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        discr1Slider->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        discr2Label->setText(QApplication::translate("MainWindow", "thres2", Q_NULLPTR));
        menuoverview->setTitle(QApplication::translate("MainWindow", "menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
