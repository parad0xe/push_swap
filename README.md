_This project has been created as part of the 42 curriculum by nlallema and ldecavel_

### DESCRIPTION

**Push_swap** is a project which goal is to build three sorting algorithms built only using **push_swap 
specific** operations : `sa sb ss pa pb ra rb rr rra rrb rrr` that interracts with **two given stacks** _a_ and _b_.
The main challenge is that the algorithms must strictly **follow the following complexities** : _O(n²)_, _O(n√n)_ and _O(n log n)_.
To verify its sorting algorithms, the Push_swap project also includes a **program called _checker_** alongside the **_push_swap_ program**.

### BUILD

To build the **_push_swap_** program :
```bash
make
```
To build the **_checker_** program :
```bash
make bonus
``` 
To delete the **build** directory :
```bash
make clean
```
To delete both the **_push_swap_** and **_checker_** programs as well as the **build** directory :
```bash
make fclean
```

### USAGE

The **_push_swap_** program takes strings of **integers** as an argument, sorts it using push_swap operations and 
print them to the standard output. It prints `Error` on the standard error output if it encounters any error.
To use it, run the following command :
```bash
./push_swap [{--simple,--medium,--complex}] [--bench] <numbers...>
#example: ./push_swap --simple 42 1 2 3
```

The **_checker_** program takes string of **integers** as an argument, then reads the standard input for any
push_swap operations to execute, and checks if the list is sorted. It prints `Error` on the standard error output
if it encounters any error. To use it, run the following command :
To use the checker, run the following command :
```bash
./checker <numbers...>
#example: ./checker 42 1 2 3
```

### ALGORITHMS

When the **_push_swap_** program is called without any flags or with the _adaptive_ flag, it uses the computed **disorder score**
to pick the most appropriate algorithm. The disorder score is a float between 0.00 and 1.00 that measures how “out of order” the input is.
It is computed by counting how many ordering mistakes the stack contains: each time a larger value appears before a smaller value
(even if they are far apart), it counts as a mistake. The final score is the proportion of these mistakes among all possible pairs of values.
A score of 0.00 means the input is already sorted, while a score close to 1.00 means the input is close to the worst possible order.
You can think of it like bubble sort: the more “inversions” there are, the more swaps would be needed to fix the order,
and therefore the higher the disorder score.

#### Simple
If the disorder score is below 0.20, the program uses the **simple algorithm** in order to minimize the number of operations on almost-sorted inputs.
Although its worst-case complexity is O(n²), this case cannot be reached when the disorder score is below 0.20, since only a limited number of local 
ordering errors need to be fixed. On such inputs, this strategy is significantly less expensive than global approaches such as radix sort.  

The algorithm is a **hybrid** one designed specifically for the Push_swap model. It combines a Turk-style targeting strategy (selecting the insertion 
position in stack A that minimizes the total number of rotations when pushing a value from B), a selection-like behavior for choosing which element to
fix next, and a lightweight chunk-based phase. During this phase, elements are initially pushed from A to B using two index-based chunks, which helps
reduce unnecessary rotations and keeps misplaced values grouped together.  

This algorithm's complexity is **O(n²)** in push_swap operations, because in the worst case it may require to do up to n rotations on each element
to push then back from b to a. Thus, the total number of operations in the worst case is n x n rotations. Space complexity is **O(n)**, which corresponds
to the memory required to store the stacks and the associated indexes.

#### Medium

##### Description

If the disorder score is between 0.20 (included) and 0.50 (excluded), the program uses the medium algorithm in order to minimize the number of operations on moderately sorted inputs. It works well on uniformly distributed inputs because the sort is divided into buckets by range, which results in a pre-sorted input regardless of the initial value positions.

The algorithm works on the **bucket sort** system model. The numbers are dispatched into multiple __buckets__ defined by the square root of the number of elements. Each bucket has a range of values it can contain, and the numbers are pushed into buckets in ascending range order. When all numbers are added to their respective buckets, a search for the maximum value is performed in descending order of buckets (high range -> low range), resulting in a sorted input.

##### Theorical concept and complexity

###### Define variables

```txt
n = number of elements
w = number of buckets
k = bucket size
ɑ = bucket size scaling factor

ɑ = 1 ∕ √0.3
k = √n · ɑ
w = n ∕ k = n ∕ √n
```

