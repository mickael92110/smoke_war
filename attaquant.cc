#include "attaquant.hh"

Attaquant::Attaquant(int vie, int chakra, std::string nom, int pointAttaque) :
Ninja(vie,chakra,nom,pointAttaque,30,10)
{

}

Attaquant::Attaquant(int vie, int chakra) :
Ninja(vie,chakra)
{
  srand (time(NULL));
  _pointAtk = rand() % 20 + 10;
  _pointDef = 20;
  _pointSoin = 10;
}

Attaquant::Attaquant() : Ninja(150,100,"Sasuke"){
  srand (time(NULL));
  _pointAtk = rand() % 30 + 20;
  _pointDef = rand() % 20 + 10;
  _pointSoin = rand() % 10 + 10;
}

void Attaquant::technique(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4){
  std::cout<< this->_nom <<" attaque de " << Attaquant::_pointAtk << " pv "<< v1.getNom()<<std::endl;
  std::cout<< this->_nom <<" attaque de " << Attaquant::_pointAtk << " pv "<< v2.getNom()<<std::endl;
  std::cout<< this->_nom <<" attaque de " << Attaquant::_pointAtk << " pv "<< v3.getNom()<<std::endl;
  std::cout<< this->_nom <<" attaque de " << Attaquant::_pointAtk << " pv "<< v4.getNom()<<std::endl;
  this->reducVie(v1, this->_pointAtk);
  this->reducVie(v2, this->_pointAtk);
  this->reducVie(v3, this->_pointAtk);
  this->reducVie(v4, this->_pointAtk);
  this->_chakra -= 40;
}

void Attaquant::techniqueSpecial(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4){
  if(this->compteurAtkSpe == 0){
    std::cout<< "Ce ninja ne peut plus faire de technique special"<<std::endl;
    return;
  }
  std::cout<< this->_nom <<" attaque special de " << this->_pointAtk*2 <<" pv "<< v1.getNom()<<std::endl;
  std::cout<< this->_nom <<" attaque special de " << this->_pointAtk*2 <<" pv "<< v2.getNom()<<std::endl;
  std::cout<< this->_nom <<" attaque special de " << this->_pointAtk*2 <<" pv "<< v3.getNom()<<std::endl;
  std::cout<< this->_nom <<" attaque special de " << this->_pointAtk*2 <<" pv "<< v4.getNom()<<std::endl;
  this->reducVie(v1, this->_pointAtk*2);
  this->reducVie(v2, this->_pointAtk*2);
  this->reducVie(v3, this->_pointAtk*2);
  this->reducVie(v4, this->_pointAtk*2);
  this->_chakra -= 80;
  --this->compteurAtkSpe;
}

void Attaquant::rechargeChakra(){
  std::cout<< this->_nom <<" recharge son chakra de 20 "<<std::endl;
  if(this->_chakra > 100) this->_chakra = 100;
  else this->_chakra += 20;
}
