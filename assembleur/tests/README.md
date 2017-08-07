# Tests

Dans ce dossier est testé l'assembleur du projet.
Le dossier contient divers fichiers de config et de support, décrits un peu plus loin.

## Installation

Pour lancer les tests, il faut installer ruby et pouvoir installer ses propres gems (les plugins ruby).
Me consulter si vous galérez (Sol) (à l'école, vous n'aurez pas accès en écriture au dossier `gem`, faut contourner).
Ensuite, `bundle install` devrait installer les bonnes gems.

## Lancement

Un simple `ruby spec.rb` devrait lancer tous les tests.

## Fonctionnement

Pour chaque champion configuré dans `spec.rb`:

- le script vient prendre le binaire asm de référence (`asm_ref`).
- lui fait compiler les champions du dossier `champs_for_spec/` dans le dossier `tmp_compiled_champs/`.
- il fait pareil avec notre binaire asm qui doit (s'appeler `asm`).
- il compare les résultats. Tout con.

## Liste des fichiers / dossiers

OSB: On S'en Branle de ce fichier car on l'utilise / le modifie jamais.

| fichier               | OSB | description                                                                  |
|-----------------------|-----|------------------------------------------------------------------------------|
| `README.md`           |     |                                                                              |
| `spec.rb`             |     | fichier rspec ruby pour décrire les specs                                    |
| `champs_for_spec/`    |     | dossier des champions à compiler pour les specs                              |
| `asm`                 |     | notre binaire, copié depuis le dossier de projet                             |
| `asm_ref`             |     | le binaire asm de référence, donné dans le sujet                             |
| `.gitignore`          | OSB |                                                                              |
| `.rspec`              | OSB | options par defaut sur rspec                                                 |
| `tmp_compiled_champs/`| OSB | le dossier des champions compilés                                            |
| `Gemfile`             | OSB | Pour gem, liste des gems à installer (sert au `bundle install`)              |
| `Gemfile.lock`        | OSB | Pour gem, liste des gems à installer, versionnées (sert au `bundle install`) |
