/*
 * memory_manager.h - Memory Manager Header
 */

#ifndef MEMORY_MANAGER_H
# define MEMORY_MANAGER_H

# include <stddef.h>
# include <stdint.h>

# define POOL_SIZE 65536  // 64KB par défaut
# define ALIGNMENT 8      // Alignement sur 8 bytes

// Structure du header de bloc
typedef struct s_block_header
{
	size_t					size;        // Taille du bloc (sans header)
	int						is_free;     // 1 si libre, 0 si utilisé
	struct s_block_header	*next;       // Prochain bloc libre
}	t_block_header;

// Structure du memory manager
typedef struct s_memory_manager
{
	void				*pool;           // Pointeur vers le pool
	size_t				pool_size;       // Taille totale du pool
	t_block_header		*free_list;      // Liste des blocs libres
	size_t				allocated;       // Mémoire allouée
	size_t				freed;           // Mémoire libérée
	int					alloc_count;     // Nombre d'allocations
	int					free_count;      // Nombre de libérations
}	t_memory_manager;

// Initialisation et destruction
int		mm_init(size_t size);
void	mm_destroy(void);

// Allocation et libération
void	*mm_alloc(size_t size);
void	mm_free(void *ptr);

// Statistiques
void	mm_stats(void);
int		mm_check_leaks(void);

// Utilitaires
size_t	mm_align(size_t size);

#endif
