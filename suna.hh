#ifndef SUNA_H
#define SUNA_H

#include <iostream>
#include "village.hh"

class Suna : public Village{


public:

  //Constructeur
  Suna();
  Suna(Village&);

  // Fonctions
  void capaciteVillage();
};


#endif
