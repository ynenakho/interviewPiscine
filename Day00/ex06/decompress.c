#include "header.h"

void listInsert(t_list *list, char *str, int index) {

	list->elems[index] = malloc(sizeof(t_elem));
	list->elems[index]->word = strdup(str);
	list->elems[index]->occurence = index;
}

t_list *listInit(int len) {
	t_list *list;
	list = malloc(sizeof(t_list));
	list->len = len;
	list->elems = malloc(sizeof(t_elem *) * len);
	bzero(list->elems, sizeof(t_elem *) * len);
	return list;
}

struct s_string *stringInit(void)
{
	t_string *newString;

	newString = malloc(sizeof(t_string));
	newString->content = calloc(16 + 1, 1);
	newString->length = 0;
	newString->capacity = 16;
	return newString;
}

int	stringAppend(struct s_string *s, char *add)
{
	int lenToAdd = strlen(add);

	if ((s->capacity - s->length) >= lenToAdd) {
		strncpy(s->content + s->length,add, lenToAdd);
		s->length += lenToAdd;
	} else {
		if (lenToAdd > ((s->capacity * 3) / 2)) {
			if ((s->content = realloc(s->content, s->capacity + lenToAdd )) == NULL)
				return 0;
			strncpy(s->content + s->length, add, lenToAdd);
			s->capacity += lenToAdd;
			s->length = s->length + lenToAdd;
		} else {
			if ((s->content = realloc(s->content, (s->capacity * 3) / 2)) == NULL)
				return 0;
			strncpy(s->content + s->length, add, lenToAdd);
			s->capacity += s->capacity/2;
			s->length = s->length + lenToAdd;
		}
	}
	return 1;
}

char *decompress(char *cBook)
{
	t_list *list;
	char tmp[30] = {0};
	int i = 0;
	int count = 1;

	list = listInit(255);
	cBook++;
	while(*cBook != '>') {
		i = 0;
		while(*cBook != ',' && *cBook != '>') {
			tmp[i++] = *cBook++;
		}
		tmp[i] ='\0';
		listInsert(list, tmp, count++);
		if (*cBook == ',')
			cBook++;
	}
	cBook++;
	count = 0;
	t_string *result = stringInit();
	char *temp = cBook;
	while (*temp) {
		if (*temp == '@') {
			*temp = '\0';
			stringAppend(result, strdup(temp - count));
			temp++;
			if ((int)(*temp) == 13 && (int)(*(temp + 1)) == 10) {
				temp++;
				stringAppend(result, list->elems[13]->word);
			} else
				stringAppend(result, list->elems[(unsigned char)(*temp)]->word);
			count =0;
			temp++;
		}
		count++;
		temp++;
	}
	stringAppend(result, strdup(temp - count));
	return result->content;
}
