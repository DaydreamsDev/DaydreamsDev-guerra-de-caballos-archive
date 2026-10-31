# DOCUMENTACION DE USUARIO

> Nota de transcripción: el texto se reproduce tal como aparece en el documento
> original de 2008, incluyendo su ortografía y puntuación. Solo se convirtió a
> UTF-8 y se normalizaron los espacios múltiples que introducía la justificación
> del procesador de textos. Los símbolos gráficos del tablero se conservan.

Este juego consiste en lograr que un caballo se coma al otro moviéndose en un
tablero de 8 x 8, los movimientos del caballo se deciden de forma aleatoria, de
la siguiente manera, la primera posibilidad de movimiento es aleatoria; dado el
caso que este movimiento no se pueda realizar porque la casilla en la que caería
el caballo esta fuera del tablero o ya ha sido usada antes los siguientes
movimientos se deciden de la siguiente manera:

```
                         3                2

                 4                                 1

                                  C

                 5                                 8

                         6                7
```

Partiendo del primer número aleatorio elegido, los posibles movimientos
siguientes están dados de acuerdo al dibujo anterior en el sentido inverso a las
manecillas del reloj, hasta completar los 8 posibles movimientos.

En juego finaliza en dos casos:

1° Cuando un CABALLO mate al otro, lo cual significa que ha ganado.

2° Cuando un CABALLO se quede sin posibles movimientos, es decir, queda
encerrado, lo cual significa que pierde.

Para poder realizar cada uno de los movimientos presione la tecla Intro, al
comienzo del juego se le entregara información sobre cual caballo empieza y en
que posición estará ubicado cada caballo, la posición inicial del caballo
también está dada de forma aleatoria al igual que la posición en la cual va
quedando.

## CONVENCIONES:

La ubicación actual de cada caballo estará determinada por el símbolo
correspondiente al caballo el número de jugada y otra vez el símbolo
correspondiente caballo.

Caballo 1(jugador): §, ejemplo ubicación del caballo 1:  § 1§

Caballo 2(la maquina): £, ejemplo ubicación del caballo 2:  £ 4£

Casilla en la que no ha estado ni esta ningún caballo: ████

(El numero de la mitad es la jugada en la que el caballo paso por ese sitio)

Casilla en la que estuvo el caballo de la maquina:  █ 3█

Casilla en la que estuvo el caballo del jugador (inicial del nombre del jugador
por ejemplo j): j 2j

Mucha SUERTE.
