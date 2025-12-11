*This project has been created as part of the 42 curriculum by yamosca-.*

# Push Swap

## Description

**Push Swap** is a sorting algorithm project at 42 School. The goal is to sort a stack of integers (Stack A) using a second empty stack (Stack B) and a limited set of instructions, with the lowest possible number of operations.

The project involves complex algorithm optimization, stack manipulation, and rigorous memory management in C.

### The Rules
- You have two stacks named **A** and **B**.
- At the beginning, **A** contains a random amount of negative and/or positive numbers which cannot be duplicated. **B** is empty.
- The goal is to sort numbers in ascending order into stack **A**.
- The available operations are:
  - `sa`, `sb`, `ss`: Swap the first 2 elements of a stack.
  - `pa`, `pb`: Push the top element of one stack to the other.
  - `ra`, `rb`, `rr`: Rotate up (first element becomes last).
  - `rra`, `rrb`, `rrr`: Reverse rotate (last element becomes first).

## Instructions

### Compilation
The project uses a `Makefile` to compile the source files.

```bash
# Clone the repository
git clone <repository_url>
cd push_swap

# Compile the executable
make