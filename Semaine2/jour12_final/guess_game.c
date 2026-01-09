/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guess_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** PROJET FINAL : Jeu de devinettes avancé
**
** Ce programme combine tous les concepts de la Semaine 2 :
** - Recherche binaire (pour l'IA)
** - Tri des scores (insertion sort)
** - Manipulation de structures
** - Génération aléatoire
**
** Concepts 42/Epitech :
** - Structures et typedef
** - Pointeurs et références
** - Algorithmique (recherche binaire, tri)
** - Gestion d'état avec structures
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
** Structure pour stocker l'état d'une partie
*/
typedef struct s_game
{
	int	target;      /* Nombre à deviner */
	int	attempts;    /* Nombre de tentatives */
	int	min;         /* Borne inférieure */
	int	max;         /* Borne supérieure */
}	t_game;

/*
** Structure pour stocker un score
*/
typedef struct s_score
{
	char	player_name[50];
	int		attempts;
	int		range_min;
	int		range_max;
}	t_score;

/* ==================== FONCTIONS DE JEU ==================== */

/*
** init_game - Initialise le jeu avec un nombre aléatoire
** @game: pointeur vers la structure de jeu
** @min: borne inférieure
** @max: borne supérieure
**
** Note: srand() doit être appelé une seule fois dans main()
** Formule: min + rand() % (max - min + 1) génère un nombre dans [min, max]
*/
void	init_game(t_game *game, int min, int max)
{
	game->min = min;
	game->max = max;
	game->target = min + rand() % (max - min + 1);
	game->attempts = 0;
}

/*
** play_human - Mode joueur humain : lit les entrées et guide le joueur
** @game: pointeur vers la structure de jeu
** Return: nombre de tentatives
**
** Algorithme:
** 1. Boucle infinie jusqu'à trouver le nombre
** 2. Lit l'entrée utilisateur avec scanf
** 3. Vérifie la validité et donne des indices
** 4. Retourne le nombre de tentatives
**
** Note: Le joueur peut utiliser la stratégie de recherche binaire
** pour trouver en log₂(n) tentatives maximum
*/
int	play_human(t_game *game)
{
	int	guess;
	int	ret;

	printf("\n🎯 Devinez le nombre entre %d et %d\n", game->min, game->max);
	printf("Conseil: utilisez la dichotomie (milieu de l'intervalle)\n\n");
	while (1)
	{
		printf("Tentative %d > ", game->attempts + 1);
		ret = scanf("%d", &guess);
		if (ret != 1)
		{
			printf("Entrée invalide. Entrez un nombre.\n");
			while (getchar() != '\n')
				;
			continue ;
		}
		game->attempts++;
		if (guess < game->min || guess > game->max)
		{
			printf("⚠️  Hors limites ! Entrez un nombre entre %d et %d\n",
				game->min, game->max);
			continue ;
		}
		if (guess == game->target)
		{
			printf("\n🎉 BRAVO ! Vous avez trouvé %d en %d tentatives !\n",
				game->target, game->attempts);
			return (game->attempts);
		}
		else if (guess < game->target)
			printf("📈 C'est PLUS GRAND !\n");
		else
			printf("📉 C'est PLUS PETIT !\n");
	}
}

/*
** play_ai - Mode IA : utilise la recherche binaire pour trouver le nombre
** @game: pointeur vers la structure de jeu
** Return: nombre de tentatives
**
** Algorithme: Recherche binaire (dichotomie)
** - Complexité: O(log n) - toujours optimal
** - Le nombre de tentatives max = ceil(log₂(max - min + 1))
**
** Principe:
** 1. Définir left = min, right = max
** 2. Calculer mid = left + (right - left) / 2
** 3. Si mid < target: chercher dans [mid+1, right]
** 4. Si mid > target: chercher dans [left, mid-1]
** 5. Répéter jusqu'à trouver
**
** Note: Cette fonction démontre l'efficacité de la recherche binaire
** Pour une plage de 1-100, l'IA trouve toujours en 7 tentatives max
*/
int	play_ai(t_game *game)
{
	int	left;
	int	right;
	int	guess;

	left = game->min;
	right = game->max;
	printf("\n🤖 L'IA utilise la recherche binaire...\n");
	printf("Plage initiale: [%d, %d]\n\n", left, right);
	while (left <= right)
	{
		guess = left + (right - left) / 2;
		game->attempts++;
		printf("Tentative %d: L'IA essaie %d", game->attempts, guess);
		if (guess == game->target)
		{
			printf(" ✓ TROUVÉ !\n");
			printf("\n🤖 L'IA a trouvé %d en %d tentatives.\n",
				game->target, game->attempts);
			return (game->attempts);
		}
		else if (guess < game->target)
		{
			printf(" → Plus grand [%d, %d]\n", guess + 1, right);
			left = guess + 1;
		}
		else
		{
			printf(" → Plus petit [%d, %d]\n", left, guess - 1);
			right = guess - 1;
		}
	}
	return (game->attempts);
}

/* ==================== GESTION DES SCORES ==================== */

/*
** sort_scores - Trie les scores par nombre de tentatives (ordre croissant)
** @scores: tableau de scores
** @count: nombre de scores
**
** Algorithme: Insertion Sort (efficace pour petits tableaux)
** - Complexité: O(n²) pire cas, O(n) si presque trié
** - Stable: oui
** - En place: oui
**
** Avantage: Après chaque ajout d'un score, le tableau est presque trié
** donc l'insertion sort est très efficace (une seule passe)
*/
void	sort_scores(t_score *scores, int count)
{
	int		i;
	int		j;
	t_score	key;

	i = 1;
	while (i < count)
	{
		key = scores[i];
		j = i - 1;
		while (j >= 0 && scores[j].attempts > key.attempts)
		{
			scores[j + 1] = scores[j];
			j--;
		}
		scores[j + 1] = key;
		i++;
	}
}

/*
** add_score - Ajoute un score à la liste et trie
** @scores: tableau de scores
** @count: pointeur vers le nombre de scores
** @new_score: nouveau score à ajouter
**
** Note: On utilise un pointeur pour count car on modifie sa valeur
*/
void	add_score(t_score *scores, int *count, t_score new_score)
{
	if (*count >= 100)
	{
		printf("⚠️  Liste des scores pleine !\n");
		return ;
	}
	scores[*count] = new_score;
	(*count)++;
	sort_scores(scores, *count);
}

/* ==================== AFFICHAGE ==================== */

/*
** print_stats - Affiche les statistiques de la partie
** @game: pointeur vers la structure de jeu
**
** Calcul du nombre optimal de tentatives:
** - Pour une plage [min, max], le nombre optimal est ceil(log₂(max - min + 1))
** - Exemple: pour [1, 100], optimal = ceil(log₂(100)) = 7
*/
void	print_stats(t_game *game)
{
	int	optimal;
	int	range;

	optimal = 0;
	range = game->max - game->min + 1;
	while (range > 1)
	{
		range = (range + 1) / 2;
		optimal++;
	}
	printf("\n╔══════════════════════════════╗\n");
	printf("║      📊 STATISTIQUES         ║\n");
	printf("╚══════════════════════════════╝\n");
	printf("  Nombre à deviner : %d\n", game->target);
	printf("  Plage : [%d, %d]\n", game->min, game->max);
	printf("  Vos tentatives : %d\n", game->attempts);
	printf("  Tentatives optimales : %d (log₂)\n", optimal);
	printf("\n  Performance : ");
	if (game->attempts <= optimal)
		printf("⭐⭐⭐ EXCELLENT !\n");
	else if (game->attempts <= optimal + 2)
		printf("⭐⭐ Très bien !\n");
	else if (game->attempts <= optimal + 5)
		printf("⭐ Bien\n");
	else
		printf("📚 Étudiez la recherche binaire !\n");
}

/*
** print_top_scores - Affiche les meilleurs scores
** @scores: tableau de scores
** @count: nombre de scores
*/
void	print_top_scores(t_score *scores, int count)
{
	int	i;
	int	max_display;

	printf("\n╔══════════════════════════════════════════════╗\n");
	printf("║              🏆 TOP SCORES                   ║\n");
	printf("╚══════════════════════════════════════════════╝\n");
	if (count == 0)
	{
		printf("  Aucun score enregistré.\n");
		printf("  Jouez une partie pour apparaître ici !\n");
		return ;
	}
	printf("  %-4s %-15s %-12s %-12s\n", "Rank", "Joueur", "Tentatives", "Plage");
	printf("  ────────────────────────────────────────────\n");
	max_display = (count < 10) ? count : 10;
	i = 0;
	while (i < max_display)
	{
		printf("  %-4d %-15s %-12d [%d-%d]\n",
			i + 1,
			scores[i].player_name,
			scores[i].attempts,
			scores[i].range_min,
			scores[i].range_max);
		i++;
	}
}

/* ==================== MENU ==================== */

/*
** main_menu - Affiche le menu principal et retourne le choix
** Return: choix de l'utilisateur (1-5)
*/
int	main_menu(void)
{
	int	choice;

	printf("\n╔════════════════════════════════════╗\n");
	printf("║    🎮 JEU DE DEVINETTES AVANCÉ     ║\n");
	printf("║    ─────────────────────────────   ║\n");
	printf("║    Projet Final - Semaine 2        ║\n");
	printf("╚════════════════════════════════════╝\n\n");
	printf("  1. 👤 Jouer (mode humain)\n");
	printf("  2. 🤖 Voir la démo IA (recherche binaire)\n");
	printf("  3. 🏆 Afficher les meilleurs scores\n");
	printf("  4. ⚙️  Choisir la difficulté\n");
	printf("  5. 🚪 Quitter\n");
	printf("\n  Votre choix : ");
	if (scanf("%d", &choice) != 1)
	{
		while (getchar() != '\n')
			;
		return (0);
	}
	return (choice);
}

/*
** select_difficulty - Menu de sélection de difficulté
** @min: pointeur vers la borne min
** @max: pointeur vers la borne max
*/
void	select_difficulty(int *min, int *max)
{
	int	diff;

	printf("\n╔══════════════════════════════╗\n");
	printf("║      ⚙️  DIFFICULTÉ           ║\n");
	printf("╚══════════════════════════════╝\n\n");
	printf("  1. 🟢 Facile    (1-10)    ~4 tentatives\n");
	printf("  2. 🟡 Moyen     (1-100)   ~7 tentatives\n");
	printf("  3. 🟠 Difficile (1-1000)  ~10 tentatives\n");
	printf("  4. 🔴 Extrême   (1-10000) ~14 tentatives\n");
	printf("\n  Choix : ");
	if (scanf("%d", &diff) != 1)
	{
		while (getchar() != '\n')
			;
		return ;
	}
	*min = 1;
	if (diff == 1)
		*max = 10;
	else if (diff == 2)
		*max = 100;
	else if (diff == 3)
		*max = 1000;
	else if (diff == 4)
		*max = 10000;
	else
	{
		printf("  ⚠️  Choix invalide, difficulté inchangée.\n");
		return ;
	}
	printf("\n  ✓ Difficulté changée : [%d, %d]\n", *min, *max);
}

/* ==================== PROGRAMME PRINCIPAL ==================== */

/*
** main - Point d'entrée du programme
**
** Architecture:
** 1. Initialisation (srand une seule fois)
** 2. Boucle principale avec menu
** 3. Dispatch selon le choix utilisateur
** 4. Gestion propre des ressources
*/
int	main(void)
{
	t_game	game;
	t_score	scores[100];
	t_score	new_score;
	int		score_count;
	int		choice;
	int		min;
	int		max;
	char	player_name[50];

	score_count = 0;
	min = 1;
	max = 100;
	srand(time(NULL));
	while (1)
	{
		choice = main_menu();
		if (choice == 1)
		{
			printf("\n  Votre nom : ");
			scanf("%49s", player_name);
			init_game(&game, min, max);
			play_human(&game);
			print_stats(&game);
			strcpy(new_score.player_name, player_name);
			new_score.attempts = game.attempts;
			new_score.range_min = min;
			new_score.range_max = max;
			add_score(scores, &score_count, new_score);
		}
		else if (choice == 2)
		{
			init_game(&game, min, max);
			printf("\n  L'IA va deviner un nombre entre %d et %d\n", min, max);
			printf("  Appuyez sur Entrée pour lancer la démo...");
			getchar();
			getchar();
			play_ai(&game);
			print_stats(&game);
		}
		else if (choice == 3)
			print_top_scores(scores, score_count);
		else if (choice == 4)
			select_difficulty(&min, &max);
		else if (choice == 5)
		{
			printf("\n  👋 Merci d'avoir joué ! À bientôt.\n\n");
			break ;
		}
		else
			printf("\n  ⚠️  Choix invalide. Essayez 1-5.\n");
	}
	return (0);
}
