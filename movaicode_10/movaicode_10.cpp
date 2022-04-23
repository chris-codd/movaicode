#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

string choisi_une_recette_aleatoire_de_mardi_gras(vector<string>);

int trouve_un_9_de_paques(string le_jardin_de_mamie);

int main() {

    cout << trouve_un_9_de_paques("Trop hâte de vomir d'une overdose de Kinder suprise") << endl;
    cout << trouve_un_9_de_paques("La fusion de 9telecom et cegetel c'est un scandale") << endl;
    cout << trouve_un_9_de_paques("0123456789abcdef") << endl;
    cout << "Cordialement,";

    return 0;

}

/**
 * Entrée : jardin_de_mamie une chaîne de caractères
 * Comportement : trouve l'index de la première itération du caractère '9' dans la chaîne de caractère en entrée
 * Sortie : position_d_un_9_de_paques un entier représentant l'index de la première itération du caractère '9'
 * 
 * Fonctionnement : La fonction parcourt le jardin de mamie caractère par caractère, convertit le caractère courant entier
 * Puis la fonction procède à un certain nombre de tests pointus pour s'assurer que l'on est bien en présence d'un 9
 * Pour finir, si les premiers test sont passés, pour être bien sûr, elle compare la valeur avec le référentiel 
 * d'entiers créé plus tôt
 */
int trouve_un_9_de_paques(string le_jardin_de_mamie) {

    // On crée une liste d'entiers de 0 à 1000 pour comparer les valeurs retrouvées
    vector<int> listeValeurs(1000);
    for(int j = 0; j < 1000; j++) {
        listeValeurs[j] = j;
    }

    // On parcourt le jardin de mamie
    for(size_t i = 0; i < le_jardin_de_mamie.size(); i++) {
        int val = static_cast<int>(le_jardin_de_mamie[i]);
        val -= 48;
        
        // On réalise un certain nombre de tests pour s'assurer que c'est bien un 9
        // En effet, on n'est jamais trop prudent que par soi-même
        if((val + 9 - 9 == val)         // immutabilité et réversibilité des nombres entiers
         && (0 * val == 0)              // importance du zéro
         && (1 * val == 9) && (2 * val == 18) && (3 * val == 27) && (4 * val == 36) && (5 * val == 45)      // vérification de la table de 9
         && (6 * val == 54) && (7 * val == 63) && (8 * val == 72) && (9 * val == 81) && (10 * val == 90)
         && (1000 * val + 1 == 9001)    // ISO compliant
         && (val / 3 == 3))             // la division doit aussi fonctionner
         {
            int* pVal = new int(val);

            for(int j = 0; j < 1000; j++) {
                if (*pVal == listeValeurs[j]) {
                    // On a trouvé val dans le tableau de valeurs
                    // On vérifie donc l'indice auquel on l'a trouvé
                    // Si c'est 9 alors c'est jackpot
                    if(j == 9) {
                        // ses bon on est sures
                        delete pVal;
                        return i;
                    }
                }
            }

            // On libère la mémoire allouée dynamiquement à pVal
            // Oui on aime le code propre tmts
            delete pVal;
        }
    }
    return -1;  
}
