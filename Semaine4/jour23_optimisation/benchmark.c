/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** JOUR 23 : Benchmarks et Optimisation
**
** Ce programme mesure et compare les performances de différents algorithmes :
** - Algorithmes de tri : Bubble, Selection, Insertion, Quick, Merge
** - Algorithmes de recherche : Linéaire, Binaire
**
** Concepts 42/Epitech :
** - Mesure du temps avec clock()
** - Complexité algorithmique en pratique
** - Analyse de performance
** - Allocation mémoire efficace
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* ==================== UTILITAIRES ==================== */

/*
** Génère un tableau aléatoire
*/
int	*generate_random_array(int size)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = rand() % (size * 10);
		i++;
	}
	return (arr);
}

/*
** Copie un tableau
*/
int	*copy_array(int *src, int size)
{
	int	*dst;

	dst = (int *)malloc(sizeof(int) * size);
	if (!dst)
		return (NULL);
	memcpy(dst, src, sizeof(int) * size);
	return (dst);
}

/*
** Vérifie si un tableau est trié
*/
int	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/* ==================== ALGORITHMES DE TRI ==================== */

/*
** Bubble Sort - O(n²)
*/
void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/*
** Selection Sort - O(n²)
*/
void	selection_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	min_idx;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		tmp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = tmp;
		i++;
	}
}

/*
** Insertion Sort - O(n²)
*/
void	insertion_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

/*
** Quick Sort - O(n log n) moyenne
*/
void	quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	if (left >= right)
		return ;
	pivot = arr[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	quick_sort(arr, left, j);
	quick_sort(arr, i, right);
}

/*
** Merge Sort helper
*/
void	merge(int *arr, int left, int mid, int right)
{
	int	*temp;
	int	i;
	int	j;
	int	k;

	temp = (int *)malloc(sizeof(int) * (right - left + 1));
	i = left;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	i = left;
	k = 0;
	while (i <= right)
		arr[i++] = temp[k++];
	free(temp);
}

