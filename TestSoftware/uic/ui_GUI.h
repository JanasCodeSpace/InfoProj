/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QWidget *centralWidget;
    QLabel *pathInput;
    QFrame *frame;
    QWidget *speed_2;
    QDoubleSpinBox *speed;
    QLabel *label_5;
    QCheckBox *bSpeed;
    QWidget *orientation;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QDoubleSpinBox *AValue;
    QDoubleSpinBox *BValue;
    QDoubleSpinBox *CValue;
    QCheckBox *bManOrientation;
    QSpinBox *meanLength;
    QLabel *label_dp;
    QLabel *label_4;
    QSpinBox *dpToleranz;
    QCheckBox *bLogging;
    QCheckBox *bOffset;
    QWidget *offset;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QDoubleSpinBox *offsetX;
    QDoubleSpinBox *offsetY;
    QDoubleSpinBox *offsetZ;
    QPushButton *pushInput;
    QPushButton *pushOutput;
    QTextBrowser *textBrowser;
    QPushButton *startCalculation;
    QLabel *pathOutput;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName("GUIClass");
        GUIClass->resize(355, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GUIClass->sizePolicy().hasHeightForWidth());
        GUIClass->setSizePolicy(sizePolicy);
        GUIClass->setMinimumSize(QSize(355, 700));
        GUIClass->setMaximumSize(QSize(355, 700));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rubik")});
        GUIClass->setFont(font);
        GUIClass->setAnimated(true);
        GUIClass->setTabShape(QTabWidget::Rounded);
        GUIClass->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName("centralWidget");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rubik")});
        font1.setBold(false);
        font1.setItalic(false);
        centralWidget->setFont(font1);
        centralWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(3, 8, 14);\n"
"color: rgb(3, 8, 14)\n"
""));
        pathInput = new QLabel(centralWidget);
        pathInput->setObjectName("pathInput");
        pathInput->setGeometry(QRect(10, 10, 331, 31));
        pathInput->setFont(font1);
        pathInput->setStyleSheet(QString::fromUtf8("border: 1px solid black; \n"
"border-radius: 10px;\n"
"background-color: rgb(210, 211, 218);\n"
"color: rgb(3, 8, 14);"));
        frame = new QFrame(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 90, 331, 491));
        frame->setStyleSheet(QString::fromUtf8("border: 1px solid black; \n"
"border-radius: 10px;\n"
"background-color: rgb(117, 125, 149)"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);
        speed_2 = new QWidget(frame);
        speed_2->setObjectName("speed_2");
        speed_2->setEnabled(false);
        speed_2->setGeometry(QRect(15, 110, 301, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rubik")});
        font2.setBold(true);
        speed_2->setFont(font2);
        speed_2->setStyleSheet(QString::fromUtf8("background-color: rgb(210,211,218);\n"
"color: rgb(117, 125, 149);\n"
"border: 1px solid rgb(67, 72, 91); "));
        speed = new QDoubleSpinBox(speed_2);
        speed->setObjectName("speed");
        speed->setGeometry(QRect(159, 12, 136, 20));
        speed->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 211, 218);\n"
"\n"
"border-radius: 6px;"));
        speed->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(speed_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(11, 12, 93, 16));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("border: 0px"));
        bSpeed = new QCheckBox(frame);
        bSpeed->setObjectName("bSpeed");
        bSpeed->setGeometry(QRect(15, 80, 171, 20));
        bSpeed->setFont(font1);
        bSpeed->setStyleSheet(QString::fromUtf8("color: rgb(3, 8, 14);\n"
"border: 0px"));
        orientation = new QWidget(frame);
        orientation->setObjectName("orientation");
        orientation->setEnabled(false);
        orientation->setGeometry(QRect(15, 190, 301, 111));
        orientation->setStyleSheet(QString::fromUtf8("background-color: rgb(210,211,218);\n"
"color: rgb(117, 125, 149);\n"
"border: 1px solid rgb(67, 72, 91); "));
        label_10 = new QLabel(orientation);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 15, 18, 16));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("border: 0px"));
        label_11 = new QLabel(orientation);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(11, 47, 33, 16));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("\n"
"border: 0px"));
        label_12 = new QLabel(orientation);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(11, 78, 17, 16));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("border: 0px"));
        AValue = new QDoubleSpinBox(orientation);
        AValue->setObjectName("AValue");
        AValue->setGeometry(QRect(153, 15, 141, 20));
        AValue->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 211, 218);\n"
