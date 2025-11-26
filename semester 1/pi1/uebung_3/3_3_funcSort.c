// Funktionsname: sortArrayDescending
// Sortiert die Eintraege eines Arrays in absteigender Reihenfolge
// Eingabeparameter mit zulässigem Wertebereich: sizeArray, Anzahl der Eintraege
// Ausgabeparameter mit zulässigem Wertebereich: sortArray, zu sortierendes Array
// Rückgabewert mit zulässigem Wertebereich: EXIT_SUCCESS
// Autor: Prof. Dr. Markus Stockmann
// Datum: 18.09.23
// Version: 1.0.0

int sortArrayDescending(int sortArray[], int sizeArray) {
    for (int i = 0; i < sizeArray - 1; i++) {
        for (int j = 0; j < sizeArray - i - 1; j++) {
            if (sortArray[j] < sortArray[j + 1]) {
                // Vertausche die Elemente, um in absteigender Reihenfolge zu sortieren
                int temp = sortArray[j];
                sortArray[j] = sortArray[j + 1];
                sortArray[j + 1] = temp;
            }
        }
    }
    return 0;
}