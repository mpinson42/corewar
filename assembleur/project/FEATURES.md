
# Features du parsing

## Obligatoire
- LABELS_CHARS contrôlés.
- LABEL_CHAR contrôlé.
- REG_NUMBER contrôlés.
- taille de la valeur de .name ou .comment contrôlée.

## En petit plus
- espaces et tabs (mixés ou non) autorisés.
- taille des valeurs numériques (32bits) contrôlés (désactivé par défaut).
- espaces après les labels non obligatoires (eg: `myanchor:live %42`).
- multiples commandes .name ou .comment contrôlés.
- les valeurs de .name ou .comment peuvent porter des `"` escapés par `\` (`\"`).
- des espaces (ou tabs) avant ou après le SEPARATOR_CHAR sont autorisés (`sti  r15, %0 , r14`).
- toute la mémoire contrôlée, libérée et sans fuites.
- erreurs explicites.
- erreurs avec numéros de ligne pour les erreurs concernant le parsing.
