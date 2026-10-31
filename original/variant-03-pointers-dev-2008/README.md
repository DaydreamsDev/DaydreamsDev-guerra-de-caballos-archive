# Variant 03 — Pointers development 2008

- **Source:**
  [`source/guerra-de-caballos-pointers-dev.cpp`](source/guerra-de-caballos-pointers-dev.cpp)
- **Mechanism:** arrays of structures and pointer traversal. The board and the move priority become
  arrays of records.
- **Status:** source and historical build artifacts; the archive publishes the source only.
- **Role:** the intermediate pointer implementation.

## What it adds

The board becomes an array of `struct tab` values; the move priority becomes an array of `struct
movimiento` values; the code walks them through pointers.

## Known issue

The board initialization is broken. The pointer is reset to the first element inside every loop
iteration, so only the first cell is cleared. The evidence is at lines 84–86 in
[`source/guerra-de-caballos-pointers-dev.cpp`](source/guerra-de-caballos-pointers-dev.cpp) and in
[`../../05-known-issues.md`](../../05-known-issues.md).

This is the development version; `variant-04` fixes the initialization.
