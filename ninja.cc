#include "ninja.hh"

int Ninja::_cpt = 0;


Ninja::Ninja(int vie, int chakra, std::string nom, int atk, int def, int soin) : _vie(vie), _chakra(chakra), _nom(nom), _id(++_cpt),
                                                    _pointAtk(atk), _pointDef(def), _pointSoin(soin){
  srand (time(NULL));
  compteurAtkSpe = rand() % 4 + 2;
}

Ninja::Ninja(int vie, int chakra) : _vie(vie), _chakra(chakra), _nom("defaut"), _id(++_cpt), _pointAtk(10), _pointDef(10), _pointSoin(10) {
  srand (time(NULL));
  compteurAtkSpe = rand() % 4 + 2;
}

Ninja::Ninja(int vie, int chakra, std::string nom) :  _vie(vie), _chakra(chakra), _nom(nom), _id(++_cpt), _pointAtk(0), _pointDef(0), _pointSoin(0){
  srand (time(NULL));
  compteurAtkSpe = rand() % 4 + 2;
}

void Ninja::toString(){
  std::cout << std::endl;
  std::cout <<"nom : "<< this->_nom << std::endl;
  std::cout <<"vie : "<< this->_vie << std::endl;
  std::cout <<"chakra : "<< this->_chakra << std::endl;
  std::cout <<"id : "<< this->_id << std::endl;
  std::cout <<"cptAtckSpé : "<< this->compteurAtkSpe << std::endl;
  std::cout <<"pointAtk : "<< this->_pointAtk << std::endl;
  std::cout <<"pointDef : "<< this->_pointDef << std::endl;
  std::cout <<"pointSoin : "<< this->_pointSoin << std::endl;
  std::cout << std::endl;
}

void Ninja::augmVie(Ninja &v, int vie){
  int vie_v = v.getVie();
  vie_v += vie ;
  if (vie_v > 100) v.setVie(100);
  else{
    v.setVie(vie_v);
  }
}

//Cette fonction reduit la vie en prenant en compte les points de defense
void Ninja::reducVie(Ninja &v, int atk){
  int vie_v = v.getVie();
  int degatReel = (v.getPointDef()*atk)/100;
  vie_v -= atk - degatReel ;
  if (vie_v < 0) v.setVie(0);
  else{
    std::cout << v.getNom() << " a perdu "<< atk-degatReel <<" pv\n";
    v.setVie(vie_v);
  }
}

void Ninja::augmDef(Ninja &v,int def){
  int def_v = v.getPointDef();
  def_v += def;
  if (def_v > 90) v.setDef(90);
  else{
    v.setDef(def_v);
  }
}


void Ninja::reducDef(Ninja &v,int def){
  int def_v = v.getPointDef();
  def_v -= def;
  if (def_v < 0) v.setDef(0);
  else{
    v.setDef(def_v);
  }
}

//Les points de defense sont utilise dans la fonction reducVie pour attenuer l'attaque inflige par l'adversaire
void Ninja::defense(Ninja &v1){
  std::cout<< this->_nom <<" defend "<< v1.getNom()<< std::endl;
  int def = v1.getPointDef();
  v1.setDef(def + this->_pointDef);  //On peut pourra modifier l'operateur () pour eviter de faire get puis set
}

void Ninja::soin(Ninja &v1){
  std::cout<< this->_nom <<" soigne "<<v1.getNom()<< std::endl;
  int vie = v1.getVie();
  v1.setVie(vie + this->_pointSoin);
}

void Ninja::attaque(Ninja &v1){
  std::cout<< this->_nom <<" attaque "<<v1.getNom()<< std::endl;
  this->reducVie(v1, this->_pointAtk);
}
