# 📚 SEMAINE 4 : Projets avancés & Optimisation — Piscine C 

## 🎯 Objectifs de la semaine
Mettre en pratique toutes les compétences acquises dans des projets complets de niveau professionnel.

**Thèmes abordés :**
- Manipulation avancée de fichiers (read, write, parsing)
- Projet mini-grep (recherche dans fichiers)
- Hash tables (structures de données avancées)
- Recréation de fonctions de la libc
- Optimisation et profiling
- Projet final intégrant tous les concepts

---

## 📅 Planning hebdomadaire

### JOUR 19 : Manipulation de fichiers 📄
**Durée estimée :** 4-5 heures

Maîtriser les opérations d'entrée/sortie sur fichiers.

#### Concepts clés :
- `open()`, `close()`, `read()`, `write()`
- Descripteurs de fichiers (file descriptors)
- Gestion d'erreurs (errno, perror)
- Modes d'ouverture (O_RDONLY, O_WRONLY, O_RDWR, O_CREAT, O_APPEND)
- fopen, fread, fwrite, fclose (FILE *)

#### Exercices à créer :
1. **ft_cat.c** - Afficher le contenu d'un fichier
2. **ft_wc.c** - Compter lignes, mots, caractères
3. **ft_cp.c** - Copier un fichier
4. **ft_tail.c** - Afficher les n dernières lignes
5. **challenge_ft_hexdump.c** - Affichage hexadécimal
6. **challenge_ft_file_search.c** - Rechercher un pattern

---

### JOUR 20 : Projet mini-grep 🔍
**Durée estimée :** 8-10 heures

Recréer une version simplifiée de grep (recherche de motifs dans fichiers).

#### Fonctionnalités :
- Rechercher un pattern dans un ou plusieurs fichiers
- Options : -i (insensible casse), -n (numéros de lignes), -c (comptage)
- Recherche récursive dans répertoires (-r)
- Expressions régulières simples (bonus)
- Colorisation de la sortie

#### Fichiers à créer :
1. **minigrep.c** - Programme principal
2. **search.c** - Logique de recherche
3. **options.c** - Parsing des options
4. **colors.c** - Colorisation ANSI
5. **Makefile** - Compilation
6. **README.md** - Documentation

---

### JOUR 21 : Hash Table 🗂️
**Durée estimée :** 6-8 heures

Implémenter une table de hachage (structure de données O(1) en moyenne).

#### Concepts clés :
- Fonction de hachage
- Gestion des collisions (chaînage)
- Load factor et redimensionnement
- Hash table générique

#### Exercices à créer :
1. **ft_hash_function.c** - Fonction de hachage
2. **ft_hashtable_create.c** - Créer une table
3. **ft_hashtable_insert.c** - Insérer un élément
4. **ft_hashtable_get.c** - Récupérer un élément
5. **ft_hashtable_delete.c** - Supprimer un élément
6. **challenge_ft_hashtable_resize.c** - Redimensionnement automatique
7. **challenge_dictionary.c** - Dictionnaire avec hash table

---

### JOUR 22 : Projet libft (libc personnalisée) 📚
**Durée estimée :** 8-10 heures

Créer une bibliothèque complète avec toutes les fonctions importantes de la libc.

#### Catégories de fonctions :
**Manipulation de caractères :**
- ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint
- ft_toupper, ft_tolower

**Manipulation de chaînes :**
- ft_strlen, ft_strcpy, ft_strncpy, ft_strcat, ft_strncat
- ft_strcmp, ft_strncmp, ft_strchr, ft_strrchr, ft_strstr
- ft_strdup, ft_substr, ft_strjoin, ft_strtrim, ft_split

**Manipulation de mémoire :**
- ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp
- ft_calloc

**Conversion :**
- ft_atoi, ft_itoa

**Listes chaînées :**
- ft_lstnew, ft_lstadd_front, ft_lstadd_back
- ft_lstsize, ft_lstlast, ft_lstdelone, ft_lstclear
- ft_lstiter, ft_lstmap

---

### JOUR 23 : Optimisation & Profiling ⚡
**Durée estimée :** 4-6 heures

Apprendre à mesurer et optimiser les performances.

#### Concepts clés :
- Profiling avec gprof et valgrind --tool=callgrind
- Complexité algorithmique en pratique
- Cache-friendly code
- Optimisations du compilateur (-O2, -O3)

#### Exercices à créer :
1. **benchmark_sorts.c** - Comparer les algorithmes de tri
2. **benchmark_search.c** - Comparer linéaire vs binaire
3. **cache_test.c** - Impact du cache
4. **memory_pool.c** - Pool d'allocation optimisé
5. **challenge_fast_strlen.c** - strlen SIMD
6. **challenge_profiling.c** - Analyse avec gprof

