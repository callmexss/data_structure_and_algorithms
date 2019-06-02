import unittest
import sys
from contextlib import contextmanager
from io import StringIO

import pysnooper


class Queue(object):
    def __init__(self):
        self.push_stack = []
        self.pop_stack = []

    def _empty(self):
        return len(self.pop_stack) == 0

    def add(self, e):
        self.pop_stack.append(e)

    def poll(self):
        while self.pop_stack:
            self.push_stack.append(self.pop_stack.pop())

        while self.push_stack:
            val = self.push_stack.pop()
            print(val)
            self.pop_stack.append(val)

    def peek(self):
        if not self.pop_stack:
            return

        while self.pop_stack:
            self.push_stack.append(self.pop_stack.pop())

        val = self.push_stack.pop()

        while self.push_stack:
            self.pop_stack.append(self.push_stack.pop())

        return val


@contextmanager
def captured_output():
    new_stdout, new_stderr = StringIO(), StringIO()
    old_stdout, old_stderr = sys.stdout, sys.stderr
    try:
        sys.stdout, sys.stderr = new_stdout, new_stderr
        yield sys.stdout, sys.stderr
    finally:
        sys.stdout, sys.stderr = old_stdout, old_stderr


class TestQueueByStack(unittest.TestCase):
    def setUp(self):
        self.q = Queue()
        li = [x for x in range(5)]
        for each in li:
            self.q.add(each)

    # def test_poll(self):
    #     self.q.poll()

    def test_peek(self):
        self.assertEqual(self.q.peek(), 0)
        self.assertEqual(self.q.peek(), 1)
        self.assertEqual(self.q.peek(), 2)
        self.assertEqual(self.q.peek(), 3)
        self.assertEqual(self.q.peek(), 4)

    def test_poll(self):
        self.q.peek()
        self.q.peek()
        self.q.add(9)

        with captured_output() as (out, err):
            self.q.poll()  # 2, 3, 4, 9

        output = out.getvalue().strip()
        self.assertEqual(output, "2\n3\n4\n9")