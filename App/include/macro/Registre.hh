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
    Registre()=delete;
    ~Registre()=delete;
    Registre(Registre const &) = delete;
    Registre & operator=(Registre const &) = delete;

public:
    //Ajoue de donnée
    static bool ajouter_dans_registre(FnCreationJoueur CFJ, std::string NJo);
    static bool ajouter_dans_registre(FnCreationJeu CFJ, std::string NJe);

    //Info
    static size_t nb_classes_dans_registre_Joueur();
    static size_t nb_classes_dans_registre_Jeu();
    static std::string getNomJoueur(size_t position);
    static std::string getNomJeu(size_t position);

    //Création
    static PtrJoueur getNouveauJoueur(size_t position,std::string nom, bool joueur_1);
    static PtrJeu getNouveauJeu(size_t position);
};

template <typename classJoueur>
class RegistreAutoJoueur {
protected:
    RegistreAutoJoueur()=default;
    static bool registre_init;
private:
    static std::string nom_classe() {
#ifdef __clang__
        std::string nom = __PRETTY_FUNCTION__;
#elif defined(__GNUC__)
        std::string nom = __PRETTY_FUNCTION__;
#elif defined(_MSC_VER)
        std::string nom = __FUNCSIG__;
#endif
        auto pos1(nom.find("="));
        auto pos2(nom.find(";"));
        return nom.substr(pos1+2,pos2-pos1-2);
    }
    static bool registre() {
        FnCreationJoueur function = [] (std::string nom,bool joueur_1) -> PtrJoueur {
            return std::make_unique<classJoueur>(nom,joueur_1);
        };
        return Registre::ajouter_dans_registre(function, nom_classe());
    }
};
template <typename classJoueur>
bool RegistreAutoJoueur<classJoueur>::registre_init = RegistreAutoJoueur<classJoueur>::registre();


template <typename classJeu>
class RegistreAutoJeu {
protected:
    RegistreAutoJeu()=default;
    static bool registre_init;
private:
    static std::string nom_classe() {
#ifdef __clang__
        std::string nom = __PRETTY_FUNCTION__;
#elif defined(__GNUC__)
        std::string nom = __PRETTY_FUNCTION__;
#elif defined(_MSC_VER)
        std::string nom = __FUNCSIG__;
#endif
        auto pos1(nom.find("="));
        auto pos2(nom.find(";"));
        return nom.substr(pos1+2,pos2-pos1-2);
    }
    static bool registre() {
        FnCreationJeu function = [] () -> PtrJeu {
            return std::make_unique<classJeu>();
        };

        return Registre::ajouter_dans_registre(function, nom_classe());
    }
};

template <typename classJeu>
bool RegistreAutoJeu<classJeu>::registre_init = RegistreAutoJeu<classJeu>::registre();
