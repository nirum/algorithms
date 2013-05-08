/* bubblesort.cpp
 * implementation of bubblesort
 * (c) benjamin.naecker@gmail.com 07 May 2013
 */

/* include */
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

/* generate random numbers */
int genRand(int topPlusOne) {
	unsigned two31 = 1U << 31;
	unsigned maxUsable = (two31 / topPlusOne) * topPlusOne;

	while(1) {
		unsigned num = random();
		if(num < maxUsable)
			return num % topPlusOne;
	};
}

/* generate array lengths */
void defArrayLengths(unsigned long *sortLengths, int N) {
	for (int ni = 0; ni < N; ni++) {
		sortLengths[ni] = pow(2, ni+1);
	}
}

/* make random array */
void makeRandomArray(double *A, int length) {
	for (int lii = 0; lii < length; lii++) {
		A[lii] = genRand(100);
	}
}

/* bubblesort */
void bubblesort(double *A, int sz) {
	for (int i = 0; i < sz-1; i++) {
		for (int j = sz; j >= i+1; j--) {
			if (A[j] < A[j-1]) {
				double tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	/* parse cmd-line args */
	// just get first, which should be max length in powers of two
	int N;
	if (argc < 2) {
		N = 10;
	} else {
		N = atoi(argv[1]);
	}

	/* define lengths of arrays to sort */
	unsigned long sortLengths[N];
	defArrayLengths(sortLengths, N);

	/* notify */
	std::cout << "sorting " << N << " lists, up to size " << pow(2,N) << "\n";

	/* loop over different sort lengths */
	for (int li = 0; li < N; li++) {
		
		/* make the array */
		double sort[sortLengths[li]];
		makeRandomArray(sort, sortLengths[li]);

		/* notify */
		std::cout << "sorting list of size " << pow(2,li+1) << " ... ";

		/* start timer */
		clock_t tStart = clock();

		/* bubblesort */
		bubblesort(sort, sortLengths[li]);

		/* stop timer */
		clock_t tEnd = clock();
		printf("%.6f seconds\n", ((float)(tEnd - tStart)/CLOCKS_PER_SEC));

	}

	/* output of main */
	return 0;
}
