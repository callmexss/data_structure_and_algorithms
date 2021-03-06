from sorting_algorithm import sortalg

import pyhandy.pyhandy as handy

if __name__ == '__main__':
    random_handy = handy.RandomHandy()
    sort_handy = handy.SortHandy()
    li = random_handy.generate_random_array(1000)
    # li = random_handy.generate_nearly_ordered_array(5)
    li1 = li[:]
    li2 = li[:]
    li3 = li[:]
    li4 = li[:]
    li5 = li[:]
    li6 = li[:]
    sort_handy.testSort(list.sort, li)
    sort_handy.testSort(sortalg.selection_sort, li1)
    sort_handy.testSort(sortalg.insertion_sort, li2)
    sort_handy.testSort(sortalg.bubble_sort, li3)
    sort_handy.testSort(sortalg.quick_sort, li4)
    sort_handy.testSort(sortalg.merge_sort, li5)
    sort_handy.testSort(sortalg.heap_sort, li6)
    li = random_handy.generate_random_array(10)
