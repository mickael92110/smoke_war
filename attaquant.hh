#ifndef ATTAQUANT_H
#define ATTAQUANT_H

#include <iostream>
#include "ninja.hh"

class Attaquant : public Ninja{

protected:
  int _pointAttaque;

public:

  //Constructeu
  Attaquant(int vie, int chakra, std::string nom, int pointAttaque) ;
  Attaquant(int vie, int chakra) ;
  Attaquant() ;

  // Fonctions
  void technique(Ninja &v);
  void techniqueSpecial(Ninja &v);
  void rechargeChakra();

};


#endif
