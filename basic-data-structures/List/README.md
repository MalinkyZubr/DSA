List: abstract data type
- store number of elements of any type
- read elements by position
- modify element at position

Arrays: contrete data type
- linked list

#### Abstract List
* store given number elements of given data type
* write or modify elements at a position in the list
* read elements at a position

what about dynamic list?
* if empty, size 0
* insert element into the list at any point
* remove any element from list
* count the number of elements
* read and modify elements
* specify datatype for the list

array implementation
* very large array
* store integer for end index of array
* if the array is empty, end is -1
* when array grows, the end value shifts to the last index
* if item is removed, the end shifts back
* what if array is full? how extend array?
* we cant extend array, so we create a new larger array and copy all elements of old array to new array. Then we free memory
  * how much bigger?
  * costly to copy all elements
  * we will double the size every time

complexity cost
* accessing variable: constant time, index access for array
  * O(1)
* insert element at end:
  * O(1)
* insert element in the middle:
  * time proportional to array size (because must shift elements)
  * O(n)
* remove element:
  * O(n)
* insert element at end if array full
  * O(n)

* in this implementation, lots of unused space
* array as dynamic list not efficient

array vs linked list
* accessing variable
  * array: O(1)
  * linked list: O(n)
* memory usage:
  * array: unused memory when array too big
  * linked list: no wasted space, but double memory per node to store addresses

* linked list is better when you have to store manyu complex datastructures
* if the elements consume lots of memory, the linked list is better
* arrays dont work if there arent large blocks of memory available. Linked list can work with memory fragmentation

* insertion
  * at beginning
    * array: O(n), shift all elements forward
    * linked lis: O(1), only edit the head pointer
  * at end
    * array: O(1) if not full
    * linked list: 0(n)
  * at n
    * array: O(n)
    * linked listL O(n)
* delete element
  * same for insertion

* ease of use:
  * array is easier
  * linked list is harder to implement