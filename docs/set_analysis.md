# Set Analysis Laboratory

## Core goal
Students must implement a set abstraction over integer values and reason carefully about correctness and complexity.

## Required operations
Students should implement and analyze:

- `insert(value)`
- `contains(value)`
- `erase(value)`
- `clear()`
- `size()`
- `empty()`
- `toVector()`
- `equals(other)`
- `isSubsetOf(other)`
- `unionWith(other)`
- `intersectionWith(other)`
- `difference(other)`

## Analysis expectations
Students should explain:

- average and worst-case complexity of insert, contains, erase, and union operations;
Insert: O(n), scans for duplicate before appending
Contains: O(n), full scan of vector
Erase: O(n), search for value and shift other elements
Union: O(n+m(n+m)), copies current set, inserts values from other set
- why duplicate prevention matters for set semantics;
A set makes sure each value appears at most once. Insert checks that once the element is appended, there are no duplicate elements. If this check does not occur, operations such as size would give results that do not follow set rules.
- the difference between a set and a multiset;
A set makes sure the frequency of each element is at most 1, whereas multiset allows for duplicate elements.
- the cost of sorting a set’s contents when returning a vector;
Since the elements are unsorted, the copy must be sorted before returning, which will take O(n log n) time and O(n) extra space.
- the trade-offs between array-backed and tree-backed sets;
Array-backed set stores values continuously, which makes iteration fast and memory-efficient. But, search, insertion, and deletion take linear time. A balanced-tree set supports O(log n) time search, insertion, and deletion, but has more memory overhead to keep values ordered.
- how hashing or balancing affects performance in practical implementations.
A hashed set can have constant insert, search, and deletion in the average case, but if values collide, it can take up to O(n) time. Balancing helps make the time complexity O(log n) in the average and worst case by keeping values in order.

## Big-O focus
Students should discuss:

- insertion cost: O(n), scans duplicates before appending
- membership testing cost: O(n), traversal through set
- deletion cost: O(n), traversal + shift affected values
- set equality and subset testing: O(1) if sizes are different, O(nm) in the worst case since it requires traversing both sets and comparing values, O(n^2) if sets are same size
- union and intersection costs for two sets of size $n$ and $m$: Union is O(n+m(n+m)) in the worst case, copies first set, inserts other set m values, checks for duplicates. Intersection is O(nm+n^2) worst case, since it checks each value against the other set and checks for duplicates to add matches to the result.
- total cost of converting a set to a sorted vector: O(n log n) time and O(n) space, since it needs to copy elements and then sort them.

## Short writing prompt
In a brief paragraph, explain when a set is preferable to a vector or list, and describe how a hash-based set differs from a balanced-tree set in both performance and guarantees.
It is better to use a set over a vector or list when only unique values should be stored, and there are frequent checks of if a value is present. Using hashing, sets can have constant time for insertion, search, and deletion in the average case. However, if many values collide, it can result in O(n) in the worst case. Using a balanced tree implementation can give guaranteed logarithmic time for the operations above.