/**
*@brief Interfaz del dado
*
*
*@file dice.h
*@author FJNR & AMH
*@version 1.0
*@date 03/02/2018
*@copyright GNU Public License
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct _Dice Dice;



Dice * dice_create ();

void dice_destroy (Dice *dice);


int dice_roll(Dice* dice);

Id dice_get_id(Dice* dice);

STATUS dice_print (Dice *dice);
