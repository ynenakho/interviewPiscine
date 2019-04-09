#include "header.h"

void	print_tank(t_tank *t)
{
	if (t->n == 0)
		printf("No energy in the tanks\n");
	for (int i = 0; i < t->n; i++)
		printf("stack %d: %d\n", i, t->stacks[i]->sum);
	printf("\n");
}

t_tank *initTank(void)
{
  return calloc(sizeof(t_tank), 1);
}

void create_stack(t_tank *tank)
{
  t_stack *new;

  tank->n++;
  tank->stacks = realloc(tank->stacks, sizeof(t_stack *) * tank->n);
  new = calloc(sizeof(t_stack), 1);
  tank->stacks[tank->n - 1] = new;

}

void stack_push(t_stack *stack, int energy)
{
  t_elem *new_elem;

  new_elem = calloc(sizeof(t_elem), 1);
  new_elem->energy = energy;
  new_elem->next = stack->elem;
  stack->elem = new_elem;
  stack->sum += energy;
}

void tankPush(t_tank *tank, int energy)
{
  if (!tank)
    return ;
  if (!tank->stacks || tank->stacks[tank->n - 1]->sum + energy > 1000)
    create_stack(tank);
  stack_push(tank->stacks[tank->n - 1], energy);
}

t_elem *elem_pop(t_elem **root)
{
  t_elem *tmp;
  tmp = *root;
  *root = (*root)->next;
  return(tmp);
}

void			delete_stack(t_tank *tank)
{
  t_stack **stacks;

  stacks = tank->stacks;
	free(tank->stacks[tank->n - 1]);
	(tank->n)--;
	if (tank->n == 0)
	{
		free(stacks);
		stacks = NULL;
	}
	tank->stacks = realloc(tank->stacks, sizeof(t_stack*) * (tank->n));
}

int tankPop(t_tank *tank)
{
  t_stack *stack;
  t_elem *elem;
  int e;

  if (tank->n == 0)
    return (0);
  stack = tank->stacks[tank->n - 1];
  elem = elem_pop(&stack->elem);
  stack->sum -= elem->energy;
  e = elem->energy;
  free(elem);
  if (stack->sum == 0)
		delete_stack(tank);
  return (e);
}
