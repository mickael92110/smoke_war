#include "soigneur.hh"

int Soigneur::_pointSoin = 40;

void Soigneur::technique(Ninja &v){
  std::cout<< this->_nom <<" soin de " << Soigneur::_pointSoin << " "<< v.getNom()<<std::endl;
  int vie_v;
  vie_v = v.getVie();
  vie_v += _pointSoin;
  v.setVie(vie_v);
  this->_chakra -= 20;
}

void Soigneur::techniqueSpecial(Ninja &v){
  std::cout<< this->_nom <<" soin special de " << Soigneur::_pointSoin*2 << " "<< v.getNom()<<std::endl;
  int vie_v;
  vie_v = v.getVie();
  vie_v += _pointSoin*2;
  v.setVie(vie_v);
  this->_chakra -= 40;
}

void Soigneur::rechargeChakra(){
  std::cout<< this->_nom <<" recharge son chakra de 30 "<<std::endl;
  this->_chakra += 30;
}
