# 🚀 ex02 : Initialisation Git — Guide pratique

## Objectif
Apprendre à versionner ton code avec Git, l'outil indispensable pour tout développeur.

---

## Étape 1 : Configuration initiale (une seule fois)

```bash
# Configure ton identité Git
git config --global user.name "Ton Nom"
git config --global user.email "ton.email@example.com"

# Vérifie la configuration
git config --list
```

---

## Étape 2 : Initialiser un dépôt Git

```bash
# Depuis le dossier de ta Piscine
cd /home/itmade/Piscine/C/Semaine1

# Initialise le dépôt
git init

# Vérifie que c'est bien fait
ls -la  # Tu dois voir un dossier .git
```

---

## Étape 3 : Créer un fichier .gitignore

```bash
# Crée un fichier pour ignorer certains fichiers
cat > .gitignore << 'EOF'
# Fichiers compilés
*.o
*.a
*.out
a.out
test
main

# Fichiers temporaires
*~
*.swp
.DS_Store

# Fichiers de debug
vgcore.*
*.dSYM/
EOF
```

---

## Étape 4 : Premier commit

```bash
# Ajoute tous les fichiers au staging
git add .

# Vérifie ce qui va être commité
git status

# Crée ton premier commit
git commit -m "Initial commit: Semaine 1 - Piscine C"
```

---

## Étape 5 : Vérifications

```bash
# Affiche l'historique des commits
git log

# Affiche l'état actuel
git status
```

---

## 📖 Commandes Git essentielles

### Ajouter des fichiers
```bash
git add fichier.c           # Ajoute un fichier spécifique
git add jour01/*.c          # Ajoute tous les .c d'un dossier
git add .                   # Ajoute tous les changements
```

### Commit
```bash
git commit -m "Message clair et concis"
git commit -am "Add + commit en une fois" # (seulement pour fichiers déjà trackés)
```

### Voir les changements
```bash
git status                  # État actuel
git diff                    # Changements non stagés
git diff --staged           # Changements stagés
git log                     # Historique des commits
git log --oneline           # Historique condensé
```

### Annuler des changements
```bash
git restore fichier.c       # Annule les modifications d'un fichier
git restore --staged file.c # Retire du staging
git reset HEAD~1            # Annule le dernier commit (garde les changements)
```

---

## 🎯 Bonnes pratiques

### Messages de commit clairs
```bash
✅ BIEN :
git commit -m "Add ft_strlen implementation"
git commit -m "Fix segfault in ft_strcpy"
git commit -m "Update Makefile: add ft_strrev"

❌ MAL :
git commit -m "update"
git commit -m "fix"
git commit -m "stuff"
```

### Commits atomiques
- **Un commit = une fonctionnalité/fix**
- Ne mélange pas plusieurs changements sans lien
- Commit régulièrement (plusieurs fois par jour)

### Avant de commit
```bash
# 1. Compile et teste ton code
gcc -Wall -Wextra -Werror *.c

# 2. Vérifie ce que tu vas commiter
git status
git diff

# 3. Commit seulement si tout fonctionne
git add .
git commit -m "Message descriptif"
```

---

## 🚀 Challenge

1. **Initialise Git** dans ton dossier Semaine1
2. **Crée le .gitignore**
3. **Fais un commit** pour chaque jour complété :
   - `"Complete jour01: basic functions"`
   - `"Complete jour02: string manipulation"`
   - etc.
4. **Bonus** : Crée un compte GitHub et pousse ton code en ligne

```bash
# Créer un dépôt sur GitHub puis :
git remote add origin https://github.com/ton-username/piscine-c.git
git branch -M main
git push -u origin main
```

---

## ⏱️ Objectifs
- ✅ Git initialisé : 5 min
- ✅ Premier commit : 10 min
- ✅ 5+ commits bien organisés : 30 min
- 🎁 Bonus GitHub : 45 min

---

## 📚 Ressources
- `man git`
- `git --help`
- https://git-scm.com/book/fr/v2
