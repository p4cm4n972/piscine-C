# 📚 SEMAINE 3 : Mémoire & Pointeurs avancés — Piscine C 

## 🎯 Objectifs de la semaine
Maîtriser la gestion mémoire et les structures de données dynamiques en C.

**Thèmes abordés :**
- Allocation dynamique (malloc, free, realloc)
- Listes chaînées (simples et doublement chaînées)
- Structures et types personnalisés
- Split de chaînes et parsing
- Mini-shell (projet intégrateur)
- Projet de gestion mémoire avancée

---

## 📅 Planning hebdomadaire

### JOUR 13 : Allocation dynamique (malloc/free) 🧠
**Durée estimée :** 4-5 heures

L'allocation dynamique permet de créer des structures de taille variable pendant l'exécution.

#### Concepts clés :
- `malloc()` : allocation mémoire
- `free()` : libération mémoire
- `calloc()` : allocation + initialisation à 0
- `realloc()` : redimensionnement
- Fuites mémoire et valgrind
- Segmentation fault et NULL checks

#### Exercices à créer :
1. **ft_malloc_basics.c** - Bases de malloc/free
2. **ft_strdup.c** - Duplication de chaîne avec malloc
3. **ft_range.c** - Créer un tableau d'entiers dynamique
4. **ft_concat.c** - Concaténer deux chaînes avec allocation
5. **challenge_ft_split_whitespaces.c** - Split simple sur espaces
6. **challenge_ft_realloc_safe.c** - Wrapper sécurisé de realloc

---

### JOUR 14 : Listes chaînées 🔗
**Durée estimée :** 5-6 heures

Les listes chaînées sont une structure de données fondamentale.

#### Concepts clés :
- Structure `t_list` avec pointeur `next`
- Création d'un maillon (node)
- Ajout en tête / en queue
- Parcours de liste
- Suppression d'éléments
- Libération complète

#### Exercices à créer :
1. **ft_list_create.c** - Créer un maillon
2. **ft_list_push_front.c** - Ajouter en tête
3. **ft_list_push_back.c** - Ajouter en queue
4. **ft_list_size.c** - Compter les éléments
5. **ft_list_last.c** - Dernier élément
6. **ft_list_at.c** - Élément à l'index n
7. **challenge_ft_list_reverse.c** - Inverser une liste
8. **challenge_ft_list_remove_if.c** - Supprimer selon condition
9. **challenge_ft_list_sort.c** - Trier une liste

---

### JOUR 15 : Structures et types personnalisés 📦
**Durée estimée :** 4-5 heures

Créer des types de données complexes avec `struct` et `typedef`.

#### Concepts clés :
- Définition de structures
- `typedef` pour simplifier
- Structures imbriquées
- Tableaux de structures
- Pointeurs vers structures
- Allocation de structures

#### Exercices à créer :
1. **ft_point.c** - Structure Point (x, y)
2. **ft_stock_str.c** - Structure pour stocker strings
3. **ft_book.c** - Gestion de livres (titre, auteur, année)
4. **ft_student.c** - Gestion d'étudiants avec notes
5. **challenge_ft_btree.c** - Arbre binaire (structure récursive)
6. **challenge_ft_graph.c** - Graphe simple

---

### JOUR 16 : Split et parsing avancé 🔪
**Durée estimée :** 4-5 heures

Parser et découper des chaînes selon des règles complexes.

#### Concepts clés :
- ft_split : découper selon un séparateur
- Compter les mots
- Allocation 2D (char **)
- Gestion des quotes et échappements
- Parsing de commandes

#### Exercices à créer :
1. **ft_split.c** - Split générique avec séparateur
2. **ft_split_multi.c** - Split avec plusieurs séparateurs
3. **ft_split_quotes.c** - Gérer les guillemets
4. **ft_parse_args.c** - Parser des arguments style shell
5. **challenge_ft_csv_parser.c** - Parser un CSV
6. **challenge_ft_json_simple.c** - Parser un JSON très simple

---

### JOUR 17 : Mini-shell (projet) 🐚
**Durée estimée :** 8-10 heures

Créer un mini-shell capable d'exécuter des commandes.

#### Fonctionnalités :
- Afficher un prompt
- Lire une ligne de commande
- Parser la commande (split)
- Exécuter avec `fork()` et `execve()`
- Gérer les built-ins (cd, exit, env)
- Gestion des erreurs

#### Fichiers à créer :
1. **minishell.c** - Programme principal
2. **parser.c** - Parsing de commandes
3. **executor.c** - Exécution des commandes
4. **builtins.c** - Commandes internes
5. **utils.c** - Fonctions utilitaires
6. **Makefile** - Compilation
7. **README.md** - Documentation

---

### JOUR 18 : Projet de gestion mémoire 🎯
**Durée estimée :** 6-8 heures

Projet final : créer un allocateur mémoire simple ou un système de gestion de données.

#### Options de projet :
**Option 1 : Memory Allocator**
- Implémenter un allocateur personnalisé
- Pool de mémoire fixe
- First-fit, Best-fit, Worst-fit
- Statistiques d'utilisation

**Option 2 : Database en mémoire**
- Stockage clé-valeur
- Hash table
- Opérations CRUD
- Sauvegarde/chargement

**Option 3 : Text Editor simple**
- Buffer de lignes en liste chaînée
- Insertion/suppression
- Recherche/remplacement
- Sauvegarde fichier

