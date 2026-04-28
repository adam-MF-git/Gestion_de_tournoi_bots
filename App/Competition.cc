#include "Competition.hh"

Competition::Competition() {
    // _progression("Resultat/progression");
    // _resultat("Resultat/resultat");
}

Competition::~Competition() {
    _progression.close();
    _resultat.close();
}


void Competition::lancer_competition() {
    int nb_jeu(Registre::instance().nb_classes_dans_registre_Jeu()-1);
    int nb_joueur(Registre::instance().nb_classes_dans_registre_Joueur()-1);

    for(int jeu(1);jeu<=nb_jeu;jeu++) {
        for(int joueur_1(1);joueur_1<=nb_joueur-1;joueur_1++) {
            for(int joueur_2(joueur_1+1);joueur_2<=nb_joueur;joueur_2++) {
                une_competition(jeu, joueur_1, joueur_2);
                float pourcentage(float(jeu));
                progression();
            }
        }
    }

}

void Competition::une_competition(int jeu,int joueur_1,int joueur_2) {
    Arbitre a(Registre::instance().getNouveauJeu(jeu),Registre::instance().getNouveauJoueur(joueur_1,std::to_string(joueur_1),true),Registre::instance().getNouveauJoueur(joueur_2,std::to_string(joueur_2),false),100);
    a.tous_partie();
    a.sauvegarder();
}

void Competition::sauvegarde() {

}

void Competition::progression(float pourcentage) {

}
