/* ************************************************************************** */
/*                                                                            */
/*   challenge_ft_comb.c                                                      */
/*                                                                            */
/*   CHALLENGE : ft_comb                                                      */
/*   Afficher toutes les combinaisons de 3 chiffres différents               */
/*                                                                            */
/* ************************************************************************** */

/*
** ÉNONCÉ :
**
** Afficher toutes les combinaisons possibles de trois chiffres différents
** dans l'ordre strictement croissant, séparées par ", ".
**
** SORTIE ATTENDUE :
** 012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789
**
** CONTRAINTES :
** - Les trois chiffres doivent être différents
** - Ordre strictement croissant (a < b < c)
** - Pas de ", " après la dernière combinaison (789)
**
** NOMBRE TOTAL : C(10,3) = 120 combinaisons
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c);
				if (!(a == '7' && b == '8' && c == '9'))
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}

/*
** EXPLICATION DE L'ALGORITHME :
**
** 1. Triple boucle imbriquée
**    a : de '0' à '7'  (pas besoin de '8' ou '9' car besoin de b et c après)
**    b : de a+1 à '8'  (strictement après a)
**    c : de b+1 à '9'  (strictement après b)
**
** 2. Condition a < b < c garantie par :
**    b = a + 1  (b toujours > a)
**    c = b + 1  (c toujours > b)
**
** 3. Condition spéciale pour ", "
**    if (!(a == '7' && b == '8' && c == '9'))
**    → Affiche ", " sauf pour la dernière combinaison
**
** COMBINATOIRE :
** C(n,k) = n! / (k! * (n-k)!)
** C(10,3) = 10! / (3! * 7!) = (10*9*8) / (3*2*1) = 720/6 = 120
*/

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** En C, on utilise 3 boucles imbriquées.
** En JS, plusieurs approches possibles :
**
** 💡 POURQUOI C'EST IMPORTANT POUR UN SENIOR JS :
**
** 1. Génération de combinaisons (LeetCode frequent!)
**    // Approche impérative (comme C)
**    function combinations3Digits() {
**        const result = [];
**        for (let a = 0; a <= 7; a++) {
**            for (let b = a + 1; b <= 8; b++) {
**                for (let c = b + 1; c <= 9; c++) {
**                    result.push(`${a}${b}${c}`);
**                }
**            }
**        }
**        return result;
**    }
**
** 2. Approche récursive (backtracking)
**    function combinations(arr, k) {
**        const result = [];
**        function backtrack(start, current) {
**            if (current.length === k) {
**                result.push([...current]);
**                return;
**            }
**            for (let i = start; i < arr.length; i++) {
**                current.push(arr[i]);
**                backtrack(i + 1, current);
**                current.pop();
**            }
**        }
**        backtrack(0, []);
**        return result;
**    }
**    combinations([0,1,2,3,4,5,6,7,8,9], 3); // 120 combinaisons
**
** 3. Question d'entretien LeetCode #77 (Combinations)
**    "Générer toutes les combinaisons de k nombres parmi n"
**    → Exactement ce problème généralisé !
**
** 4. Performance : boucles vs récursion
**    Boucles imbriquées : O(n³) mais simple
**    Backtracking : O(C(n,k)) mais plus flexible
**    → Pour k=3 fixe, boucles sont plus rapides
**
** 5. Formatage de sortie
**    // ✅ Join avec slice (éviter dernier ", ")
**    result.slice(0, -1).join(', ') + result[result.length - 1]
**
**    // ✅ Join puis replace
**    result.join(', ')
**
**    // ✅ Condition dans loop (comme C)
**    for (let i = 0; i < result.length; i++) {
**        process.stdout.write(result[i]);
**        if (i < result.length - 1) process.stdout.write(', ');
**    }
**
** 🎯 ÉQUIVALENT JS (plusieurs méthodes) :
**
** // Méthode 1 : Triple loop (impérative)
** function printCombinations() {
**     const combos = [];
**     for (let a = 0; a <= 7; a++) {
**         for (let b = a + 1; b <= 8; b++) {
**             for (let c = b + 1; c <= 9; c++) {
**                 combos.push(`${a}${b}${c}`);
**             }
**         }
**     }
**     console.log(combos.join(', '));
** }
**
** // Méthode 2 : Récursive (backtracking)
** function getCombinations(n, k) {
**     const result = [];
**     function backtrack(start, combo) {
**         if (combo.length === k) {
**             result.push(combo.join(''));
**             return;
**         }
**         for (let i = start; i < n; i++) {
**             combo.push(i);
**             backtrack(i + 1, combo);
**             combo.pop();
**         }
**     }
**     backtrack(0, []);
**     return result;
** }
** console.log(getCombinations(10, 3).join(', '));
**
** // Méthode 3 : Générateur (avancée)
** function* combinationsGenerator(arr, k) {
**     if (k === 0) {
**         yield [];
**         return;
**     }
**     for (let i = 0; i <= arr.length - k; i++) {
**         for (const combo of combinationsGenerator(arr.slice(i + 1), k - 1)) {
**             yield [arr[i], ...combo];
**         }
**     }
** }
** const combos = [...combinationsGenerator([0,1,2,3,4,5,6,7,8,9], 3)];
**
** 💼 UTILISATION EN PRODUCTION :
**
** // Génération de codes PIN, passwords
** function generatePinCombinations(length) {
**     const result = [];
**     function generate(current) {
**         if (current.length === length) {
**             result.push(current);
**             return;
**         }
**         for (let i = 0; i < 10; i++) {
**             generate(current + i);
**         }
**     }
**     generate('');
**     return result;
** }
**
** // Sélection de k éléments parmi n (lottery)
** function lottery(n, k) {
**     return combinations(Array.from({length: n}, (_, i) => i + 1), k);
** }
*/

int	main(void)
{
	ft_comb();
	ft_putchar('\n');
	return (0);
}

/*
** TESTS :
**
** COMPILATION :
** gcc -Wall -Wextra -Werror challenge_ft_comb.c -o test_comb
** ./test_comb
**
** VÉRIFICATIONS :
** 1. Début : "012, 013, 014, ..."
** 2. Fin : "..., 789" (sans ", " après)
** 3. Compte : 120 combinaisons
**
** COMMANDE POUR COMPTER :
** ./test_comb | tr ',' '\n' | wc -l
** → Devrait afficher 120
**
** PATTERNS À NOTER :
** - Premier : 012
** - Dernier : 789
** - Total : C(10,3) = 120
*/

/*
** CONCEPTS CLÉS :
**
** 1. Combinatoire
**    Combinaison C(n,k) : choix de k éléments parmi n sans ordre
**    C(10,3) = 10!/(3!*7!) = 120
**
** 2. Boucles imbriquées
**    Niveau 1 : a (0-7)
**    Niveau 2 : b (a+1 à 8)
**    Niveau 3 : c (b+1 à 9)
**
** 3. Edge case : dernière combinaison
**    Gérer le formatage différemment pour "789"
*/
