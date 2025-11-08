/* ************************************************************************** */
/*                                                                            */
/*   ex03_ft_strcpy.c                                                         */
/*                                                                            */
/*   Exercice : ft_strcpy                                                     */
/*   Reproduire le comportement de la fonction strcpy (man strcpy)            */
/*                                                                            */
/* ************************************************************************** */

/*
** ÉNONCÉ :
**
** Écrire une fonction qui copie une chaîne de caractères dans une autre.
**
** Prototype : char *ft_strcpy(char *dest, char *src);
**
** COMPORTEMENT :
** - Copier tous les caractères de src vers dest (y compris le '\0')
** - Retourner un pointeur vers dest
**
** EXEMPLES :
** char dest[20];
** ft_strcpy(dest, "Hello");  → dest contient "Hello\0"
** ft_strcpy(dest, "");       → dest contient "\0"
**
** ⚠️ ATTENTION :
** - dest DOIT être assez grand pour contenir src + '\0'
** - Si dest est trop petit → BUFFER OVERFLOW (comportement indéfini)
** - La fonction ne vérifie PAS la taille de dest
**
** RAPPEL :
** En C, c'est au programmeur de s'assurer que dest est assez grand !
** Contrairement à des langages comme Python, il n'y a pas de vérification
** automatique.
*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
** EXPLICATION DU CODE :
**
** while (src[i])
**   ↓
**   Tant que src[i] n'est pas '\0', copier le caractère
**
** dest[i] = '\0';
**   ↓
**   Important ! Copier le caractère de fin de chaîne
**
** return (dest);
**   ↓
**   Retourner le pointeur vers la destination (convention de strcpy)
*/

/*
** VISUALISATION :
**
** Avant :
** src  : ['H', 'i', '\0', ?, ?]
** dest : [?,   ?,   ?,    ?, ?]
**
** Après ft_strcpy(dest, src) :
** src  : ['H', 'i', '\0', ?, ?]  (inchangé)
** dest : ['H', 'i', '\0', ?, ?]  (copié)
*/

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** En C, strcpy() copie manuellement caractère par caractère.
** En JS, les strings sont IMMUABLES (non modifiables) :
**
** C  : strcpy(dest, src)  → Copie physique, modification en place
** JS : let dest = src     → Copie de référence (strings immuables)
** JS : dest = src.slice() → Inutile ! Les strings ne sont pas modifiables
**
** 💡 POURQUOI C'EST IMPORTANT POUR UN SENIOR JS :
**
** 1. Immuabilité des strings JS
**    let str = "Hello";
**    str[0] = "h";        // ❌ Ne fait RIEN en JS (mode strict: erreur)
**    str = "h" + str.slice(1);  // ✅ Création d'une NOUVELLE string
**
** 2. Performance : concatenation vs array
**    // ❌ Lent (crée n strings intermédiaires)
**    let result = "";
**    for (let i = 0; i < 1000; i++) {
**        result += "word";  // Comme strcpy à chaque fois !
**    }
**
**    // ✅ Rapide (1 seule allocation finale)
**    const arr = [];
**    for (let i = 0; i < 1000; i++) {
**        arr.push("word");
**    }
**    const result = arr.join("");
**
** 3. Copie profonde vs superficielle (objets)
**    // String : toujours "deep copy" (immuables)
**    let a = "Hello";
**    let b = a;
**    b = "World";  // a reste "Hello"
**
**    // Objet : shallow copy par défaut
**    let obj1 = { name: "Alice" };
**    let obj2 = obj1;         // ❌ Même référence !
**    let obj3 = { ...obj1 };  // ✅ Nouvelle copie
**
** 4. Question d'entretien type :
**    "Pourquoi concat() est plus rapide que += dans une boucle ?"
**    → Parce que += fait l'équivalent de strcpy à chaque itération !
**
** 🎯 ÉQUIVALENT JS (pour les tableaux mutables) :
**
** function arrayCopy(dest, src) {
**     for (let i = 0; i < src.length; i++) {
**         dest[i] = src[i];
**     }
**     return dest;
** }
**
** // Ou avec spread operator (ES6+)
** const destArray = [...srcArray];
**
** ⚠️ SÉCURITÉ : Buffer Overflow en C vs JS
**
** C  : char dest[3]; strcpy(dest, "Hello");  → CRASH (buffer overflow)
** JS : let dest = "Hello";                   → Pas de crash (allocation auto)
**
** 💼 CONCEPT CLÉ POUR SENIOR :
** En JS, comprendre l'immuabilité évite des bugs et optimise les perfs.
** React/Redux exploitent cette propriété pour détecter les changements !
*/

/*
** TESTS (à compiler avec un main) :
**
** #include <stdio.h>
** #include <string.h>
**
** int main(void)
** {
**     char dest1[20];
**     char dest2[20];
**
**     // Test 1 : Copie simple
**     ft_strcpy(dest1, "Hello");
**     printf("ft_strcpy(dest, \"Hello\") = \"%s\"\n", dest1);
**
**     // Test 2 : Comparaison avec strcpy
**     strcpy(dest2, "Hello");
**     printf("strcpy(dest, \"Hello\") = \"%s\"\n", dest2);
**     printf("Identiques ? %s\n\n", strcmp(dest1, dest2) == 0 ? "OUI" : "NON");
**
**     // Test 3 : Chaîne vide
**     ft_strcpy(dest1, "");
**     printf("ft_strcpy(dest, \"\") = \"%s\"\n", dest1);
**
**     // Test 4 : Retour de la fonction
**     char *result = ft_strcpy(dest1, "Test");
**     printf("Retour de ft_strcpy : \"%s\"\n", result);
**     printf("dest == result ? %s\n", dest1 == result ? "OUI" : "NON");
**
**     return (0);
** }
**
** COMPILATION :
** gcc -Wall -Wextra -Werror ex03_ft_strcpy.c -o test_strcpy
** ./test_strcpy
**
** ⚠️ EXEMPLE D'ERREUR (buffer overflow) :
** char dest[3];
** ft_strcpy(dest, "Hello");  // DANGER ! dest trop petit (3 < 6)
**                             // → Écrit en dehors de dest → crash possible
*/
