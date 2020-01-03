#include "kageSoin.hh"

//Soigne toute son equipe et reduit la defense de l'autre equipe
void KageSoin::SoinKage(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4, Ninja &t1, Ninja &t2, Ninja &t3, Ninja &t4){
  this->techniqueSpecial(t1,t2,t3,t4);
  this->reducDef(v1, 50);
  this->reducDef(v2, 50);
  this->reducDef(v3, 50);
  this->reducDef(v4, 50);
}
