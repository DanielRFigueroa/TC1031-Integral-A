# Analisis de Complejidad 🖥️ ✅

## Daniel Rodriguez Figueroa   A01612889

### Insertion

El algoritmo **(insertion)** recorre **_n_** pasos, ya que utiliza un ciclo que recorre todos los elementos hasta llegar al final de la lista para asi poder añadir el nuevo nodo.
Debido a esto su complejidad es **O(n)**. 
Sin embargo, en caso de que la lista esté vacía, se usa el **(insertionFirst)** el cual es de complejidad **O(1)**. 

### Search

El algoritmo **(search)** recorre **_n_** pasos ya que utliza un ciclo que recorre todos los elementos de la lista hasta encontrar el valor a buscar.
Debido a esto su complejidad es **O(n)** para el peor de los casos.

### Update

El algoritmo **(update)** recorre **_n_** pasos puesto que utiliza un ciclo que recorre todos los elementos de la lista hasta llegar al índice indicado para después actualizar el valor del nodo.
Debido a esto su complejidad es de **O(n)** para el peor de los casos.

### Delete At

El algoritmo **(Delete At)** recorre **_n_** pasos puesto que utiliza un ciclo que recorre todos los elementos de la lista hasta llegar al índice indicado para después eliminar el nodo.
Debido a esto su complejidad es de **O(n)** para el peor de los casos.
Sin embargo, para eliminar el primer nodo **(DeleteFirst)** su complejidad es de **O(1)**, ya que no necesita recorrer la lista completa.

### Add

El algoritmo **(Add)** lleva a cabo dos funciones, una inserta el nodo de acuerdo a su valor y la otra función (**splay**) rota y ordena el árbol (solo si es necesario) para que el nuevo valor ingresado sea la raíz del arbol.
Debido a esto su complejidad es de **O(log n)** para el peor de los casos.

### Remove

El algoritmo **(Remove)** lo utilizamos para remover un nodo del árbol y para ordenar nuevamente el árbol con un (***splay***) para asi poder asignar a su sucesor como raíz, este algoritmo tiene que recorrer **n** pasos.
Debido a esto su complejidad es de **O(log n)** para el peor de los casos.

### Find

El algoritmo **(Find)** recorre **n** pasos recursivamente para completar su busqueda, si encuentra el valor, el algoritmo ejecutará la función ***splay*** para poder asignar el valor encontrado ahora como la raíz del árbol.
Debido a esto su complejidad es de **O(log n)** para el peor de los casos.