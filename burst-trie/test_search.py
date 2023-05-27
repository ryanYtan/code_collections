from prototype import *

c1 = BurstTrieContainer({'r', 'me', 't', 've'})
c2 = BurstTrieContainer({'n'})
c3 = BurstTrieContainer()
c4 = BurstTrieContainer({'re', 'nt', 'st', ''})

n2 = BurstTrieNode()
n2._ptrs[''] = c3
n2._ptrs['a'] = c2

n1 = BurstTrieNode()
n1._ptrs['a'] = c1
n1._ptrs['y'] = n2

n3 = BurstTrieNode()
n3._ptrs['e'] = c4

n_root = BurstTrieNode()
n_root._ptrs['c'] = n1
n_root._ptrs['w'] = n3

tree = BurstTrie(n_root)

assert tree.search('came')
assert tree.search('car')
assert tree.search('cat')
assert tree.search('cave')
assert tree.search('cy')
assert tree.search('cyan')
assert tree.search('we')
assert tree.search('went')
assert tree.search('were')
assert tree.search('west')
assert not tree.search('')
assert not tree.search(' ')
assert not tree.search('assert')
assert not tree.search('cw')
assert not tree.search('cyaa')
assert not tree.search('c')
assert not tree.search('cya')
assert not tree.search('wenta')
assert not tree.search('wer')
assert not tree.search('wesp')
assert not tree.search('cyann')
