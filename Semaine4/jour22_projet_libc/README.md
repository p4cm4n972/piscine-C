# Jour 22 - Libft complète

## Objectif

Créer une bibliothèque C complète avec 40+ fonctions.

## Fonctions à implémenter

### Fonctions is* (7 fonctions)
- ft_isalpha, ft_isdigit, ft_isalnum
- ft_isascii, ft_isprint, ft_isupper, ft_islower

### Fonctions to* (2 fonctions)
- ft_toupper, ft_tolower

### Fonctions str* (15 fonctions)
- ft_strlen, ft_strcpy, ft_strncpy
- ft_strcat, ft_strncat, ft_strcmp, ft_strncmp
- ft_strchr, ft_strrchr, ft_strstr
- ft_strdup, ft_strndup, ft_strlcpy, ft_strlcat, ft_strnstr

### Fonctions mem* (6 fonctions)
- ft_memset, ft_bzero, ft_memcpy
- ft_memmove, ft_memchr, ft_memcmp

### Conversion (2 fonctions)
- ft_atoi, ft_itoa

### Bonus : Listes chaînées (10 fonctions)
- ft_lstnew, ft_lstadd_front, ft_lstadd_back
- ft_lstsize, ft_lstlast, ft_lstdelone
- ft_lstclear, ft_lstiter, ft_lstmap

## Compilation

```bash
make        # Compile libft.a
make clean  # Supprime .o
make fclean # Supprime tout
make re     # Recompile
```

## Usage

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello");
    int len = ft_strlen(str);
    free(str);
    return (0);
}
```

**Temps estimé**: 8-10 heures
**Difficulté**: ⭐⭐⭐⭐
