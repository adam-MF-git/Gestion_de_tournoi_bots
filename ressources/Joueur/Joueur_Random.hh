#pragma once
#include <Joueur/Joueur.hh>
#include <macro/Registre.hh>
#include <cstdlib>

class Joueur_Random : public Joueur {
private:
public:
    Joueur_Random(std::string nom,bool joueur_1);
    virtual void init() override;
    virtual void init_partie() override;

    virtual void recherche_coup(Jeu * const & le_jeu, int & coup) override;
};

template class RegistreAutoJoueur<Joueur_Random>;