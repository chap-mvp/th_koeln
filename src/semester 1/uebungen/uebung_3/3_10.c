/*
Es sollen die Datentypen (*_t) für ein Mau Mau Spiel implementiert werden. Entsprechende typedef Definitionen werden außerhalb des main Programms erstellt.  
 - bool_t: unsigned char 
 - farbe_t: Enumeration für die Spielfarben  
 - wert_t: Enumeration für die Spielwerte  
 - stapel_t: Enumeration für den Ort, an dem sich die Karte befindet (Nachziehstapel, Spielerhand, Ablagestapel) 
 - karte_t: Struct für eine einzelne Karte mit den Komponenten: 
 - Spielfarbe  
 - Spielwert 
 - Ort, an dem sich die Karte gerade befindet 
 - kartenset_t: Struct für eine Menge von Karten mit den Komponenten: 
 - Anzahl der Karten 
 - Array vom Typ karte_t. 
 - Bezeichner, um welchen Stapel es sich handelt  
 
Deklarieren und initialisieren Sie im main Programm 3 Arrays 
  - farb_bezeichner soll die deutschen Bezeichnungen als Strings für die Spielfarben enthalten in der gleichen Reihenfolge wie in der Enumeration farbe_t.  
  - wert_bezeichner soll die deutschen Bezeichungen als Strings für die Spielwerte enthalten in der gleichen Reihenfolge wie in der Enumeration wert_t.  
  - kartendeck vom Typ karte_t soll mit allen 32 Spielkarten initialisiert werden. Als Ort soll für jede Spielkarte der Enumeration Wert Ablagestapel (vom Typ stapel_t) angegeben werden: 
 
karte_t kartendeck [MAXCARDS] = { 
    {caro, sieben, ablage}, 
     ... 
    {kreuz, as, ablage} 
}; 

Bitte definieren Sie für alle verwendeten Arraygrößen entsprechende Konstanten (mit #define).
 */

#include <stdio.h>

int main () {
    
}