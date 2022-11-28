// -----------------------------------------------------------------------------------------------
// Fichier        : coordonnee.cpp
// Auteur(s)      : Behrmann Urs & Philibert Alexandre
// Date           : 2022-11-28
// But            : Fonction permettant d'additionner deux coordonnées.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include "coordonnee.h"

Coordonnee addition(const Coordonnee& c1, const Coordonnee& c2) {
   return {c1[0] + c2[0], c1[1] + c2[1]};
}
