/********************************************************************************
** Form generated from reading UI file 'histogramdataform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMDATAFORM_H
#define UI_HISTOGRAMDATAFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "custom_histogram_widget.h"

QT_BEGIN_NAMESPACE

class Ui_histogramDataForm
{
public:
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *nrHistosLabel;
    QTableWidget *tableWidget;
    QGroupBox *statsGroupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLabel *histoNameLabel;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLabel *nrBinsLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *nrEntriesLabel;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QLabel *minLabel;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_10;
    QLabel *maxLabel;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *underflowLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *overflowLabel;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *meanLabel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *rmsLabel;
    QFrame *frame;
    QGridLayout *gridLayout;
    CustomHistogram *histoWidget;

    void setupUi(QWidget *histogramDataForm)
    {
        if (histogramDataForm->objectName().isEmpty())
            histogramDataForm->setObjectName(QStringLiteral("histogramDataForm"));
        histogramDataForm->resize(500, 363);
        gridLayout_3 = new QGridLayout(histogramDataForm);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        splitter = new QSplitter(histogramDataForm);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nrHistosLabel = new QLabel(layoutWidget);
        nrHistosLabel->setObjectName(QStringLiteral("nrHistosLabel"));
        nrHistosLabel->setMaximumSize(QSize(80, 16777215));
        nrHistosLabel->setFrameShape(QFrame::Box);
        nrHistosLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(nrHistosLabel);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(layoutWidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget->horizontalHeader()->setMinimumSectionSize(70);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableWidget);

        statsGroupBox = new QGroupBox(layoutWidget);
        statsGroupBox->setObjectName(QStringLiteral("statsGroupBox"));
        gridLayout_2 = new QGridLayout(statsGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(statsGroupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        histoNameLabel = new QLabel(statsGroupBox);
        histoNameLabel->setObjectName(QStringLiteral("histoNameLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(histoNameLabel->sizePolicy().hasHeightForWidth());
        histoNameLabel->setSizePolicy(sizePolicy1);
        histoNameLabel->setFrameShape(QFrame::Box);
        histoNameLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(histoNameLabel);


        gridLayout_2->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(statsGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        nrBinsLabel = new QLabel(statsGroupBox);
        nrBinsLabel->setObjectName(QStringLiteral("nrBinsLabel"));
        nrBinsLabel->setFrameShape(QFrame::Box);
        nrBinsLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(nrBinsLabel);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(statsGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        nrEntriesLabel = new QLabel(statsGroupBox);
        nrEntriesLabel->setObjectName(QStringLiteral("nrEntriesLabel"));
        nrEntriesLabel->setFrameShape(QFrame::Box);
        nrEntriesLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(nrEntriesLabel);


        horizontalLayout_8->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_9 = new QLabel(statsGroupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_13->addWidget(label_9);

        minLabel = new QLabel(statsGroupBox);
        minLabel->setObjectName(QStringLiteral("minLabel"));
        minLabel->setFrameShape(QFrame::Box);
        minLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(minLabel);


        horizontalLayout_12->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_10 = new QLabel(statsGroupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_14->addWidget(label_10);

        maxLabel = new QLabel(statsGroupBox);
        maxLabel->setObjectName(QStringLiteral("maxLabel"));
        maxLabel->setFrameShape(QFrame::Box);
        maxLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(maxLabel);


        horizontalLayout_12->addLayout(horizontalLayout_14);


        gridLayout_2->addLayout(horizontalLayout_12, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(statsGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        underflowLabel = new QLabel(statsGroupBox);
        underflowLabel->setObjectName(QStringLiteral("underflowLabel"));
        underflowLabel->setFrameShape(QFrame::Box);
        underflowLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(underflowLabel);


        horizontalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(statsGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        overflowLabel = new QLabel(statsGroupBox);
        overflowLabel->setObjectName(QStringLiteral("overflowLabel"));
        overflowLabel->setFrameShape(QFrame::Box);
        overflowLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(overflowLabel);


        horizontalLayout_9->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_9, 3, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(statsGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        meanLabel = new QLabel(statsGroupBox);
        meanLabel->setObjectName(QStringLiteral("meanLabel"));
        meanLabel->setFrameShape(QFrame::Box);
        meanLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(meanLabel);


        horizontalLayout_11->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(statsGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        rmsLabel = new QLabel(statsGroupBox);
        rmsLabel->setObjectName(QStringLiteral("rmsLabel"));
        rmsLabel->setFrameShape(QFrame::Box);
        rmsLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(rmsLabel);


        horizontalLayout_11->addLayout(horizontalLayout_6);


        gridLayout_2->addLayout(horizontalLayout_11, 4, 0, 1, 1);


        verticalLayout->addWidget(statsGroupBox);

        splitter->addWidget(layoutWidget);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setMinimumSize(QSize(200, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        histoWidget = new CustomHistogram(frame);
        histoWidget->setObjectName(QStringLiteral("histoWidget"));
        sizePolicy1.setHeightForWidth(histoWidget->sizePolicy().hasHeightForWidth());
        histoWidget->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(histoWidget, 0, 0, 1, 1);

        splitter->addWidget(frame);

        gridLayout_3->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(histogramDataForm);

        QMetaObject::connectSlotsByName(histogramDataForm);
    } // setupUi

    void retranslateUi(QWidget *histogramDataForm)
    {
        histogramDataForm->setWindowTitle(QApplication::translate("histogramDataForm", "Form", nullptr));
        label->setText(QApplication::translate("histogramDataForm", "Nr. of Histos:", nullptr));
        nrHistosLabel->setText(QApplication::translate("histogramDataForm", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("histogramDataForm", "Parameter", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("histogramDataForm", "Entries", nullptr));
        statsGroupBox->setTitle(QApplication::translate("histogramDataForm", "Histo Stats", nullptr));
        label_8->setText(QApplication::translate("histogramDataForm", "Name:", nullptr));
        histoNameLabel->setText(QApplication::translate("histogramDataForm", "N/A", nullptr));
        label_7->setText(QApplication::translate("histogramDataForm", "Bins:", nullptr));
        nrBinsLabel->setText(QApplication::translate("histogramDataForm", "N/A", nullptr));
        label_2->setText(QApplication::translate("histogramDataForm", "Entries:", nullptr));
        nrEntriesLabel->setText(QApplication::translate("histogramDataForm", "N/A", nullptr));
        label_9->setText(QApplication::translate("histogramDataForm", "Min:", nullptr));
        minLabel->setText(QApplication::translate("histogramDataForm", "N/A", nullptr));
        label_10->setText(QApplication::translate("histogramDataForm", "Max:", nullptr));
        maxLabel->setText(QApplication::translate("histogramDataForm", "N/A", nullptr));
        label_3->setText(QApplication::translate("histogramDataForm", "Underflow:", nullptr));
        underflowLabel->setText(QApplication::translate("histogramDataForm", "N/A", nullptr));
        label_4->setText(QApplication::translate("histogramDataForm", "Overflow:", nullptr));
        overflowLabel->setText(QApplication::translate("histogramDataForm", "N/A", nullptr));
        label_5->setText(QApplication::translate("histogramDataForm", "Mean:", nullptr));
        meanLabel->setText(QApplication::translate("histogramDataForm", "N/A", nullptr));
        label_6->setText(QApplication::translate("histogramDataForm", "RMS:", nullptr));
        rmsLabel->setText(QApplication::translate("histogramDataForm", "N/A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class histogramDataForm: public Ui_histogramDataForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMDATAFORM_H
