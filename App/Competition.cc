#include "Competition.hh"

Competition::Competition():_progression(),_resultat() {
    _progression.open("progression");
    _progression<<0;
    _progression.close();

    _resultat.open("progression");
    _resultat<<"";
    _resultat.close();
}

Competition::~Competition() {
    _progression.close();
    _resultat.close();
}

void Competition::lancer_competition() {
    _resultat.open("resultat");
    _resultat<<"Jeu,Joueur1,Joueur2,Victoires_J1,Erreurs_J1,Invalides_J1,Victoires_J2,Erreurs_J2,Invalides_J2,Egalites\n";

    int nb_jeu(Registre::nb_classes_dans_registre_Jeu());
    int nb_joueur(Registre::nb_classes_dans_registre_Joueur());

    float max_partie(nb_jeu*( (nb_joueur*(nb_joueur-1))/2 ) );
    float compteur(0);

    std::cout << "nb_jeu : " << nb_jeu << " nb_joueur : " << nb_joueur << std::endl;

    for(int jeu(0);jeu<nb_jeu;jeu++) {
        for(int joueur_1(0);joueur_1<nb_joueur-1;joueur_1++) {
            for(int joueur_2(joueur_1+1);joueur_2<nb_joueur;joueur_2++) {
                une_competition(jeu, joueur_1, joueur_2);
                progression(++compteur/max_partie);
                std::cout << compteur << " sur " << max_partie << std::endl;
            }
        }
    }
    _resultat.close();
}

void Competition::une_competition(int jeu,int joueur_1,int joueur_2) {
    Arbitre a(Registre::getNouveauJeu(jeu),Registre::getNouveauJoueur(joueur_1,Registre::getNomJoueur(joueur_1),true),Registre::getNouveauJoueur(joueur_2,Registre::getNomJoueur(joueur_2),false),100);
    a.tous_partie();
    sauvegarde(Registre::getNomJeu(jeu),Registre::getNomJoueur(joueur_1),Registre::getNomJoueur(joueur_2),a.sauvegarder());

}

void Competition::sauvegarde(std::string jeu, std::string joueur_1, std::string joueur_2, Arbitre::sauvegarde_info sauv) {
    _resultat<<jeu+","+joueur_1+","+joueur_2+","+std::to_string(sauv.VJ1)+","+std::to_string(sauv.EJ1)+","+std::to_string(sauv.IJ1)+","+std::to_string(sauv.VJ2)+","+std::to_string(sauv.EJ2)+","+std::to_string(sauv.IJ2)+","+std::to_string(sauv.Ega)+"\n";
}

void Competition::progression(float pourcentage) {
    _progression.open("progression");
    _progression<<pourcentage;
    _progression.close();
}
