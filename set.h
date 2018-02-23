/**
*@brief Manejo de conjuntos (interfaz)
*
*
*@file set.h
*@author FJNR & AMH
*@version 1.0
*@date 19/02/2018
*@copyright GNU Public License
*/

#ifndef SET_H
#define SET_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_ID 512
/*Estructura que define un conjunto(características) */
typedef struct _Set Set;



/*
 * @brief Se encarga de crear el conjunto
 * @param nada
 * @return NULL o conj_create (nuevo conjunto recien creado)
 */
Set * set_create ();



/*
 * @brief Se encarga de liberar el conjunto
 * @param set puntero a Set
 * @return nada (void)
 */
void set_destroy (Set * set);



/*
 * @brief Se encarga de anadir un elemento (id) al conjunto
 * @param set puntero a Set
 * @param id (Id) identificador nuevo
 * @return status OK o ERROR
 * @NOTA :Es la funcion add de la iteracion (pero nos parece mas logico llamarla
    de esta manera)
 */
STATUS set_push_id (Set *set , Id id);



/*
 * @brief Se encarga de sacar un elmento si queremos
 * @param set puntero a Set
 * @return Id el identificador que usaremos
 * @NOTA :Es la funcion del de la iteracion (pero nos parece mas logico llamarla
    de esta manera)
 */
Id  set_pop_id (Set *set);



/*
 * @brief Imprimir por pantalla los elementos de la estructura
 * @param set, puntero a set
 * @return OK o ERROR, ya que es de tipo STATUS
 */
STATUS set_print(Set* set);

#endif
