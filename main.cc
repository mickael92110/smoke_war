#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "village.hh"
#include "konoha.hh"
#include "suna.hh"
#include "kiri.hh"
#include "attaquant.hh"
#include "defenseur.hh"
#include "soigneur.hh"
#include "kageAtk.hh"
#include "kageDef.hh"
#include "kageSoin.hh"

using namespace sf;

//Variables Globales
sf::RenderWindow window;
sf::Image icon;
sf::Music music;
sf::Vector2i positionSouris;
//Menu
sf::Texture menu, jouer;
sf::Sprite sprite_menu, sprite_jouer;
//Choix
sf::Texture choix,village1,village2,village3, valider;
sf::Texture t_naruto,t_sasuke, t_sakura, t_minato, t_tsunade;
sf::Texture t_gaara,t_temari, t_kankuro, t_shiyo, t_sasori;
sf::Texture t_haku,t_zabuza, t_kisame, t_hinata, t_shikamaru;
sf::Sprite sprite_choix, sprite_valider;
sf::RectangleShape vil1, vil2,vil3;
sf::RectangleShape sasuke,sakura,naruto,minato,tsunade;
sf::RectangleShape gaara,temari,kankuro,shiyo,sasori;
sf::RectangleShape haku,zabuza,kisame,hinata,shikamaru;

//texte
sf::Font font;
sf::Text text1,text2,text3,text4,text5,text6,text7,text8,text9,text10,text11,text12,text13,text14,text15;
sf::Text text_konoha,text_suna,text_kiri, consigne1, consigne2;

//Selection pour Afficher
int affiche_menu, affiche_choix, affichePersoKonoha, affichePersoSuna, affichePersoKiri,affiche_MessageJ2Choix,affiche_MessageJ1Choix;
int affiche_text;
std::string buffer;
int konohaSel,sunaSel,kiriSel;

//Creation objet
Konoha konoha;
Defenseur o_naruto("Naruto");
Soigneur o_tsunade("Tsunade");
Attaquant o_sasuke("Sasuke");
Soigneur o_sakura("Sakura");
KageAtk o_minato("Minato");

Suna suna;
KageDef o_gaara("Gaara");
Defenseur o_temari("Temari");
Attaquant o_kankuro("Kankuro");
Soigneur o_shiyo("Shiyo");
Attaquant o_sasori("Sasori");

Kiri kiri;
Defenseur o_haku("Haku");
Attaquant o_zabuza("Zabuza");
Attaquant o_kisame("Kisame");
Soigneur o_hinata("Hinata");
Defenseur o_shikamaru("Shikamaru");

//Joueur 1
int nbPersoJ1 = 0;
Village villageJ1;
Konoha konohaJ1;
Suna sunaJ1;
Kiri kiriJ1;

void initVillage(){
  konoha.addNinja(o_naruto);
  konoha.addNinja(o_tsunade);
  konoha.addNinja(o_sasuke);
  konoha.addNinja(o_sakura);
  konoha.addNinja(o_minato);

  suna.addNinja(o_gaara);
  suna.addNinja(o_temari);
  suna.addNinja(o_kankuro);
  suna.addNinja(o_shiyo);
  suna.addNinja(o_sasori);

  kiri.addNinja(o_haku);
  kiri.addNinja(o_zabuza);
  kiri.addNinja(o_kisame);
  kiri.addNinja(o_hinata);
  kiri.addNinja(o_shikamaru);

}
int CreationMenu() {
  // Load a sprite to display
  affiche_menu = 1;
  if (!menu.loadFromFile("Image/menu.png"))
      return EXIT_FAILURE;
  sprite_menu = Sprite(menu);

  if (!jouer.loadFromFile("Image/jouerC.png", sf::IntRect(0,0,352,119)))
      return EXIT_FAILURE;
  jouer.setSmooth(true);
  sprite_jouer = Sprite(jouer);
  sprite_jouer.setPosition(420,500);
  sprite_jouer.setScale(1.5,1.5);

  return 0;
}

