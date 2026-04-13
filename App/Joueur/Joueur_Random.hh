#pragma once
#include "../Joueur.hh"
// #include "../macro.hh"

class Joueur_Random : public Joueur {
private:
public:
    Joueur_Random(std::string nom,bool joueur_1) {
        Joueur(nom,joueur_1);
    }
};

// ENREGISTRER_JOUEUR(Joueur_Random)