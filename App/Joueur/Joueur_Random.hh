#pragma once
#include <Joueur/Joueur.hh>
#include <macro/Registre.hh>

class Joueur_Random : public Joueur, public RegistreAutoJoueur<Joueur_Random> {
private:
public:
    Joueur_Random(std::string nom,bool joueur_1);
    virtual void init() override;
    virtual void init_partie() override;

    virtual int recherche_coup(Jeu * const & le_jeu) override;
};

template class RegistreAutoJoueur<Joueur_Random>;