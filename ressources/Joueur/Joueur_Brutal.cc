#include "Joueur_Brutal.hh"

Joueur_Brutal::Joueur_Brutal(std::string nom, bool joueur_1):Joueur(nom,joueur_1) {
    // RegistreAutoJoueur<Joueur_Brutal>::registre_init;
}

void Joueur_Brutal::init() {

}

void Joueur_Brutal::init_partie() {

}

void Joueur_Brutal::recherche_coup(Jeu * const &le_jeu, int & coup) {
	// Une chance sur 10 de prendre "trop de temps" pour répondre
	std::this_thread::sleep_for (std::chrono::milliseconds(rand() % 11)); 
	
	// une chance sur 50 de jouer un coup qui ne fait pas partie de la liste de coups
	// sinon renvoie le dernier coup possible
	if(rand() % 51 == 0)
        coup = le_jeu->nb_coups()+1;
	else
        coup = le_jeu->nb_coups();
}
