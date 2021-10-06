from ..utils.node import Node


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def dequeue(self):
        if not self.head:
            return None
        if self.head == self.tail:
            self.tail = None
            self.head.next = None
        return_value = self.head.value
        self.head = self.head.next
        return return_value

    def enqueue(self, value):
        if value is None:
            return None
        new_node = Node(value=value)
        if self.tail:
            self.tail.next = new_node
        self.tail = new_node
        if not self.head:
            self.head = self.tail

    def isEmpty(self):
        return not self.tail

    def peek(self):
        return self.head.value if self.head else None


if __name__ == "__main__":
    s = Queue()
    assert(s.peek() is None)
    assert(s.dequeue() is None)
    s.enqueue(1)
    assert(s.peek() == 1)
    assert(s.dequeue() == 1)
    assert(s.dequeue() is None)
    for i in range(1, 4):
        s.enqueue(i)
    for i in range(1, 4):
        assert(s.peek() == i)
        assert(s.dequeue() == i)
    assert(s.dequeue() is None)
