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
// NOTE : Est-ce qu'on inclut le h ?
#include "tondeuse.h"
#include "annexe.h"

using namespace std;

const vector<char> CELLULE = {
   '#', // limite
   'X', // obstacle
   '~', // herbe haute
   '.'  // herbe coupée
};

void afficher(const Terrain& terrain) {
   for (const vector<TERRAIN>& l : terrain) {
      for(TERRAIN c : l) {
         cout << left << setw(2) << CELLULE[c];
      }
      cout << endl;
   }
}

bool obstacle(const Terrain& terrain, const Coordonnee& coordonnee) {
   // NOTE: Cast dans le bon type ?
   TERRAIN cellule = terrain[(size_t) coordonnee[0]][(size_t) coordonnee[1]];

   return cellule == L || cellule == X;
}

void deplacer(const Terrain& terrain, Tondeuse& tondeuse) {
   int axe;
   bool positif;
   Coordonnee deplacement;

   do {
      axe = random(0, 1);
      positif = random(0, 1);

      deplacement = {tondeuse[0], tondeuse[1]};
      deplacement[(Coordonnee::size_type) axe] += positif ? 1 : -1;
   } while(obstacle(terrain, deplacement));

   tondeuse[0] = deplacement[0];
   tondeuse[1] = deplacement[1];
}

void couper(Terrain& terrain, Tondeuse& tondeuse) {
   terrain[(Coordonnee::size_type) tondeuse[0]][(Coordonnee::size_type) tondeuse[1]] = C;
}

void tondre(Terrain& terrain,
            Tondeuse& tondeuse,
            int nombreDePas,
            bool afficherChaquePas
            ) {
   for (int i = 0; i < nombreDePas; ++i) {
      deplacer(terrain, tondeuse);
      couper(terrain, tondeuse);

      if (afficherChaquePas) {
         // system("clear")
         // system("cls")
      }
   }

   afficher(terrain);
}

