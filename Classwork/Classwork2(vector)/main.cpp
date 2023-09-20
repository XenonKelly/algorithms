#include <iostream>
#include <vector>
#include "sort.h";

using namespace std;

int main()
{
    cout << "The program sorts the array elements.\nInput the size of the array:\n";
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

    sorting(v);

    cout << "Sorted array: ";

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}


