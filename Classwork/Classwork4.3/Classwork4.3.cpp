#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


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
    sort(m.begin(), m.end());

    vector<pair<int, int>> pairs;

    cout << "Input S:\n";
    int s;
    cin >> s;
    int start = 0;
    int end = m.size() - 1;
    while (start < end) {
        int sum;
        sum = m[start] + m[end];

        if (sum == s)
        {
            std::vector<int>::iterator it_s = std::find(v.begin(), v.end(), m[start]);
            std::vector<int>::iterator it_e = std::find(v.begin(), v.end(), m[end]);
            pairs.push_back(make_pair(it_s - v.begin(), it_e - v.begin()));

            start++;
            end--;
        }

        else if (sum < s)
            start++;
        else if (sum > s)
            end--;
        
    }

    if (pairs.size() == 0) {
        cout << "not found";
    }

    for (auto i = 0; i < pairs.size(); ++i) {
        cout << "{" << pairs.at(i).first << ", "
            << pairs.at(i).second << "}" << "; ";
    }
    cout << endl;   
}





