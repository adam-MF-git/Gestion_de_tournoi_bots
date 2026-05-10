#include "Arbitre.hh"

Arbitre::Arbitre(std::unique_ptr<Jeu> le_jeu, std::unique_ptr<Joueur> Pjoueur, std::unique_ptr<Joueur> Sjoueur, int nb_partie):_le_jeu(std::move(le_jeu)),_Pjoueur(std::move(Pjoueur)),_Sjoueur(std::move(Sjoueur)),_nb_partie(nb_partie) {
    _VJ1=0;
    _EJ1=0;
    _IJ1=0;
    _VJ2=0;
    _EJ2=0;
    _IJ2=0;
    _Ega=0;
}

void Arbitre::init_partie() {
    std::unique_ptr<Joueur> temp(std::move(_Pjoueur));
    _Pjoueur=std::move(_Sjoueur);
    _Sjoueur=std::move(temp);

    _le_jeu->reset();

    _Pjoueur->setjoueur_1(true);
    _Pjoueur->init_partie();

    _Sjoueur->setjoueur_1(false);
    _Sjoueur->init_partie();
}

void Arbitre::partie(bool inverse) {
    init_partie();
    int tour=0;
    std::unique_ptr<Joueur> joueur_actuel;
    int coup=0;
    bool encours;
    while(!_le_jeu->terminer()) {
        if (tour%2==0) joueur_actuel=std::move(_Pjoueur);
        else joueur_actuel=std::move(_Sjoueur);

        encours=true;

        std::thread t(&Joueur::jouer,joueur_actuel.get(),_le_jeu.get(),std::ref(encours),std::ref(coup));

        int timer=10;
        while(encours && timer!=0) {
            timer--;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        if (encours) {
            t.detach();
        }
        else {
            t.join();
        }

        if (tour%2==0) _Pjoueur=std::move(joueur_actuel);
        else _Sjoueur=std::move(joueur_actuel);

        if (timer==0) {
            if (tour%2==0) {
                //STATUS -1: Le premier joueur n'a pas rendu en le temps requis
                if (inverse) _EJ2++;
                else _EJ1++;
                return;
            }
            else{
                //STATUS -2: Le second joueur n'a pas rendu en le temps requis
                if (inverse) _EJ1++;
                else _EJ2++;
                return;
            }
        }
        else {
            if (_le_jeu->coup_autorise(coup)) {
                _le_jeu->joue(coup);
            }
            else {
                if (tour%2==0) {
                    //STATUS -3: Le premier joueur a fait un coup interdit
                    if (inverse) _IJ2++;
                    else _IJ1++;
                    return;
                }
                else {
                    //STATUS -4: Le second joueur a fait un coup interdit
                    if (inverse) _IJ1++;
                    else _IJ2++;
                    return;
                }
            }
        }
    }
    if (_le_jeu->victoire()) {
        //STATUS 1: Victoire du joueur 1
        if (inverse) _VJ2++;
        else _VJ1++;
        return;
    }
    else if (_le_jeu->egalite()) {
        //STATUS 0: Victoire d'aucun joueur
        _Ega++;
        return;
    }
    else {
        //STATUS 2: Victoire du joueur 2
        if (inverse) _VJ1++;
        else _VJ2++;
        return;
    }
}

void Arbitre::tous_partie() {
    bool inverse(true);
    for(int i(0);i<_nb_partie;i++) {
        partie(inverse);
        inverse=!inverse;
        // std::cout << "nouvelle partie !" << std::endl;
    }
}

Arbitre::sauvegarde_info Arbitre::sauvegarder() {
    return sauvegarde_info(_VJ1,_EJ1,_IJ1,_VJ2,_EJ2,_IJ2,_Ega);
}
