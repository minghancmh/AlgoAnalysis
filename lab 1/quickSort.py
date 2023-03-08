def quickSort(array, low, high):
    if (low>=high):
        return
    pi = partition(array, low, high)
    quickSort(array, low, pi-1)
    quickSort(array, pi+1, high)

def partition(array, low, high):
    pivot = array[(low+high)//2]
    array[low], array[(low+high)//2] = array[(low+high)//2], array[low]
    last_small = low
    for j in range(low+1, high+1):
        if (array[j] <= pivot):
            last_small+=1
            array[last_small], array[j] = array[j], array[last_small]
    array[last_small], array[low] = array[low], array[last_small]
    return last_small


x = [10,9,8,7,6,5,4,3,2,1]

quickSort(x, 2,7)

print(x)

