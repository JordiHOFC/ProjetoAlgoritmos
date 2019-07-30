#include<stdio.h>
#include<stdlib.h>
void insertionSort(int* original, int length) {
	int i, j, atual;

	for (i = 1; i < length; i++) {
		atual = original[i];
		

		for (j = i - 1; (j >= 0) && (atual < original[j]); j--) {
			original[j + 1] = original[j];
        }

		original[j+1] = atual;
	}

}

