#include "attaquant.hh"

Attaquant::Attaquant(int vie, int chakra, std::string nom, int pointAttaque) : Ninja(vie,chakra,nom){
  _pointAttaque = pointAttaque;
}

Attaquant::Attaquant(int vie, int chakra) : Ninja(vie,chakra){
  srand (time(NULL));
    _pointAttaque = rand() % 20 + 10;
  }

Attaquant::Attaquant() : Ninja(150,100,"Sasuke"){
  srand (time(NULL));
  _pointAttaque = rand() % 20 + 10;
}

void Attaquant::technique(Ninja &v){

  std::cout<< this->_nom <<" attaque de " << Attaquant::_pointAttaque << " pv "<< v.getNom()<<std::endl;
  int vie_v;
  vie_v = v.getVie();
  vie_v -= _pointAttaque;
  if (vie_v < 0) v.setVie(0);
  else v.setVie(vie_v);
  this->_chakra -= 20;
}

void Attaquant::techniqueSpecial(Ninja &v){
  std::cout<< this->_nom <<" attaque special de " << Attaquant::_pointAttaque*2 <<" pv "<< v.getNom()<<std::endl;

  int vie_v;
  vie_v = v.getVie();
  vie_v -= _pointAttaque*2;
  if (vie_v < 0) v.setVie(0);
  else v.setVie(vie_v);
  this->_chakra -= 40;
}

void Attaquant::rechargeChakra(){
  std::cout<< this->_nom <<" recharge son chakra de 30 "<<std::endl;
  this->_chakra += 30;
}
