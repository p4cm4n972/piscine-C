# Jour 24 - Projet Final : Éditeur de Texte

## Objectif

Créer un éditeur de texte en mode terminal combinant toutes les compétences acquises.

## Fonctionnalités requises

### Core (Obligatoire)
- Ouvrir/Créer un fichier
- Naviguer avec les flèches
- Insérer/Supprimer du texte
- Sauvegarder (Ctrl+S)
- Quitter (Ctrl+Q)

### Navigation
- Déplacement ligne par ligne
- Début/Fin de ligne (Home/End)
- Début/Fin de fichier (Ctrl+Home/End)
- Page Up/Page Down

### Édition avancée
- Copier/Coller
- Annuler/Refaire (Ctrl+Z/Ctrl+Y)
- Rechercher (Ctrl+F)
- Numéros de ligne

### Bonus
- Coloration syntaxique (C/Python)
- Multi-fichiers (tabs)
- Auto-indentation
- Bracketing automatique

## Structure du projet

```
editor/
├── Makefile
├── editor.h           # Structures et prototypes
├── main.c             # Point d'entrée
├── buffer.c           # Gestion du buffer de texte
├── display.c          # Affichage terminal
├── input.c            # Gestion du clavier
├── file_io.c          # Lecture/Écriture fichiers
├── navigation.c       # Déplacement curseur
├── edit.c             # Insertion/Suppression
├── search.c           # Recherche de texte
└── syntax.c           # Coloration syntaxique (bonus)
```

## Structures de données

```c
typedef struct s_line
{
    char            *content;
    size_t          length;
    struct s_line   *next;
    struct s_line   *prev;
}   t_line;

typedef struct s_buffer
{
    t_line  *first;
    t_line  *current;
    int     cursor_x;
    int     cursor_y;
    int     total_lines;
    char    *filename;
    int     modified;
}   t_buffer;
```

## Technologies utilisées

- **termios** - Mode raw terminal
- **ANSI escape codes** - Contrôle affichage
- **Linked list** - Buffer de lignes
- **File I/O** - open/read/write
- **Signals** - Gestion Ctrl+C

## Compilation

```bash
make        # Compile l'éditeur
make clean  # Supprime .o
make fclean # Supprime tout
make re     # Recompile

./editor [filename]  # Lance l'éditeur
```

## Commandes

| Touche | Action |
|--------|--------|
| Flèches | Déplacer le curseur |
| Ctrl+S | Sauvegarder |
| Ctrl+Q | Quitter |
| Ctrl+F | Rechercher |
| Ctrl+Z | Annuler |
| Home/End | Début/Fin ligne |

## Critères d'évaluation

- Code bien structuré et modulaire
- Pas de fuites mémoire
- Gestion d'erreurs robuste
- Interface utilisateur intuitive
- Documentation complète

**Temps estimé**: 12-15 heures
**Difficulté**: ⭐⭐⭐⭐⭐
