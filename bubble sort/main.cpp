#include <iostream>
#include "sorting_algorithms.h"

using namespace std;

int main() {

    cout << "The program sorts the array elements.\nInput the size of the array:\n";

    int size;
    cin >> size;

    cout << "Input integers:\n";

    int *arr = new int [size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    bubble_sort(arr, size);

    cout << "Sorted array: ";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    delete[] arr;
}


