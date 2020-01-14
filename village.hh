#ifndef VILLAGE_H
#define VILLAGE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "ninja.hh"

class Village{

public:

  //Constructeur
  Village(std::vector <Ninja*> listeNinja,std::string s);
  Village(std::string s);
  Village() : _capaciteAtk(0),_capaciteDef(0),_capaciteSoin(0),_nomVillage("Village cache"){}

  // Fonctions
  void capaciteVillage();
  void addNinja(Ninja &n);
  void popNinja(Ninja &n);
  int getCapaciteAtk(){return _capaciteAtk;}
  int getCapaciteDef(){return _capaciteDef;}
  int getCapaciteSoin(){return _capaciteSoin;}
  Ninja* getNinja(int i){return _listeNinja[i];}
  std::string toString();
  std::vector <Ninja*> getListeNinja() {return _listeNinja;}
  bool faitPartiDuVillage(std::string s);

private :
  //void updateCapacitePoint();
protected:

  //attributs
  std::vector <Ninja*> _listeNinja;
  int _capaciteAtk;
  int _capaciteDef;
  int _capaciteSoin;
  std::string _nomVillage;

};


#endif
