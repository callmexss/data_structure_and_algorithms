import random
import unittest

class Stack(object):
    def __init__(self):
        self.list = []

    def _empty(self):
        return len(self.list) == 0

    def pop(self):
        if not self._empty():
            self.list.pop()

    def push(self, e):
        self.list.append(e)

    def top(self):
        if not self._empty():
            return self.list[-1]


class StackWithGetMin:
    def __init__(self):
        self.data_stack = Stack()
        self.min_stack = Stack()

    def _empty(self):
        return True if self.data_stack._empty() else False

    def push(self, e):
        if self.min_stack._empty() or e <= self.min_stack.top():
            self.min_stack.push(e)
        self.data_stack.push(e)

    def pop(self):
        if self._empty():
            return
        if self.data_stack.top() == self.min_stack.top():
            self.data_stack.pop()
            self.min_stack.pop()
        else:
            self.data_stack.pop()
        
    def get_min(self):
        if self.min_stack._empty():
            return None
        else:
            return self.min_stack.top()


class TestStackWithGetMin(unittest.TestCase):
    def setUp(self):
        self.stack = StackWithGetMin()
        test_list = [9, 3, 7, 2, 5, 1]
        for each in test_list:
            self.stack.push(each)

    def test_get_min(self):
        self.assertEqual(self.stack.get_min(), 1)
        self.stack.pop()
        self.assertEqual(self.stack.get_min(), 2)
        self.stack.pop()
        self.assertEqual(self.stack.get_min(), 2)
        self.stack.pop()
        self.assertEqual(self.stack.get_min(), 3)
        self.stack.pop()
        self.assertEqual(self.stack.get_min(), 3)
        self.stack.pop()
        self.assertEqual(self.stack.get_min(), 9)
        self.stack.pop()
        self.assertEqual(self.stack.get_min(), None)