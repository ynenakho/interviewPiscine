#ifndef HEADER_H
# define HEADER_H
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

typedef struct s_que_item {
	struct s_node   *que_node;
	struct s_que_item *next;
} t_que_item;

typedef struct s_queue {
  struct s_que_item *first;
	struct s_que_item *last;
} t_queue;
/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct s_node {
	char	*name;
	struct s_node **children;
} t_node;


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_node *getTreeOfLife(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
