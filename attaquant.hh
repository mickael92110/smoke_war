#ifndef ATTAQUANT_H
#define ATTAQUANT_H

#include <iostream>
#include "ninja.hh"

class Attaquant : public Ninja{

private:
  static int _pointAttaque;

public:

  //Constructeur
  Attaquant(int vie, int chakra, std::string nom) : Ninja(vie,chakra,nom){}
  Attaquant(int vie, int chakra) : Ninja(vie,chakra){}
  Attaquant() : Ninja(150,100,"Sasuke"){}

  // Fonctions
  void technique(Ninja &v);
  void techniqueSpecial(Ninja &v);
  void rechargeChakra();

};


#endif
