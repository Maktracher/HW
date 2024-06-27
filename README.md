
---

# Set Operations in C

This project demonstrates efficient implementations of basic set operations in C. It includes optimized functions for intersection, union, and other set-related functionalities using dynamic memory management.

## Features

- **Dynamic Arrays:** Efficient resizing and memory management.
- **Set Operations:** Functions to compute the intersection and union of two sets in linear time.
- **Sum Operations:** Functions to compute element-wise and total sum of sets.
- **Random Set Generation:** Populate sets with random integers for testing.

## Getting Started

### Prerequisites

Ensure you have a C compiler installed. For example, GCC:

```bash
sudo apt-get install gcc
```

### Compilation

Clone the repository and compile the source code:

```bash
git clone https://github.com/yourusername/set-operations-in-c.git
cd set-operations-in-c
gcc -o set_operations main.c
```

### Running the Program

Execute the compiled binary:

```bash
./set_operations
```

This will run the main program that:
- Generates two random sets of integers.
- Computes their intersection and union.
- Displays the results.

### Example Output

```
Set 1: 12 45 78 23 56 89 12 34 56 78 
Set 2: 34 67 23 89 12 56 90 34 78 45 

Intersection: 12 45 78 23 56 89 34 
Union: 12 45 78 23 56 89 34 67 90 
Sum of both sets: 770
Sum of elements-wise: 46 112 101 112 112 178 102 68 134 123
```

## Source Code

### `main.c`

The main file where the set operations are implemented and tested.

### Functions

- **Dynamic Array Management:**
  - `initMnoz`: Initialize a dynamic array.
  - `freeMnoz`: Free the dynamic array memory.
  - `add`: Add an element to the dynamic array.

- **Set Operations:**
  - `intersection`: Compute the intersection of two sets.
  - `unionMnoz`: Compute the union of two sets.

- **Sum Operations:**
  - `suma`: Compute the total sum of all elements in both sets.
  - `sumElements`: Compute the element-wise sum of two sets.




