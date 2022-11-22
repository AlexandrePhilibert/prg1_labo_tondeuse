// -----------------------------------------------------------------------------------------------
// Fichier        : annexe.cpp
// Auteur(s)      : Behrmann Urs & Philibert Alexandre
// Date           : 2022-11-22
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <cstdlib> // srand
#include <ctime>   // time pour srand

// Repris de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/dccd145b3e99101c98de2d9a87ff05db386e2500/04_Fonctions/04_static_srand.cpp#L36
int random (int min,
            int max) {

   // initialiser une seule fois le générateur
   static bool first = true;
   if (first) {
      srand ((unsigned)time (NULL));
      first = false;
   }

   // une valeur entre min et max compris
   return (rand() % (max-min+1) ) + min;
}