---

### JOUR 24 : Projet final libre 🎯
**Durée estimée :** 10-15 heures

Projet au choix parmi plusieurs options avancées.

#### Option 1 : Mini-compilateur d'expressions
- Parser d'expressions arithmétiques
- Arbre syntaxique abstrait (AST)
- Évaluateur d'expressions
- Variables et fonctions

#### Option 2 : Gestionnaire de base de données
- Stockage clé-valeur sur fichier
- Index avec B-tree ou hash table
- Transactions ACID (simple)
- Interface CLI

#### Option 3 : Mini-serveur HTTP
- Socket programming
- Parsing de requêtes HTTP
- Serveur de fichiers statiques
- CGI basique

#### Option 4 : Text Editor avancé
- Buffer gap ou rope
- Undo/redo
- Recherche et remplacement
- Coloration syntaxique

---

## ✅ Checklist globale Semaine 4

### Fichiers (Jour 19)
- [ ] ft_cat fonctionnel
- [ ] ft_wc compte correctement
- [ ] ft_cp copie sans corruption
- [ ] Gestion d'erreurs complète

### Mini-grep (Jour 20)
- [ ] Recherche dans fichiers
- [ ] Options -i, -n, -c implémentées
- [ ] Recherche récursive (-r)
- [ ] Colorisation de sortie

### Hash Table (Jour 21)
- [ ] Fonction de hachage efficace
- [ ] Insert/Get/Delete fonctionnels
- [ ] Gestion des collisions
- [ ] Tests de performance

### Libft (Jour 22)
- [ ] 40+ fonctions implémentées
- [ ] Tests exhaustifs
- [ ] Bibliothèque statique (.a)
- [ ] Aucune fuite mémoire

### Optimisation (Jour 23)
- [ ] Benchmarks effectués
- [ ] Profiling avec gprof
- [ ] Optimisations mesurées
- [ ] Documentation des résultats

### Projet final (Jour 24)
- [ ] Projet choisi et implémenté
- [ ] Architecture propre
- [ ] Documentation complète
- [ ] Tests et validation

---

## 📊 Compétences acquises

À la fin de la Semaine 4, tu maîtriseras :

### Systèmes de fichiers
- ✅ Lecture/écriture avec read/write
- ✅ FILE * et fonctions stdio
- ✅ Gestion d'erreurs système

### Structures de données avancées
- ✅ Hash tables
- ✅ Arbres (BST, B-tree)
- ✅ Structures optimisées

### Projets complets
- ✅ Architecture modulaire
- ✅ Makefile complexe
- ✅ Documentation professionnelle

### Performance
- ✅ Profiling et mesures
- ✅ Optimisation algorithmique
- ✅ Cache et mémoire

---

## 🎓 Niveau 

Cette semaine 4 correspond au niveau **avancé/expert ** :

| Notion | Niveau attendu |
|--------|----------------|
| Fichiers | Maîtrise complète |
| Hash tables | Implémentation from scratch |
| Projets | Niveau professionnel |
| Optimisation | Compréhension approfondie |
| Code quality | Production-ready |

---

## ⏱️ Temps total estimé

- **Exercices obligatoires** : 40-54 heures
- **Challenges bonus** : 15-20 heures
- **Total avec bonus** : 55-74 heures

**Rythme conseillé :** 8-10 heures par jour pendant 6 jours

---

## 📚 Ressources recommandées

### Man pages essentielles
```bash
man 2 open
man 2 read
man 2 write
man 3 fopen
man 3 fread
```

### Livres
- *Advanced Programming in the UNIX Environment* - Stevens
- *The Art of Computer Programming* - Knuth (pour les algorithmes)

### Outils
```bash
# Profiling
gprof ./programme
valgrind --tool=callgrind ./programme
kcachegrind callgrind.out.*

# Performance
time ./programme
perf stat ./programme
```

---

## 🎯 Objectif final de la Piscine

À la fin des 4 semaines, tu auras :
- ✅ Maîtrise complète du C
- ✅ Compréhension profonde de la mémoire
- ✅ Capacité à créer des projets complexes
- ✅ Rigueur d'ingénieur 
- ✅ Portfolio de projets en C

---

## 🏆 Critères de validation finale

Tu as réussi la Piscine C si :
- ✅ Tous les projets compilent sans erreur ni warning
- ✅ Aucune fuite mémoire (valgrind clean)
- ✅ Tu peux expliquer chaque ligne de code
- ✅ Tes projets sont bien architecturés
- ✅ Tu es prêt à coder en C professionnel

---

**Félicitations d'avoir atteint la Semaine 4 ! C'est l'aboutissement de ton parcours Piscine. 🎉**

**Tu es maintenant un développeur C compétent, prêt pour des projets ambitieux. 🚀**
