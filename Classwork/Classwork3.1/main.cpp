#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>


using namespace std;

void shell_pratt_sort(vector<int> &a) {
    vector<int> s;
    int pow3 = 1;
    int pow2;
    while (pow3 <= a.size() / 3) { 
        pow2 = pow3;
        while (pow2 <= a.size() / 3) {
            s.push_back(pow2);             //заполним сначала массив по степеням двойки
            pow2 = pow2 * 2;
        }
        pow3 = pow3 * 3;                  //далее если увеличение степени 3 не превзойдет заданного размера, то увеличиваем ее
    }
    sort(s.begin(), s.end()); 


    for (int gap = s.size(); gap >= 0; gap--) {
        for (int i = gap; i < a.size(); i++)
        {
            int x = a[i];
            int j = i;
            for (; j >= gap && a[j - gap] > x; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = x;
        }
    }
}

//в 90% случаях +- 0.0017 sec при  /3 и /5 при 10^3; 
// 0.05 sec при /3, /5 при 10^4;
// 1.3 sec при /2 и /3, 1.3-1.4 sec при /5 при 10^5;
//65 sec при /3, 70 sec при /5 при 10^6.

int main() {
    vector<int> a(10000);
    mt19937 mt(time(nullptr));
    for (int i = 0; i < a.size(); i++)
        a[i] = (mt() % 100) + 100;

    auto start = chrono::steady_clock::now();
    shell_pratt_sort(a);
    auto end = chrono::steady_clock::now();
    chrono::duration < double > elapsed_seconds = end - start;

    cout << " elapsed time: " << elapsed_seconds.count() << "s\n";
}

  

        
