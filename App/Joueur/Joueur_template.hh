#pragma once
#include <Joueur/Joueur.hh>
#include <macro/Registre.hh>

//Rajouté qu'à la fin l'héritage public RegistreAutoJoueur<Votre Classe>
class Joueur_template : public Joueur, public RegistreAutoJoueur<Joueur_template> {
private:
public:
    Joueur_template(std::string nom,bool joueur_1);
    virtual void init() override;
    virtual void init_partie() override;

    virtual int recherche_coup(Jeu * const & le_jeu) override;
};

// enlevé le commentaire quand vous créerais votre classe
template class RegistreAutoJoueur<Joueur_template>;