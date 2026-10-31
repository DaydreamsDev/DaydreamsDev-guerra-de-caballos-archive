# Movimiento en L del caballo (ayuda de lectura)

> Esta ayuda de lectura no forma parte del manual original. El manual conserva su
> diagrama original. Esta cuadrícula solo hace explícitas las ocho casillas
> alcanzables.

El caballo se mueve dos casillas en una dirección y una casilla en perpendicular.
Desde la casilla `C`, las ocho casillas alcanzables son:

```text
· 3 · 2 ·
4 · · · 1
· · C · ·
5 · · · 8
· 6 · 7 ·
```

| Movimiento | Cambio de fila | Cambio de columna | Descripción |
|---|---|---|---|
| 1 | -1 | +2 | Una fila hacia arriba, dos columnas a la derecha |
| 2 | -2 | +1 | Dos filas hacia arriba, una columna a la derecha |
| 3 | -2 | -1 | Dos filas hacia arriba, una columna a la izquierda |
| 4 | -1 | -2 | Una fila hacia arriba, dos columnas a la izquierda |
| 5 | +1 | -2 | Una fila hacia abajo, dos columnas a la izquierda |
| 6 | +2 | -1 | Dos filas hacia abajo, una columna a la izquierda |
| 7 | +2 | +1 | Dos filas hacia abajo, una columna a la derecha |
| 8 | +1 | +2 | Una fila hacia abajo, dos columnas a la derecha |

## Ejemplo de una L

El movimiento 6, dos filas hacia abajo y una columna a la izquierda, se ve así:

```text
· C ·
· · ·
X · ·
```

La `C` es la casilla de salida y la `X` es la casilla de llegada. El movimiento
no pasa por las casillas intermedias: el caballo salta.
