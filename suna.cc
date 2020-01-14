#include"suna.hh"

Suna::Suna():Village("Suna"){

}

Suna::Suna(Village& v){
  this->_capaciteAtk = v.getCapaciteAtk();
  this->_capaciteDef = v.getCapaciteDef();
  this->_capaciteSoin = v.getCapaciteSoin();
  this->_nomVillage = "Suna";
  this->_listeNinja = v.getListeNinja();
}

void Suna::capaciteVillage()
{
  int chakra;
  for(auto it = this->_listeNinja.begin(); it!= this->_listeNinja.end(); ++it)
  {
    //std::cout<< (*it)->getNom() << std::endl;
    chakra = (*it)->getChakra();
    chakra += 20;
    (*it)->setChakra(chakra);
  }
}
