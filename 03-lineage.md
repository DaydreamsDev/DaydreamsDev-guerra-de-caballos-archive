# 03 — Lineage

## Sequence

```text
variant-00  precursor 2007       different game
variant-01  baseline 2008        global arrays and references
     |
variant-02  records 2008         record for the player name; trail marks
     |
variant-03  pointers development 2008   arrays of structures and pointers; broken initialization
     |
variant-04  pointers final 2008         arrays of structures and pointers; fixed initialization
     |
variant-05  classes              missing
```

## Evidence

- The 2008 variants share the same twelve-function decomposition (main plus eleven helpers) and the
  same eight-case movement switch. The case order and the Spanish case comments match.
- `variant-02` adds the record for the player name and the `pisadas` trail character to the baseline
  structure.
- `variant-03` and `variant-04` add the arrays of structures and the pointer traversal. They differ
  in the board initialization: `variant-03` resets the pointer to the first element inside every
  loop iteration; `variant-04` walks the cells correctly.
- All four surviving 2008 headers are dated 09/03/08 (March 2008); the pointer pair is later in the
  sequence by structure, not by a documented date.
- `variant-00` is a different program: one knight and four pawns, a two-dimensional board, and a
  different win condition. It is a precursor, not a direct code ancestor.

## Confidence

The progression is inferred from shared function decomposition, shared control flow, shared comments
and the raw archive dates. It is not a byte-level diff claim, because the files were edited across
months and some comments and identifiers changed.

## Missing rung

`variant-05` is a gap, not a surviving variant. No class-based file survives. The
archive does not infer one from `variant-04`. See
[`variant-05-classes-missing/README.md`](original/variant-05-classes-missing/README.md) and
[`adaptations/README.md`](adaptations/README.md).
