# Planification

## 1) Github

## 2) Architecture du Projets
    - Choix d'implémentation
    - Structure du Projets

## 3) Début du Projets

### 1/ Racine du Projets
    - Jeu.h
    - Jeu.o (Potentiellement Implémentée des jeux dans le futur et permettre à une personne de fournir un jeu)
    - Joueur.h
    - Arbitre.hh et Arbitre.cc (Organise le match entre deux joueur pour un jeu (Prévoir erreur à la compilation et à l'éxécution))
    - Compétition (Organise plusieures arbitre pour différentes collection de match entre différents Joueur)

### 2/ Couche Bac à Sable
    Choix entre plusieures implémentation :
        - Docker
        - Sites Random
        - Application Random (par exemple le pc derrière la box du prof) (Ptit info: j'ai moins envie de ch*er)

### 3/ Couche Interface
    Choix entre :
        - Page Web
        - Application graphique

#### Application Graphique
    Page Joueur :
        Zone ou sélectionner les joueurs à prendre
        Une fois un joueur ajouter on tente déjà de le compiler dans un docker pour afficher si la compilation c'est bien passé
    
    Page Jeux / Organisation de Tournois :
        Zone ou sélectionner les jeux à prendre
        Choix des paramètre de tournois
            (différents type de tournois)

    Page Attente / Résultat :
        Pourcentage / Attente
        Résultat
        Bouton permettant d'obtenir un fichier csv des résultat
        Bouton permettant d'obtenir un fichier contenant les erreurs d'éxécution



    Supprimer tous les fichiers non nécéssaire par sécurité

### 4/ Amélioration
     - Autoriser les personnes à importer leur jeux
     - Personnalisation de tournois
     - Threading
     - Optimisation
     - Prévoir les erreurs
     - Stocker les résultats en SQL
     - Faires des cookies (exclusif WEB)
     - Proposer de la Personnalisation (Thème noir / claire)
     - Sécurisé
     - Faire des edges cases
     - Autoriser plus que 2 joueur
     - Faire des jeux ou les joueurs peuvent jouer plusieures fois par tour

## 4) Fin du Projets


