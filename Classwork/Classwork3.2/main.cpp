#include <iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include <random>

using namespace std;

int main()
{
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
 
    vector<int>::iterator ip; //для поиска дубликатов чисел в массиве
    /*vector<int> v(100); //изначальный массив
    mt19937 mt(time(nullptr));
    for (int i = 0; i < v.size(); i++)
        v[i] = (mt() % 100) + 100;*/
    
    sort(v.begin(), v.end());

    ip = unique(v.begin(), v.begin() + v.size());
    v.resize(distance(v.begin(), ip));

    cout << "Input q:\n";
    int q;
    cin >> q;

    cout << "Input l and r:\n";
    int l, r;

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;

        std::vector<int>::iterator a_it; //начало отрезка
        std::vector<int>::iterator b_it; //конец отрезка
        a_it = lower_bound(v.begin(), v.end(), l);
        b_it = upper_bound(v.begin(), v.end(), r);
        cout << b_it - a_it;
        cout << endl;
    } 
}




        





