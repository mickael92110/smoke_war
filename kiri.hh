#ifndef KIRI_H
#define KIRI_H

#include <iostream>
#include "village.hh"

class Kiri : public Village{


public:

  //Constructeur
  Kiri();
  Kiri(Village&);

  // Fonctions
  void capaciteVillage();
};


#endif
