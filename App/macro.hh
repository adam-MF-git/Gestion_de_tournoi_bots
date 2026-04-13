#pragma once
#include "Registre.hh"

#define ENREGISTRER_JOUEUR(CLASS)                                                               \
namespace {                                                                                     \
    static PtrJoueur create_##CLASS() {                                                         \
        return std::make_unique<CLASS>();                                                       \
    }                                                                                           \
    static bool enregister_##CLASS = Registre::ajouter_dans_registre( create_##CLASS );         \
}