The bucket size is scaled (by **ɑ**) to optimize its size depending on the expected disorder in stack B. If the disorder in stack B increases, the bucket size decreases, resulting in more buckets to compensate for this disorder, and vice versa.

The square root of the disorder value is used for better scaling control because the scaling of the bucket size is not proportional to the expected disorder in stack B. The variation in bucket size must be smooth and not excessive, even with small or large values of disorder.

###### Phase 1 - dispersion [stack A -> stack B]

In this phase, we will create all the buckets one by one, from lowest to highest.

in the worst case the complexity is represented by:

```txt
        n       n²
w · n = ― · n = ― = O(n²)
        k       k
```

###### Phase 2 - selection sort [stack B -> stack A]

In this final phase, we will sort all the values in ascending order, progressively placing the maximum value into the stack A at each step. The current top bucket will necessarily contain the highest value from the inputs.

in the worst case the complexity is represented by:

```txt
         n
w · k² = ― · k² = n · k = O(n · √n)
         k
```

> k² is the complexity of trivial sort algorithm used for sort the bucket

###### Total operations cost

```txt
phase 1 + phase 2 = O(n²) + O(n · √n) = O(n²)
```

The class complexity of this implementation is **O(n²)** due to the push and rotations operations used for create all the buckets, but in standard implementation based on array and hashmap data structure, the resulting class complexity is:

`O(n) + O(n · √n) = O(n · √n)`

###### Total space cost

Space complexity is **O(n)**, which corresponds to the memory required to store the stacks and the associated indexes.


#### Complex
If the disorder score is above or equal to 0.50, the program uses the **complex algorithm** in order to minimize the number of operations on highly
unsorted inputs. On these inputs, local strategies like the simple and medium algorithms require too many operations, whereas a global reordering
strategy is more efficient.  

The algorithm is a classic **radix sort** adapted to the push_swap model. Like the two previous algorithms, it uses precomputed indexes to operate,
comparing them against a single bit that is shifted at each iteration. The objective is to group together values sharing the same bit value at
each step, gradually building the sorted order.  

This algorithm's complexity is **O(n log n)** in push_swap operations, as it performs a linear number of operations per iteration,
with a logarithmic number of iterations. The logarithmic factor comes from the number of bits required to represent the indexed values.
Since the indexes range from 0 to n − 1, their binary representation has at most log2(n) bits. The algorithm processes one bit per pass,
which results in a logarithmic number of iterations. Space complexity is **O(n)**, which corresponds to the memory required to store the
stacks and the associated indexes.

### RESSOURCES

The links down below helped us to get **inspiration** on algorithms design, excepted 
Chatgpt that helped on **debugging**, understanding **time complexity**, markdown **syntax** and to
create **python scripts** for testing. Besides theses links, most of the inspiration on algorithm 
designs actually comes from discussions with other **42 students**.

[Chatgpt](https://chatgpt.com)  
[Youtube : Bitonic Sort](https://www.youtube.com/watch?v=hC00IfY5tWA)  
[Youtube : 15 Sorting Algorithms in 6 Minutes](https://www.youtube.com/watch?v=kPRA0W1kECg)  
[Wikipedia : Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)  
[Wikipedia : Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)  
[Wikipedia : Cocktail shaker sort](https://en.wikipedia.org/wiki/Cocktail_shaker_sort)  
[Wikipedia : Donald Knuth](https://en.wikipedia.org/wiki/Donald_Knuth)  
[Wikipedia : Time complexity](https://en.wikipedia.org/wiki/Time_complexity)  
[Wikipedia : Radix sort](https://en.wikipedia.org/wiki/Radix_sort)  
[Medium : Least amount of moves with two stacks](https://medium.com/%40jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

### CONTRIBUTIONS

[nlallema](https://github.com/parad0xe) :  
  * Utils  
  * Operations  
  * Linked list  
  * Bench  
  * Medium algorithm  
  * Complex algorithm
  * README
  * Push_swap  
  
[ldecavel](https://github.com/leonardecavele) :  
  * Utils  
  * Parsing  
  * Makefile  
  * Checker  
  * Simple algorithm  
  * Complex algorithm
  * README
  * Push_swap  
