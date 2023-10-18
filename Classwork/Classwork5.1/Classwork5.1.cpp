#include<iostream>
#include <random>
#include <algorithm>
#include <chrono>

void heapify(int arr[], int n, int i);
void sorting(int arr[], int n);

int main() {
    int size;
    std::cout << "Input size of array:\n";
    std::cin >> size;

    std::cout << "Input integers:\n";

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    sorting(arr, size);

    /*std::mt19937 mt(time(nullptr));
    for (int i = 0; i < size; i++)
        arr[i] = (mt() % 100) + 100;

    auto start = std::chrono::steady_clock::now();
    sorting(arr, size);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration < double > elapsed_seconds = end - start;

    auto start2 = std::chrono::steady_clock::now();
    std::sort(arr, arr + size);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration < double > elapsed_seconds2 = end2 - start2;

    std::cout << " elapsed time: " << elapsed_seconds.count() << "s\n";
    std::cout << " elapsed time: " << elapsed_seconds2.count() << "s\n";*/


    std::cout << "Sorted array: ";

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    delete[] arr;
}


void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 3 * i - 1;
    int m = 3 * i;
    int r = 3 * i + 1;

   
    if (l < n && arr[l] > arr[largest])
        largest = l;
   
    if (m < n && arr[m] > arr[largest])
        largest = m;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void sorting(int arr[], int n) {
    for (int i = n + 1 / 3; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


/*

        ternary_heap_sort()        sort()

10^3        0.0003 sec           0.0002 sec

10^4        0.004 sec             0.002 sec

10^5        0.04 sec              0.02 sec

10^6        0.5 sec               0.16 sec

10^7        64 sec                 19 sec

10^8 

*/


