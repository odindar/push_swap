_This activity has been created as part of the 42 curriculum by iergin, odindar_

---

## Description

**Push_Swap** is a sorting algorithm project that sorts random integers using two stacks (a and b) with predefined operations while minimizing the number of moves.

The project implements four sorting strategies:
- **Simple Algorithm** (O(n²)): For small datasets (disorder < 0.2 )
- **Medium Algorithm** (O(n√n)): For medium datasets (0.2 ≤ disorder ≤ 0.5)
- **Complex Algorithm** (O(n log n)): For large datasets (0.5 > disorder)
- **Adaptive Algorithm**: Automatically selects the best algorithm based on input disorder

---

## Instructions

### Compilation
```bash
make
```

### Usage
```bash
./push_swap [--simple|--medium|--complex|--adaptive] [numbers]
```

**Stack Operations:**
- `sa`, `sb`: Swap first two elements
- `pa`, `pb`: Push element between stacks
- `ra`, `rb`: Rotate stack
- `rra`, `rrb`: Reverse rotate
- `ss`, `rr`, `rrr`: Combined operations

**Examples:**
```bash
./push_swap 3 2 5 1 4
./push_swap --complex 100 5 42
```

---

## Resources

- [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)

### AI Usage
- Algorithm design and complexity analysis
- Stack operations implementation
- Performance optimization
- Code documentation and debugging

---

## Algorithm Selection & Justification

### Simple Algorithm - Selection Sort (O(n²))
Finds and swaps minimum elements. Used for small inputs where simplicity outweighs efficiency.

### Medium Algorithm - K-Sort (O(n√n))
Divides stack into √n chunks and sorts them efficiently. Balanced approach for medium-sized datasets.

### Complex Algorithm - Radix Sort (O(n log n))
Sorts by binary representation bit-by-bit. Optimal for large datasets with predictable O(n log n) performance.

### Adaptive Strategy
Calculates input disorder level and automatically selects the best algorithm. Prevents wasted operations on partially sorted data.

---

## Contributors

**iergin**
- Complex algorithm
- Disorder metric calculation
- Stack operations (swap, push, rotate, reverse rotate)
- Main program structure and algorithm selection logic

**odindar**
- Simple and medium algorithms
- Utilities and performance optimization

Both contributors understand the entire codebase and can explain any part of the implementation.
