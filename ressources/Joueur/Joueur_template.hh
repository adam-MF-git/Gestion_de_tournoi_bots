#pragma once
#include <Joueur/Joueur.hh>
#include <macro/Registre.hh>

class Joueur_template : public Joueur {
private:
public:
    Joueur_template(std::string nom,bool joueur_1);
    virtual void init() override;
    virtual void init_partie() override;

    virtual void recherche_coup(Jeu * const & le_jeu, int & coup) override;
};

// enlevé le commentaire quand vous créerais votre classe
template class RegistreAutoJoueur<Joueur_template>;