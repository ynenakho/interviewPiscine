#include "header.h"

int main(void)
{
	char *book;

	//getting the file
	book = readFile();

	/*-------------------
	launch your test here
	--------------------*/
	printf("God is mentioned %d times\n", howManyJesus(book, "God"));
	printf("Lord is mentioned %d times\n", howManyJesus(book, "Lord"));
	printf("shit is mentioned %d times\n", howManyJesus(book, "shit"));
	return (0);
}

// Function used for the test
// Don't go further :)

#define FILENAME "book.txt"

void	leave(void){
	dprintf(STDERR_FILENO, "failed to load the file.\n");
	exit(0);
}

char	*readFile(void)
{
	char *fcontent = NULL;
	int size = 0;
	FILE *fp;

	printf("Loading the file... ");
	if (NULL == (fp = fopen(FILENAME, "r")))
		leave();
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	if (NULL == (fcontent = malloc(sizeof(char) * (size + 1))))
		leave();
	fread(fcontent, 1, size, fp);
	fclose(fp);
	printf("finish!\n");
	return (fcontent);
}