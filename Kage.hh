#ifndef KAGE_H
#define KAGE_H

#include <iostream>
#include "attaquant.hh"
//Un Kage est un attaquant qui peux attaquer avec son attaque normal sur tous
//les joueurs du village adverse
class Kage : public Attaquant{

private:

public:

  //Constructeur
  Kage(int vie, int chakra, std::string nom, int pointAttaque): Attaquant(vie,chakra,nom,pointattaque){}
  Kage(int vie, int chakra) : Attaquant(vie,chakra){}
  Kage() : Attaquant(){}

  // Fonctions
  void technique(Ninja &v);

};


#endif
