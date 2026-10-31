# Variant 01 — Baseline 2008

- **Source:** [`source/guerra-de-caballos-baseline.cpp`](source/guerra-de-caballos-baseline.cpp)
- **Mechanism:** global arrays and reference parameters. The board is a flat integer array.
- **Status:** source and historical build artifacts; the archive publishes the source only.
- **Role:** the plain baseline of the two-knight game.

## What it contains

No record type, no player name and no trail marks. The state is global: board, move priority, knight
positions, turn, winner flag and current knight. The movement logic is the eight-case switch that
survives in the later variants.

## Known issues

The out-of-bounds loop, repeated seeding, `void main` and pre-standard headers are documented in
[`../../05-known-issues.md`](../../05-known-issues.md). They are preserved, not fixed.
