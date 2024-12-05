#include <iostream>
#include "MergeSort.h"

using namespace std;

/**
 * @brief Funkcja główna demonstrująca działanie MergeSort.
 */
int main() {
    int array[] = { 38, 27, 43, 3, 9, 82, 10 };
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Przed sortowaniem: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    MergeSort::sort(array, size);

    cout << "Po sortowaniu: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
