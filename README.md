*Este proyecto ha sido creado como parte del currículo de 42 por ismonter, davgarc4.*

# push_swap

## Descripción

**push_swap** es un programa escrito en C cuyo objetivo es ordenar una lista de números enteros utilizando únicamente un conjunto limitado de operaciones sobre dos stacks.

El programa recibe una lista de números en la línea de comandos y genera la **secuencia más corta posible de operaciones** necesarias para ordenar esos números en orden ascendente. El primer argumento recibido corresponde al **elemento superior del stack A**.

El proyecto está diseñado para profundizar en:

- diseño de algoritmos
- análisis de complejidad
- optimización de operaciones
- manipulación de estructuras de datos
- toma de decisiones algorítmicas basada en propiedades de la entrada

A diferencia de los algoritmos de ordenación tradicionales, el objetivo no es ordenar directamente los datos sino **generar una secuencia de operaciones válidas** que transforme el stack inicial en uno ordenado.

---

# Reglas del problema

El programa utiliza **dos stacks**:

- **Stack A**: contiene inicialmente todos los números.
- **Stack B**: comienza vacío.

El objetivo es ordenar el stack **A en orden ascendente** utilizando únicamente las operaciones permitidas.

---

# Operaciones permitidas

### Swap
- `sa` → intercambia los dos primeros elementos de A  
- `sb` → intercambia los dos primeros elementos de B  
- `ss` → ejecuta `sa` y `sb`

### Push
- `pa` → mueve el elemento superior de B a A  
- `pb` → mueve el elemento superior de A a B  

### Rotate
- `ra` → rota A hacia arriba  
- `rb` → rota B hacia arriba  
- `rr` → `ra` y `rb`

### Reverse rotate
- `rra` → rota A hacia abajo  
- `rrb` → rota B hacia abajo  
- `rrr` → `rra` y `rrb`

Cada operación se imprime en **stdout** separada por un salto de línea.

---

# Compilación

El proyecto incluye un **Makefile**.

Para compilar el programa:

`make`

# Ejecución

Formato básico:

`./push_swap [numbers...]`

Ejemplo:

`./push_swap 3 2 5 1 4`

El programa imprimirá la secuencia de operaciones necesaria para ordenar el stack.

# Selectores de estrategia

El programa permite forzar el algoritmo utilizado mediante flags.

**Flag**
- `--simple` -> algoritmo O(n²)
- `--medium`	-> algoritmo O(n√n)
- `--complex`	-> algoritmo O(n log n)
- `--adaptive` -> selección automática

Ejemplo:

`./push_swap 5 2 8 1 3 --complex`

Si no se especifica ningún selector, el programa utiliza por defecto:

`--adaptive`

# Índice de desorden

Para seleccionar la estrategia adecuada se calcula un índice de desorden. 
Este valor mide cuán lejos está la lista de estar ordenada.
El índice se calcula comparando todos los pares posibles de elementos.

El índice final se obtiene mediante:

disorder = mistakes / total_pairs

Esto produce un valor entre:

- 0	-> lista completamente ordenada
- 1	-> máximo desorden posible

## Estrategias de ordenación

El programa implementa tres algoritmos de ordenación con diferentes complejidades.

La complejidad se mide en número de operaciones push_swap generadas.

# Algoritmo simple — O(n²)

Este algoritmo está basado en una adaptación de Selection Sort.

Se eligió una adaptación de Selection Sort por su simplicidad y facilidad de implementación sobre stacks:

El motivo es que permite ordenar listas pequeñas o casi ordenadas con un número de operaciones relativamente bajo.

La idea consiste en: 
- Buscar el elemento mínimo en el stack A.

- Rotar A hasta colocar ese elemento en la cima.

- Enviarlo a B con `pb`.

- Repetir hasta vaciar A.

- Devolver todos los elementos a A con `pa`.

# Algoritmo intermedio — O(n√n)

