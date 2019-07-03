import random
import sys

import pyhandy.pyhandy as handy

sys.setrecursionlimit(1500)

def __partition(arr, l, r):
    p = random.randint(l, r)
    pivot = arr[p]

    arr[r], arr[p] = arr[p], arr[r]

    i = l
    for j in range(l, r):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[r] = arr[r], arr[i]
    return i


# arr[l...r]
def __quick_sort(arr, l, r):
    if l >= r:
        return
    
    p = __partition(arr, l, r)
    __quick_sort(arr, l, p - 1)
    __quick_sort(arr, p + 1, r)


def quick_sort(arr):
    # we will do the inner operation on arr[l...r]
    # so we will need both endpoints include
    # which need `len(arr) - 1` as argument
    __quick_sort(arr, 0, len(arr) - 1)


def __partition_without_random_pivot(arr, l, r):
    pivot = arr[r]

    i = l
    for j in range(l, r):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[r] = arr[r], arr[i]
    return i


def __quick_sort_without_random_pivot(arr, l, r):
    if l >= r:
        return

    p = __partition_without_random_pivot(arr, l, r)
    __quick_sort_without_random_pivot(arr, l, p - 1)
    __quick_sort_without_random_pivot(arr, p + 1, r)

def quick_sort_without_random_pivot(arr):
    __quick_sort_without_random_pivot(arr, 0, len(arr) - 1)


if __name__ == "__main__":
    rh = handy.RandomHandy()
    sh = handy.SortHandy()
    n = 5000

    # li = rh.gen_list(n, (-n, n))
    li = rh.generate_nearly_ordered_array(n)
    li1 = li[:]
    sh.testSort(quick_sort, li[:])
    # degenerate to O(n^2) will use about O(n) stack space
    # in python it may cause maxrecursion depth exceed
    sh.testSort(quick_sort_without_random_pivot, [x for x in range(0, 1000)])
    sh.testSort(list.sort, li[:])
