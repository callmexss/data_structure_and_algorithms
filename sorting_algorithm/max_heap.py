import random
import math


class MaxHeap:
    def __init__(self):
        self.data = [None]

    def size(self):
        return len(self.data) - 1

    def insert(self, val):
        self.data.append(val)
        self.__shift_up()

    def extract_max(self):
        assert self.size() > 0
        ret = self.data[1]
        self.data[1], self.data[-1] = self.data[-1], self.data[1]
        self.data.pop()
        self.__shift_down(1)
        return ret

    def test_print(self):
        max_size = 100
        assert(self.size() <= max_size)

        level = 0
        count = 0
        height = math.floor(math.log2(self.size())) + 1
        print(height)
        for n, val in enumerate(self.data[1:], 1):
            inner_level = math.floor(math.log2(n)) + 1
            if inner_level != level:
                print()
                level = inner_level
                count = 0
            print(" " * (max_size // (level + 1) - 1), end="")
            print(f"{val}", end="")
            count += 1

        print()

    def __shift_up(self):
        n = self.size()
        while n > 1 and self.data[n] > self.data[n // 2]:
            self.data[n], self.data[n // 2] = self.data[n // 2], self.data[n]
            n = n >> 1

    def __shift_down(self, k):
        while 2 * k <= self.size():
            j = 2 * k  # in this turn data[k] will swap with data[j]
            if j + 1 <= self.size() and self.data[j + 1] > self.data[j]:
                j += 1

            if self.data[k] > self.data[j]:
                break

            self.data[k], self.data[j] = self.data[j], self.data[k]
            k = j


if __name__ == '__main__':
    max_heap = MaxHeap()
    for i in range(20):
        max_heap.insert(random.randint(0, 100))

    print(max_heap.data)
    max_heap.test_print()

    while max_heap.size():
        print(max_heap.extract_max(), end=" ")
    print()