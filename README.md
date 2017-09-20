# Tetris
Tetris is a recursive backtracking algorithm that fits a set of Tetriminos in the smallest possible square without rotating the Tetriminos. The purpose is to make the smallest possible "square" (which can contain holes) with a given list of tetriminos, but the disposition must be as such that it returns the first possible solution when placing them recursively from the top left. More information see examples.

# Example
Here is an example of valid map of Tetriminos (maximum of 26 blocks) which the code fits in the solution below:

```
....
.##.
.##.
....

...#
...#
...#
...#

....
..##
.##.
....

....
..#.
.##.
.#..

.###
...#
....
....

##..
.#..
.#..
....

....
..##
.##.
....

.#..
.##.
..#.
....

....
###.
.#..
....
```

Solution (each individual tetriminos renamed starting from A):
```
AAB.CCD
AABCCDD
FFB..D.
.FBEEE.
HF.GGE.
HHGGIII
.H...I.
```
# Installation

    git clone https://github.com/yilinmiao/Tetris.git
Run `make`, an executable called `fillit` should compile directly. Please submit
an issue if you run into any.
