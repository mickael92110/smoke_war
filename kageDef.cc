#include "kageDef.hh"

//Augmente la defense de toute l'equipe adverse et soigne son equipe
void KageDef::defenseKage(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4, Ninja &t1, Ninja &t2, Ninja &t3, Ninja &t4){
  this->techniqueSpecial(v1,v2,v3,v4);
  this->augmVie(t1, 50);
  this->augmVie(t2, 50);
  this->augmVie(t3, 50);
  this->augmVie(t4, 50);
}
