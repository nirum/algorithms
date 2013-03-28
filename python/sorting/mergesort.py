import numpy as np
import time as t

# Merge operation
def merge2(L,R):

    A = np.zeros(len(L)+len(R))                         # empty joint array
    L = np.append(L,np.inf)                             # tack on inf to left array
    R = np.append(R,np.inf)                             # tack on inf to right array

    i = j = 0
    for k in np.arange(0,len(A)):
        if L[i] <= R[j]:                                # left comes first
            A[k] = L[i]                                 # put 1st left element into array
            i+=1
        else:                                           # right comes first
            A[k] = R[j]                                 # put 1st right element into array
            j+=1

    return A

# Mergesort
def mergesort(A,p,r):
    if p < r:
        q = np.floor((p+r)/2)                           # find a midpoint
        Al = mergesort(A,p,q)                           # sort the left branch
        Ar = mergesort(A,q+1,r)                         # sort the right branch
        A = merge2(Al,Ar)                               # merge the results
    else:
        A = A[p]

    return A

# run mergesort
if __name__=="__main__":

    # run over different problem sizes
    maxSize = 15
    sizes = 2**np.arange(0,maxSize+1)

    # for loop over sizes
    for s in sizes:

        # generate a random array
        A = np.random.randint(0,2**maxSize,(s,1))

        # run mergesort
        start = t.time()
        A = mergesort(A,0,len(A)-1)
        print "size: " + repr(s) + ")\t Elapsed time:\t" + repr(t.time() - start)
