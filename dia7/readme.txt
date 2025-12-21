Como usar: llamar el make bin/... y darle el input del problema

Advent of Code 2025 – Memoria PRA
Día 7: Laboratorios – Laboratorios de Teletransportación
1. Elección del problema

Elegimos el problema del Día 7 porque nos parecía adecuado para aplicar la técnica de Divide y Vencerás usando DFS recursivo.
El objetivo es simular la propagación de un haz de taquiones en un mapa y contar cuántas veces se divide al encontrar divisores (^). Cada división genera dos nuevos haces que se propagan hacia abajo, lo que hace que el problema se adapte perfectamente a la recursión y a la técnica de dividir el problema en subproblemas.

2. Descripción técnica
2.1 Entrada y representación

La entrada consiste en un mapa 2D representado con caracteres:

. → espacio vacío, el haz sigue bajando.

^ → divisor, el haz se detiene y se divide.

S → posición inicial del haz.

Cada línea del mapa se almacena en un vector<string> para acceder a cualquier celda por coordenadas (fila, columna).

Para evitar contar celdas duplicadas, cada posición se codifica como (fila << 32) | columna y se guarda en un unordered_set.

2.2 Algoritmo

Buscar la posición inicial S en el mapa.

Llamar a la función recursiva explorar(r, c) desde la fila debajo de S:

Si la celda es . → el haz sigue bajando.

Si la celda es ^ → se cuenta una división y se crean dos llamadas recursivas: una hacia la columna izquierda y otra hacia la derecha.

Para otros caracteres → el haz simplemente sigue bajando.

Cada celda visitada se marca en el unordered_set para evitar recalcular divisiones.

2.3 Optimización

Complejidad temporal: O(N), siendo N el número de celdas visitadas.

Complejidad espacial: O(N), por el set de celdas visitadas.

Se evita recursión innecesaria gracias al marcado de posiciones ya recorridas.

3. Código

Funciones cortas y descriptivas: leerMapa, buscarInicio, explorar.

Variables con nombres significativos (mapa, visto, R, C).

Uso de ios::sync_with_stdio(false) y cin.tie(nullptr) para lectura eficiente.

(El código completo se adjunta como anexo en el proyecto)

4. Alternativas y decisiones

Recorrer toda la matriz con bucles iterativos → más complejo y propenso a errores.

DFS recursivo simple sin marcar celdas visitadas → ineficiente para mapas grandes.

DFS con marcado de celdas visitadas (unordered_set) → eficiente, claro y evita cálculos innecesarios.

5. Valoración personal

Aprendimos a aplicar Divide y Vencerás en matrices.

Marcar estados visitados optimiza algoritmos recursivos.

Codificación eficiente de posiciones para usar unordered_set.

Organización de código modular y limpio.

6. Conclusión

Implementación eficiente y clara, cumpliendo los objetivos de la rúbrica PRA.

Aplicación correcta de DFS recursivo y Divide y Vencerás.

Documentación de decisiones técnicas, alternativas y aprendizajes.

Día 2: Gift Shop – Identificación de IDs inválidos usando Árboles Binarios de Búsqueda (BST)
1. Elección del problema

Elegimos el desafío del Día 2 porque permite aplicar estructuras de datos aprendidas en clase, especialmente BST.
El objetivo es hallar todos los identificadores inválidos dentro de los rangos dados (números que se repiten como 11, 1010, 222222…) y sumar sus valores. BST facilita guardar IDs únicos y calcular el total de manera eficiente.

2. Descripción técnica
2.1 Entrada y representación

Entrada: línea de texto con rangos de identificadores separados por comas, cada rango formado por dos números divididos por -.

Se manejan los rangos por separado, evitando recorrer todos los números y mejorando el rendimiento.

2.2 Árbol Binario de Búsqueda

Cada nodo guarda un ID no válido.

Inserción:

Menor → subárbol izquierdo.

Mayor → subárbol derecho.

Si ya existe → no se añade, evitando duplicados.

Se realiza un recorrido en orden para sumar todos los IDs.

2.3 Detección de IDs inválidos

Cada número se convierte a cadena.

La cadena se divide en dos partes iguales; si la primera se repite en la segunda, es inválida.

Solo estos IDs se añaden al BST.

3. Organización del código

Funciones autónomas:

Lectura y análisis de input.txt.

Verificación de validez de ID.

Adición al BST.

Recorrido en orden para sumar IDs.

Se incluye un Makefile para compilar y ejecutar el programa fácilmente.

4. Alternativas evaluadas

Uso de vectores o listas → menos eficiente, requiere verificar duplicados manualmente.

Generar todos los números en los rangos → impracticable para rangos grandes.

BST → eficiente, claro y aplicable.

5. Aprendizaje y reflexión

Uso de BST para guardar datos únicos y recorrerlos ordenadamente.

Estructuración de código modular y clara.

Optimización al evitar cálculos innecesarios en grandes conjuntos de datos.

Práctica en manejo de archivos de entrada y estructuras de datos dinámicas en C++.

6. Conclusión

Implementación efectiva y sencilla que cumple los objetivos: encontrar IDs inválidos y calcular la suma total.

Refuerza conocimientos de BST, algoritmos y gestión de datos complejos.
