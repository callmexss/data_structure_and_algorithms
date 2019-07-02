import random

try:
    from sorting_algorithm import heap
except ImportError:
    from . import heap


def selection_sort(arr):
    """Selection sort
    
    Arguments:
        arr {list} -- a list of stuff to be sorted
    """
    for i in range(len(arr)):
        min_index = i
        for j in range(i, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]


def insertion_sort(arr):
    for i in range(1, len(arr)):
        e = arr[i]
        j = i
        while j > 0 and arr[j - 1] > e:
            arr[j] = arr[j - 1]
            j -= 1
        arr[j] = e


def bubble_sort(arr):
    for i in range(0, len(arr)):
        swap = False
        for j in range(0, len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swap = True
        if not swap:
            break


def shell_sort(arr):
    pass


def __merge(arr, l, m, r):
    tmp = arr[l: r + 1]

    i = l
    j = m + 1
    for k in range(l, r + 1):
        if i > m:  # arr[l, m]
            arr[k] = tmp[j - l]
            j += 1
        elif j > r:  # arr[m + 1, r]
            arr[k] = tmp[i - l]
            i += 1
        elif tmp[i - l] < tmp[j - l]:
            arr[k] = tmp[i - l]
            i += 1
        else:
            arr[k] = tmp[j - l]
            j += 1


def __merge_sort(arr, l, r):
    if l >= r:
        return

    mid = (l + r) // 2
    __merge_sort(arr, l, mid)
    __merge_sort(arr, mid + 1, r)
    __merge(arr, l, mid, r)


def merge_sort(arr):
    __merge_sort(arr, 0, len(arr) - 1)


def __partition(arr, l, r):
    pivot = arr[r]

    i = l
    for j in range(l, r):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[r], arr[i] = arr[i], arr[r]
    return i


def __quick_sort(arr, l, r):
    if l >= r:
        return

    p = __partition(arr, l, r)
    __quick_sort(arr, l, p - 1)
    __quick_sort(arr, p + 1, r)


def quick_sort(arr):
    # arr[0, n-1]
    __quick_sort(arr, 0, len(arr) - 1)


def heap_sort(arr):
    max_heap = heap.MaxHeap()
    for each in arr:
        max_heap.insert(each)

    for i in range(len(arr) - 1, -1, -1):
        arr[i] = max_heap.extract_max()

def heap_sort2(arr):
    pass