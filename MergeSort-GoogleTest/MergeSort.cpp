#include "MergeSort.h"
using namespace std;

/**
 * @brief G��wna funkcja sortuj�ca, kt�ra inicjuje proces sortowania tablicy.
 *
 * Sprawdza, czy tablica ma wi�cej ni� jeden element.
 * Je�li tak, wywo�uje funkcj� rekurencyjn� `mergeSort`, kt�ra dzieli tablic� na mniejsze cz�ci
 * i sortuje je rekurencyjnie, a nast�pnie scala posortowane cz�ci.
 *
 * @param array Wska�nik do tablicy do posortowania.
 * @param size Liczba element�w w tablicy.
 */
void MergeSort::sort(int* array, int size) {
    if (size > 1) {
        mergeSort(array, 0, size - 1);
    }
}

/**
 * @brief Dzieli tablic� na mniejsze podtablice i sortuje je rekurencyjnie.
 *
 * Ta funkcja rekurencyjnie dzieli tablic� na p�, a� do osi�gni�cia podtablic z jednym elementem,
 * kt�re s� ju� posortowane. Nast�pnie scala posortowane cz�ci, u�ywaj�c funkcji `merge`.
 *
 * @param array Wska�nik do tablicy.
 * @param left Indeks pocz�tku aktualnej podtablicy.
 * @param right Indeks ko�ca aktualnej podtablicy.
 */
void MergeSort::mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Wyznacz �rodek tablicy
        mergeSort(array, left, mid);        // Sortowanie lewej cz�ci
        mergeSort(array, mid + 1, right);  // Sortowanie prawej cz�ci
        merge(array, left, mid, right);    // Scalanie posortowanych cz�ci
    }
}

/**
 * @brief Scala dwie posortowane podtablice w jedn�.
 *
 * Ta funkcja tworzy dwie tymczasowe tablice na podstawie podtablic `array[left..mid]` oraz
 * `array[mid+1..right]`. Nast�pnie elementy z obu podtablic s� por�wnywane i
 * wstawiane do tablicy g��wnej w odpowiedniej kolejno�ci.
 *
 * @param array Wska�nik do tablicy wej�ciowej, kt�ra zawiera dwie posortowane podtablice.
 * @param left Indeks pocz�tku pierwszej podtablicy.
 * @param mid Indeks ko�ca pierwszej podtablicy.
 * @param right Indeks ko�ca drugiej podtablicy.
 */
void MergeSort::merge(int* array, int left, int mid, int right) {
    // Obliczanie rozmiaru podtablic
    int n1 = mid - left + 1; // Rozmiar lewej podtablicy
    int n2 = right - mid;    // Rozmiar prawej podtablicy

    // Tworzenie dynamicznych tablic pomocniczych
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Kopiowanie danych do tablic pomocniczych
    for (int i = 0; i < n1; ++i)
        leftArray[i] = array[left + i];
    for (int i = 0; i < n2; ++i)
        rightArray[i] = array[mid + 1 + i];

    // Inicjalizacja indeks�w do iteracji
    int i = 0, j = 0, k = left;

    // Por�wnywanie element�w z lewej i prawej tablicy, i wpisywanie ich w odpowiedniej kolejno�ci
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++]; // Wstaw element z lewej podtablicy
        }
        else {
            array[k++] = rightArray[j++]; // Wstaw element z prawej podtablicy
        }
    }

    // Dodawanie pozosta�ych element�w z lewej podtablicy, je�li istniej�
    while (i < n1) {
        array[k++] = leftArray[i++];
    }

    // Dodawanie pozosta�ych element�w z prawej podtablicy, je�li istniej�
    while (j < n2) {
        array[k++] = rightArray[j++];
    }

    // Zwolnienie pami�ci dynamicznie alokowanych tablic
    delete[] leftArray;
    delete[] rightArray;
}
