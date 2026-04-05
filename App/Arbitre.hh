#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "Jeu/includeTousJeux.hh"
#include "Joueur/includeTousJoueurs.hh"

class Joueur;
class Jeu;

class Arbitre {
private:
    Jeu * _le_jeu;

    Joueur * _Pjoueur;      // Premier joueur
    Joueur * _Sjoueur;      // Second joueur

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
    Arbitre(Jeu * le_jeu, Joueur * Pjoueur, Joueur * Sjoueur, int nb_partie);

    void init_partie();

    void partie(bool inverse);

    void tous_partie();

    void sauvegarder();
};
