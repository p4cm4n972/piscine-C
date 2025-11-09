/* ************************************************************************** */
/*                                                                            */
/*   ex01_ft_putchar.c                                                        */
/*                                                                            */
/*   Exercice : ft_putchar                                                    */
/*   Afficher un caractère sur la sortie standard                            */
/*                                                                            */
/* ************************************************************************** */

/*
** ÉNONCÉ :
**
** Écrire une fonction qui affiche un caractère sur la sortie standard.
**
** Prototype : void ft_putchar(char c);
**
** COMPORTEMENT :
** - Afficher le caractère c
** - Utiliser uniquement write() pour afficher
** - Ne pas afficher de retour à la ligne
**
** EXEMPLES :
** ft_putchar('A');     → affiche "A"
** ft_putchar('z');     → affiche "z"
** ft_putchar('\n');    → affiche un retour à la ligne
**
** FONCTION AUTORISÉE :
** - write(int fd, const void *buf, size_t count)
**
** RAPPEL write() :
** - fd = 1 pour STDOUT (sortie standard)
** - buf = pointeur vers les données à écrire
** - count = nombre d'octets à écrire
** - &c crée un pointeur vers la variable c
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** EXPLICATION DU CODE :
**
** write(1, &c, 1)
**   ↓    ↓   ↓
**   fd   buf count
**
** - 1 : File descriptor pour STDOUT (sortie standard)
** - &c : Adresse mémoire du caractère c (pointeur)
** - 1 : Nombre d'octets à écrire (1 char = 1 byte)
**
** Pourquoi &c et pas c ?
** → write() attend un pointeur (void *), pas une valeur directe
** → &c donne l'adresse mémoire où est stocké c
*/

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** En C, afficher un caractère nécessite un appel système (write).
** En JS/Node.js, c'est automatique avec process.stdout :
**
** C       : write(1, &c, 1)
** Node.js : process.stdout.write(c)
** Browser : console.log(c)
**
** 💡 POURQUOI C'EST IMPORTANT POUR UN SENIOR JS :
**
** 1. Comprendre les appels système
**    En JS, console.log() cache la complexité
**    → Sous le capot : buffer → flush → write syscall
**
** 2. Performance : Buffering
**    // ❌ Lent (1 syscall par char)
**    for (let char of str) {
**        process.stdout.write(char);
**    }
**
**    // ✅ Rapide (1 syscall)
**    process.stdout.write(str);
**
** 3. Pointeurs vs Valeurs
**    C : write(1, &c, 1)  → Passe l'ADRESSE de c
**    JS : write(c)        → Passe la VALEUR (copie)
**    → En JS, tout passe par valeur (sauf objets/arrays)
**
** 4. Question d'entretien senior :
**    "Quelle est la différence entre process.stdout.write et console.log ?"
**    → console.log ajoute \n et serialise les objets
**    → write() est plus bas niveau (comme en C)
**
** 🎯 ÉQUIVALENT JS (Node.js) :
**
** function ft_putchar(c) {
**     process.stdout.write(c);
** }
**
** // Ou en browser (moins précis car ajoute \n)
** function ft_putchar(c) {
**     console.log(c);
** }
**
** 💼 UTILISATION EN PRODUCTION :
**
** // Custom logger sans \n automatique
** class Logger {
**     static write(char) {
**         process.stdout.write(char);
**     }
**
**     static progress(percent) {
**         process.stdout.write(`\r${percent}%`); // \r = retour chariot
**     }
** }
**
** // Barre de progression animée
** for (let i = 0; i <= 100; i++) {
**     Logger.progress(i);
** }
*/

/*
** TESTS (à compiler avec un main) :
**
** int main(void)
** {
**     ft_putchar('H');
**     ft_putchar('e');
**     ft_putchar('l');
**     ft_putchar('l');
**     ft_putchar('o');
**     ft_putchar('\n');  // Retour à la ligne
**
**     ft_putchar('4');
**     ft_putchar('2');
**     ft_putchar('\n');
**
**     return (0);
** }
**
** COMPILATION :
** gcc -Wall -Wextra -Werror ex01_ft_putchar.c -o test_putchar
** ./test_putchar
**
** SORTIE ATTENDUE :
** Hello
** 42
*/

/*
** CONCEPTS CLÉS :
**
** 1. File Descriptors
**    0 = STDIN (entrée standard)
**    1 = STDOUT (sortie standard)
**    2 = STDERR (sortie d'erreur)
**
** 2. Pointeurs (&)
**    &variable retourne l'adresse mémoire
**    → Nécessaire pour write() qui attend void *
**
** 3. Taille des types
**    char = 1 byte
**    → write(1, &c, 1) écrit exactement 1 octet
*/
