/********************************************************************************
** Form generated from reading UI file 'QtEmbedOutDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTEMBEDOUTDEMO_H
#define UI_QTEMBEDOUTDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtEmbedOutDemoClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_send;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *label_rev;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *QtEmbedOutDemoClass)
    {
        if (QtEmbedOutDemoClass->objectName().isEmpty())
            QtEmbedOutDemoClass->setObjectName(QString::fromUtf8("QtEmbedOutDemoClass"));
        QtEmbedOutDemoClass->resize(1265, 791);
        QtEmbedOutDemoClass->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(QtEmbedOutDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_send->sizePolicy().hasHeightForWidth());
        pushButton_send->setSizePolicy(sizePolicy);
        pushButton_send->setMinimumSize(QSize(93, 28));

        horizontalLayout->addWidget(pushButton_send);

        horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        label_rev = new QLabel(centralWidget);
        label_rev->setObjectName(QString::fromUtf8("label_rev"));
        sizePolicy1.setHeightForWidth(label_rev->sizePolicy().hasHeightForWidth());
        label_rev->setSizePolicy(sizePolicy1);
        label_rev->setMinimumSize(QSize(130, 20));

        horizontalLayout->addWidget(label_rev);

        horizontalSpacer_3 = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(0, 7, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        QtEmbedOutDemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtEmbedOutDemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1265, 26));
        QtEmbedOutDemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtEmbedOutDemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtEmbedOutDemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(QtEmbedOutDemoClass);

        QMetaObject::connectSlotsByName(QtEmbedOutDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtEmbedOutDemoClass)
    {
        QtEmbedOutDemoClass->setWindowTitle(QCoreApplication::translate("QtEmbedOutDemoClass", "QtEmbedOutDemo", nullptr));
        pushButton_send->setText(QCoreApplication::translate("QtEmbedOutDemoClass", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("QtEmbedOutDemoClass", "\346\216\245\346\224\266\357\274\232", nullptr));
        label_rev->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtEmbedOutDemoClass: public Ui_QtEmbedOutDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTEMBEDOUTDEMO_H
