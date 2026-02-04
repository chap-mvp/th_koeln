#pragma once
#include <stdbool.h>
#define MAXNAME 80
#define IBAN 22

/// @brief Konto Struktur, die allen Funktionen übergeben werden muss
typedef struct konto
{
    char name[MAXNAME];     // Kontobesitzer
    char iban[IBAN+1];       
    int pin;
    float kontostand;
    bool gesperrt;
} konto_t;

/// @brief Kreditlimit für normale Kunden
extern const float kreditNormal; 
/// @brief Kreditlimit für Geschaeftskunden
extern const float kreditBusiness;  

/// @brief hebt Geld vom Konto ab, aber nur bis zum Kreditlimit für normale Kunden. 
/// @param konto Konto, von dem abgebucht werden soll
/// @param betrag Betrag, der abgehoben werden soll
/// @return tatsaechlicher Betrag, der abgehoben wurde, kann abweichen von 
///         Betrag, weil der Kredit schon ausgeschoepft ist. 
extern float abheben(konto_t *konto, float betrag);

/// @brief zahlt Geld auf das Konto ein
/// @param konto Konto, auf das eingezahlt wird
/// @param betrag Geldbetrag, der eingezaht wird
void einzahlen (konto_t *konto, float betrag);

/// @brief Kontostand anzeigen
/// @param konto Konto, dessen Kontostand angezeigt werden soll
void kontostand (konto_t konto);

/// @brief Fragt ab, ob das Konto zur Zeit gesperrt ist
/// @param konto Konto, das abgefragt werden soll
/// @return true: das Konto ist gesprerrt, false: nicht gesperrt 
extern bool isGesperrt (konto_t konto);

/// @brief Sperrt das Konto
/// @param konto Konto, das gesperrt werden soll
void sperren (konto_t *konto);

/// @brief Entsperrt das Konto
/// @param konto Konto, das entsperrt werden soll
void entsperren (konto_t *konto);

/// @brief Ueberprueft, ob der Pin korrekt eingegeben wurde
/// @param konto Konto, dessen Pin Nummer ueberprueft wird
/// @param pin eingegebene Pin Nummer
/// @return true: die Pin Nummer stimmt überein, false: falsche Pin
bool pinCorrect (konto_t konto, int pin);

/// @brief Erzeugt ein neues Konto für den Kontobesitzer <name> mit 
///        einer Pinnummer <pin> und einem Kontostand von 0.
///        Die IBAN wird generiert.    
/// @param name Name des Kontobesitzers, auf den das neue Konto eröffnet werden soll
/// @param pin Gewuenschte Pin Nummer für das neue Konto. 
/// @return Konto Objekt mit generierter IBAN
konto_t neuesKonto (char *name, int pin);