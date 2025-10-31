# 🎯 GUIDE COMPLET SEMAINE 4 - RÉSUMÉ FINAL

## ✅ STATUT FINAL

**Semaine 4 : Projets Avancés & Optimisation**

**Progression finale : ████░░░░░░░░ 20% (Structure prête)**

---

## 📂 STRUCTURE CRÉÉE

### Documentation (3 fichiers) ✅
1. ✅ README_EXOS_Semaine4.md - Guide complet
2. ✅ SEMAINE4_COMPLETE.md - Statut détaillé
3. ✅ GUIDE_COMPLET_S4.md (ce fichier)

### Exercices à créer (~70 fichiers)
- Jour 19 : 6 exercices (fichiers)
- Jour 20 : 6 fichiers (mini-grep)
- Jour 21 : 7 exercices (hash table)
- Jour 22 : 45+ fichiers (libft)
- Jour 23 : 6 exercices (optimisation)
- Jour 24 : 1 projet final

---

## 🎓 COMPÉTENCES À ACQUÉRIR

### ✅ Jour 19 : Fichiers
- open(), close(), read(), write()
- FILE *, fopen(), fread(), fwrite()
- Gestion d'erreurs (errno, perror)
- Modes d'ouverture

### ✅ Jour 20 : Mini-grep
- Recherche dans fichiers
- Parsing d'options (-i, -n, -c, -r)
- Colorisation ANSI
- Architecture modulaire

### ✅ Jour 21 : Hash Table
- Fonction de hachage
- Gestion des collisions (chaînage)
- Insert/Get/Delete
- Redimensionnement dynamique

### ✅ Jour 22 : Libft
- 40+ fonctions de la libc
- Tests exhaustifs
- Bibliothèque statique (.a)
- Zero memory leaks

### ✅ Jour 23 : Optimisation
- Profiling (gprof, callgrind)
- Benchmarks
- Cache-friendly code
- Complexité en pratique

### ✅ Jour 24 : Projet final
- Architecture professionnelle
- Code production-ready
- Documentation complète

---

## 💻 TEMPLATES ET EXEMPLES

### JOUR 19 : Template ft_cat

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 4096

int ft_cat(const char *filename)
{
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Ouvrir le fichier
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (-1);
    }

    // Lire et afficher
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (write(1, buffer, bytes_read) == -1)
        {
            perror("write");
            close(fd);
            return (-1);
        }
    }

    if (bytes_read == -1)
    {
        perror("read");
        close(fd);
        return (-1);
    }

    close(fd);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(2, "Usage: ft_cat <file>\n", 21);
        return (1);
    }

    return (ft_cat(argv[1]));
}
```

### JOUR 20 : Template Mini-grep (structure)

```c
/* minigrep.h */
#ifndef MINIGREP_H
#define MINIGREP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_options
{
    int ignore_case;    // -i
    int line_number;    // -n
    int count_only;     // -c
    int recursive;      // -r
    int color;          // --color
}   t_options;

// search.c
int search_in_file(const char *filename, const char *pattern, t_options *opts);

// options.c
t_options *parse_options(int argc, char **argv, int *pattern_index);

// colors.c
void print_colored(const char *str, const char *pattern);

#endif
```

```c
/* main.c */
#include "minigrep.h"

int main(int argc, char **argv)
{
    t_options *opts;
    int pattern_index;
    int i;
    int matches = 0;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: minigrep [OPTIONS] PATTERN [FILE...]\n");
        return (1);
    }

    opts = parse_options(argc, argv, &pattern_index);
    if (!opts)
        return (1);

    if (pattern_index >= argc)
    {
        fprintf(stderr, "Error: No pattern specified\n");
        free(opts);
        return (1);
    }

    // Recherche dans chaque fichier
    for (i = pattern_index + 1; i < argc; i++)
    {
        matches += search_in_file(argv[i], argv[pattern_index], opts);
    }

    free(opts);
    return (matches > 0 ? 0 : 1);
}
```

### JOUR 21 : Template Hash Table

```c
/* hashtable.h */
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 16
#define LOAD_FACTOR 0.75

typedef struct s_entry
{
    char *key;
    void *value;
    struct s_entry *next;
}   t_entry;

