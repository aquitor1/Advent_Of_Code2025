---1. Motivación y selección del problema---

Nuestro grupo ha elegido el problema del Day 5: Cafeteria de Advent of Code porque permite aplicar de forma clara y directa el uso de tablas hash, una de las estructuras de datos fundamentales vistas en la asignatura. El problema se centra en la gestión eficiente de información y en la comprobación rápida de pertenencia, lo cual encaja perfectamente con las características de este tipo de estructura.

La elección de este problema se basó en tres aspectos principales. En primer lugar, su importancia técnica, ya que requiere realizar muchas consultas de pertenencia de forma eficiente. En segundo lugar, presenta una complejidad adecuada, ya que el problema es sencillo de entender pero permite aplicar estructuras de datos clave sin recurrir a soluciones excesivamente complejas. Por último, refuerza el aprendizaje conceptual, consolidando el uso práctico de tablas hash en un contexto realista.

---2. Diseño y descripción técnica de la solución---
  
  -2.1 Representación de datos
  Los rangos de identificadores frescos se procesan y se transforman en valores individuales, que se almacenan en una tabla hash     (unordered_set). Cada valor de la tabla representa un identificador de ingrediente que es considerado fresco.

  Por otro lado, los identificadores de ingredientes disponibles se leen uno a uno y se comparan directamente con el contenido de la tabla hash.   De esta forma, no es necesario mantener estructuras adicionales ni realizar comprobaciones complejas contra múltiples rangos.

  -2.2 Algoritmo principal
  Primero, se leen todos los rangos de identificadores frescos y se insertan en la tabla hash todos los valores que pertenecen a dichos rangos. Gracias a esto, los solapamientos entre rangos no suponen ningún problema, ya que la tabla hash evita duplicados de forma automática.

Una vez construida la tabla hash con todos los identificadores frescos, el programa recorre la lista de ingredientes disponibles. Para cada identificador, se realiza una consulta directa a la tabla hash para comprobar si dicho identificador está presente. Si lo está, se incrementa un contador de ingredientes frescos.

Este enfoque reduce el problema a operaciones básicas de inserción y consulta, ambas con un coste promedio constante, lo que garantiza un buen rendimiento incluso cuando el número de ingredientes es elevado.

  -2.3 Comprobación de resultados
  Nuestro grupo comprobó la corrección del algoritmo utilizando el ejemplo proporcionado en el enunciado. En dicho ejemplo, el programa identifica correctamente cuáles de los identificadores disponibles pertenecen a alguno de los rangos frescos y obtiene como resultado un total de tres ingredientes frescos, coincidiendo exactamente con la solución esperada.

Esta verificación confirma que la lógica de inserción en la tabla hash y las consultas posteriores funcionan correctamente y que el algoritmo resuelve el problema de forma adecuada.


---3. Análisis de alternativas--- 
1) Mantener los rangos sin expandir y comprobar, para cada identificador disponible, si pertenecía a alguno de ellos. Sin embargo, esta solución implicaría comparar cada identificador contra todos los rangos, aumentando el coste computacional.
2) Ordenar y fusionar los rangos solapados y realizar búsquedas binarias. Aunque esta opción reduce el uso de memoria, aumenta la complejidad del código y se aleja del objetivo principal de practicar tablas hash.

Por estos motivos, nuestro grupo decidió utilizar una tabla hash, ya que ofrece una solución equilibrada entre eficiencia, simplicidad y adecuación a los contenidos vistos en clase.

---4. Reflexión y valoración del aprendizaje---
La resolución del Day 5 permitió a nuestro grupo comprender mejor cómo utilizar tablas hash para resolver problemas de pertenencia de manera eficiente.

En conclusión, nuestro grupo considera que la solución basada en el uso de una tabla hash es la opción más adecuada puesto que se justifica por su eficiencia en tiempo de ejecución, ya que permite realizar comprobaciones de pertenencia en tiempo promedio constante, lo cual es ideal dado el número de consultas necesarias sobre los identificadores de ingredientes disponibles. Además, la implementación es clara, directa y fácil de comprender, lo que reduce la probabilidad de errores y facilita el mantenimiento del código. Aunque existen otras alternativas, estas incrementan la complejidad del diseño sin aportar beneficios significativos para el tamaño y los requisitos del problema planteado.
