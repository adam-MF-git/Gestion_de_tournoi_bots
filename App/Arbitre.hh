#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <Jeu/Jeu.hh>
#include <Joueur/Joueur.hh>
#include "memory"

class Arbitre {
private:
    std::unique_ptr<Jeu> _le_jeu;

    std::unique_ptr<Joueur> _Pjoueur;      // Premier joueur
    std::unique_ptr<Joueur> _Sjoueur;      // Second joueur

    int _nb_partie;
    // int _num_partie;

    int _VJ1;
    int _EJ1;
    int _IJ1;
    int _VJ2;
    int _EJ2;
    int _IJ2;
    int _Ega;

public:
    Arbitre(std::unique_ptr<Jeu> le_jeu, std::unique_ptr<Joueur> Pjoueur, std::unique_ptr<Joueur> Sjoueur, int nb_partie);

    void init_partie();

    void partie(bool inverse);

    void tous_partie();

    void sauvegarder();
};
