# Push Swap - Efficient Stack Sorting

Push Swap is a project from the [42 São Paulo](https://www.42sp.org.br/) Common Core curriculum. It involves developing an algorithm to sort a stack of integers using a limited set of operations and two stacks.

**Special thanks to [mcombeau](https://github.com/mcombeau)** for developing an excellent guide that greatly assisted in understanding and solving this project.

![42 São Paulo](https://img.shields.io/badge/42-São_Paulo-black?style=flat-square&logo=42)

## About 42

[42 São Paulo](https://www.42sp.org.br/) is a tuition-free, global coding school emphasizing peer-to-peer learning and project-based education. This project sharpens algorithmic thinking and optimization skills in C.

## Project Overview

Push Swap comprises two programs: `push_swap`, which generates instructions to sort a stack, and an optional `checker`, which validates the sorting. It’s divided into:
- **Mandatory Part**: the `push_swap` program sorts integers using two stacks (A and B) and outputs the shortest sequence of operations.
- **Bonus Part**: the `checker` program reads a list of integers and instructions, verifying if the stack is correctly sorted after execution. This part enhances the project by adding validation functionality, accepting instructions from standard input and confirming the result with "OK" or "KO".

### Key Features

- Sorts a stack using these operations:
  - `sa`: swap the top two elements of stack A.
  - `sb`: swap the top two elements of stack B.
  - `ss`: perform `sa` and `sb` simultaneously.
  - `pa`: push the top element of stack B to stack A.
  - `pb`: push the top element of stack A to stack B.
  - `ra`: rotate stack A upward (top element goes to bottom).
  - `rb`: rotate stack B upward.
  - `rr`: perform `ra` and `rb` simultaneously.
  - `rra`: reverse rotate stack A (bottom element goes to top).
  - `rrb`: reverse rotate stack B.
  - `rrr`: perform `rra` and `rrb` simultaneously.
- Optimizes for minimal instructions (e.g., ≤ 12 moves for 5 numbers, ≤ 700 for 100).
- Handles invalid inputs with an "Error" message.
- Bonus: validates sorting with a separate checker tool that processes custom instruction sequences.

### Restrictions

- Written in C, compliant with the 42 Norm.
- No unexpected crashes (e.g., segmentation faults).
- No memory leaks from heap allocations.
- Compiled with `-Wall -Wextra -Werror`.
- Limited to specified stack operations; no direct array sorting allowed.

## Getting Started

### Prerequisites

- C compiler (e.g., `clang`)
- `make` utility
- `libft` library in the `lib/libft` directory

### How to Build and Run

1. Clone the repository:

   ```bash
   git clone https://github.com/LuizGandra/push-swap-42.git
   cd push-swap-42

2. Build the mandatory part:

   ```bash
   make

3. Run `push_swap` with a list of integers:

   ```bash
   ./push_swap <numbers>

4. Build the bonus part (optional):

   ```bash
   make bonus

5. Run `checker` to validate instructions:

   ```bash
   ./checker <numbers>
   <instruction 1>
   <instruction 2>
   <...>

5. Finish the `checker` program with `CTRL + D` after send all the instructions. The checker outputs `OK` if sorted, `KO` if not.

#### Additional commands

- `make clean`: remove object files.
- `make fclean`: remove `libft.a` and object files.
- `make re`: rebuild everything.

## Project Structure

- `include/push_swap.h`: header for mandatory part.
- `src/*.c`: source files for push_swap (e.g., main.c, sort.c, push.c).
- `bonus/include/checker_bonus.h`: header for bonus part.
- `bonus/src/*.c`: source files for checker (e.g., main_bonus.c, instructions.c).
- `Makefile`: compilation automation.
- `lib/libft/`: directory for the libft library.

## License

This project is part of the 42 curriculum and intended for educational use.
