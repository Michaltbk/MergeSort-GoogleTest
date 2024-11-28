#pragma once
using namespace std;

class MergeSort {
public:
    static void sort(int* array, int size);

private:
    static void mergeSort(int* array, int left, int right);
    static void merge(int* array, int left, int mid, int right);
};

