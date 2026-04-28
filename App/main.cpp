#include <iostream>
#include "Competition.hh"

int main(int argc, char **argv) {
    Competition c;
    c.lancer_competition();
    c.sauvegarde();
    // std::cout << "argc : " << argc << " argv " << argv << " " << argv[0] << std::endl;
    // std::cout << "Hello World!" << std::endl;
    return 0;
}