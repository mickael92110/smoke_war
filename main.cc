#include "attaquant.hh"
#include "soigneur.hh"
#include "defenseur.hh"
#include "ninja.hh"
#include "kageAtk.hh"
#include "kageDef.hh"
#include "kageSoin.hh"
#include "village.hh"
#include "konoha.hh"
#include "Fenetre.hh"


int main(int argc, char *argv[]){
  // Attaquant sasuke;
  // Defenseur naruto;
  // Soigneur sakura;
  // KageAtk Minato;
  // KageDef Gaara;
  // KageSoin Tsunade;
  //
  // std::vector<Ninja*> listeNinja;
  // sasuke.toString();
  //
  // Konoha konoha;
  //
  // konoha.addNinja(sasuke);
  // konoha.addNinja(naruto);
  // konoha.addNinja(sakura);
  // konoha.addNinja(Minato);
  // konoha.addNinja(Gaara);
  // konoha.addNinja(Tsunade);
  //
  // konoha.capaciteVillage();
  //
  // sasuke.toString();
  // sasuke.techniqueSpecial(naruto,sakura,Minato,Gaara);
  //
  // Gaara.toString();
  // std::cout<<konoha.toString()<<std::endl;

  Gtk::Main app(argc, argv);
  Fenetre fenetre;
  Gtk::Main::run(fenetre);





  return 0;
}
