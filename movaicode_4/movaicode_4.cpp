#include <iostream>
#include <string>
#include <vector>

using namespace std;

// UNE CLASSE CAMARADE EST ABSTRAITES PARCE QUN(E) CAMARAD PEUT EN CACHE UN(E) AUTRES

class Camarade {

protected:
	string prenom;
	Camarade(string p) : prenom(p) {}
	virtual string toString() = 0;

public:
	string getPrenom() const { return prenom; }
	void setMot(string& p) { prenom = p; }
};

// UNE CAMARADEDECLASSES ET UN(E) CAMARADE QUI EST DANS LA CLASSE : HERITAGES PUBLIC
// IL(ELLE) PEUT AUSI AVOIR LA CLASSE, SES PAS DONNER A TOUS LE MONDE

class CamaradeDeClasse : public Camarade {

private:
	bool aDeLaClasse;

public:
	CamaradeDeClasse(string p) : Camarade(p), aDeLaClasse(false) {}
	CamaradeDeClasse(string p, bool _aDeLaClasse) : Camarade(p), aDeLaClasse(_aDeLaClasse) {}

	bool getaDeLaClasse() const { return aDeLaClasse; }
	void setMot(bool& a) { aDeLaClasse = a; }

	// SES POUR LITERATOR
	bool operator==(const CamaradeDeClasse& c2) const { return this->prenom == c2.prenom && this->aDeLaClasse == c2.aDeLaClasse; }

public:
	string toString() override { return prenom + (aDeLaClasse ? "\3" : ""); }
};
ostream& operator<< (ostream& os, CamaradeDeClasse camarade) { os << camarade.toString(); return os; }


// LA FONCTIONS DEMANDER

bool is_there_mon_BFF_dans_ma_classe(vector<CamaradeDeClasse> camarades_de_classe) {
	bool x1, x2;
	x1 = false;
	x2 = false;

	// ON CHERCHE LE BFF

	vector<CamaradeDeClasse>::iterator it = find(camarades_de_classe.begin(), camarades_de_classe.end(), CamaradeDeClasse("Jean-BFF <3", true));

	if (it != camarades_de_classe.end()) {
		// ON A TROUVER MAIS ON VERIRIFIS COMME MEME
		if (it->getPrenom() == "Jean-BFF <3") {
			// BON LA ON A BIEN TROUVER OK
			x2 = true;
		}
	}

	// MAIS ON VEUS ETRE SURE SURE

	for (CamaradeDeClasse cam : camarades_de_classe) {
		// ON ROCHERCHE LE BFF DE UNE AUTRES FASONN
		if (cam.getPrenom() == "Jean-BFF <3") {
			// ON VERIFI UNE DEUXIEMES FOIS POUR ETRE BIEN SURE
			if (cam.getPrenom() == "Jean-BFF <3") {
				x1 = true;
			}
		}
	}

	if (x1 == true && x2 == true) return true;

	// ON A PAS TROUVER SES TRISTES
	return false;

}


// LE PROGRAME PRINCIPALE

int main(int argc, char** argv) {

	vector<CamaradeDeClasse> camarades_de_classe;

	camarades_de_classe.push_back(CamaradeDeClasse("Squall"));
	camarades_de_classe.push_back(CamaradeDeClasse("Linoa"));
	camarades_de_classe.push_back(CamaradeDeClasse("Zell"));
	camarades_de_classe.push_back(CamaradeDeClasse("Selphie"));
	camarades_de_classe.push_back(CamaradeDeClasse("Quistis", true));
	camarades_de_classe.push_back(CamaradeDeClasse("Irvine"));
	camarades_de_classe.push_back(CamaradeDeClasse("Seifer", true));
	camarades_de_classe.push_back(CamaradeDeClasse("Edea", true));
	camarades_de_classe.push_back(CamaradeDeClasse("Kiros"));
	camarades_de_classe.push_back(CamaradeDeClasse("Ward", true));
	camarades_de_classe.push_back(CamaradeDeClasse("Laguna"));


	cout << "Ma classe : ";

	for (CamaradeDeClasse cam : camarades_de_classe) {
		cout << cam << " ";
	}

	cout << endl << endl;

	cout << "YA " << (!is_there_mon_BFF_dans_ma_classe(camarades_de_classe) ? "PAS " : "") << "MON COPAIN" << endl;

	camarades_de_classe.push_back(CamaradeDeClasse("Jean-BFF <3", true));

	cout << "YA " << (!is_there_mon_BFF_dans_ma_classe(camarades_de_classe) ? "PAS " : "") << "MON COPAIN" << endl;

	return 0;

}

// EN TOUTE CORDIALITER