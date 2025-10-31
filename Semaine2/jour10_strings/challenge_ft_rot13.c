/*
** CHALLENGE : ft_rot13
**
** Applique le chiffrement ROT13 à une chaîne de caractères.
** ROT13 est un chiffrement par substitution simple : chaque lettre est
** remplacée par la lettre située 13 positions plus loin dans l'alphabet.
**
** Prototype :
** char *ft_rot13(char *str);
**
** Règles :
** - Seules les lettres sont transformées (a-z et A-Z)
** - Les chiffres, espaces et ponctuation restent inchangés
** - ROT13 est son propre inverse : rot13(rot13(x)) = x
**
** Exemples :
** "Hello" -> "Uryyb"
** "Uryyb" -> "Hello" (réversible !)
** "Test123" -> "Grfg123"
** "A-Z" -> "N-M"
**
** Table de transformation :
** a -> n, b -> o, c -> p, ..., m -> z, n -> a, ..., z -> m
** A -> N, B -> O, C -> P, ..., M -> Z, N -> A, ..., Z -> M
*/

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_rot13(char *str)
{
	// TODO: Implémente ROT13
	// 1. Parcourir la chaîne caractère par caractère
	// 2. Pour chaque caractère :
	//    - Si c'est une minuscule (a-z) :
	//      str[i] = ((str[i] - 'a' + 13) % 26) + 'a';
	//    - Si c'est une majuscule (A-Z) :
	//      str[i] = ((str[i] - 'A' + 13) % 26) + 'A';
	//    - Sinon, ne rien faire
	// 3. Retourner str (modification en place)

	return (str);
}

int	main(void)
{
	char	str1[] = "Hello World";
	char	str2[] = "Test123";
	char	str3[] = "ABC xyz";
	char	str4[] = "The quick brown fox jumps over the lazy dog";

	printf("=== Test 1 ===\n");
	printf("Original : %s\n", str1);
	ft_rot13(str1);
	printf("ROT13    : %s\n", str1);
	ft_rot13(str1);
	printf("ROT13x2  : %s\n\n", str1);

	printf("=== Test 2 ===\n");
	printf("Original : %s\n", str2);
	ft_rot13(str2);
	printf("ROT13    : %s\n\n", str2);

	printf("=== Test 3 ===\n");
	printf("Original : %s\n", str3);
	ft_rot13(str3);
	printf("ROT13    : %s\n\n", str3);

	printf("=== Test 4 ===\n");
	printf("Original : %s\n", str4);
	ft_rot13(str4);
	printf("ROT13    : %s\n", str4);

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 ===
** Original : Hello World
** ROT13    : Uryyb Jbeyq
** ROT13x2  : Hello World
**
** === Test 2 ===
** Original : Test123
** ROT13    : Grfg123
**
** === Test 3 ===
** Original : ABC xyz
** ROT13    : NOP klm
**
** === Test 4 ===
** Original : The quick brown fox jumps over the lazy dog
** ROT13    : Gur dhvpx oebja sbk whzcf bire gur ynml qbt
**
** BONUS :
** - Chronomètre : < 15 min
** - Implémente ft_rot_n(char *str, int n) pour ROT-N générique
** - Crée un déchiffreur de César (essaie toutes les rotations)
** - Lis une ligne depuis stdin et applique ROT13
**
** 📚 THÉORIE :
** ROT13 est un cas particulier du chiffre de César (rotation de 13).
**
** Historique :
** - Utilisé dans les forums USENET pour masquer les spoilers
** - Très faible sécurité (trivialement cassable)
** - Intéressant car c'est son propre inverse
**
** Propriété mathématique :
** ROT13 fonctionne parce que l'alphabet a 26 lettres et 13 est la moitié.
** Donc : 13 + 13 = 26 ≡ 0 (mod 26)
**
** Utilisations modernes :
** - Obscurcissement léger (pas de cryptographie !)
** - Exercices pédagogiques
** - Easter eggs dans le code
*/
