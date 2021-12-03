# TC1031 Integral A 🖥️ ✅

## Daniel Rodriguez Figueroa   A01612889

### Correcciones:

Se añade la Integral A por completo, es decir el archivo main.cpp, phonebook.h, casos_de_prueba.cpp y el README.md con el analisis de complejidad de las funciones utilizadas en el programa.

### Phonebook - Libreta de contactos personal 🖥️ ✅

Este proyecto representa una libreta de contactos virtual en la que se tiene una **lista** de contactos y sus ladas, el programa se encarga de añadir, borrar, mostrar, o cambiar algun numero de contacto introducido, asi como tambien añade, busca, y muestra ladas que son guardadas en un **arbol**.

Podemos ordenar de menor a mayor los numeros que introducimos con un **sort**, y buscar numeros y ladas en especifico.

# Analisis de Complejidad 🖥️ ✅

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

### insertionSort

El Algoritmo **(insertionSort)** recorre toda la lista y le toma el mayor tiempo de ordenamiento si los elementos estan acomodados en orden invertido, es decir, **O(n^2).** 
y tarda el menor tiempo si los elementos ya estan ordenados, es decir, **O(n)**.
Debido a esto su complejidad es de **O(n^2)** para el peor de los casos.

### sortedInsert

El Algoritmo **(insertionSort)** recorre toda la lista y le toma el mayor tiempo de ordenamiento si los elementos estan acomodados en orden invertido, es decir, **O(n^2).** 
y tarda el menor tiempo si los elementos ya estan ordenados, es decir, **O(n)**.
Debido a esto su complejidad es de **O(n^2)** para el peor de los casos.

### Add

El algoritmo **(Add)** lleva a cabo dos funciones, una inserta el nodo de acuerdo a su valor y la otra función (**splay**) rota y ordena el árbol (solo si es necesario) para que el nuevo valor ingresado sea la raíz del arbol.
Debido a esto su complejidad es de **O(log n)** para el peor de los casos.

### inorder

El Algoritmo **(inorder)** recorre todo el arbol visitando cada nodo, debido a esto su complejidad es de **O(n)** para el peor de los casos.

### Find

El algoritmo **(Find)** recorre **n** pasos recursivamente para completar su busqueda, si encuentra el valor, el algoritmo ejecutará la función ***splay*** para poder asignar el valor encontrado ahora como la raíz del árbol.
Debido a esto su complejidad es de **O(log n)** para el peor de los casos.