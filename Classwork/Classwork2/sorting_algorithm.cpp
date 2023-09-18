#include <iostream>
#include "sorting_algorithm.h"

using namespace std;


void selection_sort(int m[], int size) {
	for (int i = 1; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (!(j & 1)) {
				if (m[i] >= m[j])
					swap(m[i], m[j]);
				break;
			}
			if (m[i] <= m[j]) {
				swap(m[i], m[j]);
			}
			break;
		}
	}
}