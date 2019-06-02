import unittest
import pysnooper

@pysnooper.snoop()
def reverse_stack(stack):
    if not stack:
        return []

    val = stack.pop()
    stack = reverse_stack(stack)
    stack.append(val)
    return stack


stack = [1, 2, 3, 4]
reverse_stack(stack)
print(stack)
