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
#include "tondeuse.h"

using namespace std;

const vector<char> CASE = {
   '#', // limite
   'X', // obstacle
   '~', // herbe haute
   '.'  // coupée
};

void afficher(const Terrain& terrain) {
   for (const vector<TERRAIN>& l : terrain) {
      for(TERRAIN c : l) {
         cout << left << setw(2) << CASE[c];
      }
      cout << endl;
   }
}

void tondre(const Terrain& terrain,
            const Tondeuse& tondeuse,
            int nombreDePas,
            bool afficherChaquePas) {
   afficher(terrain);
}