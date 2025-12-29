# 🎯 JOUR 18 - PROJET FINAL : MEMORY MANAGER

## 📋 Description

Implémentation d'un gestionnaire de mémoire personnalisé avec :
- Pool allocation (pré-allocation d'un grand bloc)
- Liste chaînée de blocs libres
- Statistiques d'utilisation
- Détection de fuites

## 🏗️ Architecture

```
┌─────────────────────────────────────┐
│       MEMORY POOL (HEAP)            │
├─────────────────────────────────────┤
│ [BLOC 1] [BLOC 2] [BLOC 3] ... │
│  libre    utilisé   libre          │
└─────────────────────────────────────┘
         ↓          ↓        ↓
    Liste chaînée de blocs libres
```

## 📂 Fichiers

- **memory_manager.h** : Header avec structures et prototypes
- **memory_manager.c** : Implémentation du gestionnaire
- **main.c** : Tests et démonstrations
- **Makefile** : Compilation

## 🔧 Fonctions implémentées

### Gestion de base
- `mm_init()` : Initialiser le pool
- `mm_alloc(size)` : Allouer un bloc
- `mm_free(ptr)` : Libérer un bloc
- `mm_destroy()` : Détruire le pool

### Statistiques
- `mm_stats()` : Afficher les statistiques
- `mm_check_leaks()` : Vérifier les fuites

## 🎯 Objectifs pédagogiques

1. Comprendre comment malloc/free fonctionnent
2. Gérer une liste chaînée de blocs
3. Aligner la mémoire correctement
4. Détecter les fuites mémoire
5. Optimiser l'allocation

## 📊 Complexité

- Allocation : O(n) - parcours de la liste
- Libération : O(1) - ajout en tête
- Optimisation possible : Best-fit, First-fit, Buddy system

## 🚀 Utilisation

```bash
make
./memory_manager

# Tests
make test

# Valgrind
make valgrind
```

## 📝 Exemple

```c
// Initialiser
mm_init(4096);

// Allouer
int *arr = mm_alloc(sizeof(int) * 10);

// Utiliser
for (int i = 0; i < 10; i++)
    arr[i] = i;

// Libérer
mm_free(arr);

// Statistiques
mm_stats();

// Nettoyer
mm_destroy();
```

## 🎓 Points avancés

- **Alignement** : Alignement sur 8 bytes
- **Fragmentation** : Coalescing des blocs adjacents
- **Métadonnées** : Header avec taille et flag
- **Sécurité** : Double-free detection

## 🏆 Améliorations possibles

1. Implémentation de realloc
2. Support de plusieurs pools
3. Thread-safety (mutex)
4. Buddy allocator
5. Garbage collection

---

**Temps estimé** : 6-8 heures
**Difficulté** : ⭐⭐⭐⭐ Expert
**Concepts** : Allocation, listes chaînées, alignement mémoire
