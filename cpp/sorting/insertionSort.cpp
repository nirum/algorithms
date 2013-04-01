/* insertionsort.cpp
 * implementation of insertion sort
 * (c) bnaecker@stanford.edu 20 Mar 2013
 */

/* include */
#include <iostream>
#include <cmath>
#include <ctime>

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

/* main */
int main() {

	/* define lengths of arrays to sort */
	const unsigned short N = 16;					// power of 2 of maximum array size to sort
	const unsigned long maxArraySize = pow(2, N);	// actual size
	const unsigned long maxRand = pow(2, N+1);		// make random numbers up to the next power of two

	unsigned long sortLengths[N];					// an array with all the lengths
	for (int ni = 0; ni < N; ni++) {
		sortLengths[ni] = pow(2, ni+1);
	}

	/* notify */
	std::cout << "sorting " << N << " lists, up to size " << pow(2,N) << "\n";

	/* loop over different sort lengths */
	for (int li = 0; li < N; li++) {
		
		/* make the array */
		double sort[sortLengths[li]];
		for (int lii = 0; lii < sortLengths[li]; lii++) {
			sort[lii] = genRand(100);
		}

		/* notify */
		//std::cout << "sorting a list of length " << sortLengths[li] << "\n";
		std::cout << "sorting list of size " << pow(2,li+1) << " ... ";
   /*     for (int ci = 0; ci < sortLengths[li]; ci++) {*/
				//std::cout << sort[ci] << "\t";
		//}
	  /*  std::cout << "\n\n"; */

		/* start timer */
		clock_t tStart = clock();

		/* INSERTION SORT */
		for (int j = 1; j < (sizeof(sort)/sizeof(double)); j++) {
			double key = sort[j];
			// insert sort[j] into sorted sequence sort[1..j-1]
			int i = j-1;
			while (i>=0 && sort[i] > key) {
				sort[i+1] = sort[i];
				i--;
			}
			sort[i+1] = key;
		}

		/* stop timer */
		clock_t tEnd = clock();
		printf("%.6f seconds\n", ((float)(tEnd - tStart)/CLOCKS_PER_SEC));

		//std::cout << "now the list " << li << " is:";
		//for (int ci = 0; ci < sortLengths[li]; ci++) {
			//std::cout << sort[ci] << "\t";
		//}
		/*std::cout << "\n\n";*/
	}

	/* output of main */
	return 0;
}
