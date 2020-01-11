#ifndef NINJA_H
#define NINJA_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Ninja{

public:

  //Constructeur
  Ninja(int vie, int chakra, std::string nom, int atk, int def, int soin);
  Ninja(int vie, int chakra, std::string nom);
  Ninja(int vie, int chakra) ;
  Ninja(){}

  // Fonctions
  virtual void technique(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4) = 0;
  virtual void techniqueSpecial(Ninja &v1, Ninja &v2, Ninja &v3, Ninja &v4) = 0;
  virtual void rechargeChakra() = 0;
  virtual void defense(Ninja &v1);
  virtual void soin(Ninja &v1);
  virtual void attaque(Ninja &v1);

  //Fonction gestion
  int getVie(){return _vie;}
  int getChakra(){return _chakra;}
  int getPointAtk(){return _pointAtk;}
  int getPointDef(){return _pointDef;}
  int getPointSoin(){return _pointSoin;}
  std::string getNom(){return _nom;}
  void setVie(int vie){_vie = vie;}
  void setChakra(int chakra){_chakra = chakra;}
  void setNom(std::string nom){_nom = nom;}
  void setAtk(int atk){_pointAtk = atk;}
  void setDef(int def){_pointDef = def;}
  void setSoin(int soin){_pointSoin = soin;}
  std::string toString();

  //Fonction jeu
  void augmVie(Ninja &v,int vie);
  void reducVie(Ninja &v,int atk);
  void augmDef(Ninja &v,int def);
  void reducDef(Ninja &v, int def);



protected:

  //attributs
  int _vie;
  int _chakra;
  std::string _nom;
  int _id;
  static int _cpt;
  int _pointAtk;
  int _pointDef;
  int _pointSoin;
  int compteurAtkSpe;
};


#endif
