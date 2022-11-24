// -----------------------------------------------------------------------------------------------
// Fichier        : annexe.h
// Auteur(s)      : Behrmann Urs & Philibert Alexandre
// Date           : 2022-11-22
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_TONDEUSE_ANNEXE_H
    #define PRG1_LABO_TONDEUSE_ANNEXE_H

    /** Fonction permettant de générer un nombre aléatoire entre un nombre minimal et un nombre maximal
     * -----------------------------------------------------------------------------------------------------------------
     * @param min               : correspond à la valeur minimal que le chiffre aléatoire peut avoir
     * @param max               : correspond à la valeur maximal que le chiffre aléatoire peut avoir
     * -----------------------------------------------------------------------------------------------------------------
     * @return                  : un int qui est le chiffre aléatoire généré
     * @exception               : -
     */
    int random(int min, int max);

#endif //PRG1_LABO_TONDEUSE_ANNEXE_H
