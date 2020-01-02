#include "defenseur.hh"

int Defenseur::_pointDefense = 20;

void Defenseur::technique(Ninja &v){
  std::cout<< this->_nom <<" attaque de " << Defenseur::_pointDefense << " "<< v.getNom()<<std::endl;
  int vie_v;
  vie_v = v.getVie();
  vie_v -= _pointDefense;
  v.setVie(vie_v);
  this->_chakra -= 20;
}

void Defenseur::techniqueSpecial(Ninja &v){
  std::cout<< this->_nom <<" attaque special de " << Defenseur::_pointDefense*2 << " "<< v.getNom()<<std::endl;

  int vie_v;
  vie_v = v.getVie();
  vie_v -= _pointDefense*2;
  v.setVie(vie_v);
  this->_chakra -= 40;
}

void Defenseur::rechargeChakra(){
  std::cout<< this->_nom <<" recharge son chakra de 30 "<<std::endl;
  this->_chakra += 30;
}
