#ifndef KAGESOIN_H
#define KAGESOIN_H

#include <iostream>
#include "soigneur.hh"


class KageSoin : public Soigneur{

private:

public:

  //Constructeur
  KageSoin(int vie, int chakra, std::string nom, int pointAttaque): Soigneur(vie,chakra,nom,pointAttaque){}
  KageSoin(int vie, int chakra) : Soigneur(vie,chakra){}
  KageSoin() : Soigneur(200, 200, "Tsunade", 70){}
  KageSoin(std::string nom ) : Soigneur(200, 200, nom, 70){}

  // Fonctions
  void SoinKage(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4, Ninja &t1, Ninja &t2, Ninja &t3, Ninja &t4);

};


#endif
