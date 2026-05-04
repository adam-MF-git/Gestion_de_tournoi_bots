#pragma once
#include <Jeu/Jeu.hh>
#include <macro/Registre.hh>

//Rajouté qu'à la fin l'héritage public RegistreAutoJeu<Votre Classe>
class Jeu_template : public Jeu, public RegistreAutoJeu<Jeu_template> {
private:
public:
    Jeu_template();
    virtual void joue(int coup) override;
    virtual void reset() override;

    virtual int nb_coups() const override;
    virtual int getetat() const override;
    virtual bool coup_autorise(int coup) const override;

    virtual bool terminer() const override;
    virtual bool victoire() const override;
    virtual bool egalite() const override;
};

// enlevé le commentaire quand vous créerais votre classe
template class RegistreAutoJeu<Jeu_template>;