# 06 — Restoration

This report lists every transformation applied to the private raw files to produce the public
restored edition. No source logic was changed.

## Transformations

| Transformation | Scope | Reason |
|---|---|---|
| Header normalization | `variant-01` through `variant-04` | Header fields normalized to a consistent format. The author line is `AUTHOR: Juan Camilo Rivera`; the remaining fields (Name, fecha, Description, License) are preserved. |
| License header normalization | All source files | `variant-00`: replaced the original license note with `License: MIT`; `variant-01` through `variant-04`: added the `License: MIT` line to the header. |
| Encoding conversion | All source files | Converted Windows-1252 to UTF-8. |
| Line-ending normalization | All source files | Converted Windows line endings to Unix line endings. |
| File-name normalization | All source files | Renamed to the variant identifiers and English descriptive names. The original paths are not published. |
| Documentation transcription | User manual and technical notes | Extracted the binary documents and wrote Spanish transcriptions and English translations in `documentation/`. |
| Documentation whitespace normalization | User manual and technical notes | User manual: collapsed multiple spaces and consecutive blank lines introduced by the word processor. Technical notes: collapsed consecutive blank lines only; word-processor line breaks and spacing inside the code listing are preserved. |

## What was not changed

- Source code, control flow, data structures and behavior.
- Comments outside the header block.
- Original spelling and orthographic errors.
- Original defects listed in [`05-known-issues.md`](05-known-issues.md).
- Original formatting outside the header block.

## Exclusions

- Compiled binaries, object files, debug symbols, precompiled headers and linker state.
- Integrated development environment project and workspace state.
- Private material retained in the raw vault.
- Material outside the archive scope.
- Any reconstruction of missing code.

## Verification

See [`checksums.txt`](checksums.txt) for the verified public file set.
