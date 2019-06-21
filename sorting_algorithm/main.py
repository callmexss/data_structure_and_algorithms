import sortalg 
import pyhandy.pyhandy as handy

li = handy.generate_nearly_ordered_array(10000, 10)
li1 = li[:]
handy.testSort("Selection Sort", sortalg.selection_sort, li)
handy.testSort("Insert Sort", sortalg.insertion_sort, li)
