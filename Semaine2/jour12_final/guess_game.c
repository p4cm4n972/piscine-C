/*
** PROJET FINAL : Jeu de devinettes avancé
**
** Ce programme combine tous les concepts de la Semaine 2 :
** - Recherche binaire (pour l'IA)
** - Tri des scores
** - Manipulation de structures
** - Génération aléatoire
**
** Objectif : Créer un jeu complet et modulaire
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure pour stocker l'état d'une partie
typedef struct s_game
{
	int	target;      // Nombre à deviner
	int	attempts;    // Nombre de tentatives
	int	min;         // Borne inférieure
	int	max;         // Borne supérieure
}	t_game;

// Structure pour stocker un score
typedef struct s_score
{
	char	player_name[50];
	int		attempts;
	int		range_min;
	int		range_max;
}	t_score;

/*
** Initialise le jeu avec un nombre aléatoire
*/
void	init_game(t_game *game, int min, int max)
{
	// TODO: Implémente l'initialisation
	// 1. Initialiser srand(time(NULL)) une seule fois
	// 2. game->min = min
	// 3. game->max = max
	// 4. game->target = min + rand() % (max - min + 1)
	// 5. game->attempts = 0
}

/*
** Mode joueur humain : lit les entrées et guide le joueur
*/
int	play_human(t_game *game)
{
	// TODO: Implémente le mode joueur
	// 1. Afficher les instructions
	// 2. Boucle infinie :
	//    - Lire la tentative du joueur avec scanf
	//    - Incrémenter game->attempts
	//    - Si guess == target : bravo ! retourner attempts
	//    - Si guess < target : afficher "C'est plus grand !"
	//    - Si guess > target : afficher "C'est plus petit !"
	// 3. Retourner le nombre de tentatives

	return (0);
}

/*
** Mode IA : utilise la recherche binaire pour trouver le nombre
*/
int	play_ai(t_game *game)
{
	// TODO: Implémente le mode IA avec recherche binaire
	// 1. Initialiser left = game->min, right = game->max
	// 2. Boucle while (left <= right) :
	//    - guess = left + (right - left) / 2
	//    - Incrémenter attempts
	//    - Afficher la tentative
	//    - Si guess == target : trouvé ! retourner attempts
	//    - Si guess < target : left = guess + 1, afficher "-> Plus grand"
	//    - Si guess > target : right = guess - 1, afficher "-> Plus petit"
	// 3. Retourner attempts

	return (0);
}

/*
** Affiche les statistiques de la partie
*/
void	print_stats(t_game *game)
{
	printf("\n=== STATISTIQUES ===\n");
	printf("Nombre à deviner : %d\n", game->target);
	printf("Plage : [%d, %d]\n", game->min, game->max);
	printf("Tentatives : %d\n", game->attempts);

	// Calcul du nombre optimal
	int	optimal = 0;
	int	range = game->max - game->min + 1;
	while (range > 1)
	{
		range = (range + 1) / 2;
		optimal++;
	}
	printf("Tentatives optimales (log₂) : %d\n", optimal);

	if (game->attempts <= optimal)
		printf("Performance : EXCELLENT !\n");
	else if (game->attempts <= optimal + 3)
		printf("Performance : Bien\n");
	else
		printf("Performance : Peut mieux faire\n");
}

/*
** Trie les scores par nombre de tentatives (ordre croissant)
*/
void	sort_scores(t_score *scores, int count)
{
	// TODO: Implémente un tri (bubble sort, selection sort, ou insertion sort)
	// Trier par scores[i].attempts (ordre croissant = meilleurs d'abord)
}

/*
** Affiche les meilleurs scores
*/
void	print_top_scores(t_score *scores, int count)
{
	printf("\n=== TOP SCORES ===\n");
	if (count == 0)
	{
		printf("Aucun score enregistré.\n");
		return;
	}

	printf("%-20s | %-10s | %-10s\n", "Joueur", "Tentatives", "Plage");
	printf("---------------------------------------------\n");

	int	max_display = (count < 10) ? count : 10;
	for (int i = 0; i < max_display; i++)
	{
		printf("%-20s | %-10d | [%d, %d]\n",
			scores[i].player_name,
			scores[i].attempts,
			scores[i].range_min,
			scores[i].range_max);
	}
}