void toStringNinjaSpecKonoha(Village & v, int x, int y){
  buffer = v.getNinja(0)->toString();
  text1.setString(buffer);
  text1.setPosition(x,y);

  buffer = v.getNinja(1)->toString();
  text2.setString(buffer);
  text2.setPosition(x,y+100);

  buffer = v.getNinja(2)->toString();
  text3.setString(buffer);
  text3.setPosition(x,y+200);

  buffer = v.getNinja(3)->toString();
  text4.setString(buffer);
  text4.setPosition(x,y+300);

  buffer = v.getNinja(4)->toString();
  text5.setString(buffer);
  text5.setPosition(x,y+400);
}
void toStringNinjaSpecSuna(Village & v, int x, int y){
  buffer = v.getNinja(0)->toString();
  text6.setString(buffer);
  text6.setPosition(x,y);

  buffer = v.getNinja(1)->toString();
  text7.setString(buffer);
  text7.setPosition(x,y+100);

  buffer = v.getNinja(2)->toString();
  text8.setString(buffer);
  text8.setPosition(x,y+200);

  buffer = v.getNinja(3)->toString();
  text9.setString(buffer);
  text9.setPosition(x,y+300);

  buffer = v.getNinja(4)->toString();
  text10.setString(buffer);
  text10.setPosition(x,y+400);
}
void toStringNinjaSpecKiri(Village & v, int x, int y){
  buffer = v.getNinja(0)->toString();
  text11.setString(buffer);
  text11.setPosition(x,y);

  buffer = v.getNinja(1)->toString();
  text12.setString(buffer);
  text12.setPosition(x,y+100);

  buffer = v.getNinja(2)->toString();
  text13.setString(buffer);
  text13.setPosition(x,y+200);

  buffer = v.getNinja(3)->toString();
  text14.setString(buffer);
  text14.setPosition(x,y+300);

  buffer = v.getNinja(4)->toString();
  text15.setString(buffer);
  text15.setPosition(x,y+400);
}

