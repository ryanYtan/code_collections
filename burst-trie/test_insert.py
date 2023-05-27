from prototype import *

trie = BurstTrie()
trie.insert('')
trie.insert('came')
trie.insert('went')
trie.insert('went')
trie.insert('wendigo')
trie.insert('ent')

assert trie.search('')
assert trie.search('came')
assert trie.search('went')
assert trie.search('wendigo')
assert trie.search('ent')
assert not trie.search('en')
assert not trie.search('wnt')
