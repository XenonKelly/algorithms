#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T> bool cmp(T x, T y);
template <typename T> int partition(T a[], int start, int end);
template <typename T> void print(T* a, int n);
template <typename T> void quicksort(T a[], int n);

int main() {

    cout << "Input size of array:\n";
    int size;
    cin >> size;

    int* a = new int[size];
    char* b = new char[size];
    double* c = new double[size];

    cout << "Select the type of data that will be in the array:\n";
    cout << "1) int\n";
    cout << "2) char\n";
    cout << "3) double\n";

    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        delete[] b;
        delete[] c;
        for (int i = 0; i < size; i++)
            cin >> a[i];
        quicksort(a, size);
        print(a, size);
        delete[] a;
        break;

    case 2:
        delete[] a;
        delete[] c;
        for (int i = 0; i < size; i++)
            cin >> b[i];
        quicksort(b, size);
        print(b, size);
        delete[] b;
        break;

    case 3:
        delete[] a;
        delete[] b;
        for (int i = 0; i < size; i++)
            cin >> c[i];
        quicksort(c, size);
        print(c, size);
        delete[] c;
        break;
    }
}

template <typename T> int partition(T a[], int start, int end) {
    T pivo = a[end]; //пусть опорный элемент будет в конце
    int i = start - 1; //что-то типа стенки, которую будем двигать вправо по мере нахождения меньшего элемента
    for (int j = start; j < end; j++) {
        if (cmp(pivo, a[j])) { //ставим меньшие элементы левее, а большие правее
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[end], a[i + 1]); //ставим опорный элемент на свое место 
    return (i + 1);
}

template <typename T> void quicksort(T a[], int n) {

    stack<pair<int, int>> tmp;
    int start = 0;
    int end = n - 1;
    tmp.push(make_pair(start, end)); //добавляем индексы начала и конца изначального вектора

    while (tmp.size() != 0)
    {
        start = tmp.top().first;
        end = tmp.top().second;
        tmp.pop(); //очищаем стек, чтобы обновить его значениями из подмассивов

        int pivo = partition(a, start, end); //получили индекс опорного элемента в первый раз для всего массива, потом для подмассивов

        if (pivo - 1 > start) //здесь не используем компаратор, тк идем по int
            tmp.push(make_pair(start, pivo - 1)); //берем начало и конец правого подмассива, в котором находятся значения, меньшие опорного

        if (pivo + 1 < end) 
            tmp.push(make_pair(pivo + 1, end)); //берем начало и конец левого подмассива, в котором находятся значения, большие опорного
    }
}

template <typename T> void print(T* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

template <typename T> bool cmp(T x, T y) {
    if (x >= y)
        return true; 
    else
        return false;
}
