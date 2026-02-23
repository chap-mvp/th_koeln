#include <stdio.h>
#include <stdlib.h>
#include "konto.h"

int main(void)
{
    konto_t vollesKonto =
        {"Elke Steinreich", "DE23678678673222289101", 9823, 1200130.23, false};

    konto_t leeresKonto =
        {"Rudi Ratlos", "DE55728292992916789012", 1234, -1370.65, false};

    // jeden Monat wird vollesKonto weiter gefuellt,
    // und leeresKonto weiter geleert
    for (int i = 0; i < 12; i++)
    {
        einzahlen(&vollesKonto, 5000);
        abheben(&leeresKonto, 200);
    }

    // Wie sind die Kontstaende am Ende?
    kontostand(vollesKonto);
    kontostand(leeresKonto);

    printf("Normales Kreditlimit: %.2f Euro\n", kreditNormal);
    printf("Geschaeftskunden Kreditlimit: %.2f Euro\n", kreditBusiness);

    konto_t fancyKonto = neuesKonto("Lara Croft", 7854);
    einzahlen(&fancyKonto, 450000);
    kontostand(fancyKonto);
}