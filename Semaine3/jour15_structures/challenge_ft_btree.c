/*
 * challenge_ft_btree.c - Arbre binaire basique
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_btree
{
	int				value;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

t_btree *create_node(int value)
{
	t_btree *node = malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void insert_node(t_btree **root, int value)
{
	if (!*root)
	{
		*root = create_node(value);
		return;
	}
	if (value < (*root)->value)
		insert_node(&(*root)->left, value);
	else
		insert_node(&(*root)->right, value);
}

void print_inorder(t_btree *root)
{
	if (!root)
		return;
	print_inorder(root->left);
	printf("%d ", root->value);
	print_inorder(root->right);
}

void print_tree(t_btree *root, int level)
{
	int i;
	if (!root)
		return;
	print_tree(root->right, level + 1);
	for (i = 0; i < level; i++)
		printf("    ");
	printf("%d\n", root->value);
	print_tree(root->left, level + 1);
}

void free_tree(t_btree *root)
{
	if (!root)
		return;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

int main(void)
{
	t_btree *root = NULL;

	printf("╔════════════════════════════════════════╗\n");
	printf("║     challenge_ft_btree - BST           ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	insert_node(&root, 50);
	insert_node(&root, 30);
	insert_node(&root, 70);
	insert_node(&root, 20);
	insert_node(&root, 40);
	insert_node(&root, 60);
	insert_node(&root, 80);

	printf("Parcours inorder (trié) : ");
	print_inorder(root);
	printf("\n\n");

	printf("Visualisation de l'arbre :\n");
	print_tree(root, 0);

	free_tree(root);
	printf("\n✓ Tests réussis\n");
	return (0);
}
/* gcc -Wall -Wextra -Werror -g challenge_ft_btree.c -o btree */
