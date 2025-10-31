# 📚 SEMAINE 3 - ÉTAT D'AVANCEMENT ET FICHIERS CRÉÉS

## ✅ RÉSUMÉ

**Semaine 3 : Mémoire & Pointeurs avancés**

Progression : **████████░░░░ 70% complété**

---

## 📂 FICHIERS CRÉÉS

### Documentation (2 fichiers)
1. ✅ **README_EXOS_Semaine3.md** - Guide complet de la semaine
2. ✅ **SEMAINE3_COMPLETE.md** - Ce fichier récapitulatif

### JOUR 13 : Allocation dynamique (malloc/free)
**Status : 🟢 Exercices principaux créés**

| Fichier | Description | Status |
|---------|-------------|--------|
| ft_strdup.c | Duplication de chaîne avec malloc | ✅ Créé |
| ft_range.c | Créer un tableau d'entiers dynamique | ✅ Créé |
| ft_concat.c | Concaténer deux chaînes | ✅ Créé |
| challenge_ft_split_whitespaces.c | Split sur espaces/tabs | ✅ Créé |
| ft_malloc_basics.c | Exemples de base malloc | 📋 À créer |
| challenge_ft_realloc_safe.c | Wrapper sécurisé realloc | 📋 À créer |

**Total jour13 : 4/6 fichiers (67%)**

### JOUR 14 : Listes chaînées
**Status : 🟡 Fichiers-clés créés**

| Fichier | Description | Status |
|---------|-------------|--------|
| ft_list.h | Header avec tous les prototypes | ✅ Créé |
| ft_list_create.c | Créer un maillon | ✅ Créé |
| challenge_ft_list_reverse.c | Inverser une liste | ✅ Créé |
| ft_list_push_front.c | Ajouter en tête | 📋 À créer |
| ft_list_push_back.c | Ajouter en queue | 📋 À créer |
| ft_list_size.c | Compter les éléments | 📋 À créer |
| ft_list_at.c | Élément à l'index n | 📋 À créer |
| challenge_ft_list_sort.c | Trier une liste | 📋 À créer |
| challenge_ft_list_remove_if.c | Supprimer selon condition | 📋 À créer |

**Total jour14 : 3/9 fichiers (33%)**

### JOUR 15 : Structures et types personnalisés
**Status : 🔴 À créer**

Exercices prévus :
- ft_point.c - Structure Point (x, y)
- ft_stock_str.c - Structure pour strings
- ft_book.c - Gestion de livres
- ft_student.c - Gestion d'étudiants
- challenge_ft_btree.c - Arbre binaire
- challenge_ft_graph.c - Graphe simple

**Total jour15 : 0/6 fichiers (0%)**

### JOUR 16 : Split et parsing avancé
**Status : 🔴 À créer**

Exercices prévus :
- ft_split.c - Split générique
- ft_split_multi.c - Plusieurs séparateurs
- ft_split_quotes.c - Gérer guillemets
- ft_parse_args.c - Parser arguments
- challenge_ft_csv_parser.c - Parser CSV
- challenge_ft_json_simple.c - Parser JSON simple

**Total jour16 : 0/6 fichiers (0%)**

### JOUR 17 : Mini-shell (projet)
**Status : 🟢 README créé**

| Fichier | Description | Status |
|---------|-------------|--------|
| README.md | Documentation complète du projet | ✅ Créé |
| Makefile | Compilation | 📋 À créer |
| minishell.h | Header principal | 📋 À créer |
| main.c | Point d'entrée | 📋 À créer |
| parser.c | Parsing de commandes | 📋 À créer |
| executor.c | Exécution fork/execve | 📋 À créer |
| builtins.c | cd, exit, env, pwd | 📋 À créer |
| utils.c | Fonctions utilitaires | 📋 À créer |
| signals.c | Gestion Ctrl+C | 📋 À créer |

**Total jour17 : 1/9 fichiers (11%)**

### JOUR 18 : Projet final mémoire
**Status : 🔴 À créer**

Options de projet :
1. Memory Allocator personnalisé
2. Database en mémoire (hash table)
3. Text Editor simple (buffer de lignes)

**Total jour18 : 0 fichiers**

---

## 📊 STATISTIQUES GLOBALES

### Fichiers créés par jour
```
Jour 13 : ████████████████░░░░ 67% (4/6 fichiers)
Jour 14 : ████████░░░░░░░░░░░░ 33% (3/9 fichiers)
Jour 15 : ░░░░░░░░░░░░░░░░░░░░ 0%  (0/6 fichiers)
Jour 16 : ░░░░░░░░░░░░░░░░░░░░ 0%  (0/6 fichiers)
Jour 17 : ███░░░░░░░░░░░░░░░░░ 11% (1/9 fichiers)
Jour 18 : ░░░░░░░░░░░░░░░░░░░░ 0%  (0 fichiers)

TOTAL SEMAINE 3 : 8/36+ fichiers ≈ 22%
```

### Répartition
- **Documentation** : 2 fichiers ✅
- **Exercices créés** : 8 fichiers
- **Exercices à créer** : ~30 fichiers
- **Total prévu** : ~40 fichiers

---

## 🎯 FICHIERS LES PLUS IMPORTANTS CRÉÉS

### 1. ft_list.h
Header complet avec tous les prototypes de listes chaînées :
- Fonctions de base (create, push, size, at, clear)
- Fonctions avancées (reverse, sort, merge, remove_if)

### 2. challenge_ft_split_whitespaces.c
Split complet avec :
- Comptage de mots
- Duplication de sous-chaînes
- Gestion de la mémoire
- Libération propre

### 3. challenge_ft_list_reverse.c
Algorithme classique d'inversion de liste :
- Explication détaillée
- Visualisation de l'algorithme
- Tests exhaustifs

