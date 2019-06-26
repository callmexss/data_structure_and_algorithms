import pyhandy.pyhandy as handy
import sortalg

if __name__ == '__main__':
    li = handy.generate_nearly_ordered_array(10000, 10)
    li1 = li[:]
    handy.testSort("Selection Sort", sortalg.selection_sort, li)
    handy.testSort("Insert Sort", sortalg.insertion_sort, li)
