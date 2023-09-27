#include <iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include <random>

using namespace std;

bool find_value(const vector<int>& data, int value)
{
    auto result{ find(begin(data), end(data), value) };
    if (result == end(data))
        return 0;
    else
        return 1;
}

int main()
{
    /* для заполнения вектора
    cout << "Input size:\n";

    int size;
    cin >> size;

    cout << "Input integers:\n";

    int i = 0; //заполнение вектора v
    int input;
    while (i++ != size) {
        cin >> input;
        v.push_back(input);
    }*/

    vector<int> f; //массив с повторами возможных границ промежутка
    vector<int>::iterator ip; //для поиска дубликатов чисел в массиве
    vector<int> v(100); //изначальный массив
    mt19937 mt(time(nullptr));
    for (int i = 0; i < v.size(); i++)
        v[i] = (mt() % 100) + 100;
    

    sort(v.begin(), v.end());

    ip = unique(v.begin(), v.begin() + v.size());
    v.resize(distance(v.begin(), ip));

    for (ip = v.begin(); ip != v.end(); ip++) {
        f.push_back(*ip);
    }

    cout << "Input q:\n";
    int q;
    cin >> q;

    cout << "Input l and r:\n";
    int l, r;

    for (int i = 0; i <= q; i++)
    {
        cin >> l >> r;

        std::vector<int>::iterator a_it;
        std::vector<int>::iterator b_it;

        if ((find_value(f, l)) && (find_value(f, r))) {
            a_it = find(f.begin(), f.end(), l);
            int beg = a_it - f.begin(); //начало отрезка

            b_it = find(f.begin(), f.end(), r); 
            int end = b_it - f.begin(); //конец отрезка

            cout << end - beg + 1;
            cout << endl;
        }
        else if ((find_value(f, l)) || (find_value(f, r))) {
            if ((find_value(f, l))) {
                f.push_back(r);
         
                sort(f.begin(), f.end());
                a_it = find(f.begin(), f.end(), l);
                int beg = a_it - f.begin(); 

                b_it = find(f.begin(), f.end(), r);
                int end = b_it - f.begin();

                cout << end - beg;
                cout << endl;
            }
            else {
                f.push_back(l);
                sort(f.begin(), f.end());
                a_it = find(f.begin(), f.end(), l);
                int beg = a_it - f.begin(); 

                b_it = find(f.begin(), f.end(), r);
                int end = b_it - f.begin();

                cout << end - beg;
                cout << endl;
            }
        }
        else {
            f.push_back(r);
            f.push_back(l);
            sort(f.begin(), f.end());
            a_it = find(f.begin(), f.end(), l);
            int beg = a_it - f.begin(); 

            b_it = find(f.begin(), f.end(), r);
            int end = b_it - f.begin();

            cout << end - beg - 1;
            cout << endl;
        }
        f = v;
    }
    
}




        





