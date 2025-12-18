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
to pick the most appropriate algorithm. If the disorder score is below 20, it uses the **simple algorithm** which uses less
operations to prepare its computing


A detailed explanation and justification of the algorithms selected for this project
must also be included.

the rationale for your thresholds, the internal techniques used in each regime, and a brief complexity
argument (upper bounds) for time and space within the Push_swap model.

### RESSOURCES

The links down below helped us to get **inspiration** on algorithms design, excepted 
Chatgpt that helped on **debugging**, understanding **time complexity**, markdown **syntax** and to
create **python scripts** for testing. Besides theses links, most of the inspiration on designs actually
comes from discussions with other **42 students**.

[Chatgpt](https://chatgpt.com)  
[Youtube : Bitonic Sort](https://www.youtube.com/watch?v=hC00IfY5tWA)  
[Youtube : 15 Sorting Algorithms in 6 Minutes](https://www.youtube.com/watch?v=kPRA0W1kECg)  
[Wikipedia : Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)  
[Wikipedia : Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)  
[Wikipedia : Cocktail shaker sort](https://en.wikipedia.org/wiki/Cocktail_shaker_sort)  
[Wikipedia : Donald Knuth](https://en.wikipedia.org/wiki/Donald_Knuth)  
[Wikipedia : Time complexity](https://en.wikipedia.org/wiki/Time_complexity)  

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
