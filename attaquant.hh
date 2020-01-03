#ifndef ATTAQUANT_H
#define ATTAQUANT_H

#include <iostream>
#include "ninja.hh"

class Attaquant : public Ninja{


public:

  //Constructeur
  Attaquant(int vie, int chakra, std::string nom, int pointAttaque) ;
  Attaquant(int vie, int chakra) ;
  Attaquant() ;

  // Fonctions
  void technique(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4);
  void techniqueSpecial(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4);
  void rechargeChakra();
};


#endif