La estrategia intermedia utiliza Chunk Sorting. Se eligió un algoritmo basado en chunks (división en bloques) como estrategia intermedia debido a que ptimiza la cantidad de operaciones para listas parcialmente desordenadas mediante particionamiento por rangos.

El número de bloques se calcula como:

`chunks = √n`

Cada chunk contiene aproximadamente:

`n / √n elementos.`

- Los valores se indexan previamente.

- Los índices se dividen en rangos (chunks).

- Los elementos pertenecientes al chunk actual se envían a B con pb.

- Los elementos restantes se rotan en A.

- Una vez que todos los chunks han sido procesados, los elementos se devuelven a A.

Para reconstruir A:

- Se busca el máximo en B.

- Se rota B usando rb o rrb según si el numero se encuentra en la mitad de arriba o en la de abajo.

- Se devuelve a A con pa.

# Algoritmo complejo — O(n log n)

El algoritmo complejo implementa una adaptación de Radix Sort. Se utiliza una versión binaria LSD (Least Significant Bit). Este algoritmo garantiza complejidad logarítmica en el número de bits, lo que permite manejar listas grandes con muchas operaciones de manera eficiente.

Los números se indexan previamente igual que en el algoritmo intermedio. Despues encontramos el numero mayor y miramos el numero de bits que tiene.

Se procesan los bits de menor a mayor.
Para cada bit:
 - si el bit es 0 → pb
 - si el bit es 1 → ra

Una vez procesado el bit, todos los elementos de B se devuelven a A.

Este proceso se repite hasta el valor maximo de bits que encontramos anteriormente en el numero mas grande.

# Indexación de valores

Antes de ejecutar los algoritmos chunks o radix, los números se normalizan mediante indexación.

- Los valores se copian a un array temporal.

- El array se ordena utilizando Quicksort.

A cada número se le asigna su posición en el array ordenado.

Esto permite trabajar con los valores del array ordenado lo que simplifica significativamente los algoritmos.

# Estrategia adaptativa

El modo adaptativo selecciona automáticamente el algoritmo según el índice de desorden.

Si el indice de desorden es de < 0.2 usamos el algoritmo simple
Si esta entre 0.2 y 0.5	usamos el algoritmo intermedio
Si esta entre 0.5 y 1 usamos el algoritmo complejo

- Listas casi ordenadas pueden resolverse rápidamente con algoritmos simples.

- Listas parcialmente desordenadas se benefician de estrategias basadas en bloques.

- Listas muy desordenadas requieren algoritmos de mayor complejidad 

Este enfoque permite optimizar el número de operaciones según la estructura real de la entrada.

# Modo Benchmark

El programa incluye un modo opcional:

`--bench`

Cuando se activa, el programa muestra estadísticas adicionales en stderr.

La informacion que mostramos es:

- El índice de desorden

- La estrategia utilizada

- La complejidad teórica

- El número total de operaciones

- El número de operaciones por tipo

Esto permite analizar el comportamiento del algoritmo para distintos inputs.

Si los numeros estan ya ordenados, no se mostrará la estrategia utilizada debido a que no se usa ninguna.

# Manejo de errores

El programa detecta y gestiona los siguientes errores:

- Argumentos que no son enteros

- Overflow de enteros

- Números duplicados

- Formato de entrada inválido

En caso de error se imprime `Error` en stderr.

# Recursos

Algunos recursos útiles para comprender los algoritmos utilizados:

documentación sobre Selection Sort: https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/

documentación sobre Radix Sort: https://www.geeksforgeeks.org/dsa/radix-sort/

documentación sobre Quicksort: 
https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/

# Uso de IA

Se han utilizado herramientas de inteligencia artificial como apoyo para la revisión conceptual de algoritmos y la redacción del archivo README

Todas las decisiones de diseño, implementación de algoritmos y desarrollo del código han sido realizadas por los autores del proyecto.