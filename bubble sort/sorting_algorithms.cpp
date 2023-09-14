#include <iostream>
#include "sorting_algorithms.h"

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}


void bubble_sort(int m[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (m[j] > m[j + 1]) {
                swap(m[j], m[j + 1]);
            }
        }
    }
}






