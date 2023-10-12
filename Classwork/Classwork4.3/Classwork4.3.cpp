#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int b, int m, int e) {
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

void merge_sort(vector<int>& a, int b, int e) {

    if (b < e) {
        int m = (b + e) / 2;
        merge_sort(a, b, m);
        merge_sort(a, m + 1, e);
        merge(a, b, m, e);
    }
}


int main()
{
    cout << "The program finds pairs of indexes of elemens, the result of the sum of which is S:\n";

    cout << "Input size of array:\n";
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

    vector<int> m(v);

    int s;
    cout << "Input sum:\n";
    cin >> s;

    merge_sort(m, 0, size - 1);

    vector<pair<int, int>> pairs;
    int sum;
    int l = 0;
    int r = size - 1;

    
    while (l < r) {
        int mid = l + (r - l) / 2;

        int sum = m[l] + m[r];
        if (sum == s)
        {
            int a = (std::find(v.begin(), v.end(), m[l]) - v.begin());
            int b = (std::find(v.begin(), v.end(), m[r]) - v.begin());
            pairs.push_back(make_pair(a, b));    
            r--;
            l++;
        }
        else if (sum < s) {
            l++;
        }
        else
            r--;
    }

    if (pairs.size() == 0) {
        cout << "not found";
    }

    cout << "Required pairs:\n";
    for (auto i = 0; i < pairs.size(); i++) {
        cout << "(" << pairs.at(i).first << ", " << pairs.at(i).second << ")\n";
    }
    cout << endl;
}


    








