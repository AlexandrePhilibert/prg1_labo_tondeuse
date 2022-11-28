#ifndef PRG1_LABO_TONDEUSE_COORDONNEE_H
#define PRG1_LABO_TONDEUSE_COORDONNEE_H

#include <array>

/**
 * Une cordonnée est constituée des coordonnées x et y, x en position 0 et y en position 1.
 */
using Coordonnee = std::array<int, 2>;

/**
 * @name addition
 *
 * Additionne les positions x et y de deux coordonnées.
 *
 * @param c1 : Première coordonnée
 * @param c2 : Deuxième coordonnée
 * @return   : L'addition des 2 coordonnées
 * @throws   : NIL
 */
Coordonnee addition(const Coordonnee& c1, const Coordonnee& c2);

#endif //PRG1_LABO_TONDEUSE_COORDONNEE_H
