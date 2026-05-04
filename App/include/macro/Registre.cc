#include "Registre.hh"

static std::vector<FnCreationJoueur>& get_VCFJo() {
    static std::vector<FnCreationJoueur> instance;
    return instance;
}

static std::vector<std::string>& get_VNJo() {
    static std::vector<std::string> instance;
    return instance;
}

static std::vector<FnCreationJeu>& get_VCFJe() {
    static std::vector<FnCreationJeu> instance;
    return instance;
}

static std::vector<std::string>& get_VNJe() {
    static std::vector<std::string> instance;
    return instance;
}

bool Registre::ajouter_dans_registre(FnCreationJoueur CFJ, std::string NJo)  {
    std::cout << "Ajouter Joueur nom : " << NJo << std::endl;
    get_VCFJo().push_back(CFJ);
    get_VNJo().push_back(NJo);
    return true;
}

bool Registre::ajouter_dans_registre(FnCreationJeu CFJ, std::string NJe) {
    std::cout << "Ajouter Jeu nom : " << NJe << std::endl;
    get_VCFJe().push_back(CFJ);
    get_VNJe().push_back(NJe);
    return true;
}

size_t Registre::nb_classes_dans_registre_Joueur() {
    return get_VCFJo().size();
}

size_t Registre::nb_classes_dans_registre_Jeu() {
    return get_VCFJe().size();
}

std::string Registre::getNomJoueur(size_t position) {
    if (position<nb_classes_dans_registre_Joueur())
        return get_VNJo()[position];
    else
        return "";
}

std::string Registre::getNomJeu(size_t position) {
    if (position<nb_classes_dans_registre_Joueur())
        return get_VNJe()[position];
    else
        return "";
}

PtrJoueur Registre::getNouveauJoueur(size_t position, std::string nom, bool joueur_1) {
    if (position<nb_classes_dans_registre_Joueur())
        return get_VCFJo()[position](nom,joueur_1);
    else
        return nullptr;
}

PtrJeu Registre::getNouveauJeu(size_t position) {
    if (position<nb_classes_dans_registre_Joueur())
        return get_VCFJe()[position]();
    else
        return nullptr;
}
