#include "Joueur_template.hh"

Joueur_template::Joueur_template(std::string nom, bool joueur_1):Joueur(nom,joueur_1) {
}

void Joueur_template::init() {

}

void Joueur_template::init_partie() {

}

void Joueur_template::recherche_coup(Jeu * const &le_jeu, int & coup) {
    coup = 0;
}
