#include "MergeSort.h"
using namespace std;

void MergeSort::sort(int* array, int size) {
    if (size > 1) {
        mergeSort(array, 0, size - 1);
    }
}

void MergeSort::mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        //merge(array, left, mid, right); 
    }
}

void MergeSort::merge(int* array, int left, int mid, int right) {
    
}