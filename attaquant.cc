#include "attaquant.hh"

int Attaquant::_pointAttaque = 20;

void Attaquant::technique(Ninja &v){
  std::cout<< this->_nom <<" attaque de " << Attaquant::_pointAttaque << " "<< v.getNom()<<std::endl;
  int vie_v;
  vie_v = v.getVie();
  vie_v -= _pointAttaque;
  v.setVie(vie_v);
  this->_chakra -= 20;
}

void Attaquant::techniqueSpecial(Ninja &v){
  std::cout<< this->_nom <<" attaque special de " << Attaquant::_pointAttaque*2 << " "<< v.getNom()<<std::endl;

  int vie_v;
  vie_v = v.getVie();
  vie_v -= _pointAttaque*2;
  v.setVie(vie_v);
  this->_chakra -= 40;
}

void Attaquant::rechargeChakra(){
  std::cout<< this->_nom <<" recharge son chakra de 30 "<<std::endl;
  this->_chakra += 30;
}
