#pragma once
#include <Jeu/Jeu.hh>
#include <macro/Registre.hh>
#define RACINE 0


class Jeu_Idiot:
	public Jeu, public RegistreAutoJeu<Jeu_Idiot> 
{
private:
	int _etat;
	
public:
	Jeu_Idiot();
	virtual void joue(int coup) override;
	virtual void reset() override;

    virtual int nb_coups() const override;
    virtual int getetat() const override;
    virtual bool coup_autorise(int coup) const override;

    virtual bool terminer() const override;
    virtual bool victoire() const override;
    virtual bool egalite() const override;
};

template class RegistreAutoJeu<Jeu_Idiot>;