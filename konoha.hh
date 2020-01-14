#ifndef KONOHA_H
#define KONOHA_H

#include <iostream>
#include "village.hh"

class Konoha : public Village{


public:

  //Constructeur
  Konoha();
  Konoha(Village& v);
  

  // Fonctions
  void capaciteVillage();
};


#endif
