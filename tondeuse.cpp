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

/**
 * Caractère représentant une cellule du terrain lors de l'affichage.
 * L'ordre des éléments est en relation avec l'encodage du terrain (voir tondeuse.h)
 */
const vector<char> CELLULE = {
   '#', // limite
   'X', // obstacle
   '~', // herbe haute
   '.'  // herbe coupée
};

/**
 * Les déplacements relatifs autorisé de la tondeuse
 */
const vector<Coordonnee> DEPLACEMENTS_AUTORISE = {
   {0, -1}, // Haut
   {1, 0},  // Droite
   {0, 1},  // Bas
   {-1, 0}  // Gauche
};

void afficher(const Terrain& terrain) {
   for (const vector<TERRAIN>& l : terrain) {
      for(TERRAIN c : l) {
         cout << left << setw(2) << CELLULE[c];
      }
      cout << endl;
   }
}

/**
 * @name estObstacle
 *
 * Vérifie si la cellule à la coordonnée donnée est un obstacle (limite ou obstacle)
 *
 * @param terrain Le terrain sur lequel vérifier si la coordonnée est un obstacle
 * @param coordonnee La coordonnée à vérifier sur le terrain
 * @return
 */
bool estObstacle(const Terrain& terrain, const Coordonnee& coordonnee) {
   // NOTE: Cast dans le bon type ?
   TERRAIN cellule = terrain[(size_t) coordonnee[0]][(size_t) coordonnee[1]];

   return cellule == L || cellule == X;
}

/**
 * @name deplacementsValide
 *
 * Retourne un vecteur de coordonnées contenant toutes les coordonnées valides de déplacement de la tondeuse.
 * Un déplacement est jugé valide s'il n'y pas d'obstacle sur sa position.
 *
 * @param terrain Le terrain sur lequel les coordonnées seront validées
 * @param tondeuse La position actuelle de la tondeues dans le terain
 * @return Un vecteur contenant toutes les coordonnées valides de déplacement de la tondeuse
 */
vector<Coordonnee> deplacementsValide(const Terrain& terrain, const Tondeuse& tondeuse) {
   vector<Coordonnee> deplacements;

   // TODO: Fonction pour addition des coordonnées
   // TODO: Valider que la tondeuse ne sort pas du terrain (par. ex: -1,0)
   for (Coordonnee deplacement : DEPLACEMENTS_AUTORISE) {
      if (!estObstacle(terrain, {deplacement[0] + tondeuse[0], deplacement[1] + tondeuse[1]})) {
         deplacements.push_back({deplacement[0] + tondeuse[0], deplacement[1] + tondeuse[1]});
      }
   }

   return deplacements;
}

void deplacer(const Terrain& terrain, Tondeuse& tondeuse) {
   vector<Coordonnee> deplacements = deplacementsValide(terrain, tondeuse);

   if (deplacements.empty()) {
      // NOTE: Que faire si aucun déplacement n'est possible ? (pourrait retourner booléen si déplacement fait)
      return;
   }

   Coordonnee deplacement = deplacements[(size_t) random(0, (int) (deplacements.size() - 1))];
   tondeuse[0] = deplacement[0];
   tondeuse[1] = deplacement[1];
}

/**
 * @name couper
 *
 * Coupe l'herbe sur le terrain à la position de la tondeuse.
 *
 * @param terrain Le terrain sur lequel l'herbe sera coupée
 * @param tondeuse La position de la tondeuse sur le terrain
 */
void couper(Terrain& terrain, Tondeuse& tondeuse) {
   terrain[(size_t) tondeuse[0]][(size_t) tondeuse[1]] = C;
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
         system("clear");
         afficher(terrain);
      }
   }

   system("clear");

   afficher(terrain);
}

