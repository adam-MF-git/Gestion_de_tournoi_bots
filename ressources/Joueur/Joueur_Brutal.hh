#pragma once
#include <Joueur/Joueur.hh>
#include <macro/Registre.hh>
#include <cstdlib>
#include <thread>

class Joueur_Brutal : public Joueur, public RegistreAutoJoueur<Joueur_Brutal> {
private:
public:
    Joueur_Brutal(std::string nom,bool joueur_1);
    virtual void init() override;
    virtual void init_partie() override;

    virtual void recherche_coup(Jeu * const & le_jeu, int & coup) override;
};

template class RegistreAutoJoueur<Joueur_Brutal>;