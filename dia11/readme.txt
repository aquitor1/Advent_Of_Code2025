COMO USAR: tiene un makefile para compilar los códigos, pero le tienes que dar el input 

Explicación del problema "Reactor" (Día 11)

Imagina que estás en una sala de máquinas con varios dispositivos conectados entre sí. Cada dispositivo tiene cables de salida que van a otros dispositivos.

Datos que te dan:

Una lista de dispositivos y sus conexiones

Ejemplo: bbb: ddd eee significa:

Dispositivo bbb tiene 2 salidas

Una va al dispositivo ddd

Otra va al dispositivo eee

Objetivo
Encontrar TODOS los caminos posibles desde:

Inicio: El dispositivo llamado "you" (tú)

Fin: El dispositivo llamado "out" (salida principal del reactor)

Reglas importantes
Solo se puede ir hacia adelante (nunca hacia atrás)

No hay ciclos en los datos reales (pero mejor prevenir)

Un mismo dispositivo puede aparecer varias veces en diferentes caminos

¿Por qué es un problema de grafos?
Nodos: Dispositivos (you, bbb, ccc, etc.)

Aristas: Conexiones entre dispositivos

Grafo dirigido: Las conexiones tienen dirección (solo van hacia adelante)

La solución usa DFS (Depth First Search - Búsqueda en Profundidad) recursivo para explorar todos los caminos posibles.


CONCLUSIÓN:

Es un buen problema para practicar como resolver problemas de grafos direccionados!!
