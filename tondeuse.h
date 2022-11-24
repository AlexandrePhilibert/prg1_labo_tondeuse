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
     * X = obstacle
     * H = herbe haute
     * C = herbe coupée
     */
    enum TERRAIN {L, X, H, C};

    using Terrain = std::vector<std::vector<TERRAIN>>;
    using Coordonnee = std::array<int, 2>;
    using Tondeuse = Coordonnee;

    /** Fonction permettant de controller une tondeuse à gazon qui tond un terrain
     * -----------------------------------------------------------------------------------------------------------------
     * @param terrain           : correspond au terrain qui va être tondu
     * @param tondeuse          : correspond à la tondeuse
     * @param nombreDePas       : correspond au nombres de pas que la tondeuse va faire
     * @param afficherChaquePas : correspond à s'il faut afficher chaque pas de la tondeuse ou pas
     * -----------------------------------------------------------------------------------------------------------------
     * @return                  : -
     * @exception               : -
     */
    void tondre(Terrain& terrain,
                Tondeuse& tondeuse,
                int nombreDePas,
                bool afficherChaquePas);

#endif //PRG1_LABO_TONDEUSE_TONDEUSE_H
