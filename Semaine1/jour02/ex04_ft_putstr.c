/* ************************************************************************** */
/*                                                                            */
/*   ex04_ft_putstr.c                                                         */
/*                                                                            */
/*   Exercice : ft_putstr                                                     */
/*   Afficher une chaîne de caractères sur la sortie standard                */
/*                                                                            */
/* ************************************************************************** */

/*
** ÉNONCÉ :
**
** Écrire une fonction qui affiche une chaîne de caractères sur la sortie
** standard.
**
** Prototype : void ft_putstr(char *str);
**
** COMPORTEMENT :
** - Afficher tous les caractères de str jusqu'au '\0' (non inclus)
** - Utiliser uniquement write() pour afficher
** - Ne pas afficher de retour à la ligne à la fin
**
** EXEMPLES :
** ft_putstr("Hello");      → affiche "Hello"
** ft_putstr("42\n");       → affiche "42" suivi d'un retour à la ligne
** ft_putstr("");           → n'affiche rien
**
** FONCTION AUTORISÉE :
** - write(int fd, const void *buf, size_t count)
**
** RAPPEL write() :
** - fd = 1 pour STDOUT (sortie standard)
** - buf = pointeur vers les données à écrire
** - count = nombre d'octets à écrire
** - Retourne le nombre d'octets écrits, ou -1 en cas d'erreur
*/

#include <unistd.h>

void	ft_putstr(char *str);

int main(void){
  ft_putstr("hello");
}
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
  write(1, " \n", 2);
}

/*
** EXPLICATION DU CODE :
**a
** while (*str)
**   ↓
**   Tant que le caractère pointé par str n'est pas '\0'
**   (*str équivaut à str[0])
**
** write(1, str, 1);
**   ↓
**   Écrire 1 octet (le caractère actuel) sur stdout (fd = 1)
**
** str++;
**   ↓
**   Avancer le pointeur d'un caractère
*/

/*
** OPTIMISATION POSSIBLE :
**
** Version actuelle : Appelle write() pour CHAQUE caractère
** → Inefficace pour les longues chaînes (beaucoup d'appels système)
**
** Version optimisée : Un seul appel à write() pour toute la chaîne
**
** void	ft_putstr(char *str)
** {
**     int	i;
**
**     i = 0;
**     while (str[i])
**         i++;
**     write(1, str, i);  // Un seul appel avec la longueur totale
** }
**
** Ou encore mieux, en utilisant ft_strlen :
**
** void	ft_putstr(char *str)
** {
**     write(1, str, ft_strlen(str));
** }
*/

/*
** VISUALISATION :
**
** Pour str = "Hi\0" :
**
** Itération 1 : *str = 'H' → write(1, "H", 1) → str++
** Itération 2 : *str = 'i' → write(1, "i", 1) → str++
** Itération 3 : *str = '\0' → STOP
**
** Résultat : "Hi" affiché sur stdout
*/

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** En C, write() est un appel système direct (niveau kernel).
** En JS (Node.js), process.stdout.write() fait la même chose :
**
** C       : write(1, str, len)           → Appel système direct
** Node.js : process.stdout.write(str)   → Wrapper autour de write()
** Node.js : console.log(str)            → Ajoute \n + buffering
**
** 💡 POURQUOI C'EST IMPORTANT POUR UN SENIOR JS :
**
** 1. Comprendre console.log vs process.stdout.write
**    console.log("Hello");              // "Hello\n" (avec retour ligne)
**    process.stdout.write("Hello");     // "Hello" (sans retour ligne)
**
**    // Barre de progression (pas possible avec console.log)
**    process.stdout.write("\rChargement: " + percent + "%");
**
** 2. Performance : Buffering
**    // ❌ Lent (1 appel système par caractère comme version naïve)
**    for (let char of str) {
**        process.stdout.write(char);
**    }
**
**    // ✅ Rapide (1 seul appel système)
**    process.stdout.write(str);
**
** 3. Streams et performance (Node.js senior+)
**    // Pour gros fichiers, utiliser streams
**    const readStream = fs.createReadStream('huge.txt');
**    readStream.pipe(process.stdout);  // Pas de saturation mémoire
**
** 4. Question d'entretien type :
**    "Pourquoi console.log() peut ralentir une application ?"
**    → Appels système coûteux + serialization JSON + buffering
**
** 🎯 ÉQUIVALENT JS (Node.js) :
**
** function ft_putstr(str) {
**     process.stdout.write(str);
** }
**
** // Ou en natif navigateur (ancien, éviter)
** document.write(str);  // ❌ Jamais en production !
**
** 💼 UTILISATION EN PRODUCTION :
**
** // Logger personnalisé sans \n automatique
** class Logger {
**     write(msg) {
**         process.stdout.write(`[${new Date().toISOString()}] ${msg}`);
**     }
**
**     progress(percent) {
**         process.stdout.write(`\rProgress: ${percent}%`);
**     }
** }
**
** // Animation terminal (spinner)
** const frames = ['⠋', '⠙', '⠹', '⠸', '⠼', '⠴', '⠦', '⠧', '⠇', '⠏'];
** let i = 0;
** setInterval(() => {
**     process.stdout.write('\r' + frames[i++ % frames.length] + ' Loading...');
** }, 80);
**
** ⚡ OPTIMISATION :
** Version actuelle : O(n) appels système (1 par caractère)
** Version optimisée : O(1) appel système (toute la chaîne)
**
** → En JS, toujours préférer 1 gros write à n petits writes !
*/

/*
** TESTS (à compiler avec un main) :
**
** int main(void)
** {
**     ft_putstr("Hello World");
**     write(1, "\n", 1);  // Retour à la ligne manuel
**
**     ft_putstr("42");
**     write(1, "\n", 1);
**
**     ft_putstr("");  // N'affiche rien
**     write(1, "(vide)\n", 7);
**
**     ft_putstr("Ligne 1\nLigne 2\n");  // Avec retours à la ligne
**
**     return (0);
** }
**
** COMPILATION :
** gcc -Wall -Wextra -Werror ex04_ft_putstr.c -o test_putstr
** ./test_putstr
**
** SORTIE ATTENDUE :
** Hello World
** 42
** (vide)
** Ligne 1
** Ligne 2
*/

/*
** DIFFÉRENCE AVEC printf() :
**
** printf("Hello");   → Utilise un buffer, flush automatique avec \n
** ft_putstr("Hello"); → Écrit directement, pas de buffer
**
** printf() est plus pratique mais ft_putstr() vous apprend :
** - Comment fonctionne l'affichage au niveau système
** - La différence entre buffer et écriture directe
** - L'utilisation de write() (appel système)
*/
