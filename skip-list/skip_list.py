from typing import *

T = TypeVar('T')

class ListNode:
    def __init__(self, value: T, width: int, next: None):
        self.value = value
        self.next = next
        self.width = width #number of elements to next link


class SkipList:
    def __init__(self):
        self.heads = [ListNode(None, 1)]
        self.tails = [ListNode(None, 0)]
        self.heads[0].next = self.tails[0]
        self.capacity = 0

    def size(self):
        return self.capacity

    def insert(self, value: T) -> None:
