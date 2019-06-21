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
        while j > 0 and arr[j] > e:
            arr[j] = arr[j - 1]
            j -= 1
        arr[j] = e
