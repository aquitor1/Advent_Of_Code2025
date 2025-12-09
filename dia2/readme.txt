 Day 2 — Gift Shop (Advent of Code)

La tarea consistía en identificar todos los IDs no válidos de la tienda de regalos. Un ID se considera no válido si se forma al repetir una secuencia numérica (por ejemplo: 11, 99, 1010, 222222…). Después, había que sumar todos esos valores.

Para almacenar los IDs no válidos, utilizamos un árbol binario de búsqueda (BST).
La idea es que cada número se guarda como un "nodo" dentro del árbol. Cada nodo tiene números menores a su izquierda y mayores a su derecha.

Esto nos fue útil porque previene la creación de duplicados de manera automática, así que no es necesario verificar si ya lo hemos añadido. También nos permite recorrer todos los números de forma ordenada y sumar sin complicaciones.


Lo hemos hecho de la siguiente manera: 

Primero, leemos los rangos de IDs que nos proporcionó la entrada.

Luego, para cada rango, solo generamos aquellos números que cumplen con la condición de repetición (no es necesario revisar todos los números del rango).

Cada número que cumple esta condición lo insertamos en el árbol.

Al final, recorremos el árbol y sumamos todos los números.


Así podemos evitar que tengamos que revisar números duplicados o clasificarlos posteriormente, y que la solución sea más clara y organizada.


