// El módulo 'mem-eda' redefine las operaciones 'new', 'new[]', 'delete', 
// 'delete[]' modificando únicamente el lanzamiento de excepciones. 'new' y 
// 'new[]' lanzan excepciones de la clase 'error', mientras que 'delete' y 
// 'delete[]' no lanzan excepciones.

// Nota: solo se sobrecargan las operaciones de reserva de memoria dinámica. 
//       Las posteriores operaciones de construcción i/o destrucción de 
//       datos se mantienen igual.


#ifndef _EDA_MEM
#define _EDA_MEM


#include <iostream>


    
// Asigna memoria dinámica suficiente para un objeto de un tamaño específico.
// Pre: 'size' > 0. 'size' representa el tamaño en bytes del tipo de dato 
//      del objeto a almacenar.
// Post: en caso de haber espacio suficiente, reserva un bloque de 'size' 
//       espacios de memoria dinámica para el tipo de dato especificado y 
//       devuelve un apuntador a la dirección inicial del nuevo bloque 
//       reservado. En caso contrario, lanza una excepción de la clase 
//       'error' indicando la falta de memoria dinámica.
void *operator new(size_t size) noexcept(false);


// Asigna memoria dinámica suficiente para un array de objetos de un tamaño 
// específico.
// Pre: 'size' > 0. 'size' representa el tamaño en bytes del tipo de dato 
//      del objeto multiplicado por el numero de objetos a almacenar.
// Post: en caso de haber espacio suficiente, reserva un bloque de 'size' 
//       espacios de memoria dinámica para el tipo de dato especificado y 
//       devuelve un apuntador a la dirección inicial del nuevo bloque 
//       reservado. En caso contrario, lanza una excepción de la clase 
//       'error' indicando la falta de memoria dinámica.
void *operator new[](size_t size) noexcept(false);


// Libera memoria dinámica previamente reservada con 'operator new'.
// Pre: 'ptr' != nullptr. 'ptr' debe contener una dirección de memoria 
//      previamente devuelta por una llamada a 'operator new'.
// Post: el bloque de memoria apuntado por 'ptr' es liberado y 'ptr' contiene
//       una dirección de memoria no válida.
void operator delete(void *ptr) noexcept;


// Libera memoria dinámica previamente reservada con 'operator new[]'.
// Pre: 'ptr' != nullptr. 'ptr' debe contener una dirección de memoria 
//      previamente devuelta por una llamada a 'operator new'.
// Post: el bloque de memoria apuntado por 'ptr' es liberado y 'ptr' contiene
//       una dirección de memoria no válida.
void operator delete[](void* p) noexcept;


#endif