'''
File:          array.py
File Created:  Tuesday, 26th November 2019 1:44:37 pm
Author:        xss (callmexss@126.com)
Description:   Python implementation of Array
-----
Last Modified: Tuesday, 26th November 2019 1:45:58 pm
Modified By:   xss (callmexss@126.com)
-----
'''


class Array:
    def __init__(self, capacity=10):
        self.capacity = capacity
        self.used = 0
        self.__data = [None] * (capacity + 1)  # for move data

    def __len__(self):
        return self.used

    def __getitem__(self, n):
        if 0 <= n < self.used:
            return self.__data[n]
        else:
            raise IndexError("Index out of range.")

    def __setitem__(self, n, val):
        if 0 <= n < self.used:
            self.__data[n] = val
        else:
            raise IndexError("Index out of range.")

    def full(self):
        return self.used == self.capacity

    def empty(self):
        return self.used == 0
    
    def append(self, val):
        if not self.full():
            self.used += 1
            self.__data[self.used - 1] = val
        else:
            raise IndexError("Array is full.")

    def insert(self, loc, val):
        if loc == 0 and self.empty():
            self.__data[loc] = val
            self.used += 1

        elif 0 <= loc < self.used:
            for i in range(self.used - 1, loc - 1, -1):
                self.__data[i + 1] = self.__data[i]

            self.__data[loc] = val

            if not self.full():
                self.used += 1
        else:
            raise IndexError("Index out of range.")

    def remove(self, loc):
        if 0 <= loc < self.used:
            for i in range(loc, self.used):
                self.__data[i] = self.__data[i + 1]

            self.used -= 1
        else:
            raise IndexError("Index out of range.")

    def __repr__(self):
        return "Array Object: " + str(self.__data[:self.used])


if __name__ == '__main__':
    array = Array(2)
    array.insert(0, 1)
    print(len(array))
    print(array)
    array.insert(0, 1)
    print(len(array))
    print(array)
    array.insert(0, 0)
    print(len(array))
    print(array)
    array.remove(0)
    print(len(array))
    print(array)
    array.remove(0)
    print(len(array))
    print(array)
    # print(array[100])
    array = Array()
    for i in range(9):
        array.append(i)
    array.insert(3, 10)
    array.insert(4, 11)
    array.insert(5, 12)
    array.insert(6, 13)
    array.insert(7, 14)
    print(len(array))
    print(array)
    array.remove(0)
    print(len(array))
    print(array)
    array.remove(0)
    print(len(array))
    print(array)
    array.remove(0)
    print(len(array))
    print(array)
    array.remove(0)
    # array.remove(10)
