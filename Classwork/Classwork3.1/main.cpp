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
        pow3 = pow3 * 3;                  //далее после заполнения по степеням двойки, начинаем увеличивать степень тройки
    }
    sort(s.begin(), s.end()); 

    for (int k = s.size() - 1; k >= 0; k--) {
        int gap = s[k];
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


int main() {
    vector<int> a(1000000);
    mt19937 mt(time(nullptr));
    for (int i = 0; i < a.size(); i++)
        a[i] = (mt() % 100) + 100;

    auto start = chrono::steady_clock::now();
    shell_pratt_sort(a);
    auto end = chrono::steady_clock::now();
    chrono::duration < double > elapsed_seconds = end - start;
    
    auto start2 = chrono::steady_clock::now();
    sort(a.begin(), a.end());
    auto end2 = chrono::steady_clock::now();
    chrono::duration < double > elapsed_seconds2 = end2 - start2;

    cout << " elapsed time: " << elapsed_seconds.count() << "s\n";
    cout << " elapsed time: " << elapsed_seconds2.count() << "s\n";
}

/*

        shell_pratt_sort()        sort()

10^3        0.0017 sec           0.0003 sec

10^4        0.05 sec             0.002 sec

10^5        0.3 sec              0.02 sec

10^6        4.3 sec               0.16 sec

 - при size/3 и size/5 временные затраты до 10^5 +- одинаковые, при 10^6: 65 sec при size/3, 70 sec при size/5
*/
  

        
