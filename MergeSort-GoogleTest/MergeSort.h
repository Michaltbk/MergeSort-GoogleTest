#pragma once
using namespace std;

/**
 * @class MergeSort
 * @brief Klasa implementuj�ca algorytm sortowania przez scalanie.
 */
class MergeSort {
public:
    /**
     * @brief Sortuje tablic� za pomoc� algorytmu MergeSort.
     * @param array Wska�nik do tablicy do posortowania.
     * @param size Rozmiar tablicy.
     */
    static void sort(int* array, int size);

private:
    /**
     * @brief Rekurencyjnie dzieli tablic� na mniejsze cz�ci i sortuje je.
     * @param array Wska�nik do tablicy.
     * @param left Indeks pocz�tku podtablicy.
     * @param right Indeks ko�ca podtablicy.
     */
    static void mergeSort(int* array, int left, int right);

    /**
     * @brief Scalanie dw�ch posortowanych podtablic w jedn�.
     * @param array Wska�nik do tablicy.
     * @param left Indeks pocz�tku pierwszej podtablicy.
     * @param mid Indeks ko�ca pierwszej podtablicy.
     * @param right Indeks ko�ca drugiej podtablicy.
     */
    static void merge(int* array, int left, int mid, int right);
};