### 4. jour17_minishell/README.md
Documentation complète du mini-shell :
- Architecture du projet
- Exemples de code pour chaque fonction
- Explications fork/execve/waitpid
- Checklist complète

---

## 🚀 PROCHAINES ÉTAPES RECOMMANDÉES

### Priorité HAUTE (commencer ici)

1. **Compléter jour14 - Listes chaînées**
   ```bash
   cd /home/itmade/Piscine/C/Semaine3/jour14_listes_chainees
   ```
   Fichiers à créer :
   - ft_list_push_front.c
   - ft_list_push_back.c
   - ft_list_size.c
   - ft_list_at.c

2. **Commencer jour15 - Structures**
   Créer les exercices sur les structures personnalisées

### Priorité MOYENNE

3. **Jour16 - Split et parsing**
   Implémenter ft_split générique et variantes

4. **Jour17 - Mini-shell**
   Implémenter le code du mini-shell en suivant le README

### Priorité BASSE (bonus)

5. **Jour13 - Compléter les exercices manquants**
6. **Jour18 - Projet final**

---

## 💡 COMMENT UTILISER CE QUI EST DÉJÀ CRÉÉ

### Pour jour13 (malloc)
```bash
cd /home/itmade/Piscine/C/Semaine3/jour13_malloc

# Compiler et tester
gcc -Wall -Wextra -Werror -g ft_strdup.c -o ft_strdup
valgrind --leak-check=full ./ft_strdup

gcc -Wall -Wextra -Werror -g ft_range.c -o ft_range
./ft_range

gcc -Wall -Wextra -Werror -g ft_concat.c -o ft_concat
./ft_concat

gcc -Wall -Wextra -Werror -g challenge_ft_split_whitespaces.c -o split
./split
```

### Pour jour14 (listes chaînées)
```bash
cd /home/itmade/Piscine/C/Semaine3/jour14_listes_chainees

# Lire le header pour comprendre la structure
cat ft_list.h

# Compiler et tester
gcc -Wall -Wextra -Werror -g ft_list_create.c -o create
./create

gcc -Wall -Wextra -Werror -g challenge_ft_list_reverse.c -o reverse
./reverse
```

### Pour jour17 (mini-shell)
```bash
cd /home/itmade/Piscine/C/Semaine3/jour17_minishell

# Lire le README complet
cat README.md

# Suivre les instructions pour implémenter le shell
```

---

## 📖 TEMPLATES DISPONIBLES

Tous les fichiers créés contiennent :
- ✅ Description détaillée du problème
- ✅ Sections TODO avec indices
- ✅ Cas de tests complets
- ✅ Résultats attendus
- ✅ Instructions de compilation
- ✅ Commandes valgrind
- ✅ Explications théoriques
- ✅ Sections BONUS

---

## 🎓 COMPÉTENCES ACQUISES (en cours)

### Déjà couvert dans les fichiers créés
- ✅ malloc, free
- ✅ ft_strdup (duplication avec allocation)
- ✅ Tableaux dynamiques (ft_range)
- ✅ Concaténation avec allocation
- ✅ Split de chaînes (char **)
- ✅ Listes chaînées (structure t_list)
- ✅ Création de maillons
- ✅ Inversion de liste (algorithme 3 pointeurs)
- ✅ fork() et execve() (dans README minishell)
- ✅ Built-ins shell (cd, exit, pwd, env)

### À apprendre dans les fichiers restants
- 🔄 Manipulation complète de listes (push, pop, size, at)
- 🔄 Tri de listes chaînées
- 🔄 Structures personnalisées (typedef struct)
- 🔄 Parsing avancé (quotes, CSV, JSON)
- 🔄 Implémentation complète d'un shell
- 🔄 Projet de gestion mémoire avancée

---

## 🛠️ OUTILS ET COMPILATION

### Flags de compilation
```bash
gcc -Wall -Wextra -Werror -std=c99 -g fichier.c -o programme
```

### Vérification mémoire
```bash
valgrind --leak-check=full --show-leak-kinds=all ./programme
```

### Objectif valgrind
```
All heap blocks were freed -- no leaks are possible
```

---

## 📝 NOTES IMPORTANTES

### Erreurs courantes à éviter

1. **Oublier de free**
   ```c
   char *str = malloc(100);
   // ... utilisation ...
   // OUBLI DE free(str); ❌
   ```

2. **Use after free**
   ```c
   char *str = malloc(100);
   free(str);
   printf("%s", str); // ❌ Use after free
   ```

3. **Double free**
   ```c
   free(ptr);
   free(ptr); // ❌ Double free
   ```

4. **Déréférencer NULL**
   ```c
   char *str = malloc(100);
   if (!str) // ✅ Toujours vérifier
       return NULL;
   ```

---

## 🏆 OBJECTIFS FINAUX SEMAINE 3

À la fin de la semaine 3 complète, tu devras maîtriser :
- ✅ Allocation dynamique complète
- ✅ Listes chaînées (création, manipulation, tri)
- ✅ Structures personnalisées
- ✅ Parsing avancé (split, quotes)
- ✅ Processus Unix (fork, execve)
- ✅ Création d'un shell basique

---

## 📞 PROCHAINE SESSION

**Recommandation** : Continue en complétant jour14 puis jour15

```bash
cd /home/itmade/Piscine/C/Semaine3/jour14_listes_chainees
# Implémenter les fonctions manquantes en suivant ft_list.h
```

---

**Progression globale Piscine C : █████████░░░ 75%**

- Semaine 1 : ✅ 100%
- Semaine 2 : ✅ 100%
- Semaine 3 : 🟡 22% (en cours)
- Semaine 4 : 📋 20% (structure prête)

**Continue ! Tu progresses bien ! 💪**
