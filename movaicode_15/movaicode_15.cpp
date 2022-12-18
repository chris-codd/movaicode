#include <iostream>
#include <cstring>
using namespace std;

/**
 * Fonction de distribution de coups de poing
 * Elle remplace toute lettre 'p' ou caract�re '.' ou ';' ou ':' trouv�s dans la cha�ne de caract�res str,
 * par le mot 'poing', 'poingvirgule' ou 'deuxpoings' et retourne la cha�ne de caract�res produite
 */
char* distribuer_des_coups_de_poing(const char* str);

/**
 * Ajoute une cha�ne de caract�res poing_a_distribuer � la cha�ne str � l'indice i par d�calage � droite
 */
void distribuer_un_poing(char* str, size_t i, const char* poing_a_distribuer);

/**
 * V�rifie que le 'p' qui est identifi� � l'indice i n'appartient pas � la cha�ne deuxpoings
 * car cela laisserait penser qu'il a �t� ajout� suite au remplacement d'un ':'
 */
bool verifier_p_deuxpoings(const char* str_poing, size_t i);


int main() {

	const char* synopsys = "Synopsys: dans les quartiers populaires de Philadelphie, Rocky Balboa collecte des dettes non pay�es pour Tony Gazzo, un usurier; il dispute de temps � autre, pour quelques dizaines de dollars, des combats de boxe sous l'appellation de l'�talon italien.";

	cout << distribuer_des_coups_de_poing(synopsys);

	return 0;

}


char* distribuer_des_coups_de_poing(const char* str) {

	char p = 'p';
	char P = 'P';
	char point = '.';
	char point_virgule = ';';
	char deux_points = ':';

	const char* p_poing = "poing";
	const char* P_poing = "poing";
	const char* point_poing = "poing";
	const char* point_virgule_poing = "poingvirgule";
	const char* deux_points_poing = "deuxpoings";

	char str_poing[5000]{};

	size_t i = 0;
	
	// On recopie str dans notre str_poing caract�re par caract�re
	// On prend bien soin de recalculer la longueur de str � chaque tour de boucle, au cas o�
	for (; i < strlen(str); i++) {
		str_poing[i] = str[i];
	}
	str_poing[i] = '\0';

	// On va parcourir notre str_poing et remplacer chaque �l�ment comme demand�
	// Il faudra donc d�caler vers la droite le reste de la cha�ne
	// On doit donc recalculer en permanence la longueur de str_poing afin d'�tre rigoureux
	// Attention subtilit� : si on tombe sur un 'p', il faudra s'assurer que ce n'est pas un caract�re que l'on a d�j� remplac�
	// on regardera alors les caract�res autour pour v�rifier qu'il ne s'agit pas de "deux" en pr�c�dent et "oings" en suivant
	// car cela nous laisserait penser que nous sommes en train de passer sur un ':' qui a �t� pr�alablement remplac�
	// Remarque : la cha�ne initiale "deuxpoings" ne sera donc pas trait�e, n'en d�plaise � Monsieur Stallone

	for (size_t i = 0; i < strlen(str_poing); i++) {

		if (str_poing[i] == p) {
			// On v�rifie que nous ne sommes pas en pr�sence d'un 'p' qui aurait �t� distribu�
			// suite � la d�couverte de deux points (=> deuxpoings)
			// Si c'est le cas, on ne traite pas ce 'p'
			if (! verifier_p_deuxpoings(str_poing, i)) {
				distribuer_un_poing(str_poing, i, p_poing);
			}
		}
		else if (str_poing[i] == P) {
			distribuer_un_poing(str_poing, i, P_poing);
		}
		else if (str_poing[i] == point) {
			distribuer_un_poing(str_poing, i, point_poing);
		}
		else if (str_poing[i] == point_virgule) {
			distribuer_un_poing(str_poing, i, point_virgule_poing);
		}
		else if (str_poing[i] == deux_points) {
			distribuer_un_poing(str_poing, i, deux_points_poing);
		}

	}

	return str_poing;

}


void distribuer_un_poing(char* str, size_t i, const char* poing_a_distribuer) {
	
	// On remplace le premier caract�re
	str[i] = poing_a_distribuer[0];
	i++;

	// On boucle sur les suivants
	// A chaque tour, on doit d�caler le reste de la cha�ne vers la droite, pour faire de la place
	for(size_t j = 1; j < strlen(poing_a_distribuer); j++) {
	
		// D�calage � droite
		str[strlen(str)] = '\0';
		for (size_t k = strlen(str)-1; k >= i; k--) {
			str[k+1] = str[k];
		}

		// Copie d'un caract�re suppl�mentaire
		str[i] = poing_a_distribuer[j];
		i++;
		
	}
}


bool verifier_p_deuxpoings(const char* str, size_t i) {
	// "deuxpoings"
	if (i < 4) return false;
	if (i + 5 > (strlen(str) - 1)) return false;
	if (str[i-4] != 'd' || str[i-3] != 'e' || str[i-2] != 'u' || str[i-1] != 'x' || str[i] != 'p'
		|| str[i+1] != 'o' || str[i+2] != 'i' || str[i+3] != 'n' || str[i+4] != 'g' || str[i+5] != 's')
		return false;

	return true;
}
