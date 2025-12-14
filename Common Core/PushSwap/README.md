This project has been created as part of the 42 curriculum by yamosca-.

Push_swap

Description

Push_swap is an algorithmic project that challenges you to sort a stack of integers using a second empty stack and a specific set of instructions (push, swap, rotate, reverse rotate).

The primary goal is to sort the data with the lowest possible number of operations. This project focuses on:

Algorithmic complexity (aiming for optimized performance).

Rigorous stack manipulation.

Low-level C programming and memory management.

My implementation uses a Chunk Sort strategy combined with a greedy algorithm for the return phase, optimized to handle 100 and 500 random numbers efficiently.

Instructions

Compilation

Clone the repository and compile the executable using the Makefile:

make


Execution

Run the program by passing a list of integers as arguments. The program will output the operations required to sort the stack.

./push_swap 2 1 3 6 5 8


Example Output:

sa
pb
pbhis project has been created as part of the 42 curriculum by yamosca-.
Push_s
pb
sa
pa
pa
pa


Error Handling

The program handles various error cases (non-integer arguments, values greater than INT_MAX, duplicates). In case of an error, it outputs:

Error


Resources

References

Sorting Algorithms: Research on complexity and sorting strategies (Quick Sort, Bucket Sort).

Data Structures: Stack implementation principles (LIFO).

42 Norm: Adherence to the strict coding standard of the school.

AI Usage

As required by the project guidelines, Artificial Intelligence was used during the development process for specific tasks:

Debugging: Identifying memory leaks in the parsing logic (specifically within get_long_tab and last_verif functions) and resolving segmentation faults related to linked list traversal.

Code Refactoring: Assisting in reducing function length to comply with the 25-line limit of the 42 Norm (e.g., refactoring search_min_max using helper functions).

Concept Clarification: Explaining technical behaviors such as long vs int overflow handling and standard input/output management for checkers.

Logic Verification: Comparing the logic of rb vs rrb optimization during the push-back phase to ensure the shortest path was chosen.

Note: All code and logic were reviewed, tested, and understood manually.