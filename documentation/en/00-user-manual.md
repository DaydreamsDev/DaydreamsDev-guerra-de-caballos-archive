# USER MANUAL

> Translator's note: this is an English translation of the original 2008 Spanish
> document. The wording follows the original, including its informal style. The
> console glyphs used by the program are preserved and described in the glyph
> legend at the end.

This game consists of getting one horse to eat the other by moving on an 8 x 8
board. The horse's moves are decided randomly, as follows: the first possible
move is random; if that move cannot be made because the square the horse would
land on is outside the board or has already been used, the following moves are
decided as follows:

```
                         3                2

                 4                                 1

                                  C

                 5                                 8

                         6                7
```

Starting from the first random number chosen, the following possible moves are
given according to the drawing above, counter-clockwise, until all 8 possible
moves are completed.

The game ends in two cases:

1° When one HORSE kills the other, which means it has won.

2° When a HORSE is left with no possible moves, that is, it is trapped, which
means it loses.

To make each of the moves, press the Enter key. At the start of the game you are
given information about which horse starts and in which position each horse will
be located; the horse's initial position is also given randomly, as is the
position it ends up in.

## CONVENTIONS

The current location of each horse is determined by the symbol for that horse,
the move number, and the symbol for that horse again.

Horse 1 (player): §, example of horse 1's location:  § 1§

Horse 2 (the machine): £, example of horse 2's location:  £ 4£

Square where no horse has been or is: ████

(The number in the middle is the move in which the horse passed through that
spot)

Square where the machine's horse has been:  █ 3█

Square where the player's horse has been (initial of the player's name, for
example j): j 2j

Good LUCK.

## Glyph legend

The game draws the board on a text console, so it uses single characters as
tokens. The Spanish manual names them only by example; the mapping below also
matches the character constants declared in the source code (`simcab1=21`,
`simcab2=156`, `sep=219`).

| Glyph | Meaning | Used in the source as |
| --- | --- | --- |
| `§` | Horse 1, the player's horse | `simcab1`, character 21 |
| `£` | Horse 2, the machine's horse | `simcab2`, character 156 |
| `█` | A board square, empty or already visited | `sep`, character 219 |

A cell is printed as three glyphs around the move number: the horse symbol on
both sides for the cell a horse currently occupies (`§ 1§`, `£ 4£`) or the block
glyph on both sides for a cell already visited (`█ 3█`). An empty cell is four
block glyphs (`████`). The number in the middle is always the move in which that
cell was reached. A visited cell of the player's horse keeps the player's initial
instead of the block glyph (`j 2j`).
