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
#include "coordonnee.h"

/**
 * Éléments présent sur le terrain.
 *
 * L = limite
 * X = obstacle
 * H = herbe haute
 * C = herbe coupée
 */
enum CASE_TERRAIN {L, X, H, C};

/**
 * Un terrain est représenté par des cases contenant des éléments
 * tel que des limites, obstacles, herbe haute et herbe coupée.
 */
using Terrain = std::vector<std::vector<CASE_TERRAIN>>;
/**
 * Une tondeuse est une coordonnée x et y sur un terrain.
 */
using Tondeuse = Coordonnee;

/**
* @name tondre
*
* Tonds le terrain à l'aide d'une tondeuse pour un certains nombre de pas.
*
* @param terrain           : Terrain sur lequel la tondeuse se déplace
* @param tondeuse          : La position initiale de la tondeuse sur le terrain
* @param nombreDePas       : Nombre de pas effectuer par la tondeuse. 1 pas = 1 déplacement
* @param afficherChaquePas : Affiche le terrain après chaque pas effectuer par la tondeuse
* @throws                  : out_of_range si une position hors du terrain est vérifiée
* @return                  : void
*/
void tondre(Terrain& terrain,
          Tondeuse& tondeuse,
          int nombreDePas,
          bool afficherChaquePas);

#endif //PRG1_LABO_TONDEUSE_TONDEUSE_H
