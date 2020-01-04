#ifndef KAGEATK_H
#define KAGEATK_H

#include <iostream>
#include "attaquant.hh"


class KageAtk : public Attaquant{

private:

public:

  //Constructeur
  KageAtk(int vie, int chakra, std::string nom, int pointAttaque): Attaquant(vie,chakra,nom,pointAttaque){}
  KageAtk(int vie, int chakra) : Attaquant(vie,chakra){}
  KageAtk() : Attaquant(200, 200, "Minato", 70){}

  // Fonctions
  //Les v sont les Ninja de l'equipe adverse, t les Ninja de l'equipe
  void attaqueKage(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4, Ninja &t1, Ninja &t2, Ninja &t3, Ninja &t4);

};


#endif
