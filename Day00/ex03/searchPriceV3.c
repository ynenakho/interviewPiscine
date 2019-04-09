#include "header.h"

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

t_item *createNewItem(char *key, t_art *value) {
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

int	dictInsert(t_dict *dict, char *key, t_art *value) {
	if (!dict)
		return 0;
	int index = hash(key)%(dict->capacity);
	t_item *newItem;
	newItem = createNewItem(key,value);
	addlist(&dict->items[index], newItem);


	return 1;
}

t_art *dictSearch(t_dict *dict, char *key) {
	int index = hash(key)%(dict->capacity);
	t_item *item;
	item = dict->items[index];
	while (item) {
		if (strcmp(item->key, key) == 0)
			return item->value;
		item = item->next;
	}
	return NULL;
}
