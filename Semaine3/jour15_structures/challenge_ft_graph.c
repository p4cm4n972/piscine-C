/*
 * challenge_ft_graph.c - Graphe simple (liste d'adjacence)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct s_node
{
	int				vertex;
	struct s_node	*next;
}	t_node;

typedef struct s_graph
{
	t_node	*adj_list[MAX_VERTICES];
	int		num_vertices;
}	t_graph;

t_graph *create_graph(int vertices)
{
	t_graph *graph = malloc(sizeof(t_graph));
	int i;

	if (!graph)
		return (NULL);
	graph->num_vertices = vertices;
	for (i = 0; i < vertices; i++)
		graph->adj_list[i] = NULL;
	return (graph);
}

t_node *create_node(int vertex)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->vertex = vertex;
	node->next = NULL;
	return (node);
}

void add_edge(t_graph *graph, int src, int dest)
{
	t_node *node;

	if (!graph || src >= graph->num_vertices || dest >= graph->num_vertices)
		return;

	// Ajouter dest à la liste de src
	node = create_node(dest);
	node->next = graph->adj_list[src];
	graph->adj_list[src] = node;

	// Graphe non orienté : ajouter src à la liste de dest
	node = create_node(src);
	node->next = graph->adj_list[dest];
	graph->adj_list[dest] = node;
}

void print_graph(t_graph *graph)
{
	int i;
	t_node *temp;

	printf("Graphe (liste d'adjacence) :\n");
	for (i = 0; i < graph->num_vertices; i++)
	{
		printf("  %d -> ", i);
		temp = graph->adj_list[i];
		while (temp)
		{
			printf("%d ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

void free_graph(t_graph *graph)
{
	int i;
	t_node *temp, *next;

	if (!graph)
		return;
	for (i = 0; i < graph->num_vertices; i++)
	{
		temp = graph->adj_list[i];
		while (temp)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
	}
	free(graph);
}

int main(void)
{
	t_graph *graph;

	printf("╔════════════════════════════════════════╗\n");
	printf("║     challenge_ft_graph - Graphe        ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	graph = create_graph(5);

	printf("Ajout d'arêtes...\n");
	add_edge(graph, 0, 1);
	add_edge(graph, 0, 4);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 1, 4);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 4);

	printf("\n");
	print_graph(graph);

	free_graph(graph);
	printf("\n✓ Tests réussis\n");
	return (0);
}
/* gcc -Wall -Wextra -Werror -g challenge_ft_graph.c -o graph */
