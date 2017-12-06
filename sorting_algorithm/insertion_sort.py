#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""""""""""""""""""""""""""""""""""""""""""""""
"      Filename: insertion_sort.py
"
"        Author: xss - callmexss@126.com
"   Description: ---
"        Create: 2017-12-06 22:07:49
"""""""""""""""""""""""""""""""""""""""""""""""


def insertion_sort(num):
    # num: list of number
    if len(num) == 1:
        return num

    for i in range(1, len(num)):
        temp = num[i]
        j = i

        while(j > 0 and (num[j] < num[j-1])):
            num[j], num[j-1] = num[j-1], num[j]
            j -= 1

        num[j] = temp

    return num


num = [3, 1, 4, 9, 2, 6, 5, 3]

print(insertion_sort(num))