typedef struct s_hashtable
{
    t_entry **buckets;
    size_t size;
    size_t count;
}   t_hashtable;

// Fonctions de base
t_hashtable *hashtable_create(size_t size);
void hashtable_destroy(t_hashtable *ht);

unsigned long hash_function(const char *key, size_t size);

int hashtable_insert(t_hashtable *ht, const char *key, void *value);
void *hashtable_get(t_hashtable *ht, const char *key);
int hashtable_delete(t_hashtable *ht, const char *key);

// Fonction avancée
int hashtable_resize(t_hashtable *ht, size_t new_size);

#endif
```

```c
/* ft_hash_function.c */
#include "hashtable.h"

unsigned long hash_function(const char *key, size_t size)
{
    unsigned long hash = 5381;
    int c;

    // Algorithme djb2
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c

    return (hash % size);
}
```

```c
/* ft_hashtable_create.c */
#include "hashtable.h"

t_hashtable *hashtable_create(size_t size)
{
    t_hashtable *ht;
    size_t i;

    ht = malloc(sizeof(t_hashtable));
    if (!ht)
        return (NULL);

    ht->buckets = calloc(size, sizeof(t_entry *));
    if (!ht->buckets)
    {
        free(ht);
        return (NULL);
    }

    ht->size = size;
    ht->count = 0;

    return (ht);
}
```

### JOUR 22 : Template Libft

```c
/* libft.h */
#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

// Caractères
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);

// Strings
size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
char *ft_strncpy(char *dest, const char *src, size_t n);
char *ft_strcat(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strstr(const char *haystack, const char *needle);
char *ft_strdup(const char *s);

// Mémoire
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_calloc(size_t nmemb, size_t size);

// Conversion
int ft_atoi(const char *nptr);
char *ft_itoa(int n);

// Fonctions supplémentaires
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);

// Listes chaînées
typedef struct s_list
{
    void *content;
    struct s_list *next;
}   t_list;

t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstadd_back(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_lstclear(t_list **lst, void (*del)(void*));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
```

### JOUR 23 : Template Benchmark

```c
/* benchmark_sorts.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *arr, int n);
void quick_sort(int *arr, int low, int high);
void merge_sort(int *arr, int n);

double benchmark_sort(void (*sort_func)(int*, int), int *arr, int n, const char *name)
{
    int *copy = malloc(n * sizeof(int));
    memcpy(copy, arr, n * sizeof(int));

    clock_t start = clock();
    sort_func(copy, n);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s: %.6f seconds\n", name, time_spent);

    free(copy);
    return time_spent;
}

int main(void)
{
    int sizes[] = {100, 1000, 10000};
    int i, j;

    for (i = 0; i < 3; i++)
    {
        int n = sizes[i];
        int *arr = malloc(n * sizeof(int));

        // Remplir avec des nombres aléatoires
        for (j = 0; j < n; j++)
            arr[j] = rand() % 10000;

        printf("\n=== Testing with %d elements ===\n", n);
        benchmark_sort(bubble_sort, arr, n, "Bubble Sort");
        benchmark_sort(quick_sort, arr, n, "Quick Sort");
        benchmark_sort(merge_sort, arr, n, "Merge Sort");

        free(arr);
    }

    return 0;
}
```

---

## 📊 BILAN SEMAINE 4

### Structure prête
- **Documentation** : 3 fichiers MD ✅
- **README complet** : ✅
- **Templates** : Fournis dans ce guide

### À implémenter
- **Exercices** : ~70 fichiers
- **Projets** : 3 projets complets
- **Temps estimé** : 40-54 heures

---

## 🏆 OBJECTIFS FINAUX

À la fin de la Semaine 4 complète, tu maîtriseras :
- ✅ Manipulation complète de fichiers (read/write/FILE*)
- ✅ Projets complexes multi-fichiers
- ✅ Hash tables et structures avancées
- ✅ Bibliothèque complète (40+ fonctions)
- ✅ Optimisation et profiling professionnel
- ✅ Architecture de code production-ready

**Tu seras alors un développeur C compétent et professionnel ! 💪**

---

**Dernière mise à jour** : 31 Octobre 2025
**Auteur** : Manuel ADELE
**Niveau** : Piscine C - Semaine 4
