#pragma once
#include <iostream>
#include "Jeu/includeTousJeux.hh"
#include "Jeu.hh"

class Joueur {
private:
    std::string _nom;
    bool _joueur_1;
public:
    Joueur(std::string nom,bool joueur_1);
    virtual void init()=0;
    virtual void init_partie()=0;

    std::string getnom() const;
    bool getjoueur_1() const;
    void setjoueur_1(bool joueur_1);

    void jouer(Jeu * const & le_jeu,bool & en_cours,int & coup);
    virtual int recherche_coup(Jeu * const & le_jeu)=0;

};
