/**
*@brief It defines a space
*
*
*@file space.c
*@author FJNR & AMH
*@version 1.0
*@date 05/02/2018
*@copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "space.h"
/*Lo necesitamos por las macros y utilizacion de nuevo campo Set*objects*/
#include "set.h"

/*Estructura que define un espacio (características)*/
struct _Space {
  Id id;
  char name[WORD_SIZE + 1];
  Id north;
  Id south;
  Id east;
  Id west;
  Id object;
  Set *objects;
};
/**                 Definidos en:
                        ||
                        ||
                        V
WORD_SIZE = 1000 <==types.h
MAX_SPACES = 100 <==space.h
FIRST_SPACE = 1 <==space.h
NO_ID = -1 <==types.h
NO_CMD = -1 <==command.h
UNKNOWN = 0 <==command.h
EXIT = 1 <==command.h
FOLLOWING = 2 <==command.h
PREVIOUS = 3 <==command.h
SCREEN_MAX_STR = 80 <==screen.h
P.F.: Private Function
*/



/*
 * @brief Se encarga de iniciar la estructura de espacio
   y poner el caracter fin de cadena al final del nombre de este
 * @param id, de tipo Id
 * @return newSpace, que es el puntero a la estructura Space
 */
Space* space_create(Id id) {

  Space *newSpace = NULL;

  if (id == NO_ID){
    return NULL;
  }

  newSpace = (Space *) malloc(sizeof (Space));

  if (newSpace == NULL) {
    return NULL;
  }
  newSpace->id = id;

  newSpace->name[0] = '\0';

  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;
  /*Para crear un conjunto de id (se asignará NO_ID)*/
  newSpace->objects = set_create();

  return newSpace;
}



/*
 * @brief Libera memoria para space
 * @param space: puntero a Space.
 * @return status OK o ERROR.
 */
STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }
  set_destroy(space->objects);
  space->objects = NULL;

  free(space);
  space = NULL;

  return OK;
}



/*
 * @brief Pone o cambia el nombre del espacio
 * @param space: puntero a Space.
 * @param name: puntero a char.
 * @return status OK o ERROR.
 */
STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}



/*
 * @brief Pone o cambia el north
 * @param space: puntero a Space
 * @param id: campo de Id
 * @return status OK o ERROR o NO_ID
 */
STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}



/*
 * @brief Pone o cambia el south
 * @param space: puntero a Space.
 * @param id: del type Id
 * @return status OK o ERROR o NO_ID
 */
STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}



/*
 * @brief Pone o cambia el east
 * @param space: puntero a Space.
 * @param name: puntero a char.
 * @return status OK o ERROR o NO_ID
 */
STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}



/*
 * @brief Pone o cambia el west
 * @param space: puntero a Space.
 * @param id: del type Id
 * @return status OK o ERROR o NO_ID
 */
STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}



/*
 * @brief Quita el ultimo objeto de la casilla
 * @param space: puntero a Space.
 * @return status, OK o ERROR.
 */
STATUS space_delete_object(Space* space){
  if (!space){
    return ERROR;
  }
  if(set_pop_id (space->objects)==NO_ID){
    return ERROR;
  }
  return OK;
}



/*
 * @brief Colocamos en el space un objeto
 * @param space: puntero a Space.
 * @param id: Id (identificador)
 * @return status, OK o ERROR.
 */
STATUS space_add_object(Space* space, Id id) {
  if (!space){
    return ERROR;
  }
  if (set_push_id(space->object,id)==ERROR){
    return ERROR;
  }
  return OK;
}



/*
 * @brief Devuelve el nombre (casilla)
 * @param space: puntero a Space.
 * @return name, el name space->name o NULL
 */
const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}



/*
 * @brief Devuelve el id (casilla)
 * @param space: puntero a Space.
 * @return id, el id space->id o NO_ID
 */
Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}



/*
 * @brief Devuelve el id de la casilla del norte
 * @param space: puntero a Space.
 * @return norte, space->north o NO_ID
 */
Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}



/*
 * @brief Devuelve el id de la casilla del sur
 * @param space: puntero a Space.
 * @return south, space->south o NO_ID
 */
Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}



/*
 * @brief Devuelve el id de la casilla del norte
 * @param space: puntero a Space.
 * @return norte, space->north o NO_ID
 */
Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}



/*
 * @brief Devuelve el id de la casilla del oeste
 * @param space: puntero a Space.
 * @return west, space->west o NO_ID
 */
Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}



/*
 * @brief Devuelve el si hay o no objeto en la casilla
 * @param space: puntero a Space.
 * @return object, space->object o FALSE si no existen objetos
 */
Set* space_get_objects(Space* space) {
  Set *set_aux;
  if (!space || space->objects == NULL) {
    return NULL;
  }
  /////////////////////////////*Hay algo que cambiar mas adelante seguroo NOTTAAAXXXXXXXXXXXXXXXX*/
  /* Set_Empty => Macro de set.h*/
  if (Set_Empty(space->objects)==1){
    set_destroy(set_aux);
    return NULL;
  }

  return space->objects;
}


/*Hay que ver si es necesaria de verdad esta funcion o no*/
/*
 * @brief Devuelve el si hay o no objeto en la casilla
 * @param space: puntero a Space.
 * @return object, space->object o FALSE
 */
Id space_get_object(Space* space ,Id id_objeto) {
  int i;
  Id id_aux_obj;
  if (!space) {
    return NO_ID;
  }
  for (i=0;i<MAX_OBJ;i++){
    id_aux_obj = object_get_id(space->objects);
    if (*((Id)id_aux_obj) == id_objeto){
      return *((Id) id_aux_obj);
    }
  }
}
/*
 * @brief Comprueba si un objeto esta en el espacio actual
 * @param space: puntero a Space.
 * @param id_objeto, de tipo id.
 * @return BOOL, TRUE or FALSE (si parámetros vacios/obtención de la estructura
    con errores/si sale en el bucle de comprobación (de set_delete))
 */
BOOL object_check (Space *space , Id id_objeto){
  Set *aux;
  Id id_aux;

  if (!space|| id_objeto == NO_ID){
    return FALSE;
  }
  aux = space_get_objects(space);

  if (aux == NULL){
    return FALSE;
  }
  for (  ;(id_aux=set_pop_id(aux))!=NO_ID; ){
    if (id_aux == id_objeto){
      set_destroy(aux);
      aux = NULL;
      return TRUE;
    }
  }
  set_destroy (aux);
  aux = NULL;
  return FALSE;
}


/*
 * @brief Muestra por la pantalla de salida, tanto el id, como el nombre del espacio
 * @param space: puntero a Space.
 * @return status, OK o ERROR o NO_ID
 */
STATUS space_print(Space* space) {
  Id idaux = NO_ID;
  Set * set_aux;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }
  set_aux = space_get_objects(space);

  if (set_aux != NULL){
    Set_print(set_aux);
    set_destroy(aux);
    aux = NULL;
  }
  else {
    fprintf(stdout, "---> No objects in the space.\n");
  }
  return OK;
}
