from __future__ import annotations
from typing import *
import string

ALPHABET = string.ascii_lowercase + ' '

class BurstTrieContainer:
    def __init__(self, suffixes: Set[str] = set()):
        self.suffixes = suffixes

    def insert(self, suffix: str) -> bool:
        self.suffixes.add(suffix)

    def __repr__(self) -> str:
        return str(self.suffixes)

def _create_ptrs():
    d = { c: None for c in ALPHABET }
    d[''] = None
    return d

class BurstTrieNode:
    def __init__(self, ptrs: Dict[str, BurstTrieNode | BurstTrieContainer] = None):
        self._ptrs = _create_ptrs() if ptrs is None else ptrs


    def set_key(self, key: str, v: BurstTrieNode | BurstTrieContainer) -> None:
        assert type(key) is str and len(key) <= 1
        self._ptrs[key] = v


    def get(self, key: str) -> Optional[BurstTrieNode | BurstTrieContainer]:
        return self._ptrs[key]


    def __repr__(self) -> str:
        to_print = {}
        for a, b in self._ptrs.items():
            if b is not None:
                to_print[a] = b
        return f'[parent={self.parent},ptrs={to_print}]'


class BurstTrie:
    def __init__(self, root: BurstTrieNode = BurstTrieNode()):
        self.root = root

    #query is a 1-indexed string
    def _get_container(self, query: str) -> Tuple[BurstTrieNode | BurstTrieContainer, int]:
        curr = self.root
        depth = 1
        n = len(query)
        while type(curr) is BurstTrieNode and depth <= n:
            c = query[depth - 1]
            tmp = curr.get(c)
            if tmp is None:
                break
            curr = tmp
            depth += 1
        return curr, depth

    def search(self, query: str) -> bool:
        n = len(query)
        curr, depth = self._get_container(query)
        if type(curr) is BurstTrieNode and depth == n + 1:
            return curr.get('') is not None
        elif type(curr) is BurstTrieNode:
            return False
        else:
            return curr is not None and query[depth - 1:] in curr.suffixes


    def insert(self, query: str) -> bool:
        n = len(query)
        curr, depth = self._get_container(query)

        assert curr is not None

        if type(curr) is BurstTrieNode and depth == n + 1:
            curr.set_key('', BurstTrieContainer())
        elif type(curr) is BurstTrieNode:
            char = query[depth - 1:depth]
            suffix = query[depth:]
            curr.set_key(char, BurstTrieContainer({ suffix }))
        else:
            suffix = query[depth - 1:]
            curr.insert(suffix)

    def __repr__(self):
        return str(self.root)



    #def _burst(self, curr: BurstTrieNode, parent: BurstTrieNode) -> bool:
    #    pass
