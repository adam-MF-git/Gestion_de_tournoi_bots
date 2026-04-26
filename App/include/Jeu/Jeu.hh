#pragma once
#include <iostream>

enum class etat_de_partie{
    EGA,
    DEF,
    VIC,
    NONFINI
};

class Jeu {
private:
    void _setetat(int etat);
public:
    Jeu();
    Jeu(Jeu const &)=delete;
    Jeu & operator=(Jeu const &) = delete;

    virtual void joue(int coup)=0;
    virtual void reset()=0;

    virtual int nb_coups() const=0;
    virtual int getetat() const=0;
    virtual bool coup_autorise(int coup) const=0;

//  Alternative
//  etat_de_partie getstatus() const;
//  int getstatus() const;

    virtual bool terminer() const=0;
    virtual bool victoire() const=0;
    virtual bool egalite() const=0;
};
