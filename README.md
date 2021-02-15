# fillit

The goal of this two-person project was to fit a set of Tetris pieces into 
the smallest possible square using a recursive backtracking algorithm. We 
started with the smallest square that might fit all the pieces and expanded
the size of the box only when all of the possibilities were exhausted. 

The input file should contain Tetris pieces written with '#' and '.' with an
empty line between each block, as follows:
```bash
....
....
..##
.##.

###.
#...
....
....

....
.##.
.##.
....
```

The "tests" folder contains many examples.

When the program is complete, it will return a filled square with letters
corresponding to the blocks. The first block in the file will be represented
with A's, the second with B's, etc, as follows:

```bash
.AABB.CC
AADDBCC.
.DD.BEE.
.FF.EEGG
FFHH.GG.
.HHIIIJJ
.KK.IJJ.
KK......
```

Build with `make` and run with `./fillit [FILE]`
