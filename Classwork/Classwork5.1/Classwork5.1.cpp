#include<iostream>

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


