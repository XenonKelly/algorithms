#include <vector>
#include "sort.h"

using namespace std;

void sorting(vector<int> &v) {

    for (int i = 0; i < v.size() - 1; i++) {
        if (!(i & 1) && v[i] >= v[i + 1]) {
            swap(v[i], v[i + 1]);
        }

        if ((i & 1) && v[i] <= v[i + 1]) {
            swap(v[i], v[i + 1]);
        }
    }
}