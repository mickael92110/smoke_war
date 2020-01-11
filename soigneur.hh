#ifndef SOIGNEUR_H
#define SOIGNEUR_H

#include <iostream>
#include "ninja.hh"

class Soigneur : public Ninja{



public:

  //Constructeur
  Soigneur(int vie, int chakra, std::string nom, int pointSoin) ;
  Soigneur(int vie, int chakra) ;
  Soigneur();
  Soigneur(std::string nom);

  // Fonctions
  void technique(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4);
  void techniqueSpecial(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4);
  void rechargeChakra();
};


#endif
