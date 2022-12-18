#include <iostream>
#include <cstring>
using namespace std;

char* distribuer_des_coups_de_poing(const char* str);

int main() {

	const char* synopsys = "Synopsys: dans les quartiers populaires de Philadelphie, Rocky Balboa collecte des dettes non payées pour Tony Gazzo, un usurier; il dispute de temps à autre, pour quelques dizaines de dollars, des combats de boxe sous l'appellation de l'étalon italien.";

	cout << distribuer_des_coups_de_poing(synopsys);

	return 0;

}

char* distribuer_des_coups_de_poing(const char* str) {

	char p = 'p';
	char P = 'P';
	char point = '.';
	char point_virgule = ';';
	char deux_points = ':';

	const char* p_distribues = "poing";
	const char* P_distribues = "poing";
	const char* point_distribues = "poing";
	const char* point_virgule_distribues = "poingvirgule";
	const char* deux_points_distribues = "deuxpoings";

	int i = 0;
	size_t length = strlen(str);

	char* str_distribues = new char();
	size_t length_str_distribues = 0;

	// On boucle sur les caractères de la string pour laquelle il faut distribuer
	// selon le cas, on ajoute poing, poingvirgule ou deuxpoings à la chaîne à retourner

	for (i = 0; i < length; i++) {

		if (str[i] == p) {
			for (int j = 0; j < strlen(p_distribues); j++) {
				str_distribues[length_str_distribues] = p_distribues[j];
				length_str_distribues++;
			}
		}
		else if (str[i] == P) {
			for (int j = 0; j < strlen(P_distribues); j++) {
				str_distribues[length_str_distribues] = P_distribues[j];
				length_str_distribues++;
			}
		}
		else if (str[i] == point) {
			for (int j = 0; j < strlen(point_distribues); j++) {
				str_distribues[length_str_distribues] = point_distribues[j];
				length_str_distribues++;
			}
		}
		else if (str[i] == point_virgule) {
			for (int j = 0; j < strlen(point_virgule_distribues); j++) {
				str_distribues[length_str_distribues] = point_virgule_distribues[j];
				length_str_distribues++;
			}
		}
		else if (str[i] == deux_points) {
			for (int j = 0; j < strlen(deux_points_distribues); j++) {
				str_distribues[length_str_distribues] = deux_points_distribues[j];
				length_str_distribues++;
			}
		}
		else {
			str_distribues[length_str_distribues] = str[i];
			length_str_distribues++;
		}

	}

	str_distribues[length_str_distribues] = '\0';

	return str_distribues;
	
}