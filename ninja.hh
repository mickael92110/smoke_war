#ifndef NINJA_H
#define NINJA_H

#include <iostream>
#include <string>

class Ninja{

public:

  //Constructeur
  Ninja(int vie, int chakra, std::string nom) : _vie(vie), _chakra(chakra), _nom(nom), _id(++_cpt){}
  Ninja(int vie, int chakra) : _vie(vie), _chakra(chakra), _nom("defaut"), _id(++_cpt) {}
  Ninja(){}

  // Fonctions
  virtual void technique(Ninja &v) = 0;
  virtual void techniqueSpecial(Ninja &v) = 0;
  virtual void rechargeChakra() = 0;
  // virtual void defense() = 0;
  // virtual void soin() = 0;
  // virtual void attaque() = 0;

  //Fonction
  int getVie(){return _vie;}
  int getChakra(){return _chakra;}
  std::string getNom(){return _nom;}
  void setVie(int vie){_vie = vie;}
  void setChakra(int chakra){_chakra = chakra;}
  void setNom(std::string nom){_nom = nom;}
  void toString();


protected:

  //attributs
  int _vie;
  int _chakra;
  std::string _nom;
  int _id;
  static int _cpt;



};


#endif
