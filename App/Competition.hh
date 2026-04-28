#pragma once
#include "Arbitre.hh"
#include "Joueur/includeTousJoueurs.hh"
#include "Jeu/includeTousJeux.hh"
#include <fstream>

class Competition {
private:
    std::ofstream _progression;
    std::ofstream _resultat;
public:
    Competition();
    ~Competition();
    void lancer_competition();
    void une_competition(int jeu,int joueur_1,int joueur_2);
    void sauvegarde();
    void progression(float pourcentage);
};
