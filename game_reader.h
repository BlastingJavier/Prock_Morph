/*
*@brief Carga de espacios (interfaz)
*
*
*@file game_reader.h
*@author FJNR & AMH
*@version 1.0
*@date 05/02/2018
*@copyright GNU Public License
*/
#ifndef GAME_READ
#define GAME_READ

#include "game.h"
#include "command.h"
#include "space.h"

/*
 * @author Alejandro Martin
 * @brief  Lee el fichero (funcionalidad de carga de espacios)
 * @param Game, es el string destino, en el que se copia el puntero al string de tipo char, "toks"
 * @param filename, puntero a char, que es el nombre del fichero que estamos accediendo
 * @param numcasillas , representa cuantas casillas hay en el juego (funcion de cuenta por si hace falta)
 * @return status, OK O ERROR
 */

STATUS game_reader_load_spaces(Game* game, char* filename);



/*
 * @author Francisco Nanclares
 * @brief  Lee el fichero (funcionalidad de carga de objetos)
 * @param Game, es el string destino, en el que se copia el puntero al string de tipo char, "toks"
 * @param filename, puntero a char, que es el nombre del fichero que estamos accediendo
 * @return status, OK O ERROR
 */
STATUS game_reader_load_objects(Game* game, char* filename);

#endif
