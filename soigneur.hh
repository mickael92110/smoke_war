#ifndef SOIGNEUR_H
#define SOIGNEUR_H

#include <iostream>
#include "ninja.hh"

class Soigneur : public Ninja{

private:
  static int _pointSoin;

public:

  //Constructeur
  Soigneur(int vie, int chakra, std::string nom) : Ninja(vie,chakra,nom){}
  Soigneur(int vie, int chakra) : Ninja(vie,chakra){}
  Soigneur() : Ninja(100,150,"Sakura") {}

  // Fonctions
  void technique(Ninja &v);
  void techniqueSpecial(Ninja &v);
  void rechargeChakra();

};


#endif
