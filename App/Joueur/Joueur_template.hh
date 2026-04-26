#pragma once
#include <Joueur/Joueur.hh>
#include <macro/macro.hh>

class Joueur_template : public Joueur {
private:
public:
    Joueur_template(std::string nom,bool joueur_1);
    virtual void init() override;
    virtual void init_partie() override;

    virtual int recherche_coup(Jeu * const & le_jeu) override;
};

ENREGISTRER_JOUEUR(Joueur_template)