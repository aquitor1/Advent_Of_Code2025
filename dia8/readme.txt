Como usar:
make bin/dia8_parte1
./bin/dia8_parte1 < input 
obs: cualquier duda es solo mirar el Makefile

Problema: dia 8

El problema nos dice: 
-Tenemos cajas en el espacio 3-dimensional;
-Queremos que las cajas con menor distancia estén conectadas y en un mismo circuito;
-Hacemos eso para los 1000 pares de cajas con menor distancia;
-Calculamos el producto de la cantidad de cajas de los 3 circuitos con +cajas;

Nos pide:
-El resultado del producto

Cómo lo interpretamos para resolverlo?
-Cajas=arestas
-Conexión=aresta
-Circuito=grafo

Dicho esto el problema se resume en:
Ir conectando vértices y formando grafos;
Ver cuando hay que hacer la conexión o no;
Calcular cuales son los 2 vértices +cercanos actualmente;

Porque es un buen problema?
Es un problema 100% de solo grafos y como son solo conexiones normales es un grafo no direccionado con eso es un buen problema para practicar grafos
