#ifndef DEFENSEUR_H
#define DEFENSEUR_H

#include <iostream>
#include "attaquant.hh"
//Un defenseur est un attaquant qui lorsqu'il attaque normalement il regarne de la vie
class Defenseur : public Attaquant{

private:
  int _pointDefense;

public:

  //Constructeur
  Defenseur(int vie, int chakra, std::string nom, int pointAttaque,int _pointDefense);
  Defenseur(int vie, int chakra) ;
  Defenseur() ;

  // Fonctions
  void technique(Ninja &v);


};


#endif
