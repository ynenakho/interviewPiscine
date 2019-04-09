#ifndef HEADER_H
# define HEADER_H
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

/*--------------------------------
  !! required structure
  --------------------------------*/

typedef struct s_elem {
	char *word;
	int  occurence;
}t_elem;

typedef struct s_list {
	struct s_elem **elems;
	int           len;
}t_list;

typedef struct s_string {
  char *content;
  int  length; //the current length of 'content'
  int  capacity; //the allocated size of 'content'
}t_string;

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// DYNAMIC STRING

struct s_string *stringInit(void);
int	stringAppend(struct s_string *s, char *add); //return 0 = FAIL, 1 = SUCCESS

// OTHER

char *decompress(char *cBook);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/

char *readFile(void);
char **mostUsedWords(char *book);
char *compress(char *book, char **words);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
