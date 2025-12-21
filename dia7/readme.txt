Memoria PRA - Advent of Code 2025 - Día 7
1. Elección del problema
Escogí el problema del Día 7 sobre los Laboratorios de Teletransportación porque se adapta perfectamente a una solución recursiva simple. El problema consiste en simular un haz de taquiones que se mueve por un mapa y se divide cada vez que encuentra un símbolo especial.

2. Descripción del problema
Tenemos un mapa formado por caracteres donde:

El punto (.) representa espacio vacío

El símbolo ^ representa un divisor del haz

La letra S marca la posición inicial del haz

El haz siempre se mueve hacia abajo. Cuando encuentra un divisor (^), el haz se detiene y se crean dos nuevos haces: uno que baja diagonalmente hacia la izquierda y otro que baja diagonalmente hacia la derecha. El objetivo es contar cuántas veces se divide el haz en total.

3. Solución implementada
3.1 Enfoque recursivo
Implementé una solución puramente recursiva. La idea es simple: comenzar desde la posición debajo de la S y seguir recursivamente el camino del haz.

3.2 Estructuras de datos
Un vector de strings para almacenar el mapa completo

Un conjunto (set) para llevar registro de las posiciones ya visitadas

Variables para las dimensiones del mapa (filas y columnas)

3.3 Función recursiva principal
La función recursiva tiene estos pasos:

Primero verifica si la posición actual está dentro de los límites del mapa

Luego comprueba si ya hemos procesado esa posición antes

Marca la posición como visitada

Si la celda contiene un divisor (^), suma 1 al contador y hace dos llamadas recursivas: una hacia abajo-izquierda y otra hacia abajo-derecha

Si la celda no es un divisor, simplemente hace una llamada recursiva hacia abajo

3.4 Prevención de procesamiento duplicado
Uso un conjunto para almacenar las posiciones ya visitadas. Esto evita que el programa procese la misma celda múltiples veces, lo que podría llevar a un conteo incorrecto o a un bucle infinito.

3.5 Flujo del programa
Leer todo el mapa desde la entrada estándar

Buscar la posición inicial marcada con S

Llamar a la función recursiva comenzando desde debajo de la S

Imprimir el resultado total

4. Decisiones de diseño
4.1 Recursividad simple vs compleja
Opté por una recursividad simple en lugar de técnicas más complejas como "divide y vencerás" porque el problema se presta naturalmente a este enfoque. Cada decisión (seguir recto o dividirse) se maneja con una simple llamada recursiva.

4.2 Uso de variables globales
Para simplificar el código, uso variables globales para el mapa y el conjunto de visitados. Esto evita tener que pasar estos parámetros en cada llamada recursiva.

4.3 Manejo de entrada/salida
El programa lee desde la entrada estándar, lo que permite redirigir archivos fácilmente. La salida es solo el número total de divisiones.

5. Aprendizajes
5.1 Sobre recursividad
Este problema refuerza cómo usar recursividad para explorar caminos en una estructura bidimensional. La recursividad es natural para problemas donde un proceso se bifurca en múltiples caminos.

5.2 Sobre optimización
El uso del conjunto para marcar posiciones visitadas es crucial para la eficiencia. Sin esto, el programa podría volverse extremadamente lento en mapas grandes debido a la recomputación.

5.3 Sobre claridad del código
Mantener la función recursiva simple y bien documentada hace que el código sea fácil de entender y mantener. Cada caso está claramente definido y el flujo es intuitivo.

6. Ejemplo de funcionamiento
Para el ejemplo proporcionado en el enunciado, donde el haz se divide 21 veces, mi programa calcula correctamente este valor. El programa procesa cada divisor exactamente una vez y suma todas las divisiones.

7. Conclusión
La solución implementada demuestra que para muchos problemas, una aproximación recursiva simple y bien estructurada es suficiente. No siempre se necesitan algoritmos complejos cuando el problema tiene una estructura naturalmente recursiva.

El código es corto (menos de 50 líneas), eficiente y fácil de entender. Resuelve correctamente el problema para entradas de cualquier tamaño mientras se mantenga dentro de los límites de la pila de recursión, lo cual es adecuado para los tamaños típicos de Advent of Code.
