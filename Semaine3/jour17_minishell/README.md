# 🐚 JOUR 17 : Mini-Shell — Projet intégrateur

## 🎯 Objectif
Créer un mini-shell capable d'exécuter des commandes externes et des built-ins.

---

## 📋 Description du projet

Un **shell** est un interpréteur de commandes. Il :
1. Affiche un prompt
2. Lit une ligne de commande
3. Parse la commande (découpe en arguments)
4. Exécute la commande
5. Répète (boucle REPL : Read-Eval-Print-Loop)

### Exemple d'utilisation
```bash
minishell$ ls -la
# Affiche le contenu du répertoire

minishell$ cd /tmp
# Change de répertoire

minishell$ echo Hello World
# Affiche : Hello World

minishell$ exit
# Quitte le shell
```

---

## 📁 Structure du projet

```
jour17_minishell/
├── README.md           (ce fichier)
├── Makefile            (compilation)
├── minishell.h         (header principal)
├── main.c              (point d'entrée)
├── parser.c            (parsing de commandes)
├── executor.c          (exécution avec fork/execve)
├── builtins.c          (cd, exit, env, pwd)
├── utils.c             (fonctions utilitaires)
└── signals.c           (gestion Ctrl+C)
```

---

## 🔧 Fonctionnalités à implémenter

### 1. Affichage du prompt
```c
void display_prompt(void)
{
    printf("minishell$ ");
    fflush(stdout);
}
```

### 2. Lecture de la ligne
```c
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(0);
        }
        perror("getline");
        exit(1);
    }

    return line;
}
```

### 3. Parsing : Split en arguments
```c
char **parse_line(char *line)
{
    // Utiliser ft_split_whitespaces
    // Retourne : ["ls", "-la", NULL]
}
```

### 4. Exécution de commandes externes
```c
int execute_command(char **args)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)  // Processus fils
    {
        if (execvp(args[0], args) == -1)
        {
            perror("minishell");
            exit(1);
        }
    }
    else if (pid < 0)  // Erreur fork
    {
        perror("minishell");
    }
    else  // Processus parent
    {
        waitpid(pid, &status, 0);
    }

    return 1;
}
```

### 5. Built-ins (commandes internes)

#### cd : Change directory
```c
int builtin_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "minishell: expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
            perror("minishell");
    }
    return 1;
}
```

#### exit : Quitter le shell
```c
int builtin_exit(char **args)
{
    (void)args;
    return 0;  // Retourne 0 pour arrêter la boucle
}
```

#### pwd : Print Working Directory
```c
int builtin_pwd(char **args)
{
    char cwd[1024];

    (void)args;
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s\n", cwd);
    else
        perror("minishell");
    return 1;
}
```

#### env : Afficher les variables d'environnement
```c
int builtin_env(char **args, char **envp)
{
    int i;

    (void)args;
    i = 0;
    while (envp[i])
    {
        printf("%s\n", envp[i]);
        i++;
    }
    return 1;
}
```

---

## 💻 Programme principal

```c
#include "minishell.h"

int main(int ac, char **av, char **envp)
{
    char *line;
    char **args;
    int status;

    (void)ac;
    (void)av;

    while (1)
    {
        display_prompt();
        line = read_line();
        args = parse_line(line);

        if (args[0] != NULL)
            status = execute(args, envp);

        free(line);
        free_args(args);

        if (status == 0)  // exit appelé
            break;
    }

    return 0;
}
```

---

## 🔀 Dispatcher : Built-in vs Externe

```c
int execute(char **args, char **envp)
{
    if (args[0] == NULL)
        return 1;  // Ligne vide

    // Vérifier si c'est un built-in
    if (strcmp(args[0], "cd") == 0)
        return builtin_cd(args);
    else if (strcmp(args[0], "exit") == 0)
        return builtin_exit(args);
    else if (strcmp(args[0], "pwd") == 0)
        return builtin_pwd(args);
    else if (strcmp(args[0], "env") == 0)
        return builtin_env(args, envp);

    // Sinon, commande externe
    return execute_command(args);
}
```

---

## 🛠️ Makefile

```makefile
NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c parser.c executor.c builtins.c utils.c signals.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

---

## ✅ Checklist

### Fonctionnalités de base
- [ ] Affichage du prompt
- [ ] Lecture d'une ligne avec getline
- [ ] Parsing (split en arguments)
- [ ] Exécution de commandes externes (fork + execvp)
- [ ] Gestion du PATH
- [ ] Ctrl+D pour quitter

### Built-ins
- [ ] cd (change directory)
- [ ] exit (quitter)
- [ ] pwd (print working directory)
- [ ] env (afficher environnement)

### Gestion d'erreurs
- [ ] Commande non trouvée
- [ ] Erreur fork
- [ ] Erreur execvp
- [ ] Arguments manquants pour cd

### Bonus
- [ ] Gestion de Ctrl+C (SIGINT)
- [ ] Historique de commandes
- [ ] Redirections (>, <, >>)
- [ ] Pipes (|)
- [ ] Variables d'environnement ($VAR)
- [ ] Quotes (' et ")

---

## 🧪 Tests

```bash
# Test 1 : Commandes simples
minishell$ ls
minishell$ pwd
minishell$ echo test

# Test 2 : Commandes avec arguments
minishell$ ls -la
minishell$ echo Hello World

# Test 3 : Built-ins
minishell$ cd /tmp
minishell$ pwd
minishell$ cd ..
minishell$ pwd

# Test 4 : Variables d'environnement
minishell$ env

# Test 5 : Quitter
minishell$ exit
```

---

## 📚 Concepts système

### fork()
Crée un nouveau processus (copie du parent).
```c
pid_t pid = fork();
// pid == 0 : processus fils
// pid > 0 : processus parent (pid = PID du fils)
// pid < 0 : erreur
```

### execvp()
Remplace le processus actuel par un nouveau programme.
```c
char *args[] = {"ls", "-la", NULL};
execvp(args[0], args);
// Ne retourne que si erreur
```

### waitpid()
Attend qu'un processus fils se termine.
```c
int status;
waitpid(pid, &status, 0);
```

---

## ⏱️ Temps estimé
- Version de base : 4-5h
- Built-ins : 2h
- Gestion d'erreurs : 1h
- Bonus (signaux, redirections) : 3-4h
- **Total** : 8-10h

---

## 🎯 Critères de réussite

- ✅ Compile sans erreur ni warning
- ✅ Exécute des commandes externes (ls, cat, grep, etc.)
- ✅ Les 4 built-ins fonctionnent (cd, exit, pwd, env)
- ✅ Gestion d'erreurs propre
- ✅ Pas de fuites mémoire (valgrind)
- ✅ Ctrl+D quitte proprement

---

**Ce mini-shell est un projet fondamental pour comprendre les processus Unix ! 🚀**
