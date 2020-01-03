#ifndef KAGEDEF_H
#define KAGEDEF_H

#include <iostream>
#include "defenseur.hh"


class KageDef : public Defenseur{

private:

public:

  //Constructeur
  KageDef(int vie, int chakra, std::string nom, int pointAttaque): Defenseur(vie,chakra,nom,pointAttaque){}
  KageDef(int vie, int chakra) : Defenseur(vie,chakra){}
  KageDef() : Defenseur(200, 200, "Gaara", 70){}

  // Fonctions
  void defenseKage(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4, Ninja &t1, Ninja &t2, Ninja &t3, Ninja &t4);

};


#endif
