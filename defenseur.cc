#include "defenseur.hh"



Defenseur::Defenseur(int vie, int chakra, std::string nom, int pointDefense) :
Ninja(vie,chakra,nom,20,pointDefense,20)
{

}

Defenseur::Defenseur(int vie, int chakra) :
Ninja(vie,chakra){

  srand (time(NULL));
  _pointAtk = rand() % 20 + 5;
  _pointDef = 30;
  _pointSoin = 10;
}

Defenseur::Defenseur() : Ninja(150,100,"Naruto"){

  srand (time(NULL));
  _pointAtk = rand() % 20 + 5;
  _pointDef = rand() % 30 + 20;
  _pointSoin = rand() % 10 + 10;
}

Defenseur::Defenseur(std::string nom) : Ninja(100,100,nom){

  srand (time(NULL));
  _pointAtk = rand() % 20 + 5;
  _pointDef = rand() % 30 + 20;
  _pointSoin = rand() % 10 + 10;
}

void Defenseur::technique(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4){
  std::cout<< this->_nom <<" augmente la defense de " << Defenseur::_pointDef << " def "<< v1.getNom()<<std::endl;
  std::cout<< this->_nom <<" augmente la defense de " << Defenseur::_pointDef << " def "<< v2.getNom()<<std::endl;
  std::cout<< this->_nom <<" augmente la defense de " << Defenseur::_pointDef << " def "<< v3.getNom()<<std::endl;
  std::cout<< this->_nom <<" augmente la defense de " << Defenseur::_pointDef << " def "<< v4.getNom()<<std::endl;
  this->augmDef(v1, this->_pointDef);
  this->augmDef(v2, this->_pointDef);
  this->augmDef(v3, this->_pointDef);
  this->augmDef(v4, this->_pointDef);
  this->_chakra -= 40;
}

void Defenseur::techniqueSpecial(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4){
  if(this->compteurAtkSpe == 0){
    std::cout<< "Ce ninja ne peut plus faire de technique special"<<std::endl;
    return;
  }
  std::cout<< this->_nom <<" defense special de " << this->_pointDef*2 <<" def "<< v1.getNom()<<std::endl;
  std::cout<< this->_nom <<" defense special de " << this->_pointDef*2 <<" def "<< v2.getNom()<<std::endl;
  std::cout<< this->_nom <<" defense special de " << this->_pointDef*2 <<" def "<< v3.getNom()<<std::endl;
  std::cout<< this->_nom <<" defense special de " << this->_pointDef*2 <<" def "<< v4.getNom()<<std::endl;
  this->augmDef(v1, this->_pointDef*2);
  this->augmDef(v2, this->_pointDef*2);
  this->augmDef(v3, this->_pointDef*2);
  this->augmDef(v4, this->_pointDef*2);
  this->_chakra -= 80;
  --this->compteurAtkSpe;
}

void Defenseur::rechargeChakra(){
  std::cout<< this->_nom <<" recharge son chakra de 30 "<<std::endl;
  if(this->_chakra > 100) this->_chakra = 100;
  this->_chakra += 30;
}
