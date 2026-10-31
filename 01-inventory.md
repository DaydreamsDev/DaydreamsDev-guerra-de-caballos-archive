# 01 — Inventory

All paths are relative to the repository root. Line and byte counts describe the restored public
files, not the private raw files.

## Source variants

| Variant | Path | Lines | Bytes | Mechanism | Status |
|---|---|---|---|---|---|
| `variant-00` | `original/variant-00-precursor-2007/source/ajedrez-caballo-2007.txt` | 397 | 9,402 | One knight and four pawns; two-dimensional board | Source only |
| `variant-01` | `original/variant-01-baseline-2008/source/guerra-de-caballos-baseline.cpp` | 930 | 26,502 | Global arrays and references | Source published; historical build artifacts retained privately |
| `variant-02` | `original/variant-02-records-2008/source/guerra-de-caballos-records.cpp` | 1,021 | 26,392 | Record for the player name; trail marks | Source published; historical build artifacts retained privately |
| `variant-03` | `original/variant-03-pointers-dev-2008/source/guerra-de-caballos-pointers-dev.cpp` | 1,058 | 28,644 | Arrays of structures and pointers; broken initialization | Source published; historical build artifacts retained privately |
| `variant-04` | `original/variant-04-pointers-final-2008/source/guerra-de-caballos-pointers-final.cpp` | 1,079 | 30,174 | Arrays of structures and pointers; fixed initialization | Source published; historical build artifacts retained privately |
| `variant-05` | `original/variant-05-classes-missing/README.md` | — | — | Classes | Missing |

## Documentation

| Document | Spanish transcription | English translation | Lines (Spanish / English) |
|---|---|---|---|
| User manual | `documentation/es/00-user-manual.md` | `documentation/en/00-user-manual.md` | 63 / 81 |
| Technical notes | `documentation/es/01-technical-notes.md` | `documentation/en/01-technical-notes.md` | 1,013 / 924 |

## Reading aids

| Reading aid | Spanish | English | Lines (Spanish / English) |
|---|---|---|---|
| Knight movement in L | `documentation/es/02-knight-movement.md` | `documentation/en/02-knight-movement.md` | 40 / 39 |

## Excluded from the public archive

- Compiled binaries: executables, object files, debug symbols, precompiled headers, browse databases
  and linker state.
- Integrated development environment metadata: project and workspace state, per-user options and
  build logs.
- Private material retained in the raw vault.
- Material outside the archive scope.
- The private raw vault itself.

## Checksums

See [`checksums.txt`](checksums.txt).
