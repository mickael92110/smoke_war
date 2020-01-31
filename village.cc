#include "village.hh"

Village::Village(std::vector <Ninja*> listeNinja, std::string s) :
_listeNinja(listeNinja),_capaciteAtk(0),_capaciteDef(0),_capaciteSoin(0),_nomVillage(s)
{

}

Village::Village(std::string s) :
_capaciteAtk(0),_capaciteDef(0),_capaciteSoin(0),_nomVillage(s)
{

}

void Village::addNinja(Ninja &n){
  (this->_listeNinja).push_back(&n);
  this->_capaciteAtk += n.getPointAtk();
  this->_capaciteDef += n.getPointDef();
  this->_capaciteSoin += n.getPointSoin();
}

void Village::popNinja(Ninja &n){
  (this->_listeNinja).push_back(&n);
  this->_capaciteAtk -= n.getPointAtk();
  this->_capaciteDef -= n.getPointDef();
  this->_capaciteSoin -= n.getPointSoin();
}


std::string Village::toString(){
  std::string listeNom;
  listeNom+="########################\n";

  listeNom += "Nom village : " + this->_nomVillage + "\n\n";

  listeNom+="--Liste Ninja--\n\n";
  for(auto it = this->_listeNinja.begin(); it!= this->_listeNinja.end(); ++it)
  {
    listeNom +=  (*it)->getNom();
    listeNom += "\n";
  }
  listeNom += "\n--Total capacite village--\n\n";
  listeNom += "Capacite Atk " + std::to_string(_capaciteAtk) + "\n";
  listeNom += "Capacite Def " + std::to_string(_capaciteDef) + "\n";
  listeNom += "Capacite Soin " + std::to_string(_capaciteSoin) + "\n";
  listeNom+="########################";
  return listeNom;
}

bool Village::isDead(){
  for(size_t i = 0; i < this->_listeNinja.size(); i++) {
    if ( this->_listeNinja[i]->getVie() > 0) {
      return true;
    }
  }
  return false;
}

bool Village::faitPartiDuVillage(std::string n) {
  for(size_t i = 0; i < this->_listeNinja.size(); i++) {
    if (n == this->_listeNinja[i]->getNom()) {
      return true;
    }
  }
  return false;
}

bool Village::operator==( std::string ninja){
  return this->faitPartiDuVillage(ninja);
}

bool Village::isEmpty(){
  return _listeNinja.empty();
}
