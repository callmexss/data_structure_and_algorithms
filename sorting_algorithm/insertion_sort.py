#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""""""""""""""""""""""""""""""""""""""""""""""
"      Filename: insertion_sort.py
"
"        Author: xss - callmexss@126.com
"   Description: ---
"        Create: 2017-12-06 22:07:49
"""""""""""""""""""""""""""""""""""""""""""""""
import pyhandy.pyhandy as handy


def insertion_sort(num):
    # num: list of number
    if len(num) == 1:
        return num

    for i in range(1, len(num)):
        temp = num[i]
        j = i

        # find a suitable location for num[i]
        # so move each element in sorted part to its next location
        # if it is larger than num[i]
        # and put num[i] after the first element smaller than it
        while(j > 0 and (num[j] < num[j-1])):
            num[j], num[j-1] = num[j-1], num[j]
            j -= 1

        num[j] = temp

    return num


if __name__ == "__main__":
    rh = handy.RandomHandy()
    sh = handy.SortHandy()
    n = 10000
    sh.testSort(insertion_sort, rh.generate_nearly_ordered_array(n))
    sh.testSort(insertion_sort, rh.generate_random_array(n, 0, n))
