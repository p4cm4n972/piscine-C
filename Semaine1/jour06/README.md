# 📚 JOUR 06 : Mini-projet libft

## 🎯 Objectif
Créer une bibliothèque statique `libft.a` regroupant toutes les fonctions codées durant la semaine.

---

## 📁 Structure du projet

```
jour06/
├── README.md           (ce fichier)
├── Makefile            (compile tout)
├── libft.h             (header avec tous les prototypes)
├── srcs/               (dossier des sources)
│   ├── ft_putchar.c
│   ├── ft_putstr.c
│   ├── ft_strlen.c
│   ├── ft_strcmp.c
│   ├── ft_strcpy.c
│   ├── ft_swap.c
│   └── ft_sort_int_tab.c
├── main.c              (programme de test)
└── libft.a             (généré par make)
```

---

## ⚙️ Étapes

### 1. Copie tes fonctions dans `srcs/`
```bash
# Copie toutes tes fonctions depuis les jours précédents
cp ../jour01/ex01_ft_putchar.c srcs/ft_putchar.c
cp ../jour02/ex04_ft_putstr.c srcs/ft_putstr.c
# etc.
```

### 2. Crée le fichier header `libft.h`
```c
#ifndef LIBFT_H
# define LIBFT_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
void	ft_swap(int *a, int *b);
void	ft_sort_int_tab(int *tab, int size);

#endif
```

### 3. Crée le Makefile
```makefile
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c \
       srcs/ft_strcmp.c srcs/ft_strcpy.c srcs/ft_swap.c \
       srcs/ft_sort_int_tab.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

### 4. Crée un programme de test
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
	// Test ft_putstr
	ft_putstr("=== Test libft ===\n");

	// Test ft_strlen
	printf("ft_strlen(\"Hello\") = %d\n", ft_strlen("Hello"));

	// Test ft_strcmp
	printf("ft_strcmp(\"abc\", \"abc\") = %d\n", ft_strcmp("abc", "abc"));

	// Test ft_swap
	int a = 42, b = 21;
	printf("Avant swap: a=%d, b=%d\n", a, b);
	ft_swap(&a, &b);
	printf("Après swap: a=%d, b=%d\n", a, b);

	// Test ft_sort_int_tab
	int tab[] = {5, 2, 8, 1, 9};
	printf("Avant tri: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", tab[i]);
	printf("\n");

	ft_sort_int_tab(tab, 5);
	printf("Après tri: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", tab[i]);
	printf("\n");

	return (0);
}
```

### 5. Compile et teste
```bash
# Compile la bibliothèque
make

# Compile le programme de test
gcc -Wall -Wextra -Werror main.c -L. -lft -o test

# Exécute
./test
```

---

## ✅ Checklist

- [ ] Toutes les fonctions copiées dans `srcs/`
- [ ] `libft.h` créé avec tous les prototypes
- [ ] `Makefile` fonctionnel (all, clean, fclean, re)
- [ ] `libft.a` se génère sans erreur
- [ ] `main.c` teste toutes les fonctions
- [ ] Aucune erreur de compilation avec `-Wall -Wextra -Werror`
- [ ] `make clean` et `make fclean` fonctionnent
- [ ] `make re` recompile tout

---

## 🎁 Bonus : Fonctions supplémentaires

Ajoute ces fonctions classiques à ta libft :

### ft_atoi
```c
int ft_atoi(char *str);  // Convertit string en int
```

### ft_strdup
```c
char *ft_strdup(char *src);  // Duplique une chaîne (malloc)
```

### ft_strcat
```c
char *ft_strcat(char *dest, char *src);  // Concatène deux chaînes
```

---

## ⏱️ Temps estimé
- Setup initial : 30 min
- Tests et debug : 30 min
- Bonus : 1h

---

## 📝 Rendu

Assure-toi que :
1. Ton code compile sans warning
2. Ta `libft.a` est réutilisable
3. Ton `main.c` démontre toutes les fonctions
4. Tout est versionné avec Git

```bash
git add .
git commit -m "Complete jour06: libft project"
```
