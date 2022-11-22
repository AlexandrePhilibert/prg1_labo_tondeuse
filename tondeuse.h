// -----------------------------------------------------------------------------------------------
// Fichier        : tondeuse.h
// Auteur(s)      : Behrmann Urs & Philibert Alexandre
// Date           : 2022-11-22
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_TONDEUSE_TONDEUSE_H
#define PRG1_LABO_TONDEUSE_TONDEUSE_H

#include <vector>
#include <array>

/**
 * L = limite
 * H = herbe
 * X = obstacle
 */
enum TERRAIN {L, X, H};

using Terrain = std::vector<std::vector<TERRAIN>>;
using Tondeuse = std::array<int, 2>;

void tondre(const Terrain& terrain,
            const Tondeuse& tondeuse,
            int nombreDePas,
            bool afficherChaquePas);

#endif //PRG1_LABO_TONDEUSE_TONDEUSE_H