"\n"
"border-radius: 6px;"));
        BValue = new QDoubleSpinBox(orientation);
        BValue->setObjectName("BValue");
        BValue->setGeometry(QRect(154, 47, 141, 20));
        BValue->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 211, 218);\n"
"\n"
"border-radius: 6px;"));
        CValue = new QDoubleSpinBox(orientation);
        CValue->setObjectName("CValue");
        CValue->setGeometry(QRect(154, 78, 141, 20));
        CValue->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 211, 218);\n"
"\n"
"border-radius: 6px;"));
        label_12->raise();
        label_10->raise();
        AValue->raise();
        BValue->raise();
        CValue->raise();
        label_11->raise();
        bManOrientation = new QCheckBox(frame);
        bManOrientation->setObjectName("bManOrientation");
        bManOrientation->setGeometry(QRect(15, 160, 151, 20));
        bManOrientation->setFont(font1);
        bManOrientation->setStyleSheet(QString::fromUtf8("color: rgb(3, 8, 14);\n"
"border: 0px"));
        meanLength = new QSpinBox(frame);
        meanLength->setObjectName("meanLength");
        meanLength->setGeometry(QRect(210, 48, 106, 20));
        meanLength->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 211, 218);\n"
"\n"
"border-radius: 6px;"));
        label_dp = new QLabel(frame);
        label_dp->setObjectName("label_dp");
        label_dp->setGeometry(QRect(14, 22, 144, 16));
        label_dp->setFont(font1);
        label_dp->setStyleSheet(QString::fromUtf8("color: rgb(3, 8, 14);\n"
"border: 0px"));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(14, 48, 191, 16));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(3, 8, 14);\n"
"border: 0px"));
        dpToleranz = new QSpinBox(frame);
        dpToleranz->setObjectName("dpToleranz");
        dpToleranz->setGeometry(QRect(210, 22, 106, 20));
        dpToleranz->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 211, 218);\n"
"\n"
"border-radius: 6px;"));
        dpToleranz->setFrame(true);
        dpToleranz->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dpToleranz->setAccelerated(false);
        bLogging = new QCheckBox(frame);
        bLogging->setObjectName("bLogging");
        bLogging->setGeometry(QRect(15, 460, 151, 20));
        bLogging->setFont(font1);
        bLogging->setStyleSheet(QString::fromUtf8("color: rgb(3, 8, 14);\n"
"border: 0px"));
        bOffset = new QCheckBox(frame);
        bOffset->setObjectName("bOffset");
        bOffset->setGeometry(QRect(15, 310, 151, 20));
        bOffset->setFont(font1);
        bOffset->setStyleSheet(QString::fromUtf8("color: rgb(3, 8, 14);\n"
"border: 0px"));
        offset = new QWidget(frame);
        offset->setObjectName("offset");
        offset->setEnabled(false);
        offset->setGeometry(QRect(15, 340, 301, 111));
        offset->setStyleSheet(QString::fromUtf8("background-color: rgb(210,211,218);\n"
"color: rgb(117, 125, 149);\n"
"border: 1px solid rgb(67, 72, 91); "));
        label_13 = new QLabel(offset);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 15, 18, 16));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("border: 0px"));
        label_14 = new QLabel(offset);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(11, 47, 33, 16));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("\n"
"border: 0px"));
        label_15 = new QLabel(offset);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(11, 78, 17, 16));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("border: 0px"));
        offsetX = new QDoubleSpinBox(offset);
        offsetX->setObjectName("offsetX");
        offsetX->setGeometry(QRect(153, 15, 141, 20));
        offsetX->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 211, 218);\n"
"\n"
"border-radius: 6px;"));
        offsetY = new QDoubleSpinBox(offset);
        offsetY->setObjectName("offsetY");
        offsetY->setGeometry(QRect(154, 47, 141, 20));
        offsetY->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 211, 218);\n"
"\n"
"border-radius: 6px;"));
        offsetZ = new QDoubleSpinBox(offset);
        offsetZ->setObjectName("offsetZ");
        offsetZ->setGeometry(QRect(154, 78, 141, 20));
        offsetZ->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 211, 218);\n"
