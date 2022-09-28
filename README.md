# push_swap


## The Challenge:
The goal of this project was to create a sorting algorithm that takes a list of integers on a stack and sorts them, with a limited set of instructions, in the quickest way possible.

### Available Instructions:

| Instruction | Explanation |
|:-----------:|-------------|
|```sa```|Swap the first 2 elements at the top of stack ```a```.|
|```sb```|Swap the first 2 elements at the top of stack ```b```.|
|```ss```| ```sa``` and ```sb``` at the same time.|
|```pa```| Take the first element at the top of ```b``` and put it at the top of ```a```.|
|```pb```| Take the first element at the top of ```a``` and put it at the top of ```b```.|
|```ra```| Shift up all elements of stack ```a``` by 1, the first element becomes the last one.|
|```rb```| Shift up all elements of stack ```b``` by 1. the first element becomes the last one.|
|```rr``` | ```ra``` and ```rb``` at the same time.|
|```rra```| Shift down all elements of stack ```a``` by 1, the last element becomes the first one.|
|```rrb```| Shift down all elements of stack ```b``` by 1, the last element becomes the first one.|
|```rrr```| ```rra``` and ```rrb``` at the same time.|