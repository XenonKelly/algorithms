#include <iostream>
#include <random>
#define L 10

using namespace std;

void counting_sort(int arr[], int n, int digit);
int max_element(int arr[], int n);
void print(int arr[], int n);
void radix_sort(int arr[], int n);
int random_number(int a);

int main() {

    cout << "The program sorts the array of elements using radix sort.\nInput the size of the array:\n";
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = random_number(i);

    radix_sort(arr, n);

    cout << "Sorted array:\n";
    print(arr, n);

    delete[] arr;
}

int max_element(int arr[], int n) {
    int m = arr[0];
    for (int i = 1; i < n; i++)
        m = max(m, arr[i]);
    return m;
}

void counting_sort(int arr[], int n, int digit) {
    
    int count[L] = { 0 };
    int *temp = new int[n];

    for (int i = 0; i < n; i++)
        count[(arr[i] / digit) % 10]++;

    for (int i = 1; i < L; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        temp[count[(arr[i] / digit) % 10] - 1] = arr[i];
        --count[(arr[i] / digit) % 10];
    }

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];

    delete[] temp;
}

void radix_sort(int arr[], int n) {
    int m = max_element(arr, n);

    for (int digit = 1; m / digit > 0; digit *= 10)
        counting_sort(arr, n, digit);
}

int random_number(int a)
{
    random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> distrib(1,1000);
    return distrib(gen) * distrib(gen) * distrib(gen);
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


