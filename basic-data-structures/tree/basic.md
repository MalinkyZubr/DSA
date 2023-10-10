## Trees
* no logical end
* what needs to be stored?
* what is the cost of operations
* memory usage

### trees are used for hierarchical data
* really its more like a root
* a tree is made up of nodes
* the top of the tree is the root
* nodes are connected by edges
* nodes below are called children
* nodes above are called ancestors
* siblings are adjacent children of the same parent
* all nodes that do not have children are called leaf nodes

### IDs
* recursive data structure
* consists of distinct root node, subtrees
* root contains link to all subtrees

* every tree has N nodes
* every tree has N-1 edges
* every node except root has at least one incoming edge

* depth of a node x is the length of the path from root to x
* number of edges in path from root to x

* height of node x is the longest path from x to a leaf

* max nodes in binary tree with height h
  * 2^(h+1)-1
  * 2^(no levels) - 1
  * height is the floor(log(base2)(n nodes))
* the tree is balanced if the height of the left and right subtrees is no more than 1
* height of empty tree is -1

### Classifications
* binary tree: each node has at most 2 children
* each node should have two pointers, one to left and one to right child

### Applications
* organizing data for quick search, insertion, deletion
* storing naturally hierarchical data
* trie: dictionary
* network routing algorithms

### Implementations
* dynamically created nodes
* arrays
  * used for heaps
  * 