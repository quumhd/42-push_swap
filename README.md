This project has been created as part of the 42 curriculumn by jdreissi

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.  
The goal is to sort a stack of integers in ascending order using a **limited set of stack operations** and an **auxiliary stack**, while minimizing the total number of operations.

The program starts with:
- Stack **A** containing a list of unique integers (positive and/or negative)
- Stack **B** empty

Only predefined operations such as swaps, pushes, and rotations are allowed.  
The challenge lies in designing an efficient algorithm that respects these constraints.

This implementation uses a **Radix Sort–based algorithm** on indexed values to achieve an efficient and reliable sorting strategy, especially for large input sizes.

---

## Algorithm Overview (Radix Sort)

Radix sort is a non-comparative sorting algorithm that processes numbers **bit by bit**, starting from the least significant bit (LSB) to the most significant bit (MSB).

### Key ideas used in this project:
1. **Indexing**  
   - All values in stack A are first replaced by their rank in the sorted order (`0` to `n-1`)
   - This removes issues with negative numbers and large ranges

2. **Bitwise sorting**
   - For each bit position:
     - If the current bit of the top element is `0`, it is pushed to stack B
     - If the bit is `1`, stack A is rotated
   - After processing all elements for a bit, stack B is pushed back to stack A

3. **Complexity**
   - Time complexity: **O(n log n)**
   - Operation count is efficient enough to meet project constraints for large inputs (e.g. 100–500 numbers)

Radix sort is particularly well-suited for `push_swap` because it relies only on simple operations and predictable iteration counts.

---

## Instructions

### Compilation

To compile the program, run:

```bash
make
```

### Execution

To execute the program, run:

```bash
./push_swap arguments || ./push_swap "arguments"
```

### Verification

To verify the results of the program, run:

```bash
ARG="arguments"; ./push_swap $ARG | ./checker_linux $ARG
```

## Ressouces

### Algorithm & Data Structures

- Radix Sort (Wikipedia): https://en.wikipedia.org/wiki/Radix_sort

- Bitwise operations in C: https://en.cppreference.com/w/c/language/operators

- Stack-based sorting strategies (push_swap discussions)

### Use of AI

- AI tools were used during this project for:

   - Conceptual explanations of radix sort and bitwise operations

   - Debugging logic errors and understanding operation counts

   - Clarifying algorithmic trade-offs and optimizations

- All algorithmic decisions, implementation, and final code were written and validated by the project author.
