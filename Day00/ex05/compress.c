#include "header.h"
#include <ctype.h>

size_t hash(char *input) {
    size_t hash = 5381;
    int c;

    while ((c = *input++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

t_dict *dictInit(int capacity) {
	t_dict *dict;
	dict = malloc(sizeof(t_dict));
	dict->capacity = capacity;
	dict->items = malloc(sizeof(t_item *) * capacity);
	bzero(dict->items, sizeof(t_item *) * capacity );
	return dict;
}

t_item *createNewItem(char *key, int value) {
	t_item *newItem;

	newItem = malloc(sizeof(t_item));
	newItem->value = value;
	newItem->key = key;
	newItem->next = NULL;
	return newItem;
}

void			addlist(t_item **item, t_item *newItem)
{
	if (*item)
		newItem->next = *item;
	*item = newItem;
}

int	dictInsert(t_dict *dict, char *key, int value) {
	if (!dict)
		return 0;
	int index = hash(key)%(dict->capacity);
	t_item *newItem;
	newItem = createNewItem(key,value);
	addlist(&dict->items[index], newItem);
	return 1;
}


int dictSearch(t_dict *dict, char *key) {
	int index = hash(key)%(dict->capacity);
	t_item *item;
	item = dict->items[index];
	if (item) {
		if (strcmp(item->key, key) == 0)
			return item->value;
		item = item->next;
	}
	return -1;
}

char *makeHeader(t_dict *dict)
{
	char *header;
	t_item *item;
	int i = 0;
	int headerLen = 0;
	while(i < dict->capacity) {
		item = dict->items[i];
		while (item) {
			headerLen += strlen(item->key) + 1;
			item = item->next;
		}
		i++;
	}
	i = 0;
	int j = 0;
	header = calloc(headerLen + 2, 1);
	char *res = header;
	*header++ = '<';
	while (i < dict->capacity) {
		item = dict->items[i];
		while (item) {
			j=0;
			while(item->key[j]){
				*header++ = item->key[j++];
			}
			*header++ = ',';
			item = item->next;
		}
		i++;
	}
	*--header = '>';
	return res;
}

char *copyWord(char *str, int len) {
	char *word = calloc(len +1, 1);
	word = strncpy(word, str, len);
	return word;
}


char *compress(char *book, struct s_dict *dict)
{
	char *header;
	int bookLen = strlen(book);
	header = makeHeader(dict);
	int headerLen = strlen(header);
	int i = 0, stringLen = 0, bookIndex = 0, search;
	char *tempWord;
	char *result = calloc(headerLen + bookLen + 1, 1);

	i = headerLen;
	result = strncpy(result, header, headerLen);
	while(book[bookIndex])
	{
		while(!isalpha(book[bookIndex])) {
			result[i++] = book[bookIndex++];
		}
		stringLen = 0;
		while(isalpha(book[bookIndex + stringLen])) {
			stringLen++;
		}
		tempWord = copyWord(&book[bookIndex], stringLen);
		if ((search = dictSearch(dict, tempWord)) >= 0) {
			result[i++] = '@';
			result[i++] = search + 1;
		} else {
			strncpy(result + i, tempWord, stringLen);
			i += stringLen;
		}
		bookIndex += stringLen;

	}
	return result;
}
