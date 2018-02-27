/**
*@brief Implementacion del dado
*
*
*@file dice.c
*@author FJNR & AMH
*@version 1.0
*@date 03/02/2018
*@copyright GNU Public License
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"
#include "types.h"

/*Estructura que representa datos caracteristicos de un dado (id) y el ultimo
  tiro*/
struct _Dice {
  Id id;
  int last_shoot;
};



/*
 * @brief Se encarga de iniciar la estructura de un dado
 * @param nada
 * @return NULL o la propia estructura
 */
Dice * dice_create (){
  Dice *dice;
  dice = (Dice*)malloc(sizeof(Dice));
  if (dice == NULL){
    return NULL;
  }
  dice->id = NO_ID;
  dice->last_shoot = 0;
  return dice;
}



/*
 * @brief Se encarga de liberar la memoria para un dado
 * @param dice , puntero a Dice
 * @return nada se trata de una funcion de tipo void
 */
void dice_destroy (Dice *dice){
  if (dice == NULL){
    return;
  }
  free(dice);
  dice = NULL;

  return;
}



/*
 * @brief Se encarga de sacar un numero aleatorio entre 6 (dado comun de ocaa)
 * @param dice , puntero a Dice
 * @return int (numero random)
 */
int dice_roll(Dice *dice){
  int random;
  time_t t;
  if (dice == NULL){
    return 0;
  }
  srand((unsigned) time(&t));
  random = (rand() %6 + 1);
  if (random == 0){
    return 0;
  }
  else {
    /*Se puede perfectamente utilizar una funcion de tipo STATUS y asignar el random
      a dice ->last_shoot y retornar OK pero para afianzar que esto devuelve un numero
      pseudo aleatorio hemos decidio que retorne un entero*/
    dice->last_shoot = random;
    return random;
  }
}



/*
 * @brief Se encarga de obtener el id de un dado (funcion por ver)
 * @param dice , puntero a Dice
 * @return dice->id campo id o NULL
 */
/*Por si hay mas de uno en el juego y necesitamos un id especifico*/
Id dice_get_id(Dice*dice){
  if (dice == NULL){
    return NO_ID;
  }
  return dice->id;
}



/*
 * @brief Se encarga de obtener la ultima tirada
 * @param dice , puntero a Dice
 * @return dice->last_shoot campo de dice
 */
int dice_get_last_shoot(Dice *dice ){
  if (dice == NULL){
    return 0;
  }
  return dice->last_shoot;
}



/*
 * @brief Imprime un dado (el Id y la ultima tirada)
 * @param dice , puntero a Dice
 * @return status , OK o ERROR
 */
STATUS dice_print (Dice *dice){
  if (!dice){
    return ERROR;
  }
  fprintf(stdout,"--> Dice (Id: %ld;last_shoot:%d)",dice->id,dice->last_shoot);
  return OK;
}
