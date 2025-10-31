# 📝 JOUR 11 : Projet word_sort

## 🎯 Objectif
Créer un programme qui trie des mots passés en arguments de ligne de commande par ordre alphabétique.

---

## 📋 Description du projet

Le programme `word_sort` prend des mots en arguments et les affiche triés par ordre alphabétique.

### Exemple d'utilisation
```bash
./word_sort pomme banane cerise
# Output: banane cerise pomme

./word_sort zèbre abeille chat
# Output: abeille chat zèbre

./word_sort
# Output: (rien)
```

---

## 📁 Structure du projet

```
jour11_word_sort/
├── README.md           (ce fichier)
├── Makefile            (compilation)
├── word_sort.c         (version de base)
└── word_sort_advanced.c (bonus avec options)
```

---

## 🔧 Compilation

### Avec Makefile
```bash
make                # Compile le programme
make clean          # Supprime les .o
make fclean         # Supprime les .o et l'exécutable
make re             # Recompile tout
```

### Manuellement
```bash
gcc -Wall -Wextra -Werror word_sort.c -o word_sort
```

---

## 💻 Implémentation de base

Le fichier `word_sort.c` actuel contient :

### Fonction principale : `ft_sort_words`
```c
void ft_sort_words(char **tab, int size)
```
- Trie un tableau de chaînes par ordre alphabétique
- Utilise l'algorithme de tri à bulles avec `strcmp`
- Modifie le tableau en place (échange de pointeurs)

### Main
```c
int main(int ac, char **av)
```
- Vérifie qu'il y a au moins un argument
- Appelle `ft_sort_words` sur `av + 1` (ignore le nom du programme)
- Affiche les mots triés séparés par des espaces

---

## 🎓 Concepts clés

### 1. argc et argv
```c
int main(int argc, char **argv)
```
- `argc` : nombre d'arguments (argument count)
- `argv` : tableau de pointeurs vers les chaînes (argument vector)
- `argv[0]` : nom du programme
- `argv[1]`, `argv[2]`, ... : arguments

### 2. Tableaux de pointeurs (char **)
```c
char **tab;  // Pointeur vers un pointeur de char
```
- `tab` : adresse du premier pointeur
- `tab[i]` : le i-ème pointeur (pointe vers une chaîne)
- `tab[i][j]` : le j-ème caractère de la i-ème chaîne

### 3. strcmp
```c
int strcmp(const char *s1, const char *s2);
```
- Retourne < 0 si s1 < s2 (ordre alphabétique)
- Retourne 0 si s1 == s2
- Retourne > 0 si s1 > s2

### 4. Échange de pointeurs
```c
char *tmp;
tmp = tab[i];
tab[i] = tab[j];
tab[j] = tmp;
```
On échange les **pointeurs**, pas les chaînes elles-mêmes.

---

## ✅ Checklist

### Version de base
- [ ] Le programme compile sans erreur ni warning
- [ ] Trie correctement 2 mots
- [ ] Trie correctement 5+ mots
- [ ] Gère le cas sans arguments (affiche rien)
- [ ] Gère les mots avec majuscules/minuscules
- [ ] Le Makefile fonctionne (all, clean, fclean, re)

### Tests
```bash
# Test 1 : Ordre simple
./word_sort pomme banane cerise
# Attendu : banane cerise pomme

# Test 2 : Majuscules/minuscules
./word_sort Zebra Apple banana
# Attendu : Apple Zebra banana (ASCII : majuscules < minuscules)

# Test 3 : Sans arguments
./word_sort
# Attendu : (rien)

# Test 4 : Un seul mot
./word_sort hello
# Attendu : hello

# Test 5 : Mots identiques
./word_sort test test test
# Attendu : test test test
```

---

## 🎁 Bonus : word_sort_advanced.c

Crée une version avancée avec options :

### Options à implémenter
```bash
# -r : Ordre inversé (reverse)
./word_sort -r pomme banane cerise
# Output: pomme cerise banane

# -i : Insensible à la casse (case-insensitive)
./word_sort -i Zebra Apple banana
# Output: Apple banana Zebra

# -u : Uniquement les mots uniques (unique)
./word_sort -u pomme banane pomme cerise
# Output: banane cerise pomme

# Combinaison d'options
./word_sort -ri Zebra Apple banana Apple
# Output: Zebra banana Apple
```

### Parsing des options
```c
int parse_options(int ac, char **av, int *reverse, int *case_insensitive, int *unique)
{
    int i = 1;

    while (i < ac && av[i][0] == '-')
    {
        int j = 1;
        while (av[i][j])
        {
            if (av[i][j] == 'r')
                *reverse = 1;
            else if (av[i][j] == 'i')
                *case_insensitive = 1;
            else if (av[i][j] == 'u')
                *unique = 1;
            j++;
        }
        i++;
    }
    return (i); // Retourne l'index du premier mot
}
```

---

## 🧪 Tests avancés

### Test de performance
```bash
# Générer 1000 mots aléatoires
./generate_words.sh 1000 > words.txt
time ./word_sort $(cat words.txt)
```

### Test avec valgrind
```bash
valgrind --leak-check=full ./word_sort pomme banane cerise
# Aucune fuite mémoire (pas de malloc dans la version de base)
```

---

## 📚 Ressources

### Fonctions autorisées
- `strcmp` (man 3 strcmp)
- `printf` / `write`

### Pour aller plus loin
- `strcasecmp` : comparaison insensible à la casse
- `qsort` : fonction de tri générique de la libc
- Algorithmes de tri plus efficaces (quick sort, merge sort)

---

## ⏱️ Temps estimé

- Version de base : 1h - 1h30
- Tests et validation : 30 min
- Version avancée (bonus) : 2h
- **Total** : 2h - 4h

---

## 🎯 Critères de réussite

Tu as réussi ce projet si :
- ✅ Le programme compile sans erreur avec `-Wall -Wextra -Werror`
- ✅ Le tri fonctionne correctement dans tous les cas
- ✅ Le Makefile est fonctionnel
- ✅ Tu comprends les pointeurs de pointeurs (char **)
- ✅ Tu sais utiliser argc et argv

---

## 💡 Astuces

### Debugging
```c
// Affiche le tableau avant tri
printf("Avant tri:\n");
for (int i = 0; i < size; i++)
    printf("  [%d] = '%s'\n", i, tab[i]);
```

### Comparaison insensible à la casse
```c
#include <strings.h>
if (strcasecmp(tab[i], tab[j]) > 0)
    // ...
```

### Éviter les doublons
```c
// Après le tri, parcours et saute les doublons
for (int i = 0; i < size; i++)
{
    if (i == 0 || strcmp(tab[i], tab[i-1]) != 0)
        printf("%s ", tab[i]);
}
```

---

**Bon courage ! Ce projet te prépare aux programmes qui manipulent des arguments de ligne de commande. 🚀**
