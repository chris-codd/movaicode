#include <iostream>
#include <vector>

using namespace std;

/**
 * Entrée : un entier représentant l'année qui se termine
 * Comportement : ajouter 1 à l'entier d'entrée
 * Sortie : un entier représentant l'année qui commence
 */

int changement_d_annee(int annee_qui_se_termine) {
    vector<int> toutes_les_annees(100001);
    // on dit que si on trouve pas l'année qui commence c'est qu'on est en -1000
    int annee_qui_commence = -1000;

    // on remplit un vector avec toutes les années possibles (on est prévoyant)
    for (int i = 0; i < 100000; i++) {
        toutes_les_annees[i] = i + 1;
    }

    // on recherche dans ce vector l'année qui commence (opération mathématique)
    for (int i = 0; i < 100000; i++) {
        if (toutes_les_annees[i + 1] == annee_qui_se_termine + 1) {
            annee_qui_commence = toutes_les_annees[i + 1];
        }
    }

    return annee_qui_commence;
}

int main() {
    cout << changement_d_annee(2021) << endl;
    // sa marche
    return 0;
}