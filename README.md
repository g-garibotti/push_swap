# Push_swap

![C](https://img.shields.io/badge/language-C-blue.svg)

A highly efficient number sorting program using two stacks and a limited set of operations.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Algorithm](#algorithm)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Operations](#operations)
- [Performance](#performance)
- [Contributing](#contributing)
- [License](#license)

## Overview

Push_swap is a challenging algorithmic project that requires sorting a stack of integers using two stacks (a and b) and a limited set of operations. The goal is to sort the stack with the minimum number of operations possible.

## Features

- Efficient sorting of integers using two stacks
- Implementation of various sorting algorithms depending on the input size
- Robust error handling and input validation
- Optimized for performance with large datasets

## Algorithm

The project implements different sorting strategies based on the number of integers to sort:

- For 2 numbers: Simple swap if necessary
- For 3 numbers: Hardcoded optimal solution
- For 4-5 numbers: Insertion sort variant
- For 6+ numbers: Optimized Radix sort

The Radix sort implementation is particularly efficient for larger datasets, utilizing bitwise operations to minimize the number of moves required.

## Installation

1. Clone the repository:
   ```
   git clone https://github.com/g-garibotti/push_swap.git
   ```
2. Navigate to the project directory:
   ```
   cd push_swap
   ```
3. Compile the project:
   ```
   make
   ```

## Usage

Run the program with a list of integers as arguments:

```
./push_swap 4 67 3 87 23
```

The program will output the series of operations needed to sort the stack.

## Project Structure

- `push_swap.c`: Main program logic and initialization
- `sort.c`: Implementation of sorting algorithms
- `radix_sort.c`: Radix sort algorithm for large datasets
- `validates.c`: Input validation and error handling
- `push.c`, `swap.c`, `rotate.c`, `reverse_rotate.c`: Stack operations
- `check.c`: Additional validation functions

## Operations

The program uses the following operations to sort the stack:

- `sa`: Swap the first two elements of stack a
- `sb`: Swap the first two elements of stack b
- `ss`: Perform sa and sb simultaneously
- `pa`: Push the top element from stack b to stack a
- `pb`: Push the top element from stack a to stack b
- `ra`: Rotate stack a (first element becomes last)
- `rb`: Rotate stack b
- `rr`: Perform ra and rb simultaneously
- `rra`: Reverse rotate stack a (last element becomes first)
- `rrb`: Reverse rotate stack b
- `rrr`: Perform rra and rrb simultaneously

## Performance

The project aims to meet the following performance criteria:

- For 3 numbers: Maximum of 3 operations
- For 5 numbers: Maximum of 12 operations
- For 100 numbers: Maximum of 700 operations
- For 500 numbers: Maximum of 5500 operations

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

