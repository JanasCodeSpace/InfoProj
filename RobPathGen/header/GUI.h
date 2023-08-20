#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qmessagebox.h>

#include "InputParameter.h"
#include "ui_GUI.h"
#include <string>

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();

protected:


private slots:
    void calculate(void);
    void setInputPath(void);
    void setOutputPath(void);
    void setDP(void);
    void setMean(void);
    void activateSpeed(void);
    void setSpeed(void);
    void activateOrientation(void);
    void setOrientation(void);
    void activateOffset(void);
    void setOffset(void);
    void activateLogging(void);

private:
    Ui::GUIClass ui;
    QString inputPathUI;
    QString outputPathUI;
    double dpTolerance;
    double meanLength;
    CInputParameter inputParameter;

};