/*
** Ajoute un score à la liste
*/
void	add_score(t_score *scores, int *count, t_score new_score)
{
	// TODO: Ajoute le nouveau score à la fin du tableau
	// 1. scores[*count] = new_score
	// 2. (*count)++
	// 3. Appeler sort_scores pour retrier
}

/*
** Menu principal
*/
int	main_menu(void)
{
	int	choice;

	printf("\n╔════════════════════════════════╗\n");
	printf("║   JEU DE DEVINETTES AVANCÉ     ║\n");
	printf("╚════════════════════════════════╝\n");
	printf("\n");
	printf("1. Jouer (mode humain)\n");
	printf("2. Voir la démo IA\n");
	printf("3. Afficher les meilleurs scores\n");
	printf("4. Choisir la difficulté\n");
	printf("5. Quitter\n");
	printf("\n");
	printf("Votre choix : ");
	scanf("%d", &choice);

	return (choice);
}

/*
** Programme principal
*/
int	main(void)
{
	t_game	game;
	t_score	scores[100];  // Max 100 scores
	int		score_count = 0;
	int		choice;
	int		min = 1;
	int		max = 100;
	char	player_name[50];

	// Initialiser le générateur aléatoire
	srand(time(NULL));

	while (1)
	{
		choice = main_menu();

		if (choice == 1)  // Mode joueur
		{
			printf("\nVotre nom : ");
			scanf("%s", player_name);

			init_game(&game, min, max);
			printf("\nDevinez le nombre entre %d et %d\n", min, max);
			play_human(&game);
			print_stats(&game);

			// Enregistrer le score
			t_score new_score;
			strcpy(new_score.player_name, player_name);
			new_score.attempts = game.attempts;
			new_score.range_min = min;
			new_score.range_max = max;
			add_score(scores, &score_count, new_score);
		}
		else if (choice == 2)  // Mode IA
		{
			init_game(&game, min, max);
			printf("\nL'IA va deviner un nombre entre %d et %d\n", min, max);
			printf("Appuyez sur Entrée pour continuer...");
			getchar(); getchar();
			play_ai(&game);
			print_stats(&game);
		}
		else if (choice == 3)  // Afficher scores
		{
			print_top_scores(scores, score_count);
		}
		else if (choice == 4)  // Difficulté
		{
			printf("\nChoisissez la difficulté :\n");
			printf("1. Facile (1-10)\n");
			printf("2. Moyen (1-100)\n");
			printf("3. Difficile (1-1000)\n");
			printf("4. Extrême (1-10000)\n");
			printf("Choix : ");
			int diff;
			scanf("%d", &diff);

			min = 1;
			if (diff == 1)
				max = 10;
			else if (diff == 2)
				max = 100;
			else if (diff == 3)
				max = 1000;
			else if (diff == 4)
				max = 10000;

			printf("Difficulté changée : [%d, %d]\n", min, max);
		}
		else if (choice == 5)  // Quitter
		{
			printf("\nMerci d'avoir joué ! À bientôt.\n");
			break;
		}
		else
		{
			printf("\nChoix invalide.\n");
		}
	}

	return (0);
}

/*
** TODO LIST :
**
** Fonctions à compléter :
** 1. init_game() : initialisation du jeu
** 2. play_human() : mode joueur avec boucle de jeu
** 3. play_ai() : recherche binaire pour l'IA
** 4. sort_scores() : tri des scores
** 5. add_score() : ajout d'un score et tri
**
** Tests à faire :
** - Tester avec différentes plages (1-10, 1-100, 1-1000)
** - Vérifier que l'IA trouve en log₂(n) tentatives max
** - Tester les cas limites (min=max, min=1, max=1)
** - Vérifier qu'il n'y a pas de buffer overflow avec les noms
**
** Améliorations bonus :
** - Sauvegarde des scores dans un fichier (fopen, fprintf, fscanf, fclose)
** - Chargement des scores au démarrage
** - Interface colorée avec codes ANSI
** - Chronomètre pour mesurer le temps de jeu
** - Mode multijoueur (2 joueurs alternent)
*/
