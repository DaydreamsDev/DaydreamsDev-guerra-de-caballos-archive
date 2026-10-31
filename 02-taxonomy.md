# 02 — Taxonomy

The classification axis is **what the source actually implements**, not what a folder or a later
label claimed. The surviving set is small enough to inspect and name honestly.

## The variants

| Identifier | Name | What it actually is | Why it matters |
|---|---|---|---|
| `variant-00` | Precursor 2007 | One knight and four pawns on a two-dimensional board. Pawns use sentinel values for alive and eaten. | It is a different game by the same author. It seeds the movement and board ideas but is not the two-knight game. |
| `variant-01` | Baseline 2008 | Two knights, global arrays, reference parameters, terse identifiers. No record type and no trail marks. | The plain baseline: state is global and the board is a flat integer array. |
| `variant-02` | Records 2008 | The baseline plus a record for the player name and the `pisadas` trail character. | The first data abstraction: a record exists, but it stores the player name, not the board. |
| `variant-03` | Pointers development 2008 | Arrays of structures and pointers. The board initialization is broken: the pointer is reset to the first element inside every iteration. | The intermediate pointer implementation. It preserves a real defect that the final version fixes. |
| `variant-04` | Pointers final 2008 | Arrays of structures and pointers. The initialization walks all cells correctly. | The completed pointer implementation: the board becomes an array of records accessed through pointers. |
| `variant-05` | Classes | Missing. The raw archive contains an empty folder; no source, project file or documentation was produced. | The historical progression stops before the class rung. The archive preserves the gap. |

## The precursor is not variant 05

`variant-00` is a different game: one knight and four pawns, not two competing knights. It is
included because it is the same author's earlier work and the source of several movement and board
ideas. It is not the missing class rung and it is not a direct code ancestor of the two-knight
variants.

## Class gap and scope

The historical class rung is missing; the modern class version is described in
[`adaptations/README.md`](adaptations/README.md) under `construction-11`
(encapsulation), `construction-12` (polymorphism) and `construction-13`
(composition), and will live in the laboratory at
<https://github.com/DaydreamsDev/guerra-de-caballos-lab>. The same applies to
every other step not present in the originals: modular programming, abstract
data types, object-oriented programming, generic programming and the lenses
were never intended to be worked out in the 2008 files. They are curriculum
extensions, not missing historical artifacts.

## Why the taxonomy matters

A label is not a classification. A folder named for pointers is not evidence that the source uses
pointers; a folder named for classes is not evidence that a class implementation exists. The archive
records the mechanism that is present, the mechanism that is absent, and the exact evidence for
both.
