# Jour 23 - Optimisation & Performance

## Objectif

Apprendre à optimiser du code C et mesurer les performances.

## Exercices

### Mesure de performance (3 fichiers)
- ft_benchmark.c - Mesurer le temps d'exécution
- ft_profiling.c - Profiler une fonction
- challenge_compare_algos.c - Comparer différents algorithmes

### Optimisation mémoire (3 fichiers)
- ft_memory_pool.c - Pool de mémoire réutilisable
- ft_cache_friendly.c - Code optimisé pour le cache
- challenge_bit_manipulation.c - Optimisations bit à bit

### Optimisation algorithmique (3 fichiers)
- ft_fast_search.c - Recherche binaire vs linéaire
- ft_loop_optimization.c - Optimisation de boucles
- challenge_simd.c - Vectorisation simple

## Compilation

```bash
gcc -Wall -Wextra -Werror -O0 file.c -o prog_O0  # Sans optimisation
gcc -Wall -Wextra -Werror -O2 file.c -o prog_O2  # Avec optimisation
gcc -Wall -Wextra -Werror -O3 file.c -o prog_O3  # Optimisation max

# Profiling
gcc -Wall -Wextra -Werror -pg file.c -o prog
./prog
gprof prog gmon.out > analysis.txt
```

## Outils de mesure

```c
#include <time.h>

clock_t start = clock();
// ... code à mesurer ...
clock_t end = clock();
double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
printf("Time: %.6f seconds\n", time_spent);
```

**Temps estimé**: 5-6 heures
**Difficulté**: ⭐⭐⭐⭐