/*
** Merge Sort - O(n log n) garanti
*/
void	merge_sort(int *arr, int left, int right)
{
	int	mid;

	if (left >= right)
		return ;
	mid = (left + right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

/* ==================== ALGORITHMES DE RECHERCHE ==================== */

/*
** Linear Search - O(n)
*/
int	linear_search(int *arr, int size, int target)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == target)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Binary Search - O(log n)
*/
int	binary_search(int *arr, int size, int target)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return (mid);
		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

/* ==================== BENCHMARKS ==================== */

typedef void	(*sort_func)(int *, int);
typedef void	(*sort_func_range)(int *, int, int);

double	benchmark_sort(int *arr, int size, void (*sort)(int *, int))
{
	clock_t	start;
	clock_t	end;
	int		*copy;

	copy = copy_array(arr, size);
	start = clock();
	sort(copy, size);
	end = clock();
	if (!is_sorted(copy, size))
		printf("    [ERREUR: tableau non trié]\n");
	free(copy);
	return ((double)(end - start) / CLOCKS_PER_SEC * 1000.0);
}

double	benchmark_sort_range(int *arr, int size,
			void (*sort)(int *, int, int))
{
	clock_t	start;
	clock_t	end;
	int		*copy;

	copy = copy_array(arr, size);
	start = clock();
	sort(copy, 0, size - 1);
	end = clock();
	if (!is_sorted(copy, size))
		printf("    [ERREUR: tableau non trié]\n");
	free(copy);
	return ((double)(end - start) / CLOCKS_PER_SEC * 1000.0);
}

double	benchmark_search(int *arr, int size, int target,
			int (*search)(int *, int, int), int iterations)
{
	clock_t	start;
	clock_t	end;
	int		i;

	start = clock();
	i = 0;
	while (i < iterations)
	{
		search(arr, size, target);
		i++;
	}
	end = clock();
	return ((double)(end - start) / CLOCKS_PER_SEC * 1000.0);
}

void	run_sort_benchmarks(void)
{
	int		sizes[] = {1000, 5000, 10000, 20000};
	int		num_sizes;
	int		i;
	int		*arr;
	double	time_ms;

	num_sizes = 4;
	printf("\n╔══════════════════════════════════════════════════════════════╗\n");
	printf("║              BENCHMARK - ALGORITHMES DE TRI                  ║\n");
	printf("╚══════════════════════════════════════════════════════════════╝\n");
	printf("\nTemps en millisecondes (ms)\n\n");
	printf("%-12s | %-10s | %-10s | %-10s | %-10s | %-10s\n",
		"Taille", "Bubble", "Selection", "Insertion", "Quick", "Merge");
	printf("─────────────┼────────────┼────────────┼────────────┼────────────┼────────────\n");
	i = 0;
	while (i < num_sizes)
	{
		arr = generate_random_array(sizes[i]);
		printf("%-12d |", sizes[i]);
		time_ms = benchmark_sort(arr, sizes[i], bubble_sort);
		printf(" %9.2f |", time_ms);
		time_ms = benchmark_sort(arr, sizes[i], selection_sort);
		printf(" %9.2f |", time_ms);
		time_ms = benchmark_sort(arr, sizes[i], insertion_sort);
		printf(" %9.2f |", time_ms);
		time_ms = benchmark_sort_range(arr, sizes[i], quick_sort);
		printf(" %9.2f |", time_ms);
		time_ms = benchmark_sort_range(arr, sizes[i], merge_sort);
		printf(" %9.2f\n", time_ms);
		free(arr);
		i++;
	}
}

void	run_search_benchmarks(void)
{
	int		sizes[] = {10000, 100000, 1000000, 10000000};
	int		num_sizes;
	int		i;
	int		*arr;
	int		target;
	double	time_linear;
	double	time_binary;
	int		iterations;

	num_sizes = 4;
	iterations = 10000;
	printf("\n╔══════════════════════════════════════════════════════════════╗\n");
	printf("║           BENCHMARK - ALGORITHMES DE RECHERCHE               ║\n");
	printf("╚══════════════════════════════════════════════════════════════╝\n");
	printf("\nTemps pour %d recherches (ms)\n\n", iterations);
	printf("%-12s | %-15s | %-15s | %-10s\n",
		"Taille", "Linéaire O(n)", "Binaire O(logn)", "Ratio");
	printf("─────────────┼─────────────────┼─────────────────┼────────────\n");
	i = 0;
	while (i < num_sizes)
	{
		arr = generate_random_array(sizes[i]);
		quick_sort(arr, 0, sizes[i] - 1);
		target = arr[sizes[i] / 2];
		time_linear = benchmark_search(arr, sizes[i], target,
				linear_search, iterations);
		time_binary = benchmark_search(arr, sizes[i], target,
				binary_search, iterations);
		printf("%-12d | %14.2f | %14.2f | %9.0fx\n",
			sizes[i], time_linear, time_binary,
			time_binary > 0 ? time_linear / time_binary : 0);
		free(arr);
		i++;
	}
}

void	print_complexity_table(void)
{
	printf("\n╔══════════════════════════════════════════════════════════════╗\n");
	printf("║              COMPLEXITÉS ALGORITHMIQUES                      ║\n");
	printf("╚══════════════════════════════════════════════════════════════╝\n");
	printf("\n");
	printf("┌─────────────────┬───────────┬───────────┬───────────┬─────────┐\n");
	printf("│ Algorithme      │ Meilleur  │ Moyen     │ Pire      │ Espace  │\n");
	printf("├─────────────────┼───────────┼───────────┼───────────┼─────────┤\n");
	printf("│ Bubble Sort     │ O(n)      │ O(n²)     │ O(n²)     │ O(1)    │\n");
	printf("│ Selection Sort  │ O(n²)     │ O(n²)     │ O(n²)     │ O(1)    │\n");
	printf("│ Insertion Sort  │ O(n)      │ O(n²)     │ O(n²)     │ O(1)    │\n");
	printf("│ Quick Sort      │ O(n logn) │ O(n logn) │ O(n²)     │ O(logn) │\n");
	printf("│ Merge Sort      │ O(n logn) │ O(n logn) │ O(n logn) │ O(n)    │\n");
	printf("├─────────────────┼───────────┼───────────┼───────────┼─────────┤\n");
	printf("│ Linear Search   │ O(1)      │ O(n)      │ O(n)      │ O(1)    │\n");
	printf("│ Binary Search   │ O(1)      │ O(logn)   │ O(logn)   │ O(1)    │\n");
	printf("└─────────────────┴───────────┴───────────┴───────────┴─────────┘\n");
	printf("\n");
	printf("Note: Binary Search nécessite un tableau TRIÉ au préalable.\n");
}

int	main(void)
{
	srand(time(NULL));
	printf("\n╔══════════════════════════════════════════════════════════════╗\n");
	printf("║         JOUR 23 : BENCHMARKS ET OPTIMISATION                 ║\n");
	printf("║         Mesure de performance des algorithmes                ║\n");
	printf("╚══════════════════════════════════════════════════════════════╝\n");
	run_sort_benchmarks();
	run_search_benchmarks();
	print_complexity_table();
	printf("\n╔══════════════════════════════════════════════════════════════╗\n");
	printf("║                    CONCLUSIONS                               ║\n");
	printf("╚══════════════════════════════════════════════════════════════╝\n");
	printf("\n");
	printf("1. Pour PETITS tableaux (< 50) : Insertion Sort est souvent le plus rapide\n");
	printf("2. Pour GRANDS tableaux : Quick Sort ou Merge Sort\n");
	printf("3. Quick Sort : rapide en moyenne, mais O(n²) dans le pire cas\n");
	printf("4. Merge Sort : garanti O(n log n), mais utilise plus de mémoire\n");
	printf("5. Binary Search : ~50,000x plus rapide que Linear Search sur 10M éléments\n");
	printf("\n");
	return (0);
}
