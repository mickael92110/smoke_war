#include "defenseur.hh"

Defenseur::Defenseur(int vie, int chakra, std::string nom, int pointAttaque, int pointDefense) : Attaquant(vie,chakra,nom,pointAttaque){
   _pointDefense = pointDefense;
}
  Defenseur::Defenseur(int vie, int chakra) : Attaquant(vie,chakra){
    srand (time(NULL));
    _pointDefense = rand() % 15 + 5;
  }

Defenseur::Defenseur() : Attaquant(){
  srand (time(NULL));
  _pointDefense = rand() % 15 + 5;
}

void Defenseur::technique(Ninja &v){

  std::cout<< this->_nom <<" attaque de " << Attaquant::_pointAttaque << " pv "<< v.getNom()<<" et regagne " << _pointDefense << " points de vie"<<std::endl;
  int vie_v;
  vie_v = v.getVie();
  vie_v -= _pointAttaque;
  if (vie_v < 0) v.setVie(0);
  else v.setVie(vie_v);
  this->setVie(this->getVie() + _pointDefense);
  this->_chakra -= 20;
}
