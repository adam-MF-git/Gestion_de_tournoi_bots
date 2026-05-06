#include "Joueur_Random.hh"

Joueur_Random::Joueur_Random(std::string nom, bool joueur_1):Joueur(nom,joueur_1) {
    // RegistreAutoJoueur<Joueur_Random>::registre_init;
}

void Joueur_Random::init() {

}

void Joueur_Random::init_partie() {

}

int Joueur_Random::recherche_coup(Jeu * const &le_jeu) {
	if (le_jeu->nb_coups() == 1)
		return 1;
	else
		return (rand() % le_jeu->nb_coups()) + 1;
}
