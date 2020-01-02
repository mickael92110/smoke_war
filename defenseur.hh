#ifndef DEFENSEUR_H
#define DEFENSEUR_H

#include <iostream>
#include "ninja.hh"

class Defenseur : public Ninja{

private:
  static int _pointDefense;

public:

  //Constructeur
  Defenseur(int vie, int chakra, std::string nom) : Ninja(vie,chakra,nom){}
  Defenseur(int vie, int chakra) : Ninja(vie,chakra){}
  Defenseur() : Ninja(150,100,"Naruto"){}

  // Fonctions
  void technique(Ninja &v);
  void techniqueSpecial(Ninja &v);
  void rechargeChakra();

};


#endif
