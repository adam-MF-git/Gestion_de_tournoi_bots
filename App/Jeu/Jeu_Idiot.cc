#include "Jeu_Idiot.hh"

Jeu_Idiot::Jeu_Idiot():
	Jeu() 
	, _etat(RACINE){
	
}

void Jeu_Idiot::joue(int coup){
	_etat = (_etat*10) + coup;
}

void Jeu_Idiot::reset() {
    _etat = RACINE;
}

int Jeu_Idiot::nb_coups() const {
	switch(_etat) {
		case RACINE : 
			return 2; // e
		case 1 : // a
		case 11 : // aa
		case 111 : // aaa
		case 112 : // aab
		case 113 : // aac
		case 12 : // ab
		case 121 : // aba
		case 13 : // ac
		case 132 : // acb
		case 2 :// b
		case 21 : // ba
		case 211 : // baa
		case 212 : // bab
		case 22 : // bb
		case 23 : // bc
			return 3;
		default :
			return -1;
	}
    return 0;
}

int Jeu_Idiot::getetat() const {
    return _etat;
}

bool Jeu_Idiot::coup_autorise(int coup) const {
    return (coup <= nb_coups());
}

bool Jeu_Idiot::terminer() const {
    return (
	  (_etat == 1121) || 
	  (_etat == 1122) || 
	  (_etat == 1123) ||
	  (_etat == 1131) ||
	  (_etat == 1132) ||
	  (_etat == 1133) ||
	  (_etat == 1211) ||
	  (_etat == 1212) ||
	  (_etat == 1213) ||
	  (_etat == 122) ||
	  (_etat == 123) ||
	  (_etat == 131) ||
	  (_etat == 1321) ||
	  (_etat == 1322) ||
	  (_etat == 1323)  ||
	  (_etat == 133)  ||
	  (_etat == 2111)  ||
	  (_etat == 2112)  ||
	  (_etat == 2113)  ||
	  (_etat == 2121)  ||
	  (_etat == 2122)  ||
	  (_etat == 2123)  || 
	  (_etat == 213)  ||
	  (_etat == 221)  ||
	  (_etat == 222)  ||
	  (_etat == 223)  ||
	  (_etat == 231)  ||
	  (_etat == 232)  ||
	  (_etat == 233)  ||
	  (_etat == 1111)  ||
	  (_etat == 1112)  ||
	  (_etat == 1113) );
}

bool Jeu_Idiot::victoire() const {
    return (
	  (_etat == 1122) ||
	  (_etat == 1123) ||
	  (_etat == 1132) ||
	  (_etat == 1213) ||
	  (_etat == 123) ||
	  (_etat == 2113) ||
	  (_etat == 231) ||
	  (_etat == 232) ||
	  (_etat == 233) ||
	  (_etat == 1113) );
}

bool Jeu_Idiot::egalite() const {
    return (
	  (_etat == 1133) ||
	  (_etat == 1212) ||
	  (_etat == 131) ||
	  (_etat == 1321) ||
	  (_etat == 1323) ||
	  (_etat == 133) ||
	  (_etat == 2122) ||
	  (_etat == 221) ||
	  (_etat == 222) ||
	  (_etat == 223) ||
	  (_etat == 1111) ||
	  (_etat == 1112) );
}