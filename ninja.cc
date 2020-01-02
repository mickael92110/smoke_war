#include "ninja.hh"

int Ninja::_cpt = 0;

void Ninja::toString(){
  std::cout << std::endl;
  std::cout <<"nom : "<< this->_nom << std::endl;
  std::cout <<"vie : "<< this->_vie << std::endl;
  std::cout <<"chakra : "<< this->_chakra << std::endl;
  std::cout <<"id : "<< this->_id << std::endl;
  std::cout << std::endl;
}
