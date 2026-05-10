#include "Joueur_Random.hh"

Joueur_Random::Joueur_Random(std::string nom, bool joueur_1):Joueur(nom,joueur_1) {
    // RegistreAutoJoueur<Joueur_Random>::registre_init;
}

void Joueur_Random::init() {

}

void Joueur_Random::init_partie() {

}

void Joueur_Random::recherche_coup(Jeu * const &le_jeu, int & coup) {
	if (le_jeu->nb_coups() == 1)
        coup = 1;
	else
        coup = (rand() % le_jeu->nb_coups()) + 1;
}
