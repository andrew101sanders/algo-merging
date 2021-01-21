def merge(L, R):
    temp = []
    for i in range(len(R) + len(L)):
        temp.append(-1)
    i = j = k = 0

    # Copy data to temp arrays L[] and R[]
    while i < len(L) and j < len(R):
        if L[i] < R[j]:
            temp[k] = L[i]
            i += 1
        else:
            temp[k] = R[j]
            j += 1
        k += 1

    # Checking if any element was left
    while i < len(L):
        temp[k] = L[i]
        i += 1
        k += 1

    while j < len(R):
        temp[k] = R[j]
        j += 1
        k += 1
    return temp