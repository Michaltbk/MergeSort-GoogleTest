#include "MergeSort.h"
using namespace std;

/**
 * @brief G³ówna funkcja sortuj¹ca, która inicjuje proces sortowania tablicy.
 *
 * Sprawdza, czy tablica ma wiêcej ni¿ jeden element.
 * Jeœli tak, wywo³uje funkcjê rekurencyjn¹ `mergeSort`, która dzieli tablicê na mniejsze czêœci
 * i sortuje je rekurencyjnie, a nastêpnie scala posortowane czêœci.
 *
 * @param array WskaŸnik do tablicy do posortowania.
 * @param size Liczba elementów w tablicy.
 */
void MergeSort::sort(int* array, int size) {
    if (size > 1) {
        mergeSort(array, 0, size - 1);
    }
}

/**
 * @brief Dzieli tablicê na mniejsze podtablice i sortuje je rekurencyjnie.
 *
 * Ta funkcja rekurencyjnie dzieli tablicê na pó³, a¿ do osi¹gniêcia podtablic z jednym elementem,
 * które s¹ ju¿ posortowane. Nastêpnie scala posortowane czêœci, u¿ywaj¹c funkcji `merge`.
 *
 * @param array WskaŸnik do tablicy.
 * @param left Indeks pocz¹tku aktualnej podtablicy.
 * @param right Indeks koñca aktualnej podtablicy.
 */
void MergeSort::mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Wyznacz œrodek tablicy
        mergeSort(array, left, mid);        // Sortowanie lewej czêœci
        mergeSort(array, mid + 1, right);  // Sortowanie prawej czêœci
        merge(array, left, mid, right);    // Scalanie posortowanych czêœci
    }
}

/**
 * @brief Scala dwie posortowane podtablice w jedn¹.
 *
 * Ta funkcja tworzy dwie tymczasowe tablice na podstawie podtablic `array[left..mid]` oraz
 * `array[mid+1..right]`. Nastêpnie elementy z obu podtablic s¹ porównywane i
 * wstawiane do tablicy g³ównej w odpowiedniej kolejnoœci.
 *
 * @param array WskaŸnik do tablicy wejœciowej, która zawiera dwie posortowane podtablice.
 * @param left Indeks pocz¹tku pierwszej podtablicy.
 * @param mid Indeks koñca pierwszej podtablicy.
 * @param right Indeks koñca drugiej podtablicy.
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

    // Inicjalizacja indeksów do iteracji
    int i = 0, j = 0, k = left;

    // Porównywanie elementów z lewej i prawej tablicy, i wpisywanie ich w odpowiedniej kolejnoœci
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++]; // Wstaw element z lewej podtablicy
        }
        else {
            array[k++] = rightArray[j++]; // Wstaw element z prawej podtablicy
        }
    }

    // Dodawanie pozosta³ych elementów z lewej podtablicy, jeœli istniej¹
    while (i < n1) {
        array[k++] = leftArray[i++];
    }

    // Dodawanie pozosta³ych elementów z prawej podtablicy, jeœli istniej¹
    while (j < n2) {
        array[k++] = rightArray[j++];
    }

    // Zwolnienie pamiêci dynamicznie alokowanych tablic
    delete[] leftArray;
    delete[] rightArray;
}
