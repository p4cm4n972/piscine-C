# 📚 SEMAINE 2 : Algorithmique avancée — Piscine C 

## 🎯 Objectifs de la semaine
Maîtriser les concepts algorithmiques fondamentaux et les techniques de programmation avancées en C.

**Thèmes abordés :**
- Récursivité et algorithmes récursifs
- Algorithmes de tri (bubble sort, selection sort, insertion sort)
- Algorithmes de recherche (linéaire, binaire)
- Manipulation avancée de chaînes de caractères
- Gestion de tableaux de pointeurs
- Projet final intégrant tous les concepts

---

## 📅 Planning hebdomadaire

### JOUR 07 : Récursivité 🔄
**Durée estimée :** 3-4 heures

La récursivité est une technique où une fonction s'appelle elle-même. C'est fondamental pour de nombreux algorithmes.

#### Exercices disponibles :
1. **ft_recursive_factorial.c** - Calcul du factoriel de manière récursive
2. **ft_recursive_power.c** - Calcul de puissance récursif
3. **ft_fibonacci.c** - Suite de Fibonacci
4. **ft_is_palindrome.c** - Vérifier si une chaîne est un palindrome
5. **ft_sum_digits.c** - Somme des chiffres d'un nombre
6. **main.c** - Programme de test

#### Concepts clés :
- Cas de base (condition d'arrêt)
- Cas récursif (appel à soi-même)
- Stack overflow et profondeur de récursion
- Complexité temporelle et spatiale

#### Challenge à ajouter :
- **challenge_ft_tower_hanoi.c** - Tours de Hanoï (algorithme classique)

---

### JOUR 08 : Algorithmes de tri 📊
**Durée estimée :** 4-5 heures

Les algorithmes de tri sont essentiels en informatique. Tu vas implémenter les 3 tris fondamentaux.

#### Exercices disponibles :
1. **ft_bubble_sort.c** - Tri à bulles (O(n²))
2. **ft_selection_sort.c** - Tri par sélection (O(n²))
3. **ft_insertion_sort.c** - Tri par insertion (O(n²))
4. **main.c** - Tests comparatifs

#### Concepts clés :
- Complexité temporelle : O(n²) vs O(n log n)
- Complexité spatiale : tri en place
- Stabilité d'un tri
- Cas optimal, moyen, pire

#### Challenges à ajouter :
- **challenge_ft_quick_sort.c** - Quick Sort (O(n log n))
- **challenge_ft_merge_sort.c** - Merge Sort (O(n log n))
- **benchmark.c** - Comparer les performances

---

### JOUR 09 : Algorithmes de recherche 🔍
**Durée estimée :** 3-4 heures

Savoir chercher efficacement dans des données est crucial.

#### Exercices disponibles :
1. **ft_find_int.c** - Recherche linéaire (O(n))
2. **ft_binary_search.c** - Recherche binaire (O(log n))
3. **main.c** - Tests de performance

#### Concepts clés :
- Recherche linéaire vs binaire
- Précondition : tableau trié pour binary search
- Complexité logarithmique
- Dichotomie

#### Challenges à ajocher :
- **challenge_ft_find_string.c** - Recherche de sous-chaîne (KMP ou Boyer-Moore)
- **challenge_ft_interpolation_search.c** - Recherche par interpolation

---

### JOUR 10 : Manipulation avancée de chaînes 🔤
**Durée estimée :** 3-4 heures

Approfondir les techniques de manipulation de strings.

#### Exercices disponibles :
1. **ft_strrev.c** - Inverser une chaîne
2. **ft_is_anagram.c** - Vérifier si deux mots sont des anagrammes
3. **main.c** - Tests

#### Concepts clés :
- Manipulation de pointeurs de caractères
- Tableaux de comptage
- Algorithmes de transformation de strings

#### Challenges à ajouter :
- **challenge_ft_rot13.c** - Chiffrement ROT13
- **challenge_ft_capitalize.c** - Capitaliser chaque mot
- **challenge_ft_count_words.c** - Compter les mots dans une phrase

---

### JOUR 11 : Tri de mots (projet) 📝
**Durée estimée :** 4-5 heures

Projet complet : trier des mots passés en arguments.

#### Fichiers disponibles :
1. **word_sort.c** - Programme principal avec ft_sort_words
2. **Makefile** - Compilation avec règles standard

#### Fonctionnalités :
```bash
./word_sort pomme banane cerise
# Output : banane cerise pomme
```

#### Concepts clés :
- Tableau de pointeurs (char **)
- argc et argv
- strcmp pour comparer des chaînes
- Tri appliqué aux strings

#### Améliorations à ajouter :
- **README.md** - Documentation du projet
- **word_sort_advanced.c** - Version avec options (-r reverse, -i insensible à la casse)

---

### JOUR 12 : Projet final 🎯
**Durée estimée :** 5-6 heures

Projet intégrateur combinant tous les concepts de la semaine 2.

#### Fichier disponible :
1. **numbers_game.c** - Jeu avec combinaisons de chiffres

#### Description :
Le fichier actuel implémente un générateur de combinaisons de 3 chiffres dont la somme égale 6.

#### Projet final à créer :
Un **jeu de devinettes avancé** qui combine :
- Génération aléatoire de nombres
- Recherche binaire pour deviner
- Tri des scores
- Statistiques de jeu
- Sauvegarde des meilleurs scores

#### Améliorations à ajouter :
- **README.md** - Documentation complète du projet
- **numbers_game_complete.c** - Version complète du jeu
- **scores.c** - Gestion des scores

---

## ✅ Checklist globale Semaine 2

### Récursivité (Jour 07)
- [ ] ft_recursive_factorial implémenté et testé
- [ ] ft_recursive_power implémenté et testé
- [ ] ft_fibonacci implémenté et testé
- [ ] ft_is_palindrome implémenté et testé
- [ ] ft_sum_digits implémenté et testé
- [ ] Challenge Tours de Hanoï complété

### Tri (Jour 08)
- [ ] Bubble sort implémenté avec analyse de complexité
- [ ] Selection sort implémenté avec analyse de complexité
- [ ] Insertion sort implémenté avec analyse de complexité
- [ ] Quick sort (challenge) implémenté
- [ ] Merge sort (challenge) implémenté
- [ ] Benchmark comparatif des tris

### Recherche (Jour 09)
- [ ] Recherche linéaire implémentée
- [ ] Recherche binaire implémentée
- [ ] Tests de performance comparatifs
- [ ] Challenge recherche de sous-chaîne

### Strings avancées (Jour 10)
- [ ] ft_strrev implémenté
- [ ] ft_is_anagram implémenté
- [ ] ROT13 (challenge) implémenté
- [ ] Capitalize (challenge) implémenté
- [ ] Count words (challenge) implémenté

### Projet word_sort (Jour 11)
- [ ] Programme compile sans erreur
- [ ] Trie correctement les arguments
- [ ] Makefile fonctionnel
- [ ] Version avancée avec options

### Projet final (Jour 12)
- [ ] Jeu de devinettes fonctionnel
- [ ] Gestion des scores implémentée
- [ ] Statistiques affichées
- [ ] Code propre et commenté

---

## 📊 Compétences acquises

À la fin de la Semaine 2, tu maîtriseras :

### Algorithmique
- ✅ Récursivité (cas de base, cas récursif)
- ✅ Tri : Bubble, Selection, Insertion, Quick, Merge
- ✅ Recherche : Linéaire, Binaire
- ✅ Complexité temporelle et spatiale

### Programmation C
- ✅ Manipulation avancée de pointeurs
- ✅ Tableaux de pointeurs (char **)
- ✅ argc et argv
- ✅ Makefile et compilation multi-fichiers

### Bonnes pratiques
- ✅ Analyse de complexité
- ✅ Tests de performance
- ✅ Code modulaire et réutilisable
- ✅ Documentation du code

---

## 🎓 Niveau 

Cette semaine 2 correspond au niveau attendu en **fin de piscine ** :

| Notion | Niveau attendu |
|--------|----------------|
| Récursivité | Maîtrise complète |
| Algorithmes de tri | Connaissance des 5 principaux |
| Complexité | Analyse O(n), O(log n), O(n²) |
| Pointeurs | Manipulation avancée (**, ***) |
| Makefile | Création autonome |

---

## ⏱️ Temps total estimé

- **Exercices obligatoires** : 18-22 heures
- **Challenges bonus** : 8-10 heures
- **Total avec bonus** : 26-32 heures

**Rythme conseillé :** 4-5 heures par jour pendant 6 jours

---

## 📚 Ressources recommandées

### Livres
- *The C Programming Language* - Kernighan & Ritchie (K&R)
- *Introduction to Algorithms* - CLRS (pour la théorie)

### En ligne
- man gcc
- man gdb (débogage)
- https://www.bigocheatsheet.com/ (complexités)

### Outils
```bash
# Mesurer le temps d'exécution
time ./programme

# Profiler le code
valgrind --tool=callgrind ./programme
kcachegrind callgrind.out.*

# Vérifier les fuites mémoires
valgrind --leak-check=full ./programme
```

---

## 🚀 Après la Semaine 2

Si tu as terminé tous les exercices, tu es prêt pour :
- **Structures de données** : listes chaînées, arbres, graphes
- **Allocation dynamique** : malloc, free, gestion mémoire
- **Fichiers** : lecture/écriture, parsing
- **Projets avancés** : mini-shell, mini-grep, mini-printf complet

---

## 📝 Notes importantes

### Compilation
Tous les exercices doivent compiler avec :
```bash
gcc -Wall -Wextra -Werror -std=c99 fichier.c -o programme
```

### Tests
- Teste TOUJOURS les cas limites (0, négatif, NULL)
- Vérifie les fuites mémoire avec valgrind
- Compare tes résultats avec les fonctions système quand possible

### Git
```bash
# Commit régulièrement
git add .
git commit -m "Complete jour08: sorting algorithms"
```

---

## 🎯 Critères de réussite

Tu as réussi la Semaine 2 si :
- ✅ Tous les exercices obligatoires compilent sans erreur
- ✅ Tu peux expliquer la complexité de chaque algorithme
- ✅ Tu comprends la différence entre récursif et itératif
- ✅ Tu sais quand utiliser quel algorithme de tri/recherche
- ✅ Tes projets (jour 11 et 12) fonctionnent parfaitement

---

**Bon courage ! La Semaine 2 est intense mais très formatrice. 💪**
