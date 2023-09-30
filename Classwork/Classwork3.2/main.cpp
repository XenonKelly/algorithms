#include <iostream>
#include<vector>
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
 
    int k = *std::max_element(v.begin(), v.end()) + 1;
    
    vector<int> count(k, 0);
    for (auto x : v) {
        count[x] += 1;
    }

    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

  
    /*vector<int> v(100); //изначальный массив
    mt19937 mt(time(nullptr));
    for (int i = 0; i < v.size(); i++)
        v[i] = (mt() % 100) + 100;*/
    

    cout << "Input q:\n";
    int q;
    cin >> q;

    cout << "Input l and r:\n";
    int l, r, res;

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;

        if ((l == 0) && (r >= k))
            res = count.back();
        else if ((l > 0) && (r >= k))
            res = count.back() - count[l - 1];
        else if (l == 0 and r < k)
            res = count[r];
        else
            res = count[r] - count[l - 1];

        cout << res;
        cout << endl;
    }
}




        





