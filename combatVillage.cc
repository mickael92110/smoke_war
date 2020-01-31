#include"combatVillage.hh"
#include <stdlib.h>
#include <time.h>

int CombatVillage::tour = 0;

CombatVillage::CombatVillage(Village &v1, Village &v2) : _v1(&v1), _v2(&v2){}


std::string CombatVillage::toString(){

  std::string buff = "";

  buff += "### Village de " + _v1->getNom() + " ###\n";
  for(size_t i = 0; i < this->_v1->getSize(); i++) {
    buff += _v1->getNinja(i)->toString();
  }

  buff += "### Village de " + _v2->getNom() + " ###\n";

  for(size_t i = 0; i < this->_v2->getSize(); i++) {
    buff += _v2->getNinja(i)->toString();
  }


  return buff;
}

void CombatVillage::actionVillage(Village*v1, Village*v2){
  int joueur1 = 0;
  int action = 0;
  int joueur2 = 0;
  std::string buff = "";

  buff += "\n### Tour de  " + v1->getNom() + " de jouer ###";
  std::cout<< buff <<std::endl;
  buff = "Choisir un joueur entre 0 et 2\n";
  std::cout<< buff <<std::endl;
  std::cin>>joueur1;
  buff = "\nChoisir une action :\n1)attaque\n2)soin\n3)defense\n";
  std::cout<< buff <<std::endl;
  std::cin>>action;

  if(action == 1)
  {
    buff = "Choisir un joueur de l'equipe adverse entre 0 et 2\n";
    std::cout<< buff <<std::endl;
    std::cin>>joueur2;
  }
  else
  {
    buff = "Choisir un joueur de votre equipe entre 0 et 2\n";
    std::cout<< buff <<std::endl;
    std::cin>>joueur2;
  }

  if(action == 1){
    v1->getNinja(joueur1)->attaque(*(v2->getNinja(joueur2)));
  }

  if(action == 2){
    v1->getNinja(joueur1)->soin(*(v1->getNinja(joueur2)));
  }

  if(action == 3){
    v1->getNinja(joueur1)->defense(*(v1->getNinja(joueur2)));
  }
}

void CombatVillage::combat(){
  std::cout<<this->toString()<<std::endl;
  do{
  if(tour%2 == 0)
  {
    actionVillage(_v1,_v2);
  }
  else{
    actionVillage(_v2,_v1);
  }
  ++tour;
  std::cout<<this->toString()<<std::endl;

  }while(_v1->isDead() || _v2->isDead());
}