void AfficheIcon() {
  icon.loadFromFile("Image/icon.jpeg"); // File/Image/Pixel
  window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
int CreationVillage() {
  vil1 = RectangleShape(sf::Vector2f(120, 120));
  vil2 = RectangleShape(sf::Vector2f(120, 120));
  vil3 = RectangleShape(sf::Vector2f(120, 120));
  if (!village1.loadFromFile("Image/konoha.jpg") )
      return EXIT_FAILURE;
   village1.setSmooth(true);
   vil1.setTexture(&village1); // texture est un sf::Texture
   vil1.setOutlineColor(sf::Color(0, 0, 0));
   vil1.setOutlineThickness(5);
   vil1.setTextureRect(sf::IntRect(100, 10, 250, 250));
   vil1.setPosition(200,50);

   if (!village2.loadFromFile("Image/suna.jpg") )
       return EXIT_FAILURE;
    village2.setSmooth(true);
    vil2.setTexture(&village2); // texture est un sf::Texture
    vil2.setOutlineColor(sf::Color(0, 0, 0));
    vil2.setOutlineThickness(5);
    vil2.setTextureRect(sf::IntRect(100, 10, 250, 250));
    vil2.setPosition(600,50);

    if (!village3.loadFromFile("Image/kiri.jpg") )
        return EXIT_FAILURE;
     village3.setSmooth(true);
     vil3.setTexture(&village3); // texture est un sf::Texture
     vil3.setOutlineColor(sf::Color(0, 0, 0));
     vil3.setOutlineThickness(5);
     vil3.setTextureRect(sf::IntRect(100, 10, 250, 250));
     vil3.setPosition(1000,50);

   return 0;
}
int CreationChoix() {
  // Création background
  /*affiche_choix = 0;
  if (!choix.loadFromFile("Image/Choix.jpg"))
      return EXIT_FAILURE;
  sprite_choix = Sprite(choix);*/

  //Création icon village
  CreationVillage();
  return 0;
}
int Musique(){

  if (!music.openFromFile("naruto_theme.ogg"))
      return EXIT_FAILURE;
  // Play the music
  music.play();
  music.setLoop(true);

  return 0;
}
void Affichage(){
  // Clear screen
  window.clear();
  // Draw the sprite

  if (affiche_menu == 1) {
    window.draw(sprite_menu);
    window.draw(sprite_jouer);
  }
  if (affiche_MessageJ1Choix == 1) {

    window.draw(sprite_choix);
    window.draw(consigne1);
    window.draw(sprite_valider);

  }
  if (affiche_MessageJ2Choix == 1) {

    window.draw(sprite_choix);
    window.draw(consigne2);
    window.draw(sprite_valider);

  }
  if (affiche_choix == 1) {
        window.draw(sprite_choix);
        window.draw(vil1);
        window.draw(vil2);
        window.draw(vil3);
        window.draw(text_konoha);
        window.draw(text_suna);
        window.draw(text_kiri);
    if (affichePersoKonoha==1) {
        window.draw(sasuke);
        window.draw(naruto);
        window.draw(sakura);
        window.draw(minato);
        window.draw(tsunade);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
    }
    if (affichePersoSuna==1) {
        window.draw(gaara);
        window.draw(temari);
        window.draw(kankuro);
        window.draw(shiyo);
        window.draw(sasori);
        window.draw(text6);
        window.draw(text7);
        window.draw(text8);
        window.draw(text9);
        window.draw(text10);
    }
    if (affichePersoKiri==1) {
        window.draw(haku);
        window.draw(zabuza);
        window.draw(kisame);
        window.draw(hinata);
        window.draw(shikamaru);
        window.draw(text11);
        window.draw(text12);
        window.draw(text13);
        window.draw(text14);
        window.draw(text15);
  }


  }
  // Draw the string
  //window.draw(text);
  // Update the window
  //window.setPosition(Vector2i(350,150));
  window.setSize(sf::Vector2u(1312,700));
  window.display();
}
void gestionSouris() {
    positionSouris = sf::Mouse::getPosition(window);
    int mx = positionSouris.x;
    int my = positionSouris.y;
    //printf("Mx = %d et My = %d\n",mx,my );

  //Si la souris va sur bouton jouer
  if (affiche_menu == 1) {
    if((mx>=420) && (mx<900) && (my>=500) && (my<650)){
      sprite_jouer.setColor(sf::Color(0, 0, 0));
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        affiche_menu = 0;
        affiche_choix = 0;
        affiche_MessageJ1Choix = 1;
      }
    }
    else
      sprite_jouer.setColor(sf::Color(255, 0, 0));
  }

  if (affiche_MessageJ1Choix==1) {
    if((mx>=700) && (mx<1050) && (my>=400) && (my<520)){
      sprite_valider.setColor(sf::Color(255, 255, 255, 128));
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        affiche_MessageJ1Choix = 0;
        affiche_choix = 1;

      }
    }
    else
      sprite_valider.setColor(sf::Color(255, 255, 255));
  }

  //Si la souris va sur les villages
  if (affiche_choix == 1) {
    //va sur Konoha
    if (nbPersoJ1 == 0) {
      if(((mx>=200) && (mx<320) && (my>=50) && (my<170)) ){
        toStringNinjaSpecKonoha(konoha, 170, 170);
        vil1.setFillColor(sf::Color(255, 255, 255, 128));
        affichePersoKonoha = 1;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          konohaSel = 1;
          affichePersoSuna = 0;
          affichePersoKiri = 0;
          kiriSel = 0;
          sunaSel = 0;

        }
        }
        else{
        if (konohaSel != 1 ) {
          vil1.setFillColor(sf::Color(255, 255, 255));
          affichePersoKonoha = 0;
        }

      }
      //Va sur suna
      if(((mx>=600) && (mx<720) && (my>=50) && (my<170))){
          toStringNinjaSpecSuna(suna, 570, 170);
          vil2.setFillColor(sf::Color(255, 255, 255, 128));
          affichePersoSuna = 1;
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sunaSel = 1;
            konohaSel = 0;
            kiriSel = 0;
            affichePersoKonoha = 0;
            affichePersoKiri = 0;

          }
        }
        else {
          if (sunaSel != 1 ) {
            vil2.setFillColor(sf::Color(255, 255, 255));
            affichePersoSuna = 0;
          }
        }
      //Va sur kiri
      if(((mx>=1000) && (mx<1120) && (my>=50) && (my<170))){
              toStringNinjaSpecKiri(kiri, 970, 170);
              vil3.setFillColor(sf::Color(255, 255, 255, 128));
              affichePersoKiri = 1;
              if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sunaSel =0;
                konohaSel = 0;
                kiriSel = 1;
                affichePersoSuna = 0;
                affichePersoKonoha = 0;

              }
            }
        else {
              if (kiriSel != 1 ) {
                vil3.setFillColor(sf::Color(255, 255, 255));
                affichePersoKiri = 0;
              }
            }
    }


  }

  if (konohaSel==1){
    if (nbPersoJ1 == 3) {
      konohaJ1 = villageJ1;
      affiche_MessageJ2Choix=1;
      affiche_choix = 0;
      sprite_valider.setColor(sf::Color(255, 255, 255));
    }
    //va sur naruto
    if((mx>=80) && (mx<160) && (my>=200) && (my<280)) {
      naruto.setFillColor(sf::Color(255, 255, 255, 128));

      if (nbPersoJ1 < 3) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          if (!(villageJ1=="Naruto")){
            nbPersoJ1++;
            villageJ1.addNinja(o_naruto);
          }
        }
      }

      }
      else {

        if (!(villageJ1=="Naruto")) {
          naruto.setFillColor(sf::Color(255, 255, 255));
        }
      }
    if((mx>=80) && (mx<160) && (my>=300) && (my<380)) {
      tsunade.setFillColor(sf::Color(255, 255, 255, 128));
        if (nbPersoJ1 < 3) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (!(villageJ1=="Tsunade") )  {
              nbPersoJ1++;
              villageJ1.addNinja(o_tsunade);
            }

          }
        }
      }
      else {
        if (!(villageJ1==("Tsunade"))) {
          tsunade.setFillColor(sf::Color(255, 255, 255));
        }

      }
    if((mx>=80) && (mx<160) && (my>=400) && (my<480)) {
      sasuke.setFillColor(sf::Color(255, 255, 255, 128));
      if (nbPersoJ1 < 3) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          if (!(villageJ1==("Sasuke")))  {
            nbPersoJ1++;
            villageJ1.addNinja(o_sasuke);
          }

        }
      }
      }
      else {
      if (!(villageJ1==("Sasuke"))) {
        sasuke.setFillColor(sf::Color(255, 255, 255));
      }

    }
    if((mx>=80) && (mx<160) && (my>=500) && (my<580)) {
      sakura.setFillColor(sf::Color(255, 255, 255, 128));
      if (nbPersoJ1 < 3) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          if (!(villageJ1==("Sakura")) )  {
            nbPersoJ1++;
            villageJ1.addNinja(o_sakura);
          }

        }
      }
      }
      else {
      if (!(villageJ1==("Sakura"))) {
        sakura.setFillColor(sf::Color(255, 255, 255));
      }

    }
    if((mx>=80) && (mx<160) && (my>=600) && (my<680)) {
      minato.setFillColor(sf::Color(255, 255, 255, 128));
      if (nbPersoJ1 < 3) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          if (!(villageJ1==("Minato")) )  {
            nbPersoJ1++;
            villageJ1.addNinja(o_minato);
          }

        }
      }
      }
      else {
      if (!(villageJ1==("Minato"))) {
        minato.setFillColor(sf::Color(255, 255, 255));
      }

      }
    }

  if (sunaSel==1) {

    //va sur gaara
    if (nbPersoJ1 == 3) {
      sunaJ1 = villageJ1;
      affiche_MessageJ2Choix=1;
      affiche_choix = 0;
      sprite_valider.setColor(sf::Color(255, 255, 255));
    }

    if((mx>=480) && (mx<560) && (my>=200) && (my<280)) {
        gaara.setFillColor(sf::Color(255, 255, 255, 128));
        if (nbPersoJ1 < 3) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (!(villageJ1==("Gaara")) )  {
              nbPersoJ1++;
              villageJ1.addNinja(o_gaara);
            }

          }
        }
        }
        else {
            if (!(villageJ1==("Gaara"))) {
              gaara.setFillColor(sf::Color(255, 255, 255));
            }
        }
    if((mx>=480) && (mx<560) && (my>=300) && (my<380)) {
        temari.setFillColor(sf::Color(255, 255, 255, 128));
          if (nbPersoJ1 < 3) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              if (!(villageJ1==("Temari")) )  {
                nbPersoJ1++;
                villageJ1.addNinja(o_temari);
              }

            }
          }
          }
          else {
          if (!(villageJ1==("Temari"))) {
            temari.setFillColor(sf::Color(255, 255, 255));
          }

          }
    if((mx>=480) && (mx<560) && (my>=400) && (my<480)) {
          kankuro.setFillColor(sf::Color(255, 255, 255, 128));
            if (nbPersoJ1 < 3) {
              if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (!(villageJ1==("Kankuro")) )  {
                  nbPersoJ1++;
                  villageJ1.addNinja(o_kankuro);
                }

              }
            }
            }
            else {
            if (!(villageJ1==("Kankuro"))) {
              kankuro.setFillColor(sf::Color(255, 255, 255));
            }

            }
    if((mx>=480) && (mx<560) && (my>=500) && (my<580)) {
            shiyo.setFillColor(sf::Color(255, 255, 255, 128));
              if (nbPersoJ1 < 3) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                  if (!(villageJ1==("Shiyo")) )  {
                    nbPersoJ1++;
                    villageJ1.addNinja(o_shiyo);
                  }

                }
              }
              }
              else {
              if (!(villageJ1==("Shiyo"))) {
                shiyo.setFillColor(sf::Color(255, 255, 255));
              }

              }
    if((mx>=480) && (mx<560) && (my>=600) && (my<680)) {
              sasori.setFillColor(sf::Color(255, 255, 255, 128));
                if (nbPersoJ1 < 3) {
                  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (!(villageJ1==("Sasori")) )  {
                      nbPersoJ1++;
                      villageJ1.addNinja(o_sasori);
                    }

                  }
                }
                }
                else {
                if (!(villageJ1==("Sasori"))) {
                  sasori.setFillColor(sf::Color(255, 255, 255));
                }

              }
            }

  if (kiriSel==1) {


    if (nbPersoJ1 == 3) {
      kiriJ1 = villageJ1;
      affiche_MessageJ2Choix=1;
      affiche_choix = 0;
      sprite_valider.setColor(sf::Color(255, 255, 255));
    }

    if((mx>=880) && (mx<960) && (my>=200) && (my<280)) {
      haku.setFillColor(sf::Color(255, 255, 255, 128));
      if (nbPersoJ1 < 3) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          if (!(villageJ1==("Haku")) )  {
            nbPersoJ1++;
            villageJ1.addNinja(o_haku);
          }

        }
      }
      }
      else {
          if (!(villageJ1==("Haku"))) {
            haku.setFillColor(sf::Color(255, 255, 255));
          }
      }
    if((mx>=880) && (mx<960) && (my>=300) && (my<380)) {
        zabuza.setFillColor(sf::Color(255, 255, 255, 128));
        if (nbPersoJ1 < 3) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (!(villageJ1==("Zabuza")) )  {
              nbPersoJ1++;
              villageJ1.addNinja(o_zabuza);
            }

          }
        }
        }
        else {
            if (!(villageJ1==("Zabuza"))) {
              zabuza.setFillColor(sf::Color(255, 255, 255));
            }
        }
    if((mx>=880) && (mx<960) && (my>=400) && (my<480)) {
          kisame.setFillColor(sf::Color(255, 255, 255, 128));
          if (nbPersoJ1 < 3) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              if (!(villageJ1==("Kisame")) )  {
                nbPersoJ1++;
                villageJ1.addNinja(o_kisame);
              }

            }
          }
          }
          else {
              if (!(villageJ1==("Kisame"))) {
                kisame.setFillColor(sf::Color(255, 255, 255));
              }
          }
    if((mx>=880) && (mx<960) && (my>=500) && (my<580)) {
            hinata.setFillColor(sf::Color(255, 255, 255, 128));
            if (nbPersoJ1 < 3) {
              if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (!(villageJ1==("Hinata")) )  {
                  nbPersoJ1++;
                  villageJ1.addNinja(o_hinata);
                }

              }
            }
            }
            else {
                if (!(villageJ1==("Hinata"))) {
                  hinata.setFillColor(sf::Color(255, 255, 255));
                }
            }
    if((mx>=880) && (mx<960) && (my>=600) && (my<680)) {
              shikamaru.setFillColor(sf::Color(255, 255, 255, 128));
              if (nbPersoJ1 < 3) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                  if (!(villageJ1==("Shikamaru")) )  {
                    nbPersoJ1++;
                    villageJ1.addNinja(o_shikamaru);
                  }

                }
              }
              }
              else {
                  if (!(villageJ1==("Shikamaru"))) {
                    shikamaru.setFillColor(sf::Color(255, 255, 255));
                  }
              }

          }


}
int CreationPersoSuna() {

  gaara = RectangleShape(sf::Vector2f(80, 80));
  temari = RectangleShape(sf::Vector2f(80, 80));
  kankuro = RectangleShape(sf::Vector2f(80, 80));
  shiyo = RectangleShape(sf::Vector2f(80, 80));
  sasori = RectangleShape(sf::Vector2f(80, 80));

  if (!t_gaara.loadFromFile("Image/gaara.jpg") )
      return EXIT_FAILURE;
   //t_naruto.setSmooth(true);
   gaara.setTexture(&t_gaara); // texture est un sf::Texture
   gaara.setTextureRect(sf::IntRect(0, 0, 788, 788));
   gaara.setPosition(480,200);

   if (!t_temari.loadFromFile("Image/temari.jpg") )
       return EXIT_FAILURE;
    //t_naruto.setSmooth(true);
    temari.setTexture(&t_temari); // texture est un sf::Texture
    temari.setTextureRect(sf::IntRect(40, 0, 300, 300));
    temari.setPosition(480,300);

    if (!t_kankuro.loadFromFile("Image/kankuro.jpg") )
        return EXIT_FAILURE;
     //t_naruto.setSmooth(true);
     kankuro.setTexture(&t_kankuro); // texture est un sf::Texture
     kankuro.setTextureRect(sf::IntRect(50, 0, 384, 384));
     kankuro.setPosition(480,400);

     if (!t_shiyo.loadFromFile("Image/shiyo.jpg") )
         return EXIT_FAILURE;
      //t_naruto.setSmooth(true);
      shiyo.setTexture(&t_shiyo); // texture est un sf::Texture
      shiyo.setTextureRect(sf::IntRect(0, 0, 250, 250));
      shiyo.setPosition(480,500);

      if (!t_sasori.loadFromFile("Image/sasori.jpg") )
          return EXIT_FAILURE;
       //t_naruto.setSmooth(true);
       sasori.setTexture(&t_sasori); // texture est un sf::Texture
       sasori.setTextureRect(sf::IntRect(0, 0, 1024, 1024));
       sasori.setPosition(480,600);

   return 0;
}
int CreationPersoKiri() {

  haku = RectangleShape(sf::Vector2f(80, 80));
  zabuza = RectangleShape(sf::Vector2f(80, 80));
  kisame = RectangleShape(sf::Vector2f(80, 80));
  hinata = RectangleShape(sf::Vector2f(80, 80));
  shikamaru = RectangleShape(sf::Vector2f(80, 80));

  if (!t_haku.loadFromFile("Image/haku.png") )
      return EXIT_FAILURE;
   //t_naruto.setSmooth(true);
   haku.setTexture(&t_haku); // texture est un sf::Texture
   haku.setTextureRect(sf::IntRect(200, 0, 480, 480));
   haku.setPosition(880,200);

   if (!t_zabuza.loadFromFile("Image/zabuza.png") )
       return EXIT_FAILURE;
    //t_naruto.setSmooth(true);
    zabuza.setTexture(&t_zabuza); // texture est un sf::Texture
    zabuza.setTextureRect(sf::IntRect(0, 0, 250, 250));
    zabuza.setPosition(880,300);

    if (!t_kisame.loadFromFile("Image/kisame.png") )
        return EXIT_FAILURE;
     //t_naruto.setSmooth(true);
     kisame.setTexture(&t_kisame); // texture est un sf::Texture
     kisame.setTextureRect(sf::IntRect(0, 0, 507, 507));
     kisame.setPosition(880,400);

     if (!t_hinata.loadFromFile("Image/hinata.png") )
         return EXIT_FAILURE;
      //t_naruto.setSmooth(true);
      hinata.setTexture(&t_hinata); // texture est un sf::Texture
      hinata.setTextureRect(sf::IntRect(0, 0, 500, 500));
      hinata.setPosition(880,500);

      if (!t_shikamaru.loadFromFile("Image/shikamaru.jpg") )
          return EXIT_FAILURE;
       //t_naruto.setSmooth(true);
       shikamaru.setTexture(&t_shikamaru); // texture est un sf::Texture
       shikamaru.setTextureRect(sf::IntRect(50, 0, 380, 380));
       shikamaru.setPosition(880,600);

   return 0;
}
int CreationPersoKonoha() {

  naruto = RectangleShape(sf::Vector2f(80, 80));
  sakura = RectangleShape(sf::Vector2f(80, 80));
  minato = RectangleShape(sf::Vector2f(80, 80));
  tsunade = RectangleShape(sf::Vector2f(80, 80));
  sasuke = RectangleShape(sf::Vector2f(80, 80));

  if (!t_naruto.loadFromFile("Image/naruto.png") )
      return EXIT_FAILURE;
   //t_naruto.setSmooth(true);
   naruto.setTexture(&t_naruto); // texture est un sf::Texture
   naruto.setTextureRect(sf::IntRect(0, 0, 480, 480));
   naruto.setPosition(80,200);

   if (!t_tsunade.loadFromFile("Image/tsunade.png") )
       return EXIT_FAILURE;
    //t_naruto.setSmooth(true);
    tsunade.setTexture(&t_tsunade); // texture est un sf::Texture
    tsunade.setTextureRect(sf::IntRect(130, 0, 1080, 1080));
    tsunade.setPosition(80,300);

    if (!t_sasuke.loadFromFile("Image/sasuke.jpg") )
        return EXIT_FAILURE;
     //t_naruto.setSmooth(true);
     sasuke.setTexture(&t_sasuke); // texture est un sf::Texture
     sasuke.setTextureRect(sf::IntRect(280, 0, 648, 648));
     sasuke.setPosition(80,400);

     if (!t_sakura.loadFromFile("Image/sakura.jpg") )
         return EXIT_FAILURE;
      //t_naruto.setSmooth(true);
      sakura.setTexture(&t_sakura); // texture est un sf::Texture
      sakura.setTextureRect(sf::IntRect(50, 0, 206, 206));
      sakura.setPosition(80,500);

      if (!t_minato.loadFromFile("Image/minato.jpg") )
          return EXIT_FAILURE;
       //t_naruto.setSmooth(true);
       minato.setTexture(&t_minato); // texture est un sf::Texture
       minato.setTextureRect(sf::IntRect(0, 0, 332, 332));
       minato.setPosition(80,600);

   return 0;
}
int CreationTexte(){
  int tailleTexte = 20;
  if(!font.loadFromFile("SF_Arch_Rival.ttf")){
    std::cout<<"Erreur texte"<<std::endl;
  }
  //STAT PERSONNAGE
  text1.setString(buffer);
  text1.setFont(font);
  text1.setCharacterSize(tailleTexte);
  text1.setFillColor(sf::Color::Black);
  text1.setStyle(sf::Text::Bold);

  text2.setString(buffer);
  text2.setFont(font);
  text2.setCharacterSize(tailleTexte);
  text2.setFillColor(sf::Color::Black);
  text2.setStyle(sf::Text::Bold);

  text3.setString(buffer);
  text3.setFont(font);
  text3.setCharacterSize(tailleTexte);
  text3.setFillColor(sf::Color::Black);
  text3.setStyle(sf::Text::Bold);

  text4.setString(buffer);
  text4.setFont(font);
  text4.setCharacterSize(tailleTexte);
  text4.setFillColor(sf::Color::Black);
  text4.setStyle(sf::Text::Bold);

  text5.setString(buffer);
  text5.setFont(font);
  text5.setCharacterSize(tailleTexte);
  text5.setFillColor(sf::Color::Black);
  text5.setStyle(sf::Text::Bold);

  text6.setString(buffer);
  text6.setFont(font);
  text6.setCharacterSize(tailleTexte);
  text6.setFillColor(sf::Color::Black);
  text6.setStyle(sf::Text::Bold);

  text7.setString(buffer);
  text7.setFont(font);
  text7.setCharacterSize(tailleTexte);
  text7.setFillColor(sf::Color::Black);
  text7.setStyle(sf::Text::Bold);

  text8.setString(buffer);
  text8.setFont(font);
  text8.setCharacterSize(tailleTexte);
  text8.setFillColor(sf::Color::Black);
  text8.setStyle(sf::Text::Bold);

  text9.setString(buffer);
  text9.setFont(font);
  text9.setCharacterSize(tailleTexte);
  text9.setFillColor(sf::Color::Black);
  text9.setStyle(sf::Text::Bold);

  text10.setString(buffer);
  text10.setFont(font);
  text10.setCharacterSize(tailleTexte);
  text10.setFillColor(sf::Color::Black);
  text10.setStyle(sf::Text::Bold);

  text11.setString(buffer);
  text11.setFont(font);
  text11.setCharacterSize(tailleTexte);
  text11.setFillColor(sf::Color::Black);
  text11.setStyle(sf::Text::Bold);

  text12.setString(buffer);
  text12.setFont(font);
  text12.setCharacterSize(tailleTexte);
  text12.setFillColor(sf::Color::Black);
  text12.setStyle(sf::Text::Bold);

  text13.setString(buffer);
  text13.setFont(font);
  text13.setCharacterSize(tailleTexte);
  text13.setFillColor(sf::Color::Black);
  text13.setStyle(sf::Text::Bold);

  text14.setString(buffer);
  text14.setFont(font);
  text14.setCharacterSize(tailleTexte);
  text14.setFillColor(sf::Color::Black);
  text14.setStyle(sf::Text::Bold);

  text15.setString(buffer);
  text15.setFont(font);
  text15.setCharacterSize(tailleTexte);
  text15.setFillColor(sf::Color::Black);
  text15.setStyle(sf::Text::Bold);


  // TEXT CONSIGNE J1 ET J2
  consigne1.setString(buffer);
  consigne1.setFont(font);
  consigne1.setCharacterSize(40);
  consigne1.setFillColor(sf::Color::Black);
  consigne1.setStyle(sf::Text::Bold);

  consigne2.setString(buffer);
  consigne2.setFont(font);
  consigne2.setCharacterSize(35);
  consigne2.setFillColor(sf::Color::Black);
  consigne2.setStyle(sf::Text::Bold);

  consigne1.setString("Joueur 1 Veuillez Selectionner votre village et 3 Personnages");
  consigne1.setPosition(50,250);

  consigne2.setString("Joueur 2 Veuillez Selectionner votre village et 3 Personnages");
  consigne2.setPosition(50,250);


  return 0;
}
int CreationTexteVillage(){
  if(!font.loadFromFile("SF_Arch_Rival.ttf")){
    std::cout<<"Erreur texte"<<std::endl;
  }

  text_konoha.setString(buffer);
  text_konoha.setFont(font);
  text_konoha.setCharacterSize(36);
  text_konoha.setFillColor(sf::Color::Black);
  text_konoha.setStyle(sf::Text::Bold);

  text_suna.setString(buffer);
  text_suna.setFont(font);
  text_suna.setCharacterSize(36);
  text_suna.setFillColor(sf::Color::Black);
  text_suna.setStyle(sf::Text::Bold);

  text_kiri.setString(buffer);
  text_kiri.setFont(font);
  text_kiri.setCharacterSize(36);
  text_kiri.setFillColor(sf::Color::Black);
  text_kiri.setStyle(sf::Text::Bold);

  text_konoha.setString("Konoha");
  text_konoha.setPosition(200,5);

  text_suna.setString("Suna");
  text_suna.setPosition(610,5);

  text_kiri.setString("Kiri");
  text_kiri.setPosition(1030,5);

  return 0;
}
int MessageChoix(){
  affiche_MessageJ1Choix = 0;
  if (!choix.loadFromFile("Image/Choix.jpg"))
      return EXIT_FAILURE;
  sprite_choix = Sprite(choix);
  sprite_choix.setPosition(0,-500);
  //Ecriture des consignes

  if (!valider.loadFromFile("Image/validerC.png"))
      return EXIT_FAILURE;
  sprite_valider = Sprite(valider);
  valider.setSmooth(true);
  sprite_valider = Sprite(valider);
  sprite_valider.setPosition(700,400);




  return 0;
}


