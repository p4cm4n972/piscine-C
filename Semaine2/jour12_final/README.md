# 🎯 JOUR 12 : Projet final — Jeu de devinettes avancé

## 🎯 Objectif
Créer un jeu complet qui intègre tous les concepts de la Semaine 2 :
- Algorithmes de recherche
- Algorithmes de tri
- Manipulation de chaînes
- Gestion de fichiers (bonus)
- Statistiques et scores

---

## 🎮 Description du jeu

### Règle du jeu
Le programme génère un nombre aléatoire entre 1 et 100, et le joueur doit le deviner.
Après chaque tentative, le programme indique si le nombre est plus grand ou plus petit.

### Fonctionnalités
1. **Génération aléatoire** d'un nombre cible
2. **Recherche par dichotomie** pour l'IA (mode démo)
3. **Statistiques** : nombre de tentatives, meilleur score
4. **Tri des scores** des différentes parties
5. **Sauvegarde** des meilleurs scores (bonus)

---

## 📁 Structure du projet

```
jour12_final/
├── README.md                 (ce fichier)
├── numbers_game.c            (version simplifiée existante)
├── guess_game.c              (jeu complet à créer)
├── scores.c                  (gestion des scores - bonus)
├── Makefile                  (compilation)
└── highscores.txt            (fichier des meilleurs scores)
```

---

## 🔧 Fichier actuel : numbers_game.c

Le fichier existant implémente un **générateur de combinaisons** :
- Trouve toutes les combinaisons de 3 chiffres dont la somme = 6
- Utilise la récursivité
- Exemple de sortie : 006, 015, 024, 033, ...

**Ceci est un bon point de départ pour comprendre la récursivité**, mais ce n'est pas le jeu final.

---

## 💻 À implémenter : guess_game.c

### Structure du programme

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure pour stocker les stats d'une partie
typedef struct s_game
{
    int target;         // Nombre à deviner
    int attempts;       // Nombre de tentatives
    int min;            // Borne inférieure
    int max;            // Borne supérieure
}   t_game;

// Initialise le générateur aléatoire et la structure
void init_game(t_game *game, int min, int max);

// Joue une partie (mode joueur humain)
int play_human(t_game *game);

// Joue une partie (mode IA avec recherche binaire)
int play_ai(t_game *game);

// Affiche les statistiques de la partie
void print_stats(t_game *game);

// Menu principal
int main_menu(void);

// Programme principal
int main(void);
```

---

## 🎮 Fonctionnalités détaillées

### 1. Mode Joueur (play_human)
```c
int play_human(t_game *game)
{
    int guess;
    int attempts = 0;

    printf("Devinez le nombre entre %d et %d\n", game->min, game->max);

    while (1)
    {
        printf("Tentative %d: ", attempts + 1);
        scanf("%d", &guess);
        attempts++;

        if (guess == game->target)
        {
            printf("Bravo! Trouvé en %d tentatives!\n", attempts);
            game->attempts = attempts;
            return (attempts);
        }
        else if (guess < game->target)
            printf("C'est plus grand!\n");
        else
            printf("C'est plus petit!\n");
    }
}
```

### 2. Mode IA (play_ai)
Utilise l'algorithme de **recherche binaire** pour trouver le nombre optimal :

```c
int play_ai(t_game *game)
{
    int left = game->min;
    int right = game->max;
    int guess;
    int attempts = 0;

    printf("L'IA cherche le nombre %d...\n", game->target);

    while (left <= right)
    {
        guess = left + (right - left) / 2;
        attempts++;
        printf("Tentative %d: %d\n", attempts, guess);

        if (guess == game->target)
        {
            printf("IA a trouvé en %d tentatives!\n", attempts);
            game->attempts = attempts;
            return (attempts);
        }
        else if (guess < game->target)
        {
            printf("  -> Plus grand\n");
            left = guess + 1;
        }
        else
        {
            printf("  -> Plus petit\n");
            right = guess - 1;
        }
    }
    return (attempts);
}
```

### 3. Menu principal
```c
int main_menu(void)
{
    int choice;

    printf("\n=== JEU DE DEVINETTES ===\n");
    printf("1. Jouer (mode humain)\n");
    printf("2. Voir la démo IA\n");
    printf("3. Afficher les statistiques\n");
    printf("4. Quitter\n");
    printf("Votre choix: ");
    scanf("%d", &choice);

    return (choice);
}
```

---

## 📊 Gestion des scores (bonus)

### Structure pour les scores
```c
typedef struct s_score
{
    char player_name[50];
    int attempts;
    int range_min;
    int range_max;
    char date[20];
}   t_score;
```

### Fonctions de gestion des scores
```c
// Ajoute un score à la liste
void add_score(t_score *scores, int *count, t_score new_score);

// Trie les scores par nombre de tentatives
void sort_scores(t_score *scores, int count);

