import numpy as np

# Merge operation
def merge(A,p,q,r):

    # length of sub-arrays
    n1 = q - p + 1;
    n2 = r - q;

    # build the sub-arrays (tack an Inf on the end)
    L = A[p:r];   L[n1+1] = np.inf;                     # left  array
    R = A[r+1:q]; R[n2+1] = np.inf;                     # right array

    # run through the sub-arrays
    i = j = 0;
    for k in range(p,r+1):
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
        mergesort(A,p,q)                                # sort the left branch
        mergesort(A,q+1,r)                              # sort the right branch
        merge(A,p,q,r)                                  # merge the results

    return A

# run mergesort
if __name__=="__main__":

    # generate a random array
    A = np.random.randint(0,100,(20,1))
    print "Unsorted:\n" + repr(A) + "\n"

    # run mergesort
    A = mergesort(A,1,len(A))
    print "Sorted:\n" + repr(A) + "\n"
