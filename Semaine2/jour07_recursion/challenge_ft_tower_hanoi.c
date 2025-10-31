/*
** CHALLENGE : ft_tower_hanoi
**
** Résout le problème classique des Tours de Hanoï avec n disques.
**
** Règles :
** - Il y a 3 tours : A (source), B (auxiliaire), C (destination)
** - n disques de tailles différentes sur la tour A
** - Déplacer tous les disques de A vers C
** - Un seul disque à la fois
** - Un disque plus grand ne peut jamais être sur un plus petit
**
** Prototype :
** void ft_tower_hanoi(int n, char from, char aux, char to);
**
** Exemples :
** ft_tower_hanoi(3, 'A', 'B', 'C');
** Output :
** Move disk 1 from A to C
** Move disk 2 from A to B
** Move disk 1 from C to B
** Move disk 3 from A to C
** Move disk 1 from B to A
** Move disk 2 from B to C
** Move disk 1 from A to C
**
** Complexité : O(2^n) - exponentielle !
*/

#include <stdio.h>

void	ft_tower_hanoi(int n, char from, char aux, char to)
{
	// TODO: À toi de coder !
	// Astuce (stratégie récursive) :
	// 1. Cas de base : si n == 1, déplace le disque de 'from' vers 'to'
	//    printf("Move disk 1 from %c to %c\n", from, to);
	//
	// 2. Cas récursif (n > 1) :
	//    a) Déplace (n-1) disques de 'from' vers 'aux' en utilisant 'to' comme auxiliaire
	//       ft_tower_hanoi(n-1, from, to, aux);
	//
	//    b) Déplace le plus grand disque (n) de 'from' vers 'to'
	//       printf("Move disk %d from %c to %c\n", n, from, to);
	//
	//    c) Déplace (n-1) disques de 'aux' vers 'to' en utilisant 'from' comme auxiliaire
	//       ft_tower_hanoi(n-1, aux, from, to);
}

int	main(void)
{
	printf("=== Tours de Hanoï avec 2 disques ===\n");
	ft_tower_hanoi(2, 'A', 'B', 'C');

	printf("\n=== Tours de Hanoï avec 3 disques ===\n");
	ft_tower_hanoi(3, 'A', 'B', 'C');

	printf("\n=== Tours de Hanoï avec 4 disques ===\n");
	ft_tower_hanoi(4, 'A', 'B', 'C');

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
**
** === Tours de Hanoï avec 2 disques ===
** Move disk 1 from A to B
** Move disk 2 from A to C
** Move disk 1 from B to C
**
** === Tours de Hanoï avec 3 disques ===
** Move disk 1 from A to C
** Move disk 2 from A to B
** Move disk 1 from C to B
** Move disk 3 from A to C
** Move disk 1 from B to A
** Move disk 2 from B to C
** Move disk 1 from A to C
**
** BONUS :
** - Chronomètre : < 20 min
** - Compte le nombre total de mouvements (devrait être 2^n - 1)
** - Visualise graphiquement les tours avec des caractères ASCII
** - Version itérative (bien plus complexe !)
**
** 📚 THÉORIE :
** Le problème des Tours de Hanoï est un exemple classique de récursivité.
** La solution récursive est élégante et courte, mais la version itérative
** est beaucoup plus complexe à comprendre.
**
** Nombre de mouvements pour n disques : 2^n - 1
** - n=1 : 1 mouvement
** - n=2 : 3 mouvements
** - n=3 : 7 mouvements
** - n=4 : 15 mouvements
** - n=64 : 18 446 744 073 709 551 615 mouvements (légende du temple !)
*/
