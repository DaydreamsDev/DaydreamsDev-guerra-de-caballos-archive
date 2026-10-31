# Guerra de Caballos — Archive

This is the canonical public archive of the 2007–2008 work *Guerra de Caballos* by Juan Camilo
Rivera. It preserves the original implementations as evidence, classified by mechanism and lineage.
It is not the learning laboratory and it is not a modern build.

## What this archive is

- A restored edition of the surviving 2007–2008 source files.
- A classification of the variants by what they actually implement.
- A provenance record: what exists, what is missing, what was changed, and what was excluded.
- The evidence base for the archaeology track of the learning laboratory.

## What this archive is not

- Not the learning laboratory. The laboratory will live in `guerra-de-caballos-lab`.
- Not a modern C++ project. The original code targets Microsoft Visual C++ 6.0 and a pre-standard
  dialect (private-vault evidence; see Build status).
- Not a reconstruction. No missing code is invented here.
- Not a bug-fix branch. The original defects are preserved as evidence.

## Variants

| Identifier | Name | Mechanism | Status |
|---|---|---|---|
| `variant-00` | [Precursor 2007](original/variant-00-precursor-2007/README.md) | One knight and four pawns; two-dimensional board | Source only |
| `variant-01` | [Baseline 2008](original/variant-01-baseline-2008/README.md) | Global arrays and references | Source published; historical build artifacts retained privately |
| `variant-02` | [Records 2008](original/variant-02-records-2008/README.md) | Record for the player name; trail marks | Source published; historical build artifacts retained privately |
| `variant-03` | [Pointers development 2008](original/variant-03-pointers-dev-2008/README.md) | Arrays of structures and pointers; broken initialization | Source published; historical build artifacts retained privately |
| `variant-04` | [Pointers final 2008](original/variant-04-pointers-final-2008/README.md) | Arrays of structures and pointers; fixed initialization | Source published; historical build artifacts retained privately |
| `variant-05` | [Classes](original/variant-05-classes-missing/README.md) | Missing; never produced or archived | Missing |

Each variant has its own `README.md` under `original/`.

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

## Documentation

- [`documentation/es/00-user-manual.md`](documentation/es/00-user-manual.md) — faithful Spanish
  transcription of the user manual.
- [`documentation/en/00-user-manual.md`](documentation/en/00-user-manual.md) — English translation.
- [`documentation/es/01-technical-notes.md`](documentation/es/01-technical-notes.md) — faithful
  Spanish transcription of the technical notes.
- [`documentation/en/01-technical-notes.md`](documentation/en/01-technical-notes.md) — English
  translation.
- [`documentation/es/02-knight-movement.md`](documentation/es/02-knight-movement.md) — Spanish
  reading aid for the L-shaped knight movement.
- [`documentation/en/02-knight-movement.md`](documentation/en/02-knight-movement.md) — English
  reading aid for the L-shaped knight movement.

## Reports

- [`00-provenance.md`](00-provenance.md) — origin, restoration policy, exclusions.
- [`01-inventory.md`](01-inventory.md) — files, lines, bytes, mechanisms, status.
- [`02-taxonomy.md`](02-taxonomy.md) — what each variant is and why.
- [`03-lineage.md`](03-lineage.md) — how the variants relate.
- [`04-build-status.md`](04-build-status.md) — original toolchain and modern status.
- [`05-known-issues.md`](05-known-issues.md) — defects preserved as evidence.
- [`06-restoration.md`](06-restoration.md) — every transformation applied to the originals.

## Build status

The private raw vault contains project and build artifacts from Microsoft Visual C++ 6.0 (1998). The
public archive publishes source only; the toolchain claim is based on the private vault and is not
independently verifiable from this repository. The source does not compile as modern C++ without
compatibility work; the archive preserves that state and does not fix it.

## Language

The original source and its comments are Spanish. The archive documentation is English. The user
manual and technical notes have a Spanish transcription and an English translation. No lesson or
report requires the reader to understand Spanish.

## License and citation

The archive is released under the MIT license. The author is Juan Camilo Rivera. See
[`LICENSE`](LICENSE) and [`CITATION.cff`](CITATION.cff).
