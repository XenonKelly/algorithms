#include <iostream>
#include "sorting_algorithm.h"

using namespace std;


void array_sort(int m[], int size) {
	for (int i = 1; i < size; i++) {
		int j = i;
		int x = m[i];
		while (j > 0 && m[j - 1] > x) {
			m[j] = m[j - 1];
			j--;
		}
		m[j] = x;
	}

	for (int i = 1; i < size-1; i+=2) {
		swap(m[i], m[i+1]);
	}
}

