#ifndef SOIGNEUR_H
#define SOIGNEUR_H

#include <iostream>
#include "ninja.hh"

class Soigneur : public Ninja{

private:
  int _pointSoin;

public:

  //Constructeur
  Soigneur(int vie, int chakra, std::string nom, int pointSoin) ;
  Soigneur(int vie, int chakra) ;
  Soigneur();

  // Fonctions
  void technique(Ninja &v);
  void techniqueSpecial(Ninja &v);
  void rechargeChakra();

};


#endif
