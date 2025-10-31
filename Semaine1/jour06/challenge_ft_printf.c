/*
** CHALLENGE FINAL : ft_printf (version simplifiée)
**
** Recode une version basique de printf qui supporte :
** - %c : caractère
** - %s : chaîne de caractères
** - %d : entier décimal
** - %% : caractère %
**
** Prototype :
** void ft_printf(char *format, ...);
**
** Exemples :
** ft_printf("Hello %s!\n", "World");           -> Hello World!
** ft_printf("Char: %c\n", 'A');                -> Char: A
** ft_printf("Number: %d\n", 42);               -> Number: 42
** ft_printf("Mix: %s has %d points\n", "Bob", 100);  -> Mix: Bob has 100 points
** ft_printf("Percent: %%\n");                  -> Percent: %
**
** Contraintes :
** - Utilise <stdarg.h> pour les arguments variables
** - Réutilise ft_putchar et ft_putstr
** - Gère les nombres négatifs pour %d
*/

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	// TODO: Affiche un nombre entier
	// Astuce :
	// 1. Gère le cas spécial de INT_MIN (-2147483648)
	// 2. Si négatif, affiche '-' et prend l'opposé
	// 3. Utilise la récursion : divise par 10, affiche le quotient, puis le reste
}

void	ft_printf(char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			// TODO: Traite les différents formats
			// if (format[i] == 'c')
			//     ...
			// else if (format[i] == 's')
			//     ...
			// etc.
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;
	}

	va_end(args);
}

int	main(void)
{
	// Tests de ft_printf
	ft_printf("=== Tests ft_printf ===\n");

	ft_printf("Test %%c: %c\n", 'A');
	ft_printf("Test %%s: %s\n", "Hello World");
	ft_printf("Test %%d positif: %d\n", 42);
	ft_printf("Test %%d négatif: %d\n", -42);
	ft_printf("Test %%d zéro: %d\n", 0);
	ft_printf("Test %%%%: %%\n");

	ft_printf("\nTest complexe: %s a %d ans et aime le caractère '%c'.\n",
		"Alice", 25, 'C');

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Tests ft_printf ===
** Test %c: A
** Test %s: Hello World
** Test %d positif: 42
** Test %d négatif: -42
** Test %d zéro: 0
** Test %%: %
**
** Test complexe: Alice a 25 ans et aime le caractère 'C'.
**
** ⏱️ OBJECTIFS :
** - Version basique (%c, %s, %d, %%) : 1h30
** - Tests complets : 30 min
** - Bonus (%x, %p) : 2h
**
** 📚 RESSOURCES :
** - man stdarg
** - man va_start, va_arg, va_end
** - Recherche "variadic functions in C"
**
** 🎯 NIVEAU EPITA :
** Ce challenge te prépare au vrai ft_printf de la piscine EPITA.
** Maîtriser les fonctions variadiques est essentiel !
*/
