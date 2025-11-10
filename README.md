# 🚀 Piscine C

> **Formation intensive en programmation système et algorithmique C**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Progress](https://img.shields.io/badge/Progress-85%25-brightgreen)](https://github.com/p4cm4n972/piscine-C)

---

## 📖 À propos du projet

Ce repository contient une formation intensive et auto-dirigée en programmation C, axée sur :
- **Algorithmique** : tri, recherche, récursion, optimisation
- **Structures de données** : tableaux, listes chaînées, hash tables, arbres
- **Gestion mémoire** : malloc/free, pointeurs, valgrind
- **Programmation système** : fork, exec, pipes, signals

**Objectif** : Maîtriser les fondamentaux de la programmation bas-niveau et renforcer les compétences en algorithmique.

**Durée** : ~120 heures de formation intensive (4 semaines)
**Statut** : 85% complété | ~9000 lignes de code | 70+ exercices

---

## 🎯 Compétences Acquises

### Compétences Principales

| Domaine | Compétences Développées | Exercices |
|---------|------------------------|-----------|
| **Algorithmique** | Tri (Bubble, Quick, Merge), Recherche (linéaire, binaire), Récursion, Complexité Big O | 35 exercices |
| **Structures de données** | Tableaux, listes chaînées, hash tables, arbres binaires | 18 implémentations |
| **Gestion mémoire** | malloc/free, pointeurs, valgrind, détection fuites mémoire | 45+ programmes |
| **Programmation système** | fork, exec, pipes, signals, processus | Mini-shell |
| **Chaînes de caractères** | Manipulation, parsing, conversion | 20 exercices |
| **Debugging** | GDB, Valgrind, profiling | 70+ programmes |
| **Build & Tooling** | Makefile, compilation, flags GCC | 8 Makefiles |

---

## 📁 Structure du Projet

```
piscine-C/
├── Semaine1/
│   ├── jour01/              # Bases C (variables, types, conditions)
│   ├── jour02/              # Boucles et fonctions
│   ├── jour03/              # Récursion et optimisation
│   ├── jour04/              # Pointeurs et tableaux
│   ├── jour05/              # Makefile & Git
│   └── jour06/              # Libft (bibliothèque personnelle)
│
├── Semaine2/
│   ├── jour07/              # Allocation dynamique
│   ├── jour08/              # Listes chaînées
│   ├── jour09/              # Hash tables
│   └── jour10/              # Arbres binaires
│
├── Semaine3/
│   ├── jour11/              # Programmation système (fork, exec)
│   ├── jour12/              # Pipes et signaux
│   └── jour13/              # Mini-shell
│
├── Semaine4/
│   ├── jour14/              # Parsing et arguments
│   ├── jour15/              # Fichiers et I/O
│   └── projet-final/        # Mini-grep, benchmarks
│
└── README.md                # Ce fichier
```

---

## 🏆 Semaines Réalisées

### Semaine 1 : Fondamentaux C ✅ 100%

#### Jour 01 : Bases de C
**Description** : Variables, types de données, opérateurs, conditions

**Exercices** :
- ex00 : Hello World
- ex01 : Variables et types (int, char, float)
- ex02 : Opérateurs arithmétiques (+, -, *, /, %)
- ex03 : Conditions (if/else, switch)
- ex04 : Opérateurs logiques (&&, ||, !)

**Compétences acquises** :
- ✅ Compilation avec GCC
- ✅ Types de données en C
- ✅ Structures de contrôle
- ✅ Format d'affichage (printf)

---

#### Jour 02 : Boucles et Fonctions
**Description** : for, while, do-while, fonctions personnalisées

**Exercices** :
- ex00 : Boucle for (affichage 1-100)
- ex01 : Boucle while (factorielle)
- ex02 : do-while (menu interactif)
- ex03 : Fonctions simples (ft_add, ft_sub)
- ex04 : Prototypes et headers

**Compétences acquises** :
- ✅ Boucles (for, while, do-while)
- ✅ Création de fonctions
- ✅ Prototypes et headers
- ✅ Passage de paramètres

**Exemple de code** :
```c
// Factorielle itérative
int ft_factorial(int n) {
    int result = 1;
    int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}
```

---

#### Jour 03 : Récursion ✅ 100%
**Description** : Fonctions récursives et optimisation

**Exercices réalisés** :
- ✅ `ft_factorial.c` - Factorielle récursive
- ✅ `ft_power.c` - Puissance (x^n)
- ✅ `ft_sqrt.c` - Racine carrée (méthode de Newton)
- ✅ `ft_is_prime.c` - Test de primalité (optimisé √n)
- ✅ `challenge_ft_find_next_prime.c` - Prochain nombre premier

**Compétences acquises** :
- ✅ Récursion simple et double
- ✅ Optimisation algorithmique (√n pour nombres premiers)
- ✅ Cas de base et récursion terminale
- ✅ Analyse de complexité

**Exemple de code** :
```c
// Test de primalité optimisé
int ft_is_prime(int nb) {
    int i;

    if (nb < 2)
        return 0;
    if (nb == 2)
        return 1;
    if (nb % 2 == 0)
        return 0;

    i = 3;
    while (i * i <= nb) {  // Optimisation : √n au lieu de n
        if (nb % i == 0)
            return 0;
        i += 2;
    }
    return 1;
}
// Complexité : O(√n)
```

**Connexions avec JavaScript** :
```javascript
// Équivalent JS avec optimisation similaire
function isPrime(n) {
    if (n < 2) return false;
    if (n === 2) return true;
    if (n % 2 === 0) return false;

    for (let i = 3; i * i <= n; i += 2) {
        if (n % i === 0) return false;
    }
    return true;
}
```

---

#### Jour 04 : Pointeurs et Tableaux ✅ 100%
**Description** : Manipulation de pointeurs et tableaux

**Exercices réalisés** :
- ✅ `ft_swap.c` - Échange de valeurs avec pointeurs
- ✅ `ft_sort_int_tab.c` - Tri à bulles (Bubble Sort)
- ✅ `ft_rev_int_tab.c` - Inversion de tableau (Two Pointers)
- ✅ `challenge_ft_max.c` - Maximum dans un tableau

**Compétences acquises** :
- ✅ Pointeurs (* et &)
- ✅ Arithmétique de pointeurs
- ✅ Tableaux et parcours
- ✅ Pattern Two Pointers

**Exemple de code** :
```c
// Two Pointers pour inversion de tableau
void ft_rev_int_tab(int *tab, int size) {
    int i = 0;
    int tmp;

    while (i < size / 2) {
        tmp = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - 1 - i] = tmp;
        i++;
    }
}
// Complexité : O(n/2) = O(n), Space O(1)
```

**Connexions avec JavaScript** :
```javascript
// Two Pointers en JS
function reverseArray(arr) {
    let left = 0, right = arr.length - 1;
    while (left < right) {
        [arr[left], arr[right]] = [arr[right], arr[left]];
        left++;
        right--;
    }
    return arr;
}
```

---

#### Jour 05 : Makefile & Git ✅ 100%
**Description** : Automatisation de la compilation et gestion de versions

**Exercices réalisés** :
- ✅ Makefile simple avec règles (all, clean, fclean, re)
- ✅ Compilation avec flags (-Wall -Wextra -Werror)
- ✅ Variables Makefile ($@, $<, $^)
- ✅ Gestion Git (commit, push, branches)

**Compétences acquises** :
- ✅ Écriture de Makefiles
- ✅ Flags de compilation GCC
- ✅ Dépendances et recompilation
- ✅ Git (conventional commits)

**Exemple de Makefile** :
```makefile
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_strlen.c ft_strcpy.c ft_strcmp.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

---

#### Jour 06 : Libft (Bibliothèque personnelle) ✅ 100%
**Description** : Recréation de fonctions standard de la libc

**Fonctions implémentées** :
```c
// Strings
ft_strlen()     // Longueur d'une chaîne
ft_strcpy()     // Copie de chaîne
ft_strncpy()    // Copie avec limite
ft_strcmp()     // Comparaison
ft_strcat()     // Concaténation
ft_strdup()     // Duplication avec malloc

// Memory
ft_memset()     // Remplissage mémoire
ft_bzero()      // Mise à zéro
ft_memcpy()     // Copie mémoire
ft_memcmp()     // Comparaison mémoire

// Conversion
ft_atoi()       // String to int
ft_itoa()       // Int to string

// Character checks
ft_isalpha()    // Test alphabétique
ft_isdigit()    // Test chiffre
ft_isalnum()    // Test alphanumérique
```

**Compétences acquises** :
- ✅ Manipulation de chaînes de caractères
- ✅ Gestion mémoire (malloc, free)
- ✅ Création de bibliothèque statique (.a)
- ✅ Documentation et tests

**Exemple de code** :
```c
// ft_strdup - Duplication avec allocation
char *ft_strdup(const char *s) {
    char *dup;
    int len = 0;
    int i;

    // Calcul de la longueur
    while (s[len])
        len++;

    // Allocation
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return NULL;

    // Copie
    i = 0;
    while (i < len) {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';

    return dup;
}
```

---

### Semaine 2 : Structures de Données ✅ 80%

#### Jour 07 : Allocation Dynamique ✅ 100%
**Description** : malloc, free, calloc, realloc

**Exercices réalisés** :
- ✅ Allocation simple (malloc/free)
- ✅ Tableaux dynamiques
- ✅ Matrices 2D
- ✅ Gestion d'erreurs (NULL checks)
- ✅ Détection de fuites (Valgrind)

**Compétences acquises** :
- ✅ malloc() et free()
- ✅ Gestion d'erreurs d'allocation
- ✅ Valgrind pour détecter les leaks
- ✅ Tableaux dynamiques redimensionnables

**Exemple de code** :
```c
// Allocation d'un tableau dynamique
int *create_array(int size) {
    int *arr;
    int i;

    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return NULL;  // Gestion d'erreur

    // Initialisation
    i = 0;
    while (i < size) {
        arr[i] = 0;
        i++;
    }

    return arr;
}

// Usage avec vérification
int main() {
    int *arr = create_array(100);
    if (!arr) {
        printf("Allocation failed\n");
        return 1;
    }

    // Utilisation...

    free(arr);  // Libération obligatoire
    return 0;
}
```

**Détection de fuites avec Valgrind** :
```bash
gcc -g program.c -o program
valgrind --leak-check=full ./program

# Résultat attendu :
# All heap blocks were freed -- no leaks are possible
```

---

#### Jour 08 : Listes Chaînées ✅ 100%
**Description** : Implémentation complète de linked lists

**Structure de base** :
```c
typedef struct s_list {
    int data;
    struct s_list *next;
} t_list;
```

**Opérations implémentées** :
- ✅ `ft_create_node()` - Création d'un nœud
- ✅ `ft_list_push_front()` - Insertion en tête
- ✅ `ft_list_push_back()` - Insertion en queue
- ✅ `ft_list_size()` - Taille de la liste
- ✅ `ft_list_at()` - Accès par index
- ✅ `ft_list_remove_if()` - Suppression conditionnelle
- ✅ `ft_list_reverse()` - Inversion de la liste
- ✅ `ft_list_sort()` - Tri (Bubble Sort)
- ✅ `ft_list_clear()` - Libération mémoire

**Compétences acquises** :
- ✅ Structures chaînées
- ✅ Manipulation de pointeurs complexes
- ✅ Gestion mémoire dynamique
- ✅ Algorithmes sur listes

**Exemple de code** :
```c
// Création d'un nœud
t_list *ft_create_node(int data) {
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insertion en tête O(1)
void ft_list_push_front(t_list **head, int data) {
    t_list *new_node;

    new_node = ft_create_node(data);
    if (!new_node)
        return;

    new_node->next = *head;
    *head = new_node;
}

// Inversion de liste (Two Pointers)
void ft_list_reverse(t_list **head) {
    t_list *prev = NULL;
    t_list *current = *head;
    t_list *next;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}
// Complexité : O(n), Space O(1)
```

**Connexions avec JavaScript** :
```javascript
// Équivalent en JavaScript
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    pushFront(data) {
        const newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
    }

    reverse() {
        let prev = null;
        let current = this.head;
        while (current) {
            const next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        this.head = prev;
    }
}
```

---

#### Jour 09 : Hash Tables 🔄 60%
**Description** : Implémentation d'une table de hachage

**Structure de base** :
```c
#define TABLE_SIZE 100

typedef struct s_entry {
    char *key;
    int value;
    struct s_entry *next;  // Gestion des collisions
} t_entry;

typedef struct s_hashtable {
    t_entry *table[TABLE_SIZE];
} t_hashtable;
```

**Fonctions implémentées** :
- ✅ `hash_function()` - Fonction de hachage (djb2)
- ✅ `ht_create()` - Création de la table
- ✅ `ht_insert()` - Insertion avec gestion collisions
- ✅ `ht_search()` - Recherche O(1) moyen
- 🔄 `ht_delete()` - Suppression (en cours)

**Compétences acquises** :
- ✅ Fonction de hachage
- ✅ Gestion des collisions (chaînage)
- ✅ Complexité O(1) amortie

**Exemple de code** :
```c
// Fonction de hachage djb2
unsigned long hash_function(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c

    return hash % TABLE_SIZE;
}

// Insertion avec gestion des collisions
void ht_insert(t_hashtable *ht, const char *key, int value) {
    unsigned long index = hash_function(key);
    t_entry *new_entry = create_entry(key, value);

    // Collision : chaînage
    new_entry->next = ht->table[index];
    ht->table[index] = new_entry;
}
```

---

#### Jour 10 : Arbres Binaires 🔄 50%
**Description** : Introduction aux arbres binaires de recherche (BST)

**Structure de base** :
```c
typedef struct s_tree {
    int data;
    struct s_tree *left;
    struct s_tree *right;
} t_tree;
```

**Opérations en cours** :
- ✅ `tree_create_node()` - Création d'un nœud
- ✅ `tree_insert()` - Insertion BST
- ✅ `tree_search()` - Recherche O(log n)
- 🔄 `tree_inorder()` - Parcours in-order
- 🔄 `tree_delete()` - Suppression

---

### Semaine 3 : Programmation Système 🔄 60%

#### Jour 11 : Processus (fork, exec) 🔄 70%
**Description** : Création et gestion de processus

**Exercices réalisés** :
- ✅ `fork()` - Création de processus enfant
- ✅ `exec()` - Remplacement de processus
- ✅ `wait()` - Attente de terminaison
- 🔄 `getpid()`, `getppid()` - Identifiants processus

**Compétences acquises** :
- ✅ Création de processus
- ✅ Communication parent/enfant
- ✅ Codes de retour

**Exemple de code** :
```c
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Erreur
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Processus enfant
        printf("Child process (PID: %d)\n", getpid());
        execlp("/bin/ls", "ls", "-l", NULL);
        perror("exec failed");
        return 1;
    } else {
        // Processus parent
        printf("Parent process (PID: %d), child PID: %d\n", getpid(), pid);
        wait(NULL);  // Attente de l'enfant
        printf("Child terminated\n");
    }

    return 0;
}
```

---

#### Jour 12 : Pipes et Signaux 🔄 50%
**Description** : Communication inter-processus

**Concepts abordés** :
- ✅ `pipe()` - Communication unidirectionnelle
- 🔄 `signal()` - Gestion de signaux (SIGINT, SIGTERM)
- 🔄 Redirections (stdin, stdout, stderr)

---

#### Jour 13 : Mini-Shell 🔄 60%
**Description** : Implémentation d'un shell basique

**Fonctionnalités implémentées** :
- ✅ Parsing de commandes
- ✅ Exécution avec `fork()` et `exec()`
- ✅ Commandes built-in (cd, exit)
- 🔄 Redirections (>, <)
- 🔄 Pipes (|)

**Exemple de code** :
```c
// Boucle principale du shell
void shell_loop() {
    char *line;
    char **args;
    int status = 1;

    while (status) {
        printf("minishell> ");
        line = read_line();
        args = parse_line(line);
        status = execute(args);

        free(line);
        free(args);
    }
}
```

---

### Semaine 4 : Projets Avancés 🔄 40%

#### Projet : Mini-Grep 🔄 60%
**Description** : Implémentation simplifiée de grep

**Fonctionnalités** :
- ✅ Recherche de motif dans un fichier
- ✅ Affichage des lignes correspondantes
- 🔄 Options (-i, -n, -v)

---

#### Projet : Benchmarks et Optimisation 🔄 30%
**Description** : Comparaison de performances algorithmiques

**Comparaisons réalisées** :
- ✅ Tri : Bubble Sort vs Quick Sort vs Merge Sort
- 🔄 Recherche : Linéaire vs Binaire
- 🔄 Allocation : Stack vs Heap

---

## 📊 Métriques du Projet

### Volume de Code
```
📁 Semaines réalisées   : 3.5 / 4 semaines
📝 Lignes de code       : ~9000 lignes C
📚 Documentation        : 15+ fichiers README
🎯 Exercices résolus    : 70+ exercices
🚀 Projets              : 5 projets (libft, mini-shell, mini-grep, etc.)
⏱️  Temps investi        : ~120 heures
```

### Qualité
```
✅ Compilation          : 0 warnings avec -Wall -Wextra -Werror
✅ Memory leaks         : 0 leaks détectés (Valgrind)
✅ Tests                : 70+ programmes testés et validés
✅ Git commits          : 35+ commits structurés
✅ Normes               : Respect des conventions C
```

### Algorithmes Implémentés

| Algorithme | Complexité | Fichier |
|------------|-----------|---------|
| Bubble Sort | O(n²) | `ft_bubble_sort.c` |
| Quick Sort | O(n log n) | `ft_quick_sort.c` |
| Merge Sort | O(n log n) | `ft_merge_sort.c` |
| Binary Search | O(log n) | `ft_binary_search.c` |
| Two Pointers | O(n) | `ft_rev_int_tab.c` |
| Récursion | Varie | `ft_factorial.c`, `ft_power.c` |
| Liste chaînée | O(1)-O(n) | `jour08/*.c` |
| Hash Table | O(1) moyen | `jour09/hashtable.c` |

---

## 🚀 Comment Utiliser ce Repository

### Prérequis

```bash
# GCC compiler
gcc --version  # Minimum : GCC 7.0

# Valgrind (détection fuites mémoire)
sudo apt-get install valgrind

# GDB (debugging)
sudo apt-get install gdb

# Make
sudo apt-get install make
```

### Compilation

```bash
# Cloner le repository
git clone https://github.com/p4cm4n972/piscine-C.git
cd piscine-C

# Compiler un exercice
cd Semaine1/jour03
gcc -Wall -Wextra -Werror ft_is_prime.c -o ft_is_prime
./ft_is_prime

# Compiler avec Makefile (libft)
cd Semaine1/jour06
make
# Crée libft.a

# Tester avec Valgrind
valgrind --leak-check=full ./program
```

### Debugging avec GDB

```bash
# Compiler avec symboles de debug
gcc -g program.c -o program

# Lancer GDB
gdb ./program

# Commandes GDB utiles
(gdb) break main       # Point d'arrêt
(gdb) run             # Exécuter
(gdb) next            # Ligne suivante
(gdb) print var       # Afficher variable
(gdb) backtrace       # Call stack
```

---

## 🎓 Compétences Transférables

Les compétences acquises dans ce projet sont directement applicables à :

### Développement Backend Performant
- Gestion mémoire efficace (éviter les leaks)
- Optimisation d'algorithmes (comprendre O(n))
- Structures de données adaptées
- Profiling et debugging

### Algorithmique Avancée
- Tri et recherche optimisés
- Patterns (Two Pointers, Recursion)
- Analyse de complexité
- Trade-offs mémoire/vitesse

### Programmation Système
- Processus et threads
- Communication inter-processus
- Gestion de la mémoire bas-niveau
- Debugging avancé

### JavaScript/Node.js
- Compréhension des performances V8
- Optimisation de boucles
- Choix de structures de données
- Memory profiling

---

## 📚 Ressources et Références

### Livres
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language) - Kernighan & Ritchie
- [C Programming: A Modern Approach](http://knking.com/books/c2/)

### Outils
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [Valgrind Documentation](https://valgrind.org/docs/)
- [GDB Tutorial](https://www.gnu.org/software/gdb/documentation/)

### Algorithmique
- [VisuAlgo](https://visualgo.net/) - Visualisation d'algorithmes
- [BigO Cheat Sheet](https://www.bigocheatsheet.com/)
- [GeeksforGeeks - Data Structures](https://www.geeksforgeeks.org/data-structures/)

### Programmation Système
- [Beej's Guide to Unix IPC](https://beej.us/guide/bgipc/)
- [Linux System Programming](https://www.oreilly.com/library/view/linux-system-programming/9781449341527/)

---

## 📈 Progression

### Statut Actuel : 85% Complété

**✅ Semaines Complètes**
- [x] Semaine 1 - Fondamentaux C (100%)
  - [x] Jour 01 - Bases (100%)
  - [x] Jour 02 - Boucles et fonctions (100%)
  - [x] Jour 03 - Récursion (100%)
  - [x] Jour 04 - Pointeurs (100%)
  - [x] Jour 05 - Makefile & Git (100%)
  - [x] Jour 06 - Libft (100%)

**🔄 Semaines En Cours**
- [x] Semaine 2 - Structures de données (80%)
  - [x] Jour 07 - Allocation dynamique (100%)
  - [x] Jour 08 - Listes chaînées (100%)
  - [ ] Jour 09 - Hash tables (60%)
  - [ ] Jour 10 - Arbres binaires (50%)

- [ ] Semaine 3 - Programmation système (60%)
  - [ ] Jour 11 - fork/exec (70%)
  - [ ] Jour 12 - Pipes et signaux (50%)
  - [ ] Jour 13 - Mini-shell (60%)

- [ ] Semaine 4 - Projets avancés (40%)
  - [ ] Mini-grep (60%)
  - [ ] Benchmarks (30%)

**⏳ Prochaines Étapes**
- Compléter les arbres binaires (BST)
- Finaliser le mini-shell avec pipes
- Ajouter tests unitaires automatisés
- Benchmarks de performance détaillés

---

## 🔗 Connexions avec JavaScript

Ce projet renforce mes compétences JavaScript en :

### Algorithmes
```c
// C - Quick Sort
void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
```

```javascript
// JavaScript - Quick Sort
function quickSort(arr, low = 0, high = arr.length - 1) {
    if (low < high) {
        const pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    return arr;
}
```

### Structures de Données
```c
// C - Linked List Node
typedef struct s_list {
    int data;
    struct s_list *next;
} t_list;
```

```javascript
// JavaScript - Linked List Node
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}
```

### Patterns Communs
- Two Pointers (inversion, palindrome)
- Recursion (factorial, fibonacci)
- Hash Tables (Map en JS)
- Binary Search (sur Array.sort())

---

## 👤 Auteur

**Manuel ADELE**
- GitHub: [@P4cm4n972](https://github.com/P4cm4n972)
- LinkedIn: [Manuel ADELE](https://linkedin.com/in/manuel-adele)
- Email: manuel.adele@gmail.com

Software Engineer Full-Stack avec 6 ans d'expérience, renforçant ses compétences en programmation bas-niveau et algorithmique.

---

## 📄 License

MIT © Manuel ADELE

---

## 🙏 Remerciements

Ce projet de formation s'inspire de :
- Piscine C de l'école 42
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language) (K&R)
- Ressources GeeksforGeeks et StackOverflow
- Communauté C et algorithmique

---

**Dernière mise à jour** : Novembre 2024
**Version** : 1.0
**Statut** : En cours (85%)
