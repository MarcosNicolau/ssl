# T.P 1

Este repositorio es un benchmark que compara haskell y javascript y es parte del trabajo practico 1. Podes ver la consigna [acá](./assignment.md).

El documento con el trabajo completo lo podes leer [acá](https://docs.google.com/document/d/1qB87sdZocwzo-rBPS5drxwRoQ4tNlJF-o7Iz9nw1scI/edit)

## Resultados

Las medidas se hicieron bajo un hexa-core 2.9GHz Intel® i5-10400f®, 32 GiB de RAM y 2TB M.2; corriendo en Pop!\_OS™ 22.04 x86_64 GNU/Linux.

-   Haskell
    | Algoritmos | Single shot | Average time |
    | ---------- | ----------- | ------------ |
    | sort | 0.00041ms | 0.00022ms |
    | find | 0.00038ms | 0.00021ms |

-   Javascript
    | Algoritmos | Single shot | Average time |
    | ---------- | ----------- | ------------ |
    | sort | 0.15442ms | 0.01809ms |
    | find | 0.16273ms | 0.00805ms |

### Como se midieron las ejecuciones

Se hacen dos tipos de mediciones:

-   **Single shot**: Se mide el tiempo de la primera ejecución del algoritmo. Esto mide el "cold" performance.
-   **Average Time**: El mismo consiste en:
    1. Warmup-stage: Se corre el programa 10.000 veces sin medir el tiempo.
    2. Measure-stage: Se corre el programa otras 10.000 veces esta vez midiendo el tiempo.
    3. Calculation: Se calcula el promedio de ejecución, y se muestra el resultado.

## Correlo en tu compu!

### Linux

1. Dale permiso: `chmod +x ./run_benchmarks.sh`
2. Ejecuta el script: `./run_benchmarks.sh` o `./run_benchmarks.sh --help` para ver como funciona

### Windows

Perdón pero no tenemos idea como se hace en windows :)
