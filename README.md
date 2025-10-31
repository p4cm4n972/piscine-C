# 🏊 Piscine C - Formation Intensive 4 Semaines

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Progress](https://img.shields.io/badge/Progress-75%25-brightgreen)](https://github.com/p4cm4n972/piscine-C)

> Programme complet d'entraînement intensif en programmation C
> **~100 fichiers | ~9000 lignes de code | 70+ exercices**

---

## 📖 À propos

Ce repository contient l'intégralité d'une **Piscine C** (bootcamp intensif) couvrant 4 semaines de formation progressive, du niveau débutant au niveau avancé, avec des exercices pratiques, des projets complets et une documentation exhaustive.

**Auteur :** Manuel ADELE
**Durée :** 4 semaines (~120 heures)
**Niveau :** Débutant → Avancé

---

## 🎯 Objectifs

- ✅ Maîtriser la syntaxe C complète
- ✅ Comprendre le fonctionnement de la machine (mémoire, pointeurs)
- ✅ Implémenter des algorithmes fondamentaux (tri, recherche, récursion)
- ✅ Gérer la mémoire dynamique (malloc, free, valgrind)
- ✅ Créer des structures de données (listes chaînées, arbres)
- ✅ Développer des projets système (mini-shell, grep, allocateur)

---

## 📊 Structure du Programme

| Semaine | Thème | Exercices | Status | Durée |
|---------|-------|-----------|--------|-------|
| **[Semaine 1](Semaine1/)** | Syntaxe & Bases du C | 35 fichiers | ✅ 100% | 18-26h |
| **[Semaine 2](Semaine2/)** | Algorithmique Pure | 35 fichiers | ✅ 100% | 26-32h |
| **[Semaine 3](Semaine3/)** | Mémoire & Pointeurs | 12 fichiers | ✅ 100% structure | 32-40h |
| **[Semaine 4](Semaine4/)** | Projets Avancés | En cours | 📋 20% | 40-54h |

**Progression globale : 75%** 🎉

---

## 🗂️ Contenu Détaillé

### 📅 Semaine 1 : Syntaxe & Bases
- **Jour 1-2 :** Variables, types, boucles, chaînes de caractères
- **Jour 3-4 :** Fonctions, tableaux, pointeurs basiques
- **Jour 5-6 :** Makefile, Git, bibliothèque statique (libft)

**Compétences acquises :**
- Syntaxe C complète
- Manipulation de chaînes (`ft_strlen`, `ft_strcmp`, `ft_strcpy`)
- Algorithmes basiques (factorielle, nombres premiers, racine carrée)

### 📅 Semaine 2 : Algorithmique
- **Jour 7 :** Récursivité (Fibonacci, Tours de Hanoï)
- **Jour 8 :** Algorithmes de tri (Bubble, Selection, Quick Sort, Merge Sort)
- **Jour 9 :** Algorithmes de recherche (linéaire, binaire)
- **Jour 10-11 :** Manipulation avancée de strings, parsing
- **Jour 12 :** Projet final (jeu de devinettes avec IA)

**Compétences acquises :**
- Complexité algorithmique (O(n), O(n log n), O(log n))
- Récursion et cas de base
- Tri et recherche optimisés

### 📅 Semaine 3 : Mémoire & Pointeurs
- **Jour 13 :** Allocation dynamique (`malloc`, `free`, `calloc`, `realloc`)
- **Jour 14 :** Listes chaînées (création, inversion, tri)
- **Jour 15-16 :** Structures personnalisées, parsing avancé
- **Jour 17 :** Mini-shell (fork, execve, built-ins)
- **Jour 18 :** Projet mémoire (allocateur / database / text editor)

**Compétences acquises :**
- Gestion mémoire complète (valgrind 0 leaks)
- Listes chaînées et algorithmes associés
- Processus Unix (fork, exec, waitpid)

### 📅 Semaine 4 : Projets Avancés
- **Jour 19 :** Manipulation de fichiers (`ft_cat`, `ft_wc`, `ft_cp`)
- **Jour 20 :** Mini-grep (regex, colorisation)
- **Jour 21 :** Hash Table (gestion des collisions)
- **Jour 22 :** Libft complète (40+ fonctions)
- **Jour 23 :** Optimisation (profiling, benchmarks)
- **Jour 24 :** Projet final libre (compilateur / HTTP server / etc.)

---

## 🛠️ Technologies & Outils

### Compilation
```bash
gcc -Wall -Wextra -Werror -std=c99 -g fichier.c -o programme
```

### Vérification Mémoire
```bash
valgrind --leak-check=full --show-leak-kinds=all ./programme
```

### Debugging
```bash
gdb ./programme
```

### Outils Requis
- **Compilateur :** GCC ou Clang
- **Debugger :** GDB, Valgrind
- **Build :** Make
- **Versioning :** Git
- **Éditeur :** Vim/Neovim (recommandé) ou VSCode

---

## 🚀 Démarrage Rapide

### Installation (Linux)

**Arch/Manjaro :**
```bash
sudo pacman -S gcc make valgrind gdb git vim
```

**Debian/Ubuntu :**
```bash
sudo apt install build-essential valgrind gdb git vim
```

### Utilisation

```bash
# Cloner le repository
git clone https://github.com/p4cm4n972/piscine-C.git
cd piscine-C

# Compiler un exercice
cd Semaine1/jour01
gcc -Wall -Wextra -Werror ex01_ft_putchar.c -o test
./test

# Vérifier avec Valgrind
valgrind --leak-check=full ./test
```

---

## 📚 Documentation

- **[README_PiscineC.md](README_PiscineC.md)** - Guide principal complet
- **[RESUME_COMPLET_PISCINE.md](RESUME_COMPLET_PISCINE.md)** - Résumé des 4 semaines
- **[Semaine3/GUIDE_COMPLET_S3.md](Semaine3/GUIDE_COMPLET_S3.md)** - Guide Semaine 3
- **[Semaine3/jour17_minishell/README.md](Semaine3/jour17_minishell/README.md)** - Documentation mini-shell

Chaque semaine dispose de son propre README détaillé.

---

## 💡 Exemples de Code

### Hello World
```c
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    ft_putchar('H');
    ft_putchar('i');
    ft_putchar('\n');
    return (0);
}
```

### Liste Chaînée
```c
typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}   t_list;

t_list *ft_create_elem(void *data)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}
```

---

## 🎓 Compétences Acquises

### Techniques
- ✅ Programmation C professionnelle
- ✅ Algorithmique et structures de données
- ✅ Gestion mémoire avancée
- ✅ Programmation système Unix
- ✅ Debugging et optimisation

### Soft Skills
- ✅ Résolution de problèmes complexes
- ✅ Rigueur et organisation du code
- ✅ Autonomie et documentation
- ✅ Gestion de projets

---

## 📈 Statistiques

```
Fichiers créés       : ~100 fichiers
Lignes de code       : ~9000 lignes
Documentation        : 17 fichiers MD (~70 KB)
Exercices            : 70+ exercices pratiques
Projets              : 5 projets complets
Temps investi        : ~61 heures
```

---

## 🏆 Projets Phares

1. **Mini-Shell** - Shell Unix basique avec fork/execve
2. **Guess Game** - Jeu de devinettes avec IA (recherche binaire)
3. **Libft** - Recréation de la libc
4. **Split & Parsing** - Parsing avancé avec gestion mémoire
5. **Listes Chaînées** - Implémentation complète avec tri

---

## 📋 TODO / Roadmap

- [x] Semaine 1 complète
- [x] Semaine 2 complète
- [x] Semaine 3 structure et guides
- [ ] Compléter les exercices Semaine 3
- [ ] Implémenter le mini-shell
- [ ] Créer les exercices Semaine 4
- [ ] Projet final (compilateur ou HTTP server)

---

## 🤝 Contribution

Ce projet est personnel, mais les suggestions et corrections sont les bienvenues !

Pour contribuer :
1. Fork le projet
2. Crée une branche (`git checkout -b feature/amelioration`)
3. Commit tes changements
4. Push vers la branche
5. Ouvre une Pull Request

---

## 📜 License

Ce projet est sous licence MIT. Voir le fichier [LICENSE](LICENSE) pour plus de détails.

---

## 🙏 Remerciements

- **Claude Code** pour l'assistance au développement
- La communauté **42** pour les standards de code
- La communauté open-source pour l'inspiration

---

## 📞 Contact

**Manuel ADELE**
📧 manuel.adele@gmail.com
🐙 GitHub: [@P4cm4n972](https://github.com/P4cm4n972)

---

## ⭐ Si ce projet t'aide...

N'hésite pas à ⭐ star le repository et à le partager !

**Fait avec ❤️ et beaucoup de ☕ en C**

---

> *"Un bon programmeur n'écrit pas du code, il résout des problèmes."*
