#include "header.h"

int pop(struct s_stack *stack)
{
  int tmp;

  if (!stack || !stack->item)
    return (0);
  tmp = stack->item->idx;
  stack->item = stack->item->next;
  return (tmp);
}

void push(struct s_stack *stack, int idx)
{
  t_item *new;

  if (!stack)
    return ;
  new = calloc(sizeof(t_item), 1);
  new->idx = idx;
  new->next = stack->item;
  stack->item = new;
}

struct s_stack *stackInit(void)
{
  t_stack *stack;

  stack = calloc(sizeof(t_stack), 1);
  return (stack);
}

char *console(void)
{
  char *input = NULL;
  static char *ret = NULL;
  static t_stack *stack;
  int i;
  int add;
  size_t buf = 256;

  if (!stack)
    stack = stackInit();
  printf("?:");
  int n = getline(&input, &buf, stdin);
  input[n - 1] = '\0';
  if (strcmp(input, "UNDO") == 0)
  {
    add = (stack->item && stack->item->next) ? 1 : 0;
    if (ret && stack->item && stack->item->idx)
    {
      i = strlen(ret) - pop(stack) - add;
      ret = strndup(ret, i);
      printf("%s", ret);
    }
  }
  else if (strcmp(input, "SEND") == 0)
    return (ret);
  else
  {
    if (!(input[0] == '\0' && n == 1))
    {
      push(stack, strlen(input));
      if (!ret)
        ret = input;
      else
      {
        strcat(ret, " ");
        strcat(ret, input);
      }
      printf("%s", ret);
    }
  }
  printf("\n\n");
  return (console());
}
