#include"konoha.hh"

Konoha::Konoha():Village("Konoha"){

}

Konoha::Konoha(Village& v){
  this->_capaciteAtk = v.getCapaciteAtk();
  this->_capaciteDef = v.getCapaciteDef();
  this->_capaciteSoin = v.getCapaciteSoin();
  this->_nomVillage = "Konoha";
  this->_listeNinja = v.getListeNinja();
}

void Konoha::capaciteVillage()
{
  int vie;
  for(auto it = this->_listeNinja.begin(); it!= this->_listeNinja.end(); ++it)
  {
    //std::cout<< (*it)->getNom() << std::endl;
    vie = (*it)->getVie();
    vie += 20;
    (*it)->setVie(vie);
  }
}
