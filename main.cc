#include "attaquant.hh"
#include "soigneur.hh"
#include "defenseur.hh"
#include "ninja.hh"



int main(void){
  Attaquant sasuke;
  sasuke.toString();
  Soigneur sakura;
  sakura.toString();
  Defenseur naruto;
  naruto.toString();
  sasuke.technique(sakura);
  naruto.technique(sasuke);
  // naruto.technique(sasuke);
  // naruto.techniqueSpecial(sasuke);
  // naruto.rechargeChakra();
  // naruto.toString();
  // sasuke.toString();


  return 0;
}
