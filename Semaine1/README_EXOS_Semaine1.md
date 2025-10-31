# 🧩 SEMAINE 1 – SYNTAXE & BASES DU C

## 📋 Vue d'ensemble

**Durée :** 18-26 heures
**Niveau :** Débutant
**Objectif :** Maîtriser la syntaxe C, les pointeurs basiques et les outils de développement

### 📊 Progression

| Jour | Thème | Exercices | Status |
|------|-------|-----------|--------|
| Jour 1 | Premiers pas | 6 fichiers | ✅ 100% |
| Jour 2 | Chaînes | 5 fichiers | ✅ 100% |
| Jour 3 | Fonctions | 5 fichiers | ✅ 100% |
| Jour 4 | Tableaux | 4 fichiers | ✅ 100% |
| Jour 5 | Makefile/Git | 2 fichiers | ✅ 100% |
| Jour 6 | Libft | 5 fichiers | ✅ 100% |

**Total :** 27 exercices ✅ 100% complété

---

---

## 🗓️ Jour 1 — Premiers pas en C

### ex01 : ft_putchar
Écris une fonction qui affiche un seul caractère à l’écran.  
Prototype :
```c
void ft_putchar(char c);
```
⚙️ **Règle** : tu dois utiliser `write(1, &c, 1)` (pas `printf`).

---

### ex02 : ft_print_alphabet
Affiche toutes les lettres minuscules de l’alphabet, de `a` à `z`.  
Prototype :
```c
void ft_print_alphabet(void);
```

---

### ex03 : ft_print_numbers
Affiche les chiffres de `0` à `9`.  
Prototype :
```c
void ft_print_numbers(void);
```

---

### ex04 : ft_is_negative
Écris une fonction qui affiche :
- `P` si le nombre est positif ou nul  
- `N` si le nombre est négatif  

Prototype :
```c
void ft_is_negative(int n);
```

---

### Challenge : ft_comb
Affiche toutes les combinaisons possibles de trois chiffres différents dans l’ordre croissant.  
Exemple :  
`012, 013, 014, …, 789`

---

## 🗓️ Jour 2 — Chaînes de caractères

### ex01 : ft_strlen
Retourne la longueur d’une chaîne.  
```c
int ft_strlen(char *str);
```

### ex02 : ft_strcmp
Compare deux chaînes.  
Retourne :
- négatif si `s1 < s2`
- 0 si égales
- positif si `s1 > s2`

### ex03 : ft_strcpy
Copie une chaîne dans une autre.  
```c
char *ft_strcpy(char *dest, char *src);
```

### ex04 : ft_putstr
Affiche une chaîne.  
```c
void ft_putstr(char *str);
```

### Challenge : ft_strrev
Inverse une chaîne **en place**.

---

## 🗓️ Jour 3 — Conditions & fonctions

### ex01 : ft_iterative_factorial
Calcule la factorielle d’un nombre entier `n`.  
Retourne 0 si `n < 0`.

### ex02 : ft_iterative_power
Calcule `nb` à la puissance `power`.

### ex03 : ft_sqrt
Retourne la racine carrée entière d’un nombre.  
Retourne 0 si ce n’est pas un carré parfait.

### ex04 : ft_is_prime
Retourne 1 si le nombre est premier, 0 sinon.

### Challenge : ft_find_next_prime
Retourne le plus petit nombre premier ≥ `nb`.

---

## 🗓️ Jour 4 — Tableaux & pointeurs

### ex01 : ft_swap
Échange les valeurs de deux entiers via leurs adresses.

### ex02 : ft_sort_int_tab
Trie un tableau d’entiers par ordre croissant.

### ex03 : ft_rev_int_tab
Inverse l’ordre d’un tableau d’entiers.

### Challenge : ft_max
Retourne la plus grande valeur du tableau.

---

## 🗓️ Jour 5 — Makefile & Git

### ex01 : Makefile
Crée un fichier `Makefile` permettant de compiler tous les `.c` du dossier en une librairie statique `libft.a`.

**Règles à inclure** :
- `all`
- `clean`
- `fclean`
- `re`

### ex02 : Git
Initialise un dépôt local, ajoute tes fichiers et fais un premier commit propre.

---

## 🗓️ Jour 6 — Mini-projet : libft

Regroupe toutes les fonctions des jours précédents dans une librairie `libft.a`.  
Teste-la avec un `main.c` capable d’utiliser les fonctions suivantes :
```c
ft_putchar, ft_putstr, ft_strlen, ft_strcmp, ft_strcpy, ft_swap, ft_sort_int_tab
```

### Challenge final : ft_printf
Recode une version simplifiée de `printf` (supportant `%c`, `%s`, `%d`).

---

## 🧠 Bonus chaque soir
- Implémente une fonction que tu as déjà vue **sans regarder ton ancien code**.
- Note dans un carnet les erreurs récurrentes.
- Chrono : ≤ 45 min / exo max.

---

## 🛠️ Compilation et Tests

### Compiler un exercice

```bash
cd Semaine1/jour01
gcc -Wall -Wextra -Werror ex01_ft_putchar.c -o test
./test
```

### Compiler la libft

```bash
cd Semaine1/jour06_libft
make
./test_libft
make clean
```

### Flags obligatoires

```bash
gcc -Wall -Wextra -Werror -std=c99 fichier.c -o programme
```

---

## 📚 Documentation complète

- **[SEMAINE1_COMPLETE.md](SEMAINE1_COMPLETE.md)** - Statut détaillé de tous les fichiers
- **[GUIDE_COMPLET_S1.md](GUIDE_COMPLET_S1.md)** - Guide final avec templates
- **[jour05/ex02_git_guide.md](jour05/ex02_git_guide.md)** - Guide Git
- **[jour06/README.md](jour06/README.md)** - Documentation Libft

---

## 🎯 Objectifs de la Semaine 1

À la fin de cette semaine, tu dois maîtriser :

- ✅ Syntaxe C complète (variables, types, opérateurs)
- ✅ Boucles (for, while) et conditions (if/else)
- ✅ Fonctions et prototypes
- ✅ Pointeurs basiques (* et &)
- ✅ Tableaux et manipulation
- ✅ Chaînes de caractères (char *)
- ✅ Makefile et compilation
- ✅ Git et versioning

---

## 📈 Progression

**Semaine 1 : ████████████ 100% complété**

Prêt pour la **Semaine 2 : Algorithmique** ! 🚀

---

**Dernière mise à jour :** 31 Octobre 2025
**Niveau :** Piscine C - Semaine 1
