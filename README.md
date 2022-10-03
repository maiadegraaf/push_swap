# push_swap

- [The Challenge](#the-challenge)
	- [Available Instructions](#available-instructions)
	- [Expected Input and Output](#expected-input-and-output)
	- [Error Handling](#error-handling)
- [Implementation](#implementation)
	- [Creating the Stack](#creating-the-stack)
	- [Sorting the Stack](#sorting-the-stack)
		- [Small Stack](#small-stack)
		- [Big Stack](#big-stack)
- [Demonstration](#demonstration)
	- [Output](#output)
- [Speed](#speed)
- [Installation](#installation)
	- [Some commands to try:](#some-commands-to-try)

## The Challenge
The goal of this project was to create a sorting algorithm that takes a list of integers on a stack and sorts them, with a limited set of instructions, in the quickest way possible.  We are given two stacks, ```a``` and ```b```.  Stack ```a``` is initialized with an x amount of unsorted integers (provided as argument when the program is run), and stack ```b``` is empty.  Using the instructions below, and using only the two stacks the program should return stack ```a``` sorted with the smallest on top and the largest on the bottom, and stack ```b``` should be empty.

### Available Instructions

| Instruction | Explanation                                                                            |
| :---------: | -------------------------------------------------------------------------------------- |
|  ```sa```   | Swap the first 2 elements at the top of stack ```a```.                                 |
|  ```sb```   | Swap the first 2 elements at the top of stack ```b```.                                 |
|  ```ss```   | ```sa``` and ```sb``` at the same time.                                                |
|  ```pa```   | Take the first element at the top of ```b``` and put it at the top of ```a```.         |
|  ```pb```   | Take the first element at the top of ```a``` and put it at the top of ```b```.         |
|  ```ra```   | Shift up all elements of stack ```a``` by 1, the first element becomes the last one.   |
|  ```rb```   | Shift up all elements of stack ```b``` by 1. the first element becomes the last one.   |
|  ```rr```   | ```ra``` and ```rb``` at the same time.                                                |
|  ```rra```  | Shift down all elements of stack ```a``` by 1, the last element becomes the first one. |
|  ```rrb```  | Shift down all elements of stack ```b``` by 1, the last element becomes the first one. |
|  ```rrr```  | ```rra``` and ```rrb``` at the same time.                                              |

### Expected Input and Output
The program takes both several integers as argument or a list of integers separated by space and within double quotes.  If the program is run without arguments, it simply does nothing.  Otherwise it prints the list of instructions that the program used to sort the stack.

```sh
$>./push_swap 2 1 3 6 5
ra
pb
ra
ra
ra
pb
sa
ra
pa
pa
$>./push_swap 2 1      
sa
$>./push_swap 2
$>./push_swap
$>./push_swap "4 67 3 87 23" | wc -l
       9
```


### Error Handling

Incase of an error, the program will display: 
```Error\n```<br>
These can include:
- Some items are not integers. Characters as well as numbers out of scope are not accepted.
- Duplicates.

```sh
$>./push_swap 2 1 2 3
Error
$>./push_swap 2 1 a 3
Error
$>./push_swap -2147483647 3 2 2.1
Error
$>
```

## Implementation
### Creating the Stack
The first thing I considered was how I was going to represent the stacks in my code.  Of the two obvious options, arrays and linked lists, I chose the later.  My only previous experience with linked lists was making the helper functions for the [libft](https://github.com/maiadegraaf/libft) project, so essentially next to nothing.  It really felt like a good way to learn how to use them properly.  Arrays also seemed like a real headache to work with in this project, as the stacks constantly would have to be reallocated with each ```pa``` or ```pb```, or worse, allocate a huge amount of space which would be a really ugly solution. By the end of this project I had really discovered a love for linked lists, and now rarely use arrays unless I really have to!

The first thing the program does is take the arguments and parse them into a linked list format, at this stage the program also checks for errors. 

### Sorting the Stack
#### Small Stack
One of the requirements of the subject was to sort three numbers with three or less instructions, and five numbers with twelve or less instructions.  The easiest way to do this was to essentially hard code all stacks that have five or less numbers. As three numbers can only be ordered in five different ways, by comparing each number, you can easily determine which action(s) should be used, as demonstrated in the following graphic.

![small stack sort 001](https://user-images.githubusercontent.com/68693691/192802602-91ee87a7-ae57-4f5c-986d-4dd57ebf511e.png)

For five numbers I simply move the smallest two numbers to the other stack while the remaining three numbers are sorted, using the above logic.

Thanks to [this article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) for the clear explanation.

#### Big Stack
Larger stacks however, cannot be hardcoded.  While there are several different ways to implement an effective sorting algorithm, I decided to use a radix sort, inspired by [this article](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e).  Not only was this quite an elegant simple solution, it also allowed me to learn about binary and bitwise operations! 

Radix essentially breaks the sorting up into several steps. At each step it sorts the numbers based upon their position in the first, tenth, hundredth, etc. place. 
<p align="center">
  <a href="https://github.com/maiadegraaf">
    <picture>
    <img alt="Radix Sort" src="https://user-images.githubusercontent.com/68693691/192822529-27b03f76-5b16-4fa4-bcc0-d7a1e4f0e2e0.png" width=350>
    </picture>
  </a>
</p>

Since we only have access to two stacks in push_swap, the most efficient way to handle radix is through binary, and sort by `1`'s and `0`'s.  As this method only works with positive integers, before sorting the stack, the program checks what the final order should be, using a far simpler sorting algorithm, so each item on the stack gets assigned a number between ```0``` and ```n - 1``` where ```n``` is the size of the stack.

## Demonstration

*Original*:
```
2
-1
-33
6
7
1
0
------		------
a		b
```

*Stack Represented by the Final Order*:
```
4
1
0
5
6
3
2
------		------
a		b
```
*Binary*:
```
100
001
000
101
110
011
010
------		------
a		b
```
*Push All Nodes that have a `0` in the 0th bit to stack `b`*

```
pb
ra
pb
ra
pb
ra
pb
```
```
001		010
101		110
011		000
		100
------		------
a		b
```

*Push all elements back to stack `a`*
```
pa
pa
pa
pa
```

```
100
000
110
010
001		
101		
011		
------		------
a		b
```

*Push All Nodes that have a `0` in the 1st bit to stack `b`*
```
pb
pb
ra
ra
pb
pb
ra
```
```
110		101
010		001
011		000
		100
------		------
a		b
```

*Push all elements back to stack `a`*
```
pa
pa
pa
pa
```
```
100
000
001
101
110
010
011	
------		------
a		b
```

*Push All Nodes that have a `0` in the 2nd bit to stack `b`*
```
ra
pb
pb
ra
ra
pb
pb
```
```
100		011
101		010
110		001
		000
------		------
a		b
```

*Push all elements back to stack `a`*
```
pa
pa
pa
pa
```
```
000
001
010
011
100
101
110	
------		------
a		b
```

*The Sorted Stack*
```
0
1
2
3
4
5
6	
------		------
a		b
```

### Output
```sh
$>./push_swap 2 -1 -33 6 7 1 0       
pb
ra
pb
ra
pb
ra
pb
pa
pa
pa
pa
pb
pb
ra
ra
pb
pb
ra
pa
pa
pa
pa
ra
pb
pb
ra
ra
pb
pb
pa
pa
pa
pa
```

## Speed

Although radix is a simple and quick sorting algorithm it isn't the fastest comparatively.  In retrospect I think the ultimate solution would have been to create a program that tries multiple algorithms and then outputs the fastest set of instructions.

| Stack Size | Average Instructions |
| :--------: | :------------------: |
|     3      |          1           |
|     5      |          8           |
|     10     |          65          |
|    100     |         1084         |
|    500     |         6784         |

One of the (what I think) fun parts of radix is that it will always use the same amount of instructions to sort a stack of `n` size.  So for example it will always use 1084 instructions for a stack that had 100 numbers. Of course this is quite logical as the inputted numbers are sorted based on their translated order (ie. the order they end up in). So stack `a` and stack `b` are always going to be the same size at each stage, and will therefore have the same amount of instructions.

## Installation
### Clone the repository:
``` 
git clone https://github.com/maiadegraaf/push_swap.git
cd push_swap
make
```

### Some commands to try:
**10 random numbers:**
```sh
ARG=$(seq 10 | sort -R | tr '\n' ' ') && ./push_swap $ARG
```
**100 random numbers:**
```sh
ARG=$(seq 100 | sort -R | tr '\n' ' ') && ./push_swap $ARG
```
**Number of instructions with 100 random numbers:**
```sh
ARG=$(seq 100 | sort -R | tr '\n' ' ') && ./push_swap $ARG | wc -l
```
**500 random numbers:**
```sh
ARG=$(seq 500 | sort -R | tr '\n' ' ') && ./push_swap $ARG
```
**Number of instructions with 500 random numbers:**
```sh
ARG=$(seq 500 | sort -R | tr '\n' ' ') && ./push_swap $ARG | wc -l
```

If you would like to check that my program actually does what it's supposed to I really recommend [this tester](https://github.com/louisabricot/push_swap_tester).
