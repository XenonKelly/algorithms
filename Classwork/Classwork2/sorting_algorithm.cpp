#include <iostream>
#include "sorting_algorithm.h"


using namespace std;


void array_sort(int m[], int size) {
	
	for (int i = 0; i < size - 1; i++) {
		if (!(i & 1) && m[i] >= m[i + 1]) {
			swap(m[i], m[i + 1]);
		}
			
		if ((i & 1) && m[i] <= m[i + 1]) {
			swap(m[i], m[i + 1]);
		}		
	}
}