"\n"
"border-radius: 6px;"));
        pushInput = new QPushButton(centralWidget);
        pushInput->setObjectName("pushInput");
        pushInput->setGeometry(QRect(240, 10, 101, 31));
        pushInput->setFont(font1);
        pushInput->setStyleSheet(QString::fromUtf8("border: 1px solid black; \n"
"border-radius: 10px;\n"
"background-color: rgb(117, 125, 149);\n"
"color: rgb(3, 8, 14);"));
        pushOutput = new QPushButton(centralWidget);
        pushOutput->setObjectName("pushOutput");
        pushOutput->setGeometry(QRect(240, 50, 101, 31));
        pushOutput->setFont(font1);
        pushOutput->setStyleSheet(QString::fromUtf8("border: 1px solid black; \n"
"border-radius: 10px;\n"
"background-color: rgb(117, 125, 149);\n"
"color: rgb(3, 8, 14);"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(0, 630, 355, 71));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 211, 218);\n"
"border-radius: 0px"));
        startCalculation = new QPushButton(centralWidget);
        startCalculation->setObjectName("startCalculation");
        startCalculation->setGeometry(QRect(10, 590, 331, 31));
        sizePolicy.setHeightForWidth(startCalculation->sizePolicy().hasHeightForWidth());
        startCalculation->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Rubik")});
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        startCalculation->setFont(font3);
        startCalculation->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 10px;\n"
"background-color: rgb(67, 72, 91);\n"
"color: rgb(210, 211, 218)"));
        pathOutput = new QLabel(centralWidget);
        pathOutput->setObjectName("pathOutput");
        pathOutput->setGeometry(QRect(10, 50, 331, 31));
        pathOutput->setFont(font1);
        pathOutput->setStyleSheet(QString::fromUtf8("border: 1px solid black; \n"
"border-radius: 10px;\n"
"background-color: rgb(210, 211, 218);\n"
"color: rgb(3, 8, 14);"));
        pathOutput->setTextFormat(Qt::MarkdownText);
        GUIClass->setCentralWidget(centralWidget);
        pathInput->raise();
        frame->raise();
        textBrowser->raise();
        startCalculation->raise();
        pathOutput->raise();
        pushOutput->raise();
        pushInput->raise();

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QCoreApplication::translate("GUIClass", "Roboter Pfad Editor", nullptr));
        pathInput->setText(QCoreApplication::translate("GUIClass", "Eingabedatei", nullptr));
        speed->setSuffix(QCoreApplication::translate("GUIClass", " m/s", nullptr));
        label_5->setText(QCoreApplication::translate("GUIClass", "Geschwindigkeit", nullptr));
        bSpeed->setText(QCoreApplication::translate("GUIClass", "Manuelle Geschwindigkeit", nullptr));
        label_10->setText(QCoreApplication::translate("GUIClass", "A", nullptr));
        label_11->setText(QCoreApplication::translate("GUIClass", "B", nullptr));
        label_12->setText(QCoreApplication::translate("GUIClass", "C", nullptr));
        bManOrientation->setText(QCoreApplication::translate("GUIClass", "Manuelle Ausrichtung", nullptr));
        label_dp->setText(QCoreApplication::translate("GUIClass", "Douglas-Peuker-Toleranz", nullptr));
        label_4->setText(QCoreApplication::translate("GUIClass", "Filterl\303\244nge gleitender Mittelwert", nullptr));
        dpToleranz->setSpecialValueText(QString());
        dpToleranz->setSuffix(QString());
        bLogging->setText(QCoreApplication::translate("GUIClass", "Detailliertes Logging", nullptr));
        bOffset->setText(QCoreApplication::translate("GUIClass", "Einstellung Offset", nullptr));
        label_13->setText(QCoreApplication::translate("GUIClass", "X", nullptr));
        label_14->setText(QCoreApplication::translate("GUIClass", "Y", nullptr));
        label_15->setText(QCoreApplication::translate("GUIClass", "Z", nullptr));
        pushInput->setText(QCoreApplication::translate("GUIClass", "Datei w\303\244hlen", nullptr));
        pushOutput->setText(QCoreApplication::translate("GUIClass", "Pfad w\303\244hlen", nullptr));
        startCalculation->setText(QCoreApplication::translate("GUIClass", "Datei erstellen", nullptr));
        pathOutput->setText(QCoreApplication::translate("GUIClass", "Ausgabeordner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
