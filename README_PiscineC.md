# 🏊 Piscine Algorithmie C
_Auteur : Manuel ADELE_
_Distribution : Manjaro Linux / GCC_
_Durée : 4 semaines_

---

## 🎯 Objectif général
Revenir aux bases du raisonnement algorithmique et du langage C pour acquérir :
- Une compréhension **fine du fonctionnement de la machine**  
- Une **rigueur d’ingénieur** (organisation, propreté du code, logique)  
- Une **autonomie totale** dans la résolution de problèmes  

---

## ⚙️ Environnement
- **OS :** Manjaro / Ubuntu / Debian (Linux obligatoire)
- **Éditeur :** Vim ou Neovim  
- **Compilateur :** `gcc`  
- **Outils :** `make`, `valgrind`, `gdb`, `git`  

### Installation rapide :
```bash
sudo pacman -S gcc make valgrind gdb git vim
```

---

## 🧩 Structure des semaines

| Semaine | Thème principal | Objectif clé |
|----------|----------------|--------------|
| 1 | Syntaxe & bases du C | Comprendre le langage, types, boucles, fonctions |
| 2 | Algorithmie pure | Récursion, tri, recherche, logique |
| 3 | Mémoire & pointeurs | Allocation dynamique, gestion mémoire, mini-shell |
| 4 | Projets avancés | Structures de données, fichiers, parsing, optimisation |

---

## 🧱 Règles fondamentales (“Esprit Piscine”)

1. **Compiler strictement :**
   ```bash
   gcc -Wall -Wextra -Werror file.c -o test
   ```
   Aucune erreur, aucun warning toléré.

2. **Interdiction de copier sans comprendre.**  
   Tu peux lire, mais jamais coller.  
   Si tu colles sans comprendre, tu triches ton cerveau.

3. **Réfléchis avant d’écrire.**  
   Le but n’est pas de produire du code, mais de **comprendre le raisonnement**.

4. **Toujours tester ton code.**
   - Crée un `main.c` minimal pour chaque fonction.
   - Teste les cas limites (0, négatif, vide, très grand).

5. **Lis ton code à froid.**  
   Relis une fonction 2h plus tard, sans contexte.  
   Si tu ne comprends pas instantanément, réécris-la.

6. **Pas d’IA, pas de StackOverflow avant 30 minutes d’effort.**  
   La douleur, c’est la pédagogie.

7. **Organisation stricte :**
   ```
   PiscineC/
   ├── jour01/
   ├── jour02/
   ├── ...
   └── semaineX/
   ```
   Chaque jour est un dossier autonome avec un `Makefile` propre.

8. **Sauvegarde continue :**
   ```bash
   git add .
   git commit -m "JourX terminé"
   ```

---

## 🧠 Pense-bête syntaxique C

### Fonctions et prototypes
```c
int ft_add(int a, int b);
void ft_print(char *str);
```

### Boucles
```c
for (int i = 0; i < n; i++) { ... }
while (condition) { ... }
```

### Conditions
```c
if (a > b)
    return a;
else
    return b;
```

### Pointeurs
```c
int a = 10;
int *p = &a;
printf("%d", *p);
```

### Allocation dynamique
```c
int *tab = malloc(sizeof(int) * n);
if (!tab) return NULL;
free(tab);
```

---

## 🧮 Vérification mémoire
Toujours exécuter avant validation :
```bash
valgrind ./test
```
→ Aucune fuite, aucune erreur.

---

## 🧰 Commandes essentielles

| Commande | Rôle |
|-----------|------|
| `gcc -Wall -Wextra -Werror main.c` | Compilation stricte |
| `make` / `make re` | Compilation via Makefile |
| `valgrind ./prog` | Analyse mémoire |
| `gdb ./prog` | Débogage pas à pas |
| `git log --oneline` | Historique des commits |

---

## 🧗 Routine quotidienne (mode immersion)

| Heure | Activité |
|--------|----------|
| 08h30 | Café + plan de la journée |
| 09h00 – 12h00 | Exercices du jour |
| 12h00 – 13h00 | Pause |
| 13h00 – 16h00 | Mini-projet ou challenge |
| 16h00 – 18h00 | Tests, corrections, valgrind |
| 18h00 – 19h00 | Lecture, relecture, veille technique |

---

## 🧠 Conseils d’ingénieur

- 💬 *“Tu ne codes pas pour que ça marche. Tu codes pour comprendre pourquoi ça marche.”*  
- 🧩 *Découpe toujours ton problème en sous-problèmes.*  
- 🧘 *Code sobre, clair, lisible. Les fonctions trop longues sont des erreurs de pensée.*  
- 🧱 *Ton terminal est ton environnement. Ton éditeur est ton couteau.*  
- 🔁 *Apprends à aimer la boucle infinie (jusqu’à ce qu’elle marche).*

---

## ✅ Objectif final
À la fin de cette Piscine :
- Tu seras capable d’écrire du code **C propre, robuste et portable**.  
- Tu comprendras les **mécanismes internes** que tout langage haut niveau cache.  
- Tu auras la **rigueur **, utile dans tout projet (Angular, NestJS, ou DevOps).

---

## 📜 Citation 
> “Un bon ingénieur n’écrit pas du code,  
> il écrit une solution que la machine peut comprendre.”

---

**Manuel ADELE – Piscine Algorithmie C 2025**
