# Variant 02 — Records 2008

- **Source:** [`source/guerra-de-caballos-records.cpp`](source/guerra-de-caballos-records.cpp)
- **Mechanism:** the baseline plus a record for the player name and the `pisadas` trail character.
- **Status:** source and historical build artifacts; the archive publishes the source only.
- **Role:** the first data abstraction in the progression.

## What it adds

`struct movimiento { char nombre[250]; }` stores the player name. The first character of that name
becomes the trail mark for visited cells. The board is still a flat integer array; the record does
not represent the board.

## Known issues

The out-of-bounds loop, unbounded name input, repeated seeding, `void main` and pre-standard headers
are documented in [`../../05-known-issues.md`](../../05-known-issues.md). They are preserved, not
fixed.
