#include "header.h"

void	swap(t_node **a, t_node **b) {
	t_node	*tmp = *a;
	t_node	*tmpLeft = (*b)->left;
	t_node	*tmpRight = (*b)->right;

	*a = *b;
	if (tmp->left == (*b)) {
		(*b)->left = tmp;
		(*b)->right = tmp->right;
	} else {
		(*b)->right = tmp;
		(*b)->left = tmp->left;
	}
	tmp->left = tmpLeft;
	tmp->right = tmpRight;
}

void		transform(t_node **root) {
	if (*root) {
		if ((*root)->left && (*root)->value < (*root)->left->value)
			swap(root, &(*root)->left);
		if ((*root)->right && (*root)->value < (*root)->right->value)
			swap(root, &(*root)->right);
		transform(&(*root)->left);
		transform(&(*root)->right);
	}
}

int count(t_node **root) {
	if (!(*root))
		return 0;
	return (1 + count(&(*root)->left) + count(&(*root)->right));
}

void saveTheSequoia(struct s_node **root)
{
	if (!root) return;

	int n = count(root);
	for (int i = 0; i < n; i++)
		transform(root);
}
