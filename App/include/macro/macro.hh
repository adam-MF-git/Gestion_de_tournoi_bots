#pragma once
#include "Registre.hh"

#define ENREGISTRER_JOUEUR(CLASS)                                                               \
namespace {                                                                                     \
    static PtrJoueur create_##CLASS(std::string nom,bool joueur_1) {                            \
        return std::make_unique<CLASS>(nom,joueur_1);                                           \
    }                                                                                           \
    static bool enregister_##CLASS = Registre::ajouter_dans_registre( create_##CLASS, #CLASS ); \
}

#define ENREGISTRER_JEU(CLASS)                                                                  \
namespace {                                                                                     \
    static PtrJeu create_##CLASS() {                                                            \
        return std::make_unique<CLASS>();                                                       \
}                                                                                               \
    static bool enregister_##CLASS = Registre::ajouter_dans_registre( create_##CLASS, #CLASS ); \
}