// Affiche le top 10
void print_top_scores(t_score *scores, int count);

// Sauvegarde dans un fichier
void save_scores(t_score *scores, int count, char *filename);

// Charge depuis un fichier
int load_scores(t_score *scores, char *filename);
```

---

## ✅ Checklist du projet

### Fonctionnalités de base
- [ ] Génération aléatoire d'un nombre
- [ ] Mode joueur humain fonctionnel
- [ ] Mode IA avec recherche binaire
- [ ] Affichage du nombre de tentatives
- [ ] Menu principal interactif
- [ ] Gestion de plusieurs parties consécutives

### Fonctionnalités avancées
- [ ] Statistiques : min, max, moyenne des tentatives
- [ ] Choix de la difficulté (1-10, 1-100, 1-1000)
- [ ] Gestion des noms de joueurs
- [ ] Tri des scores par performance
- [ ] Sauvegarde des scores dans un fichier
- [ ] Chargement des scores au démarrage

### Tests
- [ ] Le jeu fonctionne correctement
- [ ] L'IA trouve toujours en log₂(n) tentatives maximum
- [ ] Les statistiques sont correctes
- [ ] Aucune fuite mémoire (valgrind)
- [ ] Compilation sans erreur ni warning

---

## 🧮 Mathématiques du jeu

### Nombre de tentatives optimal
Pour un nombre entre 1 et N, l'algorithme de recherche binaire trouve en **maximum log₂(N) tentatives**.

| Plage | Tentatives max |
|-------|----------------|
| 1-10 | 4 |
| 1-100 | 7 |
| 1-1000 | 10 |
| 1-1000000 | 20 |

### Exemple avec [1, 100]
```
Tentative 1: 50
Tentative 2: 75 ou 25 (selon la réponse)
Tentative 3: ...
Maximum: 7 tentatives
```

---

## 🎁 Extensions possibles

### Niveau 1 : Variantes du jeu
- Mode "Devinez le mot" (utilise des chaînes)
- Mode "Devinez la lettre" (comme le pendu)
- Mode multijoueur (2 joueurs à tour de rôle)

### Niveau 2 : Améliorations
- Interface colorée (ANSI colors)
- Chronomètre pour mesurer le temps
- Système de points avec pénalité par tentative
- Indices après N tentatives échouées

### Niveau 3 : IA avancée
- Stratégie optimale avec probabilités
- Apprentissage du style de jeu du joueur
- Génération de nombres "intelligents" (pas complètement aléatoire)

---

## 🔧 Compilation

### Makefile
```makefile
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = guess_game

SRCS = guess_game.c scores.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

### Compilation manuelle
```bash
gcc -Wall -Wextra -Werror guess_game.c -o guess_game
```

---

## 📚 Concepts intégrés

Ce projet final intègre :

| Concept | Utilisation dans le jeu |
|---------|-------------------------|
| Récursivité | Peut être utilisée pour l'IA |
| Tri | Tri des scores par performance |
| Recherche binaire | Algorithme de l'IA |
| Tableaux | Stockage des scores |
| Structures | t_game, t_score |
| Fichiers | Sauvegarde/chargement des scores |
| Aléatoire | Génération du nombre cible |
| Boucles | Logique du jeu |

---

## 🎯 Objectifs pédagogiques

À la fin de ce projet, tu maîtriseras :
1. **Intégration** de plusieurs concepts en un seul programme
2. **Architecture** d'un programme modulaire
3. **Structures** de données personnalisées
4. **Algorithmes** (tri, recherche) en situation réelle
5. **Fichiers** pour la persistance des données
6. **Tests** et validation d'un programme complet

---

## ⏱️ Temps estimé

- Version de base (mode joueur + IA) : 2h
- Gestion des scores : 1h30
- Fichiers et persistance : 1h
- Tests et polish : 1h
- **Total** : 5h30 - 6h

---

## 💡 Conseils

### Développement progressif
1. Commence par le mode joueur simple
2. Ajoute le mode IA
3. Implémente les statistiques
4. Ajoute la sauvegarde des scores
5. Polish l'interface

### Debugging
```c
#define DEBUG 1

#if DEBUG
    printf("[DEBUG] Target = %d\n", game->target);
#endif
```

### Valgrind
```bash
valgrind --leak-check=full ./guess_game
```

---

## 🏆 Critères de réussite

Tu as réussi le projet final si :
- ✅ Le jeu est jouable et amusant
- ✅ L'IA utilise la recherche binaire correctement
- ✅ Les scores sont triés et affichés
- ✅ Le code est propre et commenté
- ✅ Aucune fuite mémoire
- ✅ Tu peux expliquer tous les algorithmes utilisés

---

**Félicitations ! Ce projet marque la fin de la Semaine 2. Tu as maintenant des bases solides en algorithmique et en C. 🎉**
