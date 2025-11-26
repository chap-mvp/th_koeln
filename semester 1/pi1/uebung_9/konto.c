#include "konto.h"
#include <math.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <string.h>


const float kreditNormal = -1000;
const float kreditBusiness = -5000;
static char ibanBuffer[IBAN+1];
static const char ibanPrefix[] = "DE1438050723";
static void generateIBAN();

float abheben(konto_t *konto, float betrag)
{
    float kredit = konto->kontostand - kreditNormal;
    float abhebeBetrag = fmin (kredit, betrag);
    konto->kontostand -= abhebeBetrag;
    return abhebeBetrag;
}
void einzahlen (konto_t *konto, float betrag)
{
    konto->kontostand += betrag;
}

void kontostand (konto_t konto)
{
    static int kontostandAbfragen = 0;
    
    kontostandAbfragen++;
    printf ("Kontostand für Konto %s: %.2f Euro\n", 
        konto.iban, konto.kontostand);
}

bool isGesperrt (konto_t konto)
{
    return konto.gesperrt;
}

void sperren (konto_t *konto)
{
    konto->gesperrt = true;
}

void entsperren (konto_t *konto)
{
    konto->gesperrt = false;
}

bool pinCorrect(konto_t konto, int pin)
{
    return konto.pin == pin;
}

konto_t neuesKonto (char *name, int pin)
{
    konto_t konto;
    strcpy (konto.name, name);
    konto.kontostand = 0;
    konto.pin = pin;
    konto.gesperrt = false;
    generateIBAN();
    strcpy(konto.iban, ibanBuffer);
    return konto;
}

/// @brief generates IBAN based on nextID and places the generated IBAN 
///        in amodule internal buffer
static void generateIBAN ()
{
    static long long nextID = 6002001000;
    sprintf (ibanBuffer, "%s%lld", ibanPrefix, nextID);
    nextID++;
}