#pragma once
#include <memory>
#include "Joueur.hh"
#include <vector>

using PtrJoueur = std::unique_ptr<Joueur>;
using FnCreationJoueur = PtrJoueur(*)();

class Registre {
private:
    Registre()=default;
    ~Registre()=default;
    Registre(Registre const &) = delete;
    Registre & operator=(Registre const &) = delete;
    std::vector<FnCreationJoueur> _VCFJ;
public:
    static Registre& instance() {
        static Registre le_registre;
        return le_registre;
    }

    static bool ajouter_dans_registre(FnCreationJoueur CFJ) {
        instance()._VCFJ.push_back(CFJ);
        return true;
    }

    static size_t nb_classes_dans_registre() {
        return instance()._VCFJ.size();
    }

    static PtrJoueur getNouveauJoueur(size_t position) {
        if (position<nb_classes_dans_registre())
            return instance()._VCFJ[position]();
        else
            return nullptr;
    }
};




