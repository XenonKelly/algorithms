#include <vector>
#include <iostream>
#define K 10


using namespace std;

void insertion_sort(vector<int>& a);
void merge(vector<int>& a, int b, int m, int e);
void sort(vector<int>& a, int b, int e);


int main() {
    cout << "Input size:\n";

    int size;
    cin >> size;

    cout << "Input integers:\n";

    vector<int> v;
    int i = 0;
    int input;
    while (i++ != size) {
        cin >> input;
        v.push_back(input);
    }

    sort(v, 0, size - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < size; i++) {
        cout << v[i] << ' ';
    }
}

void insertion_sort(vector<int> &a) {
    for (int i = 1; i < a.size(); i++) {
        int x = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > x) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = x;
    }
}

void merge(vector<int> &a, int b, int m, int e) {
    vector<int> tmp;
    int i, j;
    i = b;
    j = m + 1;

    while (i <= m && j <= e) {
        if (a[i] <= a[j]) {
            tmp.push_back(a[i]);
            i++;
        }
        else {
            tmp.push_back(a[j]);
            j++;
        }
    }

    while (i <= m) {
        tmp.push_back(a[i]);
        i++;
    }

    while (j <= e) {
        tmp.push_back(a[j]);
        j++;
    }

    for (int i = b; i <= e; i++)
        a[i] = tmp[i - b];
}

    
void sort(vector<int> &a, int b, int e) {
    if (e - b > K) {
        int m = (b + e) / 2;
        sort(a, b, m);
        sort(a, m + 1, e);
        merge(a, b, m, e);
    }
    else {
        insertion_sort(a);
    }
}



