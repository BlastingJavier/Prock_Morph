/**
*@brief Manejo de jugadores (funcionalidad)
*
*
*@file player.c
*@author FJNR & AMH
*@version 1.0
*@date 06/02/2018
*@copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "object.h"
#include "space.h"
#include "player.h"


/*Estrucura que para las caracteristicas de player*/
struct _Player {
  Id player_id;
  char name[WORD_SIZE+1];
  Id space_id;/*objeto del inventario*/
  Set *inventory_items;/*localicación*/
};



/*
 * @brief Se encarga de crear el player,
   y poner el caracter fin de cadena al final del nombre de este
 * @param id, de tipo Id
 * @return newPlayer, que es el puntero a la estructura
 */
Player* player_create (Id id){
  Player *newPlayer = NULL;
  if (id == NO_ID){
    return NULL;
  }
  newPlayer = (Player*)malloc(sizeof(Player));

  if (newPlayer==NULL){
    return NULL;
  }
  newPlayer->player_id=id;
  newPlayer->inventory_items= set_create();

  return newPlayer;
}



/*
 * @brief Libera memoria para player.
 * @param Player: puntero a Player .
 * @return status OK o ERROR.
 */
STATUS player_destroy (Player* player){
  if(!player){
    return ERROR;
  }
  set_destroy(player->inventory_items);
  free(player);

  return OK;
}



/*
 * @brief Pone o cambia el nombre del player
 * @param objeto: puntero a Objeto.
 * @param name: puntero a char.
 * @return status OK o ERROR.
 */
STATUS player_set_name (Player* player, char* name){
  if (!player || !name){
    return ERROR;
  }
  if (!strcpy(player->name,name)){
    return ERROR;
  }

  return OK;
}



/*NO SE NECESITA PERO SE CONSERVA
 * @brief Pone o cambia el objeto del inventario
 * @param player: puntero a Player.
 * @param objeto: campo de Objeto.
 * @return status OK o ERROR.

STATUS player_set_object(Player* player,Id object) {
  if (!player || !object) {
    return ERROR;
  }
  player->inventory_item_id = object;
  return OK;
}*/



/*
 * @brief Pone o cambia la localizacion de player
 * @param player: puntero a Player.
 * @param location: campo de Space.
 * @return status OK o ERROR.
 */
STATUS player_set_location(Player* player,Id location) {
  if (!player || !location) {
    return ERROR;
  }
  player->space_id = location;
  return OK;
}



/*
 * @brief Devuelve el nombre asignado a un player
 * @param player: puntero a player.
 * @return name, el nombre que asignamos al player
 */
const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}



/* NO ES NECESARIA PERO VAMOS A CONSERVARLA POR SI ACASO
 * @brief Devuelve la inventory_item
 * @param player: puntero a Player.
 * @return player->inventory_item (objeto)

Id player_get_inventory_item(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->inventory_item_id;
}
*/


/*q
 * @brief Devuelve el set de objetos de un jugador
 * @param player: puntero a Player.
 * @return player->inventory_items (puntero a Set)
 */
Set *player_get_inventory_items (Player *player){
  if (player == NULL ||player->inventory_items == NULL){
    return NULL;
  }
  return player->inventory_items;
}


/*
 * @brief Devuelve la location
 * @param player: puntero a Player.
 * @return player->location(localizacion)
 */
Id player_get_location(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->space_id;
}



/*
 * @brief Devuelve el id del player
 * @param player: puntero a player.
 * @return player->player_id(identificador)
 */
Id player_get_id(Player * player){
  if (!player){
    return NO_ID;
  }
  return player->player_id;
}



/*
 * @brief Quita un objeto al jugador
 * @param pla: puntero a player.
 * @return status OK o ERROR
 */
STATUS player_delete_inventory_item(Player *player){
  if (player==NULL){
    return ERROR;
  }
  if (set_pop_id(player->inventory_items)==NO_ID){
    return ERROR;
  }

  return OK;
}



/*
 * @brief Pone un objeto al jugador
 * @param pla: puntero a player.
 * @param id: Identificador
 * @return status OK o ERROR
 */
STATUS player_add_inventory_item(Player *player , Id id){
  if (!player || id == NO_ID){
    return ERROR;
  }
  if(set_push_id(player->inventory_items,id)==ERROR){
    return ERROR;
  }
  return OK;
}


/*
 * @brief Muestra por la pantalla de salida, tanto el id, como el nombre del player
 * @param player: puntero a player.
 * @return status, OK o ERROR
 */
 /**
 * USO ALTERNATIVO ==> PLAYER PRINT: Control de errores Debugging
 */
STATUS player_print(Player* player) {
  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->player_id, player->name);

  if (NULL != player_get_inventory_items(player)) {
    fprintf(stdout, "---> inventory_item: %ld.\n",(long)player_get_inventory_items(player));
  }else {
    fprintf(stdout, "---> No inventory_item.\n");
  }
  if (NO_ID != player_get_location(player)) {
    fprintf(stdout, "---> Location: %ld.\n",(long)player_get_location(player));
  }else {
    fprintf(stdout, "---> No location.\n");
  }

  return OK;
}
