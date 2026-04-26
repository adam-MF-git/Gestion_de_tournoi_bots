#pragma once
#include <memory>
#include <Joueur/Joueur.hh>
#include <Jeu/Jeu.hh>
#include <vector>

using PtrJoueur = std::unique_ptr<Joueur>;
using FnCreationJoueur = PtrJoueur(*)(std::string,bool);
using PtrJeu = std::unique_ptr<Jeu>;
using FnCreationJeu = PtrJeu(*)();

class Registre {
private:
    Registre()=default;
    ~Registre()=default;
    Registre(Registre const &) = delete;
    Registre & operator=(Registre const &) = delete;
    std::vector<FnCreationJoueur> _VCFJo;
    std::vector<FnCreationJeu> _VCFJe;
public:
    static Registre& instance() {
        static Registre le_registre;
        return le_registre;
    }

    static bool ajouter_dans_registre(FnCreationJoueur CFJ) {
        instance()._VCFJo.push_back(CFJ);
        return true;
    }
    static bool ajouter_dans_registre(FnCreationJeu CFJ) {
        instance()._VCFJe.push_back(CFJ);
        return true;
    }

    static size_t nb_classes_dans_registre_Joueur() {
        return instance()._VCFJo.size();
    }
    static size_t nb_classes_dans_registre_Jeu() {
        return instance()._VCFJe.size();
    }

    static PtrJoueur getNouveauJoueur(size_t position,std::string nom, bool joueur_1) {
        if (position<nb_classes_dans_registre_Joueur())
            return instance()._VCFJo[position](nom,joueur_1);
        else
            return nullptr;
    }
    static PtrJeu getNouveauJeu(size_t position) {
        if (position<nb_classes_dans_registre_Joueur())
            return instance()._VCFJe[position]();
        else
            return nullptr;
    }
};




