#include "header.h"
#include <limits.h>
#define MAX(a,b) (a > b ? a : b)

void getAllInfo(t_node *root, t_info *info) {
	if (!root)
		return ;
	info->elements++;
	if ((root->left && (root->left->value >= root->value)) ||
	 (root->right && (root->right->value <= root->value)))
	 	info->isBST = 0;
	if (root->value < info->min)
		info->min = root->value;
	if (root->value > info->max)
		info->max = root->value;
	getAllInfo(root->left, info);
	getAllInfo(root->right, info);
}

int getHeight(t_node *root) {
	if (!root)
		return 0;
	return 1 + MAX(getHeight(root->left), getHeight(root->right));
}

int isBalanced(t_node *root)
{
   if(root == NULL)
    return 1;
   if((abs(getHeight(root->left) - getHeight(root->right)) <= 1) &&
       isBalanced(root->left) &&
       isBalanced(root->right))
     return 1;
   return 0;
}

struct s_info   getInfo(struct s_node *root) {
	t_info info;
	bzero(&info, sizeof(t_info));
	info.min = INT_MAX;
	info.max = INT_MIN;
	info.isBST = 1;
	info.isBalanced = isBalanced(root);
	info.height = getHeight(root);
	getAllInfo(root, &info);
	return info;
}
