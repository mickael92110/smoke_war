#include"suna.hh"

Suna::Suna():Village("Suna"){

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
