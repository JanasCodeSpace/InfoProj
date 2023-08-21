/**
 * @file GUI.h
 *
 * @brief Header File handling the User Interface
 */

#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qmessagebox.h>

#include "InputParameter.h"
#include "ui_GUI.h"
#include <string>

 /**
  * Diese Klasse ruft das User Interface auf und stellt alle Funktionalitaeten bereit
  * @brief UI und Funktionen
  */
class GUI : public QMainWindow
{
    Q_OBJECT

public:
    /**
    * Initialisiert das UI Fenster
    * @brief Default Konstruktor
    */
    GUI(QWidget *parent = nullptr);
    /**
    * @brief Dekonstruktor
    */
    ~GUI();

private slots:
    /**
    * @brief Ruft nacheinander die Klassen fuer die Berechnung auf und erstellt alle notwendigen Files
    */
    void calculate(void);
    /**
    * @brief Liest den Pfad der Input Datei ein
    */
    void setInputPath(void);
    /**
    * @brief Liest den Pfad des Output Ordners aus
    */
    void setOutputPath(void);
    /**
    * @brief Liest die DP Toleranz ein
    */
    void setDP(void);
    /**
    * @brief Liest das Fenster fuer den gleitenden Mittelwertsfilter ein
    */
    void setMean(void);
    /**
    * @brief Aktiviert die das manuelle Einstellen der Geschwindigkeit
    */
    void activateSpeed(void);
    /**
    * @brief Setzt eine gewaehlte Geschwindigkeit
    */
    void setSpeed(void);
    /**
    * @brief Aktiviert die das manuelle Einstellen der Orientierung
    */
    void activateOrientation(void);
    /**
    * @brief Setzt eine gewaehlte Orientierung
    */
    void setOrientation(void);
    /**
    * @brief Aktiviert die das manuelle Einstellen des Offsets
    */
    void activateOffset(void);
    /**
    * @brief Setzt eine gewaehlten Offset
    */
    void setOffset(void);
    /**
    * @brief Das detaillierte Logging
    */
    void activateLogging(void);

private:
    /**
    * Verbindung mit der im ui file graphisch erstellten Oberflaeche
    */
    Ui::GUIClass ui;
    /**
    * Pfad des Eingabefiles
    */
    QString inputPathUI;
    /**
    * Pfad fuer Ausgabedateien
    */
    QString outputPathUI;
    double dpTolerance;
    double meanLength;
    CInputParameter inputParameter;

};