int main()
{

    // Create the main window
    window.create(sf::VideoMode(1312, 700), "Life is Smoke");


    //Icon
    AfficheIcon();
    //Création menu
    CreationMenu();
    //Creation sprite_choix
    CreationChoix();
    // Load a music to play
    Musique();
    initVillage();
    //Creation Personnages
    CreationPersoKonoha();
    CreationPersoSuna();
    CreationPersoKiri();
    CreationTexte();
    CreationTexteVillage();
    MessageChoix();


    while (window.isOpen())
    {
        // Process events
              sf::Event event;
              while (window.pollEvent(event))
              {
                      switch (event.type)
                      {
                         // fenêtre fermée
                         case sf::Event::Closed:
                             window.close();
                             break;

                         // on ne traite pas les autres types d'évènements
                         default:
                             break;
               }



              }
        //GESTION SOURIS//
        gestionSouris();

        Affichage();

    }
    // initKonoha();
    // buffer = konoha.getNinja(0)->toString();
    // std::cout<<buffer<<std::endl;


    return EXIT_SUCCESS;
}

// int main(){
//   Village  v1;
//   Attaquant Sasuke;
//   Konoha ko;
//   //v1.addNinja(Sasuke);
//   ko = v1;
//
//   std::cout<< ko.isEmpty()<< std::endl;
//
//
//
//   return 0;
// }
