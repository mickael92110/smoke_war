#ifndef DEFENSEUR_H
#define DEFENSEUR_H

#include <iostream>
#include "ninja.hh"

class Defenseur : public Ninja{


public:

  //Constructeur
  Defenseur(int vie, int chakra, std::string nom, int pointDefense);
  Defenseur(int vie, int chakra) ;
  Defenseur() ;
  Defenseur(std::string nom);

  // Fonctions
  void technique(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4);
  void techniqueSpecial(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4);
  void rechargeChakra();
};


#endif
