#include "Joueur.hh"

Joueur::Joueur(std::string nom, bool joueur_1):_nom(nom),_joueur_1(joueur_1) {

}

std::string Joueur::getnom() const {
    return _nom;
}

bool Joueur::getjoueur_1() const {
    return _joueur_1;
}

void Joueur::setjoueur_1(bool joueur_1) {
    _joueur_1=joueur_1;
}

void Joueur::jouer(Jeu * const & le_jeu,bool & en_cours,int & coup) {
    coup=recherche_coup(le_jeu);
    en_cours=false;
}
