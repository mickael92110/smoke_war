#include "ninja.hh"

int Ninja::_cpt = 0;



Ninja::Ninja(int vie, int chakra, std::string nom) : _vie(vie), _chakra(chakra), _nom(nom), _id(++_cpt){
  srand (time(NULL));
  compteur = rand() % 4 + 2;
}

Ninja::Ninja(int vie, int chakra) : _vie(vie), _chakra(chakra), _nom("defaut"), _id(++_cpt) {
  srand (time(NULL));
  compteur = rand() % 4 + 2;
}

void Ninja::toString(){
  std::cout << std::endl;
  std::cout <<"nom : "<< this->_nom << std::endl;
  std::cout <<"vie : "<< this->_vie << std::endl;
  std::cout <<"chakra : "<< this->_chakra << std::endl;
  std::cout <<"id : "<< this->_id << std::endl;
  std::cout <<"cptAtckSpé : "<< this->compteur << std::endl;
  std::cout << std::endl;
}
