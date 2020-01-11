# Push_swap
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves.

To start with:
* stack **a** contains a random number of either positive or negative numbers without any duplicates ;
* stack **b** is empty.

The **goal** is to sort numbers into stack **a**.

We have the following operations: swap (`sa, sb, ss`), push (`pa, pb`), rotate (`ra, rb, rr`), reverse rotate(`rra, rrb, rrr`). Read more about operations in `push_swap.en.pdf`

The project consists of two programs:
- **push_swap** : the output of the program is a list of instructions for sorting.
- **checker** : read the instructions and execute them; it sends "OK" to stdin if stack **a** is correctly sorted, otherwise it sends "KO".
```
> ./push_swap [argv ...]
> ./checker [-vcf] [argv ...]
 ```
