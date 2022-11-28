#include "coordonnee.h"

Coordonnee addition(const Coordonnee& c1, const Coordonnee& c2) {
   return {c1[0] + c2[0], c1[1] + c2[1]};
}
