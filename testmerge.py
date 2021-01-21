import timeit
import merging

def printList(L, R):
    for i in range(len(L)):
        print(L[i], end=" ")
    for i in range(len(R)):
        print(R[i], end=" ")
    print()

def prepare(num):
    L = []
    R = []
    for i in range(1, num,2):
        L.append(i)
    for i in range(2, num,2):
        R.append(i)
    return L,R
def test(L, R):
    
    #print("Given array is", end="\n")
    #printList(L, R)
    final = merging.merge(L, R)
    #print("Sorted array is: ", end="\n")
    #printList(final[0:len(final)-1//2], final[(len(final)-1//2)+1:-1])
if __name__ == '__main__':
    times = 10
    amount = 25000000
    print(timeit.Timer(f'test(L,R)', setup=(f'from __main__ import test, prepare; L,R = prepare({amount})')).timeit(times)/times)
    
    
