from ..utils.node import Node


class Stack:
    def __init__(self):
        self.head = None

    def pop(self):
        if not self.head:
            return None
        top_node = self.head
        self.head = self.head.next
        return top_node.value

    def push(self, value):
        if value is None:
            return None
        self.head = Node(value=value, next_node=self.head)

    def isEmpty(self):
        return not self.head

    def top(self):
        return self.head.value if self.head else None


if __name__ == "__main__":
    s = Stack()
    assert(s.top() is None)
    assert(s.pop() is None)
    s.push(1)
    assert(s.top() == 1)
    assert(s.pop() == 1)
    for i in range(1, 4):
        s.push(i)
    for i in range(3, 0, -1):
        assert(s.top() == i)
        assert(s.pop() == i)
