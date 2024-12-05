#pragma once
using namespace std;

/**
 * @class MergeSort
 * @brief Klasa implementuj¹ca algorytm sortowania przez scalanie.
 */
class MergeSort {
public:
    /**
     * @brief Sortuje tablicê za pomoc¹ algorytmu MergeSort.
     * @param array WskaŸnik do tablicy do posortowania.
     * @param size Rozmiar tablicy.
     */
    static void sort(int* array, int size);

private:
    /**
     * @brief Rekurencyjnie dzieli tablicê na mniejsze czêœci i sortuje je.
     * @param array WskaŸnik do tablicy.
     * @param left Indeks pocz¹tku podtablicy.
     * @param right Indeks koñca podtablicy.
     */
    static void mergeSort(int* array, int left, int right);

    /**
     * @brief Scalanie dwóch posortowanych podtablic w jedn¹.
     * @param array WskaŸnik do tablicy.
     * @param left Indeks pocz¹tku pierwszej podtablicy.
     * @param mid Indeks koñca pierwszej podtablicy.
     * @param right Indeks koñca drugiej podtablicy.
     */
    static void merge(int* array, int left, int mid, int right);
};
