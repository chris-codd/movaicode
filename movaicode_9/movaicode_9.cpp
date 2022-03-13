#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

string choisi_une_recette_aleatoire_de_mardi_gras(vector<string>);

int main() {

    vector<string> specialites{ "gaufres", "croustillons du ch'nord", "bugnes", "ganses", "pets de nonne", "roussettes", "merveilles", "crouchepettes", "bougnettes", "beugnot", "bottereaux", "oreillettes" };

    cout << choisi_une_recette_aleatoire_de_mardi_gras(specialites);
    return 0;

}

/**
 * Entrée : une liste de string contenant toutes les spécialités régionales de Mardi Gras
 * Comportement : séléctionne aléatoirement un élément de la liste
 * Sortie : un string réprésentant la spécialité séléctionnée
 * 
 * Fonctionnement : la fonction demande un certain nombre d'informations capitales à l'utilisateur
 * La durée que met l'utilisateur pour compléter l'interrogatoire est calculée
 * On lui applique un modulo 12 (nombre de spécialités)
 * 
 */
string choisi_une_recette_aleatoire_de_mardi_gras(vector<string> specialites) {

    string val;

    auto startingTimeStamp = chrono::system_clock::now();

    cout << "**************************************" << endl;
    cout << "WELCOME" << endl;
    cout << "WE ARE SO HAPPY THAT YOU COULD MAKE IT" << endl;
    cout << "**************************************" << endl;

    cout << "what's your name? > ";
    getline(cin, val);
    cout << "what's your age? > ";
    getline(cin, val);
    cout << "where do you live? > ";
    getline(cin, val);
    cout << "do you think bycicles should be allowed to ignore traffic lights? > ";
    getline(cin, val);
    cout << "would you marry me? > ";
    getline(cin, val);
    cout << "which is the fastest: the ant or the dog? > ";
    getline(cin, val);
    cout << "would you prefer being a database or buying a house? > ";
    getline(cin, val);
    cout << "in csgo, what does 'rush corniche' mean? > ";
    getline(cin, val);
    cout << "when an action is passed and dated, should we use preterit or present perfect? > ";
    getline(cin, val);
    cout << "do you prefer miss parker, monsieur lyle or sydney? > ";
    getline(cin, val);
    cout << "when will it happen? > ";
    getline(cin, val);
    cout << "i lost the game" << endl << endl;

    auto endingTimeStamp = chrono::system_clock::now();

    // Calcul du temps passé à compléter le questionnaire (en ms)
    int diff = static_cast<int>((endingTimeStamp - startingTimeStamp).count());

    // Calcul de l'index à utiliser dans le tableau (malin)
    int index = diff % 12;

    return specialites[index];

}