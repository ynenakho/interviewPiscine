#include "header.h"

t_node *createRoot(int *arr, int n, t_node *root) {
	if (n == 0)
		return NULL;
	root = calloc(sizeof(t_node), 1);
	(root)->value = arr[n/2];
	root->left = createRoot(arr, n / 2, (root)->left);
	root->right = createRoot(arr + n/2 + 1, n % 2 ? n / 2: n / 2 - 1, (root)->right);
	return root;
}

t_node *createBST(int *arr, int n) {
	t_node *head = NULL;
	head = createRoot(arr, n, head);
	return head;
}
