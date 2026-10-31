# 04 — Build status

## Original toolchain

The surviving project and build artifacts in the private raw vault are from **Microsoft Visual C++
6.0 (1998)**. The public archive publishes source only; this claim is based on the private vault and
is not independently verifiable from the public repository alone. The evidence is:

- Visual Studio 6 project and workspace files.
- Build logs that reference the `VC98` include directory and the `cl.exe` compiler.
- Debug symbols, incremental link state and precompiled headers produced by that toolchain.

No other toolchain is asserted. The public repository publishes source only; the historical build
artifacts remain in the private raw vault, so the toolchain claim cannot be independently verified
from this repository.

## Per variant

| Variant | Source artifacts | Historical build artifacts | Notes |
|---|---|---|---|
| `variant-00` | Source listing only | None | The 2007 precursor is a text listing. |
| `variant-01` | Source | Exists privately | Uses `void main` and the pre-standard headers. |
| `variant-02` | Source | Exists privately | Uses `void main`; adds the player-name record and trail. |
| `variant-03` | Source | Exists privately | Uses `int main`; the board initialization is broken. |
| `variant-04` | Source | Exists privately | Uses `void main`; the initialization is correct. |
| `variant-05` | None | None | Classes; missing. No build status exists. |

## Modern status

None of the historical variants compile as modern C++ without compatibility work. The blockers are:

- `#include<iostream.h>` and `#include<conio.h>` — pre-standard and platform headers.
- `void main()` in `variant-01`, `variant-02` and `variant-04`.
- `system("color 1f")` — Windows console command.
- `cin >> nom.nombre` into a fixed-size character array without a width limit.

The archive preserves these conditions. It does not fix them.

## Zero warnings

Zero warnings is a rule for new work, not for the historical code. The archive does not build the
historical code with a modern toolchain, and it does not claim a clean modern build. The
laboratory's readability and port editions will carry the zero-warning rule.

## Binaries

No compiled binaries, object files, debug symbols, precompiled headers or integrated development
environment state are published. They remain in the private raw vault.
