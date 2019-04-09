#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue *q = queueInit();
	printf("is empty: %d\n", isEmpty(q));
	printf("dequeue msg: %s\n", dequeue(q));
	printf("first second third are added\n");
	enqueue(q, "first");
	enqueue(q, "second");
	enqueue(q, "third");
	printf("peek msg: %s\n", peek(q));
	printf("dequeue msg: %s\n", dequeue(q));
	printf("dequeue msg: %s\n", dequeue(q));
	printf("dequeue msg: %s\n", dequeue(q));
	printf("dequeue msg: %s\n", dequeue(q));
	return (0);
}



// Function used for the test
// Don't go further :)

