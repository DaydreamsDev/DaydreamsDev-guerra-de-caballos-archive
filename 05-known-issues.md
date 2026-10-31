# 05 — Known issues

These defects are preserved as evidence. They are not fixed in `original/`. The archaeology track
uses them to teach diagnosis; the laboratory uses them to teach repair.

## Correctness and portability

| Issue | Variant and line | Consequence |
|---|---|---|
| Loop bound writes one element past a 64-element array | `variant-01:61`, `variant-02:72`, `variant-03:82`, `variant-04:88` | Undefined behavior; possible corruption of adjacent memory. |
| `void main()` | `variant-01:32`, `variant-02:37`, `variant-04:52` | Not standard C++; not portable. |
| `int main()` | `variant-00:359`, `variant-03:47` | Valid form; recorded for contrast. |
| `srand(time(NULL))` in placement | `variant-00:36` (seeds once, no retry loop); `variant-01:76`, `variant-02:87`, `variant-03:99`, `variant-04:105` (inside the retry loop) | Non-reproducible placement; repeated seeding in the 2008 variants. |
| Broken board initialization | `variant-03:84-86` | The pointer is reset to the first element inside every iteration, so only the first cell is cleared. |
| Inverted win condition in the precursor | `variant-00:299` | The machine is declared the winner when all four pawns have been eaten. |
| Unbounded name input into `char nombre[250]` | `variant-02:46`, `variant-03:56`, `variant-04:62` | Buffer overflow risk. |
| Windows console command | `variant-00:363`, `variant-01:38`, `variant-02:43`, `variant-03:53`, `variant-04:59` | Platform lock-in. |
| Pre-standard headers | All variants, lines 11–12 | `iostream.h` and `conio.h` are not modern standard headers. |

## Engineering practice

- No automated tests and no deterministic seed.
- No version control during the original work.
- The original files carry no separate license file; the precursor header carried a non-MIT license
  note, normalized to MIT in the restored edition.
- Comments often narrate the obvious, contain orthographic errors, or describe behavior that
  changed.
- The class-based implementation is missing; no source, project file or documentation survives.

## The rule

Do not repair these issues in `original/`. A repair belongs in a labeled adaptation or in the
laboratory. The archive records the defect, the line, and the consequence.
