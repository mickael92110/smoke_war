#include "soigneur.hh"



Soigneur::Soigneur(int vie, int chakra, std::string nom, int pointSoin) :
Ninja(vie,chakra,nom,10,30,pointSoin)
{

}

Soigneur::Soigneur(int vie, int chakra) :
Ninja(vie,chakra)
{

  srand (time(NULL));
  _pointAtk = 15;
  _pointDef = 20;
  _pointSoin = rand() % 20 + 10;
  }

Soigneur::Soigneur() : Ninja(150,100,"Sakura"){
  srand (time(NULL));
  _pointAtk = rand() % 15 + 10;
  _pointDef = rand() % 15 + 10;
  _pointSoin = rand() % 40 + 10;
}

Soigneur::Soigneur(std::string nom) : Ninja(100,100,nom){

  srand (time(NULL));
  _pointAtk = rand() % 15 + 10;
  _pointDef = rand() % 15 + 10;
  _pointSoin = rand() % 40 + 10;
}


void Soigneur::technique(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4){
  std::cout<< this->_nom <<" soigne de " << Soigneur::_pointSoin << " pv "<< v1.getNom()<<std::endl;
  std::cout<< this->_nom <<" soigne de " << Soigneur::_pointSoin << " pv "<< v2.getNom()<<std::endl;
  std::cout<< this->_nom <<" soigne de " << Soigneur::_pointSoin << " pv "<< v3.getNom()<<std::endl;
  std::cout<< this->_nom <<" soigne de " << Soigneur::_pointSoin << " pv "<< v4.getNom()<<std::endl;
  this->augmVie(v1, this->_pointSoin);
  this->augmVie(v2, this->_pointSoin);
  this->augmVie(v3, this->_pointSoin);
  this->augmVie(v4, this->_pointSoin);
  this->_chakra -= 40;
}

void Soigneur::techniqueSpecial(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4){
  if(this->compteurAtkSpe == 0){
    std::cout<< "Ce ninja ne peut plus faire de technique special"<<std::endl;
    return;
  }
  std::cout<< this->_nom <<" soin special de " << this->_pointSoin*2 <<" pv "<< v1.getNom()<<std::endl;
  std::cout<< this->_nom <<" soin special de " << this->_pointSoin*2 <<" pv "<< v2.getNom()<<std::endl;
  std::cout<< this->_nom <<" soin special de " << this->_pointSoin*2 <<" pv "<< v3.getNom()<<std::endl;
  std::cout<< this->_nom <<" soin special de " << this->_pointSoin*2 <<" pv "<< v4.getNom()<<std::endl;
  this->augmVie(v1, this->_pointAtk*2);
  this->augmVie(v2, this->_pointAtk*2);
  this->augmVie(v3, this->_pointAtk*2);
  this->augmVie(v4, this->_pointAtk*2);
  this->_chakra -= 80;
  --this->compteurAtkSpe;
}

void Soigneur::rechargeChakra(){
  std::cout<< this->_nom <<" recharge son chakra de 50 "<<std::endl;
  if(this->_chakra > 100) this->_chakra = 100;
  this->_chakra += 50;
}
