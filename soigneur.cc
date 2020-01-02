#include "soigneur.hh"

Soigneur::Soigneur(int vie, int chakra, std::string nom, int pointSoin) : Ninja(vie,chakra,nom){
  _pointSoin = pointSoin;
}

Soigneur::Soigneur(int vie, int chakra) : Ninja(vie,chakra){
  srand (time(NULL));
    _pointSoin = rand() % 20 + 10;
  }

Soigneur::Soigneur() : Ninja(150,100,"Sakura"){
  srand (time(NULL));
  _pointSoin = rand() % 20 + 10;
}


void Soigneur::technique(Ninja &v){
  std::cout<< this->_nom <<" soin de " << Soigneur::_pointSoin << " pv "<< v.getNom()<<std::endl;
  int vie_v;
  vie_v = v.getVie();
  vie_v += _pointSoin;
  v.setVie(vie_v);
  this->_chakra -= 20;
}

void Soigneur::techniqueSpecial(Ninja &v){
  std::cout<< this->_nom <<" soin special de " << Soigneur::_pointSoin*2 << " pv "<< v.getNom()<<std::endl;
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
