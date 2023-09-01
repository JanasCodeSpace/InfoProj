/**
 * @file RobPathEditor.cpp
 *
 * @brief Hier wird die main Funktion aufgerufen
 */

 /** \mainpage Beschreibung Roboter Path Editor
  *
  * \section intro_sec Nutzen
  *
  * Mit diesem Programm sollen haendisch aufgenommene Pfad Daten einer Roboterbewegung zu einem fuer Kuka
  * Roboter lesbaren File gemacht werden. Zusaetzlich soll einstellbar sein ob die Orientierung berechnet
  * werden soll, oder eingegeben werden soll. Das selbe gilt fuer Geschwindigkeitsdaten.
  *
  * \section install_sec Aufbau
  *
  * In der Grundidee werden die eingelesenen Daten immer aus der vorhergegangenen Klasse ausgelesen und nach der
  * Verarbeitung in der aktuellen Klasse gespeichert.
  *
  * \subsection step1 Logging
  *
  * Zuerst wird die Loggingklasse CLogging initialisiert. In ihr wird gespeichert in welchem Schritt das Programm gerade ist.
  * Dieser Klasse wird ein Pfad uebergeben an welchem die Daten gespeichert werden sollen.
  *
  * \subsection step2 Daten einlesen
  *
  * Als naechstes werden die Nutzerdaten eingelesen und anschliessend die aufgenommenen Daten eingelesen. Dabei wird
  * Ueberprueft ob es sich um einen zusammenhaengenden Pfad handelt.
  * Das passiert in der Klasse CInputParameter.
  *
  * \subsection step3 Daten verarbeiten
  *
  * In mehreren Schritten folgt eine Nachbearbeitung der Daten. Zuerst werden die Daten mit einem gleitendem
  * Mittelwertfilter in der Klasse CMeanFilter geglaettet. Anschliessend werden Punkte mit Hilfe des Douglas-Peuker
  * Algorithmuses in der Klasse CSegmentApproximator geloescht. Sollten es mehrere nicht zusammenhaengende Pfade sein
  * muessen diese jetzt noch zusammengesetzt werden.
  *
  * \subsection step4 Roboter Code erstellen
  *
  * Als letzter Schritt werden die Nutzereinstellungen in die Daten uebernommen und der Robotercode erstellt.
  */


#include <iostream>
#include <ctime>

#include "../header/GUI.h"
#include <QtWidgets/QApplication>

using namespace std;

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	GUI w;
	w.show();
	return a.exec();
}