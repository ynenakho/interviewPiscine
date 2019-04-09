#include "header.h"

void recursion(struct s_city *city, int n, char **cityName) {
	static int count;

	if(!city)
		count = 0;
	else {
		recursion(city->next, n, &*cityName);
		if (count == n)
			*cityName = city->name;
		count++;
	}
}

char *NthLastCity(struct s_city *city, int n)
 {
	 char *cityName;

	 recursion(city, n, &cityName);
	 return cityName;

 }
