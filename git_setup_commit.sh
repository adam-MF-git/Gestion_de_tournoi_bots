#!/bin/bash

teste=0
detecte=()
function dossier_valide {

    path="App/$1"    
    #Vérifie que le dossier existe
    if [[ ! -d "$path" ]]; then
        echo "Erreur : le dossier '$path' n'existe pas !"
        exit 1
    fi
    
    #Rajoute les fichiers attendu dans une liste associative
    declare -A fichier_valide
    local -n liste=$2
    #echo "AAAAAAA   ${liste[@]}"
    for fichier in "${liste[@]}"; do
        #echo "Rajoute $fichier $2"
        fichier_valide["$fichier"]=1
    done
    
    #Parcours tous le dossier pour trouver les potentiels fichiers non attendus
    for fichier in "$path"/*; do
        nom=$(basename "$fichier")
        if [[ ! ${fichier_valide["$nom"]} ]]; then
            #echo "\${fichier_valide[\"\$nom\"]} ${fichier_valide["$nom"]}"
            detecte+=("$1/$nom")
        fi
    done
    
    if [[ ${#detecte[@]} -gt 0 ]]; then
        echo "${#detecte[@]} fichier(s) supplémentaire(s) détecté(s) dans le dossier '$path' :"
        printf '  - App/%s\n' "${detecte[@]}"
        echo
        teste=1
    else
        echo "Tous les fichiers du dossier '$path' sont setup pour le git."
    fi
}


Joueur=("CMakeLists.txt" "includeTousJoueurs.hh" "includeTousJoueurs.hh.in")
Jeu=("CMakeLists.txt" "includeTousJeux.hh" "includeTousJeux.hh.in")

dossier_valide "Joueur" Joueur teste 
dossier_valide "Jeu" Jeu teste 

#echo "test : ${detecte[@]}"

if [[ $teste -eq 1 ]]; then    
    reponse=""
    read -p "Voulez-vous déplacer automatiquement dans les ressources ces fichiers (o/n) : " reponse
    while [[ ! ( $reponse == "o" || $reponse == "n" ) ]]; do
        read reponse    
    done
    if [[ $reponse == "o" ]]; then
        #rm -i "App/${detecte[@]}" Ancienne solution
        for fichier in "${detecte[@]}"; do
            mkdir -p "ressources/$(dirname "$fichier")"
            mv -i "App/$fichier" "ressources/$fichier"
        done
    fi
fi
