#include<iostream>
#include<vector> 

using namespace std;

int merge(vector<int>& v, int l, int mid, int r);
int merge_sort(vector<int>& v, int l, int r);

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

    cout << "Number of pairs: " << merge_sort(v, 0, v.size() - 1) << endl;
}

int merge(vector<int>& v, int l, int mid, int r) {

    vector<int> tmp;
    int i = l;
    int j = mid + 1;
    int counter = 0;

    while ((i <= mid) && (j <= r)) {
        if (v[i] <= v[j]) {
            tmp.push_back(v[i]);
            i++;
        }
        else {
            tmp.push_back(v[j]);
            counter += (mid - i + 1); //если i-тый элемент левого отсортированного массива > j-того, то и последующие элементы левого массива будут > него
            j++;
        }
    }

    while (i <= mid) {
        tmp.push_back(v[i]);
        i++;
    }

    while (j <= r) {
        tmp.push_back(v[j]);
        j++;
    }

    for (int k = l; k <= r; k++)
        v[k] = tmp[k - l];

    return counter;
}

int merge_sort(vector<int>& v, int l, int r) {

    int counter = 0;
    if (l >= r) 
        return counter;

    else if (l < r) {
        int mid = (r + l) / 2;

        counter += merge_sort(v, l, mid); //для левой части
        counter += merge_sort(v, mid + 1, r); //для правой части

        counter += merge(v, l, mid, r); //в общем
    }
    return counter;
}

