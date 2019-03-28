#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPop(tank);
	print_tank(tank);

	tankPush(tank, 10);
	print_tank(tank);

	tankPush(tank, 50);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPush(tank, 950);
	print_tank(tank);


	tankPush(tank, 950);
	print_tank(tank);

	tankPush(tank, 100);
	print_tank(tank);

	tankPush(tank, 20);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);
	return (0);
}



// Function used for the test
// Don't go further :)
