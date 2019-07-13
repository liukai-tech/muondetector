/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtQuickWidgets/QQuickWidget"

QT_BEGIN_NAMESPACE

class Ui_Map
{
public:
    QVBoxLayout *verticalLayout;
    QQuickWidget *quickWidget;

    void setupUi(QWidget *Map)
    {
        if (Map->objectName().isEmpty())
            Map->setObjectName(QString::fromUtf8("Map"));
        Map->resize(592, 510);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Map->sizePolicy().hasHeightForWidth());
        Map->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Map);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        quickWidget = new QQuickWidget(Map);
        quickWidget->setObjectName(QString::fromUtf8("quickWidget"));
        sizePolicy.setHeightForWidth(quickWidget->sizePolicy().hasHeightForWidth());
        quickWidget->setSizePolicy(sizePolicy);
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        verticalLayout->addWidget(quickWidget);


        retranslateUi(Map);

        QMetaObject::connectSlotsByName(Map);
    } // setupUi

    void retranslateUi(QWidget *Map)
    {
        Map->setWindowTitle(QApplication::translate("Map", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Map: public Ui_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
