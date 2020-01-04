#include"konoha.hh"

Konoha::Konoha():Village("Konoha"){
  
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
