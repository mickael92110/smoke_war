#include"kumo.hh"

Kumo::Kumo():Village("Kumo"){

}

void Kumo::capaciteVillage()
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
