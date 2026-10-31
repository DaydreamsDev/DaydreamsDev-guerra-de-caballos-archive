# Variant 04 — Pointers final 2008

- **Source:**
  [`source/guerra-de-caballos-pointers-final.cpp`](source/guerra-de-caballos-pointers-final.cpp)
- **Mechanism:** arrays of structures and pointer traversal. The board and the move priority are
  arrays of records.
- **Status:** source and historical build artifacts; the archive publishes the source only.
- **Role:** the completed pointer implementation.

## What it adds

The pointer traversal is the same approach as `variant-03`, but the board initialization walks every
cell correctly. This is the last surviving historical variant.

## Known issues

The out-of-bounds loop, unbounded name input, repeated seeding, `void main` and pre-standard headers
are documented in [`../../05-known-issues.md`](../../05-known-issues.md). They are preserved, not
fixed.
