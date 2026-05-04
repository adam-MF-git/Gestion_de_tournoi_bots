#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <Jeu/Jeu.hh>
#include <Joueur/Joueur.hh>
#include "memory"

class Arbitre {
private:
    std::unique_ptr<Jeu> _le_jeu;

    std::unique_ptr<Joueur> _Pjoueur;      // Premier joueur
    std::unique_ptr<Joueur> _Sjoueur;      // Second joueur

    int _nb_partie;
    // int _num_partie;

    int _VJ1;
    int _EJ1;
    int _IJ1;
    int _VJ2;
    int _EJ2;
    int _IJ2;
    int _Ega;

public:
    Arbitre(std::unique_ptr<Jeu> le_jeu, std::unique_ptr<Joueur> Pjoueur, std::unique_ptr<Joueur> Sjoueur, int nb_partie);

    void init_partie();

    void partie(bool inverse);

    void tous_partie();

    struct sauvegarde_info {
        int VJ1;
        int EJ1;
        int IJ1;
        int VJ2;
        int EJ2;
        int IJ2;
        int Ega;
        sauvegarde_info() {
            VJ1=0;
            EJ1=0;
            IJ1=0;
            VJ2=0;
            EJ2=0;
            IJ2=0;
            Ega=0;
        };
        sauvegarde_info(int vj1,int ej1, int ij1, int vj2, int ej2, int ij2, int ega) {
            VJ1=vj1;
            EJ1=ej1;
            IJ1=ij1;
            VJ2=vj2;
            EJ2=ej2;
            IJ2=ij2;
            Ega=ega;
        };
    };

    sauvegarde_info sauvegarder();
};
