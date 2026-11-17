*This project has been created as part of the 42 curriculum by masase.*

# push_swap

## Description

`push_swap` sorts a stack of integers using a **limited set of operations** and a second stack, while trying to output the **smallest possible number of moves**. The project is about algorithmic complexity and choosing a sorting strategy adapted to the input size.

There are two stacks, `a` and `b`. At the start, `a` contains the numbers (no duplicates) and `b` is empty. The goal is to have `a` sorted in ascending order, with the smallest number on top.

### Allowed operations

| Op | Effect |
|----|--------|
| `sa` / `sb` / `ss` | Swap the first two elements of a / b / both |
| `pa` / `pb` | Push the top of b onto a / the top of a onto b |
| `ra` / `rb` / `rr` | Rotate a / b / both up (first becomes last) |
| `rra` / `rrb` / `rrr` | Reverse rotate a / b / both (last becomes first) |

## Instructions

### Compilation

```bash
make
```

### Usage

```bash
./push_swap 2 1 3 6 5 8
```

The program prints the list of operations, one per line. On error (non-integer, duplicate, overflow), it prints `Error` on standard error.


## Algorithm


- **2-3 elements**: hard-coded cases
- **5 elements**: push the smallest values to `b`, sort the 3 remaining, push back
- **Larger inputs**: custom algorithm inspired by this article https://medium.com/@ayogun/push-swap-c1f5d2d41e97

Values are first normalized to indexes (0 to n-1) to simplify the sorting.


## Resources

- Articles and videos on sorting algorithms (radix sort, quicksort on stacks)
- https://medium.com/@ayogun/push-swap-c1f5d2d41e97
