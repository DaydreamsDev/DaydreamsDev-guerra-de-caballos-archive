# Variant 00 — Precursor 2007

- **Source:** [`source/ajedrez-caballo-2007.txt`](source/ajedrez-caballo-2007.txt)
- **Mechanism:** one knight and four pawns; two-dimensional board; sentinel values for pawn state.
- **Status:** source only; no build artifacts survive.
- **Role:** a different game by the same author. It is the precursor of the movement and board
  ideas, not the two-knight game.

## Why it is here

It shows the earlier model: one knight hunts four pawns on a two-dimensional board. The later
variants flatten the board to a one-dimensional array and replace the pawns with a competing knight.

## Known issues

The inverted win condition is documented in [`../../05-known-issues.md`](../../05-known-issues.md).
The source is preserved; it is not fixed.