---

## ✅ Checklist globale Semaine 3

### Allocation dynamique (Jour 13)
- [ ] Comprendre malloc/free/calloc/realloc
- [ ] ft_strdup implémenté
- [ ] ft_range implémenté
- [ ] ft_split_whitespaces fonctionnel
- [ ] Aucune fuite mémoire (valgrind)

### Listes chaînées (Jour 14)
- [ ] Structure t_list définie
- [ ] Création de maillons
- [ ] Ajout en tête et queue
- [ ] Parcours et affichage
- [ ] Suppression d'éléments
- [ ] Libération complète
- [ ] Challenge reverse et sort complétés

### Structures (Jour 15)
- [ ] Structures Point, Book, Student définies
- [ ] Manipulation avec pointeurs
- [ ] Tableaux de structures
- [ ] Challenge arbre binaire exploré

### Split et parsing (Jour 16)
- [ ] ft_split générique fonctionnel
- [ ] Gestion des guillemets
- [ ] Parsing d'arguments
- [ ] Challenge CSV parser

### Mini-shell (Jour 17)
- [ ] Prompt affiché
- [ ] Lecture de commandes
- [ ] Parsing fonctionnel
- [ ] Exécution avec fork/execve
- [ ] Built-ins (cd, exit, env)
- [ ] Gestion d'erreurs

### Projet final (Jour 18)
- [ ] Projet choisi et implémenté
- [ ] Documentation complète
- [ ] Tests exhaustifs
- [ ] Code propre et commenté

---

## 📊 Compétences acquises

À la fin de la Semaine 3, tu maîtriseras :

### Gestion mémoire
- ✅ Allocation dynamique (malloc, calloc, realloc)
- ✅ Libération mémoire (free)
- ✅ Détection de fuites (valgrind)
- ✅ Gestion des erreurs d'allocation

### Structures de données
- ✅ Listes chaînées (simples)
- ✅ Structures personnalisées
- ✅ Arbres binaires (bases)
- ✅ Tableaux 2D dynamiques

### Programmation système
- ✅ fork() et execve()
- ✅ Processus parents/enfants
- ✅ Built-ins shell
- ✅ Variables d'environnement

### Parsing
- ✅ Split de chaînes
- ✅ Gestion des séparateurs
- ✅ Parsing d'arguments
- ✅ Guillemets et échappements

---

## 🎓 Niveau 

Cette semaine 3 correspond au niveau **intermédiaire-avancé ** :

| Notion | Niveau attendu |
|--------|----------------|
| malloc/free | Maîtrise complète |
| Listes chaînées | Manipulation avancée |
| Structures | Création et utilisation |
| Fork/execve | Compréhension et usage |
| Parsing | Niveau shell basique |

---

## ⏱️ Temps total estimé

- **Exercices obligatoires** : 32-40 heures
- **Challenges bonus** : 10-15 heures
- **Total avec bonus** : 42-55 heures

**Rythme conseillé :** 6-8 heures par jour pendant 6 jours

---

## 📚 Ressources recommandées

### Man pages essentielles
```bash
man 3 malloc
man 3 free
man 2 fork
man 2 execve
man 3 getline
```

### Livres
- *Pointers in C* - Kenneth Reek
- *The Linux Programming Interface* - Michael Kerrisk

### Debugging
```bash
# Valgrind pour les fuites mémoire
valgrind --leak-check=full --show-leak-kinds=all ./programme

# GDB pour le debugging
gdb ./programme
(gdb) run
(gdb) backtrace
```

---

## 🚀 Après la Semaine 3

Si tu as terminé, tu es prêt pour :
- **Fichiers** : lecture/écriture avancée
- **Projets complexes** : compilateur, interpréteur
- **Optimisation** : profiling, cache
- **Structures avancées** : hash tables, graphes

---

## 📝 Notes importantes

### Compilation
```bash
gcc -Wall -Wextra -Werror -std=c99 -g fichier.c -o programme
```
Le flag `-g` est important pour le debugging avec gdb.

### Tests avec valgrind
TOUJOURS tester avec valgrind :
```bash
valgrind --leak-check=full ./programme
```
Objectif : "All heap blocks were freed -- no leaks are possible"

### Git
```bash
# Commit régulièrement
git add .
git commit -m "Complete jour13: malloc basics"
```

---

## 🎯 Critères de réussite

Tu as réussi la Semaine 3 si :
- ✅ Aucune fuite mémoire dans tes programmes
- ✅ Tu comprends la différence entre stack et heap
- ✅ Tu sais créer et manipuler des listes chaînées
- ✅ Tu peux parser des commandes shell
- ✅ Ton mini-shell exécute des commandes simples

---

## ⚠️ Erreurs courantes

### 1. Oublier de free
```c
char *str = malloc(100);
// ... utilisation ...
// OUBLI DE free(str); ❌
```

### 2. Utiliser après free
```c
char *str = malloc(100);
free(str);
printf("%s", str); // ❌ Use after free
```

### 3. Double free
```c
free(ptr);
free(ptr); // ❌ Double free
```

### 4. Déréférencer NULL
```c
char *str = malloc(100);
if (!str) // ✅ Toujours vérifier
    return NULL;
```

---

**Bon courage ! La Semaine 3 est intense mais c'est là que tu deviens vraiment à l'aise avec le C. 💪**
