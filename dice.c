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


struct _Dice {
  Id id;
  int last_shoot
};


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

void dice_destroy (Dice *dice){
  if (dice == NULL){
    return;
  }
  free(dice);
  return;
}

int dice_roll(Dice *dice){
  int random;
  time_t t;
  if (dice == NULL){
    return 0;
  }
  srand((unsigned) time(&t));
  random = (rand() %6);
  if (random == 0){
    return 0;
  }
  else {
    dice->last_shoot = random;
    return random;
  }
}
/*Por si hay mas de uno en el juego y necesitamos un id especifico*/
Id dice_get_id(Dice*dice){
  if (dice == NULL){
    return NO_ID;
  }
  return dice->id;
}

STATUS dice_print (Dice *dice){
  Id id_aux;
  int int_aux;
  if (!dice){
    return ERROR;
  }
  fprintf(stdout,"--> Dice (Id: %ld;last_shoot:%d)",dice->id,dice->last_shoot);
  return OK;
}
