#ifndef HEADER_H
# define HEADER_H
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct s_player {
  int   score;
  char  *name;
} t_player;

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void quickSort(struct s_player **players);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_player **genRandomPlayers(int n);
struct s_player *createRandomPlayer(char *name);
void printPlayers(struct s_player **players);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
