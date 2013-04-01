/* mergesort.cpp
 * implementation of mergesort algorithm
 * (c) bnaecker@stanford.edu 25 Mar 2013
 */

/* includes */
#include <iostream>
#include <cmath>
#include <ctime>
#include <limits>

/* setup "infinity" */
int infty = std::numeric_limits<int>::max();

/* generate random numbers */
int genRand(int topPlusOne) {
	unsigned two31 = 1U << 31;
	unsigned maxUsable = (two31 / topPlusOne) * topPlusOne;

	while(1) {
		unsigned num = random();
		if (num < maxUsable) {
			return num % topPlusOne;
		}
	}
}

/* method to merge two lists */
void merge(double *A, int p, int q, int r) {
	
	//std::cout << "\n";

	/* sizes of sub arrays */
	int n1 = q - p + 1;
	int n2 = r - q;

	/* create new subarrays from the original */

	// allocate the arrays
	int L[n1+1], R[n2+1];

	// copy the values from the original array
	for (int i=0; i<n1; i++) {
		L[i] = A[p + i];
	}
	for (int j=0; j<n2; j++) {
		R[j] = A[q + j + 1];
	}

	/* add sentinels */
	L[n1] = infty;
	R[n2] = infty;

	/* merge the arrays appropriately */
	int i = 0, j = 0;
	for (int k=p; k<=r; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}

}

/* mergesort */
void mergesort(double *A, int p, int r) {
	if (p < r) {
		int q = floor((p+r)/2);
		mergesort(A, p, q);
		mergesort(A, q+1, r);
		merge(A, p, q, r);
	}
}

/* main */
int main() {

	/* definte lengths of arrays to sort */	
	const unsigned short N = 18;					// power of 2 of maximum array size to sort
	const unsigned long maxArraySize = pow(2, N);	// actual size of arrays to sort
	const unsigned long maxRand = pow(2, N+1);		// make random numbers up to next power of 2

	/* make an array with all the lenghts to sort */
	unsigned long lengths[N];
	for (int ni=0; ni<N; ni++) {
		lengths[ni] = pow(2, ni+1);
	}

	/* loop over different sorting lengths */
	for (int li=0; li<N; li++) {

		/* make array to be sorted */
		double A[lengths[li]];
		for (int ai=0; ai<lengths[li]; ai++) {
			A[ai] = genRand(maxRand);
		}

		// print original array
   /*     std::cout << "original array : ";*/
		//for (int i=0; i < N; i++) {
			//std::cout << A[i] << "\t";
	  /*  }*/

		std::cout << "sorting random array of size " << lengths[li] << " ... ";
		clock_t tStart = clock();
		mergesort(A, 0, lengths[li]-1);
		clock_t tEnd = clock();
		printf("%.6f seconds\n", ((float)(tEnd - tStart)/CLOCKS_PER_SEC));

		// print merged array
   /*     std::cout << "\nsorted array : ";*/
		//for (int i=0; i<N; i++) {
			//std::cout << A[i] << "\t";
	  /*  }*/
	}

	// return statement for main
	return 0;
}
