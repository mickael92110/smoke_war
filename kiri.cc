#include"kiri.hh"

Kiri::Kiri():Village("Kiri"){

}

Kiri::Kiri(Village& v){
  this->_capaciteAtk = v.getCapaciteAtk();
  this->_capaciteDef = v.getCapaciteDef();
  this->_capaciteSoin = v.getCapaciteSoin();
  this->_nomVillage = "Kiri";
  this->_listeNinja = v.getListeNinja();
}

void Kiri::capaciteVillage()
{
  int def;
  for(auto it = this->_listeNinja.begin(); it!= this->_listeNinja.end(); ++it)
  {
    //std::cout<< (*it)->getNom() << std::endl;
    def = (*it)->getPointDef();
    def += 20;
    (*it)->setDef(def);
  }
}
