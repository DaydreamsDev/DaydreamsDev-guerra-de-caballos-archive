# Knight movement in L (reading aid)

> This reading aid is not part of the original manual. The manual keeps its
> original diagram. This grid only makes the eight reachable cells explicit.

The knight moves two cells in one direction and one cell perpendicular to it.
From cell `C`, the eight reachable cells are:

```text
· 3 · 2 ·
4 · · · 1
· · C · ·
5 · · · 8
· 6 · 7 ·
```

| Move | Row change | Column change | Description |
|---|---|---|---|
| 1 | -1 | +2 | One row up, two columns right |
| 2 | -2 | +1 | Two rows up, one column right |
| 3 | -2 | -1 | Two rows up, one column left |
| 4 | -1 | -2 | One row up, two columns left |
| 5 | +1 | -2 | One row down, two columns left |
| 6 | +2 | -1 | Two rows down, one column left |
| 7 | +2 | +1 | Two rows down, one column right |
| 8 | +1 | +2 | One row down, two columns right |

## One L example

Move 6, two rows down and one column left, looks like this:

```text
· C ·
· · ·
X · ·
```

`C` is the starting cell and `X` is the destination cell. The move does not pass
through the intermediate cells: the knight jumps.
