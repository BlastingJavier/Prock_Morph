/**
*@brief Manejo de conjuntos
*
*
*@file set.c
*@author FJNR & AMH
*@version 1.0
*@date 19/02/2018
*@copyright GNU Public License
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"
#include "types.h"

/*Para no desaprovechar memoria...*/
#define Set_Empty(x) (x==0)/*Macro para ver si el conjunto esta vacio*/
#define Set_Full(x) (x > MAX_ID)/*Macro para ver si el conjunto esta lleno*/

/*Estructura que define un conjunto(características) */
struct _Set {
  Id id_array[MAX_ID];
  int num_array_actual;
};



/*
 * @brief Se encarga de crear el conjunto
 * @param nada
 * @return NULL o conj_create (nuevo conjunto recien creado)
 */
Set * set_create (){
  Set *conj_create;
  conj_create = (Set*)malloc (sizeof(Set));
  if (conj_create == NULL){
    return NULL;
  }
  else {
    for (i=0;i<MAX_ID;i++){
      conj_create->id_array[i] = NO_ID;
    }
    conj_create->n_array_actual = 0;
  }
  return conj_create;
}



/*
 * @brief Se encarga de liberar el conjunto
 * @param set puntero a Set
 * @return nada (void)
 */
void set_destroy (Set * set){
  int i;
  if (set == NULL){
    return;
  }
  else {
    for (i=0;i<MAX_ID;i++){
      free(set->id_array[i]);
    }

    set = NULL;
    free(set);

    return;
  }
}



/*
 * @brief Se encarga de anadir un elemento (id) al conjunto
 * @param set puntero a Set
 * @param id (Id) identificador nuevo
 * @return status OK o ERROR
 */
STATUS set_add (Set *set , Id id){
  int i;
  if (set == NULL){
    return ERROR;
  }
  if (Set_Full(set->num_array_actual)==1){
    return ERROR;
  }
  else {
    for (i=0;set->id_array[i]!=0 && i< MAX_ID;i++);
  }
  if (i >=MAX_ID){
    return ERROR;
  }
  else {
    set->id_array[i] = id;
    (set->num_array_actual)++;
  }
  return OK;
}


/*
 * @brief Se encarga de sacar un elmento si queremos
 * @param set puntero a Set
 * @return Id el identificador que usaremos
 */
Id  set_delete (Set *set){
  Id temp;

  if(!set){
    return ERROR;
  }
  /*Set_empty no es una funcion, es una macro (devuelve 1 = verdadero)*/
  if (Set_Empty(set->num_array_actual) ==1){
    return NO_ID
  }
  else {
    set->num_array_actual--;
    temp = set->id_array[set->num_array_actual];
    set->id_array[set->num_array_actual] = NO_ID;
    return temp;
  }
}


/*
 * @brief Imprimir por pantalla los elementos de la estructura
 * @param set, puntero a set
 * @return OK o ERROR, ya que es de tipo STATUS
 */
STATUS set_print(Set* set) {
  int i;
  if (set == NULL){
    return ERROR;
  }
  for (i=0;i<MAX_ID/*no necesario*/ || i<set->num_array_actual;i++){
    frprintf(stdout,"Elemento %d : %ld\n",i+1,set->id_array[i]);
  }
  fprintf(stdout,"La cantidad de elementos total es : %d",i);
  return OK;
}
