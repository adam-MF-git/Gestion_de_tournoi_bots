#pragma once
#include <Jeu/Jeu.hh>
#include <macro/macro.hh>

class Jeu_template : public Jeu {
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

ENREGISTRER_JEU(Jeu_template)