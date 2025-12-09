COMO LLAMAR AL CODIGO:
make -> bin/tab -> darle el contenido de 'input' -> control + D



Ruleta – Conteo de posiciones con instrucciones
1. Elección del problema

Este proyecto simula la lectura de instrucciones de movimiento sobre una ruleta de 100 posiciones (0–99), registrando cuántas veces la ruleta apunta a la posición 0.
El objetivo es practicar el procesamiento de entradas en tiempo real, el manejo de estructuras de datos eficientes (unordered_map) y la modularización de cálculos para optimizar el conteo.

2. Descripción técnica
2.1 Entrada y representación

La entrada consiste en una serie de instrucciones en formato carácter + número, por ejemplo:

L10 → mover 10 posiciones a la izquierda.

R25 → mover 25 posiciones a la derecha.

Cada instrucción se procesa dígito a dígito para evitar problemas con números grandes.

La posición inicial de la ruleta es 50.

Se utiliza un unordered_map<int, long long> para almacenar la frecuencia de visitas a cada posición, optimizando el acceso y evitando búsquedas lineales.

2.2 Algoritmo

Leer instrucciones hasta el final de la entrada.

Para cada instrucción:

Determinar la dirección (L o R).

Extraer el valor numérico dígito a dígito.

Calcular la nueva posición usando módulo 100 para mantener la ruleta dentro del rango.

Registrar la frecuencia de la posición en el unordered_map.

Contar cuántas veces la ruleta apuntó a la posición 0 al final del proceso.

Mostrar:

Total de instrucciones leídas.

Veces que la ruleta apuntó a 0.

2.3 Optimización

Uso de unordered_map para accesos rápidos y almacenamiento dinámico de posiciones visitadas.

Parseo de números dígito a dígito evita conversiones de cadena a entero costosas.

Modulo aplicado directamente para limitar la posición en [0, 99].

3. Código

Código compacto, legible y modular, con comentarios que explican cada paso.

Variables con nombres claros: pos, freq, instr, total_instructions.

Uso de ios::sync_with_stdio(false) y cin.tie(nullptr) para lectura eficiente de entrada estándar.

(El código completo se adjunta al final como anexo en el proyecto)

4. Alternativas evaluadas

Usar un vector de tamaño 100 en lugar de unordered_map → útil si todas las posiciones son visitadas, pero desperdicia memoria si pocas posiciones son accedidas.

Leer la instrucción completa como número en una sola operación → más rápido, pero menos seguro frente a caracteres no válidos.

Procesar cada carácter individualmente → permite mayor control sobre la entrada y robustez ante datos inválidos.

5. Aprendizaje y reflexión

Práctica en procesamiento seguro de entrada y parseo manual de números.

Aprendizaje del uso de unordered_map para contar frecuencias.

Aplicación de módulo para limitar valores dentro de un rango.

Organización de código limpio, con variables significativas y separación de responsabilidades.

6. Conclusión

Implementación eficiente y clara, cumpliendo los objetivos: contar instrucciones y visitas a la posición 0.

Uso correcto de estructuras de datos dinámicas y técnicas de procesamiento de entrada.

Código fácilmente extensible para otras simulaciones o conteo de posiciones en ruletas de diferente tamaño.
