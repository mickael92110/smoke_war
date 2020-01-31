#ifndef COMBATVILLAGE_H
#define COMBATVILLAGE_H

#include "village.hh"

class CombatVillage{
public:
  CombatVillage(Village &v1, Village &v2);

  std::string toString();
  void combat();
  void actionVillage(Village*v1, Village*v2);

private:
  static int tour;
  Village * _v1;
  Village * _v2;
};



#endif
