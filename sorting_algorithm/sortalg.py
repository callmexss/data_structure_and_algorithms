import random


def selection_sort(arr):
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


def merge_sort(arr):
    pass


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
