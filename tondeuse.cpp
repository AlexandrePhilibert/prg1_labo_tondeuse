// -----------------------------------------------------------------------------------------------
// Fichier        : tondeuse.cpp
// Auteur(s)      : Behrmann Urs & Philibert Alexandre
// Date           : 2022-11-22
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>               // Utilisation de numeric limits
// NOTE : Est-ce qu'on inclut le h ?
// NOTE : Toujours, mais je crois que <vector> est ajoute a double, car il est aussi dans le .h
#include "tondeuse.h"
#include "annexe.h"

using namespace std;

const vector<char> CELLULE = {
        '#', // limite
        'X', // obstacle
        '~', // herbe haute
        '.'  // herbe coupée
};

void afficher(const Terrain &terrain) {
    for (const vector<TERRAIN> &l: terrain) {
        for (TERRAIN c: l) {
            cout << left << setw(2) << CELLULE[c];
        }
        cout << endl;
    }
}

bool obstacle(const Terrain &terrain, const Coordonnee &coordonnee) {
    // NOTE: Cast dans le bon type ?
    // NOTE: UB (Coordonnee::size_type) a la place de (size_t) ?

    // Trouve le type de terrain dans la cellule choisie et test si elle est un obstacle ou pas.
    TERRAIN cellule = terrain[(Coordonnee::size_type)coordonnee[0]][(Coordonnee::size_type) coordonnee[1]];

    return cellule == L || cellule == X;
}

void deplacer(const Terrain &terrain, Tondeuse &tondeuse) {
    int axe;
    bool positif;
    Coordonnee deplacement;

    // Choisi aleatoirement une position adjointe a la tondeuse tant que cette position n'est pas
    // bloquee par un obstacle.
    do {
        axe = random(0, 1);
        positif = random(0, 1);

        deplacement = {tondeuse[0], tondeuse[1]};
        deplacement[(Coordonnee::size_type) axe] += positif ? 1 : -1;
    } while (obstacle(terrain, deplacement));

    // Donne les nouvelles coordonnees à la tondeuse
    tondeuse[0] = deplacement[0];
    tondeuse[1] = deplacement[1];
}

void couper(Terrain &terrain, Tondeuse &tondeuse) {
    // Changer la valeur du terrain ou la tondeuse se situe en coupe "C"
    terrain[(Coordonnee::size_type) tondeuse[0]][(Coordonnee::size_type) tondeuse[1]] = C;
}

void tondre(Terrain &terrain,
            Tondeuse &tondeuse,
            int nombreDePas,
            bool afficherChaquePas
) {

    // À chaque pas : deplacer la tondeuse, couper la nouvelle position de la tondeuse et afficher
    // le nouveau terrain s'il doit être affiche.
    for (int i = 0; i < nombreDePas; ++i) {
        deplacer(terrain, tondeuse);
        couper(terrain, tondeuse);

        // Efface l'ancien affichage, affiche le "nouveau" terrain et demande un input de
        // l'utilisateur pour continuer.
        if (afficherChaquePas) {

            if (system("cls")) system("clear");

            afficher(terrain);

            cout << endl << "Appuyez sur ENTER pour continuer.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    afficher(terrain);
}

