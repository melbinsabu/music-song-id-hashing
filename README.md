# Music Application - Hashing Assignment

## Problem
A music application stores the song IDs:

`105, 210, 315, 420, 525, 630, 735, 840`

The assignment implements hashing using the Division Method, handles collisions
using Linear Probing, searches the IDs using hashing and linear search, and
compares their performance.

## Hashing Details
- Table size: 10
- Hash function: `h(key) = key % 10`
- Collision handling: Linear Probing
- Number of records: 8
- Load factor: `8 / 10 = 0.80`

## Files
- `music_hashing.c` - C source code
- `input.txt` - input data and configuration
- `output.txt` - execution output
- `trace_table.txt` - insertion and search trace tables
- `complexity_analysis.txt` - time/space complexity and load-factor analysis
- `comparison_table.txt` - performance comparison and final conclusion

## Compilation and Execution

```bash
gcc music_hashing.c -o music_hashing
./music_hashing
```

On Windows:

```bash
gcc music_hashing.c -o music_hashing.exe
music_hashing.exe
```

## Important Results

| Metric | Hashing | Linear Search |
|---|---:|---:|
| Total operations/comparisons | 20 | 36 |
| Average | 2.50 | 4.50 |
| Best case | O(1) | O(1) |
| Average case | Expected O(1) | O(n) |
| Worst case | O(n) | O(n) |

## Conclusion
Hashing gives fewer observed search operations for this input. It is suitable
for a music application requiring frequent song-ID lookup. The example also
shows why collision handling, table size, and load factor are important:
these IDs produce repeated collisions under `key % 10`.
