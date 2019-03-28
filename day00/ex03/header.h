#ifndef HEADER_H
# define HEADER_H
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...


/*--------------------------------
  !! required structure
  --------------------------------*/

typedef struct  s_art {
  char *name;
  int  price;
}       t_art;

typedef struct s_item {
  char           *key; //here the key will be the name
  struct s_art   *value;
  struct s_item  *next;
}       t_item;

typedef struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
}       t_dict;

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// DICTIONNARY

size_t hash(char *input); //return hash result

struct s_dict *dictInit(int capacity); //initialize the dictionnary, given as parameter the capacity of the array.
int	dictInsert(struct s_dict *dict, char *key, struct s_art *value); //add one element in the dictionnary, if FAIL return 0, otherwise 1
struct s_art *dictSearch(struct s_dict *dict, char *key); //find one element in the dictionnary, if not found, return NULL

// OTHER

int searchPrice(struct s_dict *dict, char *name);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/

struct s_art **getArts(int *n);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
