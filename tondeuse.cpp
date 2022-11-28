// -----------------------------------------------------------------------------------------------
// Fichier        : tondeuse.cpp
// Auteur(s)      : Behrmann Urs & Philibert Alexandre
// Date           : 2022-11-22
// But            : Fonctions responsables pour la gestion de la tondeuse (déplacement, coupe) et
//                  de l'affichage du terrain.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <vector>
#include "tondeuse.h"
#include "coordonnee.h"
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

/**
 * @name afficher
 *
 * Affiche le terrain à l'aide du tableau de correspondance entre le type de cellule et
 * le caractère a afficher.
 *
 * @param terrain : le terrain à afficher
 * @throws        : NIL
 * @return        : NIL
 */
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
 * @param terrain    : Le terrain sur lequel vérifier si la coordonnée est un obstacle
 * @param coordonnee : La coordonnée à vérifier sur le terrain
 * @return           : true si un obstacle est présent à la coordonnée, false si aucun obstacle n'est présent
 * @throws           : out_of_bounds si la coordonnée est hors du terrain
 */
bool estObstacle(const Terrain& terrain, const Coordonnee& coordonnee) {
   // Trouve le type de terrain dans la cellule choisie et test si elle est un obstacle ou pas.
   TERRAIN cellule = terrain.at((size_t) coordonnee[0]).at((size_t) coordonnee[1]);

   return cellule == L || cellule == X;
}

/**
 * @name deplacementsValide
 *
 * Retourne un vecteur de coordonnées contenant toutes les coordonnées valides de déplacement de la tondeuse.
 * Un déplacement est jugé valide s'il n'y pas d'obstacle sur sa position.
 *
 * Ne valide pas si la tondeuse sort du terrain.
 *
 * @param terrain  : Le terrain sur lequel les coordonnées seront validées
 * @param tondeuse : La position actuelle de la tondeuse dans le terrain
 * @return         : Un vecteur contenant toutes les coordonnées valides de déplacement de la tondeuse
 * @throws         : out_of_bounds si une position hors du terrain est vérifiée
 */
vector<Coordonnee> deplacementsValide(const Terrain& terrain, const Tondeuse& tondeuse) {
   vector<Coordonnee> deplacements;

   for (Coordonnee coordonnee : DEPLACEMENTS_AUTORISE) {
      Coordonnee deplacement = addition(tondeuse, coordonnee);
      if (!estObstacle(terrain, deplacement)) {
         deplacements.push_back(deplacement);
      }
   }

   return deplacements;
}

/**
 * @name deplacer
 *
 * Déplacement de la tondeuse vers l'une des cellules valide.
 *
 * @param terrain  : Le terrain sur lequel la tondeuse va tenter de se déplacer
 * @param tondeuse : La position de la tondeuse
 * @return         : false si la tondeuse n'a pas de déplacement valide, true si la tondeuse s'est déplacée
 * @throws         : out_of_bounds si une position hors du terrain est vérifiée
 */
bool deplacer(const Terrain& terrain, Tondeuse& tondeuse) {
   vector<Coordonnee> deplacements = deplacementsValide(terrain, tondeuse);

   if (deplacements.empty()) {
      return false;
   }

   Coordonnee deplacement = deplacements[(size_t) random(0, (int) (deplacements.size() - 1))];
   tondeuse[0] = deplacement[0];
   tondeuse[1] = deplacement[1];

   return true;
}

/**
 * @name couper
 *
 * Coupe l'herbe sur le terrain à la position de la tondeuse.
 *
 * @param terrain  : Le terrain sur lequel l'herbe sera coupée
 * @param tondeuse : La position de la tondeuse sur le terrain
 * @return         : void
 * @throws         : out_of_range si la position de la tondeuse est hors du terrain
 */
void couper(Terrain& terrain, Tondeuse& tondeuse) {
   terrain.at((size_t) tondeuse[0]).at((size_t) tondeuse[1]) = C;
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
         afficher(terrain);

         if (system("clear")) {
            system("cls");
         }
      }
   }

   afficher(terrain);
}