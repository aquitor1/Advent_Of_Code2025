
En el Day 5: Cafeteria, nuestro grupo se enfrentó a un problema cuyo objetivo principal es determinar cuántos identificadores de ingredientes disponibles pueden considerarse frescos. Nuestro grupo decidió abordar el problema almacenando todos los identificadores de ingredientes frescos en una tabla hash, lo que nos permite comprobar de manera rápida si un ingrediente disponible pertenece al conjunto de ingredientes frescos. Esta estrategia simplifica considerablemente la verificación, ya que cada consulta se reduce a una operación directa sobre la estructura de datos.

Dado que los rangos de IDs pueden solaparse, expandirlos y almacenarlos en la tabla hash evita tener que comprobar cada identificador disponible contra múltiples rangos, lo que simplifica la lógica del programa.Asimismo, la solución escala correctamente cuando el número de ingredientes disponibles aumenta, manteniendo un buen rendimiento y una estructura clara y mantenible.

No obstante, aunque la solución basada en tablas hash es válida y eficiente, nuestro grupo reconoce que existen otras alternativas como:

1) Ordenar los rangos y fusionar aquellos que se solapan, para posteriormente realizar búsquedas binarias sobre ellos.
2) Arboles de intervalos, que permitirían comprobar la pertenencia a rangos sin necesidad de expandirlos

En conclusión, nuestro grupo considera que la solución basada en el uso de una tabla hash es la opción más adecuada puesto que se justifica por su eficiencia en tiempo de ejecución, ya que permite realizar comprobaciones de pertenencia en tiempo promedio constante, lo cual es ideal dado el número de consultas necesarias sobre los identificadores de ingredientes disponibles. Además, la implementación es clara, directa y fácil de comprender, lo que reduce la probabilidad de errores y facilita el mantenimiento del código. Aunque existen otras alternativas, estas incrementan la complejidad del diseño sin aportar beneficios significativos para el tamaño y los requisitos del problema planteado.
