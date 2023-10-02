## Algorithmic Complexity
* time <
* space <
* communication
* processor
* circuit

### Algorithm Language
#### Decision problem
* this sort of algorithm takes one input, and returns either true or false, deciding if a condition is met

#### function problem
* represents problem with exactly one output for all inputs given. 
* Not necessarily a discrete value like the decision

### Time complexity
* explores how algorithms respond to an increase in input size in bits
* we want a function that tells us how the execution time of a function with 2n bits differs from one that takes n bits. this is T(n)
* since there is variability over how much time something will take, we measure worst case time: maximum amount of time it will take for all inputs x
* if T(n) is a polynomial, the function's time complexity is said to be polynomial
  * polynomial time problems can always be solved with relative ease

### Turing Machines?
* turing machines are used to calculate different complexities of algorithms
* mostly deterministic for realistic purposes
  * deterministic means they abide by a specific set of rules in operations
* probabalistic machines employ randomness in their algorithms, for stuff like cryptography maybe?
* non-deterministic machines have little bearing on real life but are useful for representing abstract issues
  * the ND turing machine branches out in several methods for solving problems. When one branch solves the problem, the problem is solved

### Time Complexity on Turing Machine
* take a problem P
* the time complexity to solve problem P is the numher of steps taken by the turing machine to solve the problem
  * num steps before the result is returned
* the turing machine operates on f(n) if each step takes f(n) time 
* problems solvable in f(n) time on DTMs are said to use DTIME

### Big O notation
* mathematical means of expressing complexity
* characterizes function with growth rate, based on the order of the function (exponent of the leading term)
* when calculating O(f(x)) (big O of f(x)), we employ 2 rules
  * the term with the largest growth rate (exponent) is the only one that matters, get rid of the others
  * if the function is multiplied by a constant, the constant is irrelevant and can be removed
  * this is because big O examines functions as they approach infinity where these extra things are irrelevant
* basically, in algorithm analysis, O(f(n)) takes whatever the exact equation for time complexity is and simplifies it. 
* a polynomial time complexity with a leading term of 4x^4 would just be expressed in big O as O(x^4)
* get rid of constants and lower order terms

### Best, worst, average complexity
* different ways of measuring complexity
* best case: time complexity for solving problem with best input size N
* average: measures the time complexity of several randomized inputs, if same size inputs are equally likely to appear. Measured over all inputs N, ideally
* Amortized: consider costly and non-costly operations
* worst case: worst time complexity, worst input size analysis. Most often used
* for instance: inputs in certain formats or orderings might take N^2 time, some might only take nlogn

### Calculating time complexity
* algorithms are either iterative or recursive
* to find upper bound of an iterative algorithm:
  * estimate maximum number of times each loop executes
  * add these maximums together if the loops are not nested
  * multiply them if the loops are nested
* recursive algorithms
  * back substitution
  * algorithm tree
  * continue here later

https://www.bigocheatsheet.com/ for all main algorithms