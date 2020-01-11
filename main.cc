#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

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
sf::Texture choix,village1,village2,village3;
sf::Texture t_naruto,t_sasuke, t_sakura, t_minato, t_tsunade;
sf::Texture t_gaara,t_temari, t_kankuro, t_shiyo, t_sasori;
sf::Texture t_haku,t_zabuza, t_kisame, t_hinata, t_shikamaru;
sf::Sprite sprite_choix;
sf::RectangleShape vil1, vil2,vil3;
sf::RectangleShape sasuke,sakura,naruto,minato,tsunade;
sf::RectangleShape gaara,temari,kankuro,shiyo,sasori;
sf::RectangleShape haku,zabuza,kisame,hinata,shikamaru;

//Selection pour Afficher
int affiche_menu, affiche_choix,affichePersoKonoha,affichePersoSuna,affichePersoKiri;


int CreationMenu() {
  // Load a sprite to display
  affiche_menu = 1;
  if (!menu.loadFromFile("Image/menu.png"))
      return EXIT_FAILURE;
  sprite_menu = Sprite(menu);

  if (!jouer.loadFromFile("Image/jouer.png", sf::IntRect(0,0,352,119)))
      return EXIT_FAILURE;
  jouer.setSmooth(true);
  sprite_jouer = Sprite(jouer);
  sprite_jouer.setPosition(420,500);
  sprite_jouer.setScale(1.5,1.5);

  return 0;
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
  affiche_choix = 0;
  if (!choix.loadFromFile("Image/Choix.jpg"))
      return EXIT_FAILURE;
  sprite_choix = Sprite(choix);

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
  if (affiche_choix == 1) {
    window.draw(sprite_choix);
    window.draw(vil1);
    window.draw(vil2);
    window.draw(vil3);

  if (affichePersoKonoha==1) {
    window.draw(sasuke);
    window.draw(naruto);
    window.draw(sakura);
    window.draw(minato);
    window.draw(tsunade);
    }
  if (affichePersoSuna==1) {
    window.draw(gaara);
    window.draw(temari);
    window.draw(kankuro);
    window.draw(shiyo);
    window.draw(sasori);
    }
  if (affichePersoKiri==1) {
    window.draw(haku);
    window.draw(zabuza);
    window.draw(kisame);
    window.draw(hinata);
    window.draw(shikamaru);
    }


  }
  // Draw the string
  //window.draw(text);
  // Update the window
  window.display();
}
void gestionSouris() {
    positionSouris = sf::Mouse::getPosition(window);
    int mx = positionSouris.x;
    int my = positionSouris.y;
    //printf("Mx = %d et My = %d\n",mx,my );

  //Si la souris va sur bouton jouer
  if (affiche_menu == 1) {
    if((mx>=420) && (mx<770) && (my>=500) && (my<619)){
      sprite_jouer.setColor(sf::Color(0, 0, 0));
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        affiche_menu = 0;
        affiche_choix = 1;
      }
    }
    else
      sprite_jouer.setColor(sf::Color(255, 255, 255));
  }
  //Si la souris va sur les villages
  if (affiche_choix == 1) {
    //va sur Konoha
    if(((mx>=200) && (mx<320) && (my>=50) && (my<170)) || (affichePersoKonoha==1)){
      vil1.setFillColor(sf::Color(255, 255, 255, 128));
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        affichePersoKonoha = 1;
        affichePersoSuna = 0;
        affichePersoKiri = 0;
      }
    }
    else
      vil1.setFillColor(sf::Color(255, 255, 255));
    //Va sur suna
      if(((mx>=600) && (mx<720) && (my>=50) && (my<170)) || (affichePersoSuna==1)){
        vil2.setFillColor(sf::Color(255, 255, 255, 128));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          affichePersoKonoha = 0;
          affichePersoSuna = 1;
          affichePersoKiri = 0;
        }
      }
      else
        vil2.setFillColor(sf::Color(255, 255, 255));

    //Va sur kiri
          if(((mx>=1000) && (mx<1120) && (my>=50) && (my<170)) || (affichePersoKiri==1)){
            vil3.setFillColor(sf::Color(255, 255, 255, 128));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              affichePersoKonoha = 0;
              affichePersoSuna = 0;
              affichePersoKiri = 1;
            }
          }
          else
            vil3.setFillColor(sf::Color(255, 255, 255));

  }

  if (affichePersoKonoha==1) {
    //va sur naruto
    if((mx>=80) && (mx<160) && (my>=200) && (my<280)) {
      naruto.setFillColor(sf::Color(255, 255, 255, 128));
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        //faire qqch
      }
    }
    else {
      naruto.setFillColor(sf::Color(255, 255, 255));
    }



      if((mx>=80) && (mx<160) && (my>=300) && (my<380)) {
        tsunade.setFillColor(sf::Color(255, 255, 255, 128));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          //faire qqch
        }
      }
      else {
        tsunade.setFillColor(sf::Color(255, 255, 255));
      }

        if((mx>=80) && (mx<160) && (my>=400) && (my<480)) {
          sasuke.setFillColor(sf::Color(255, 255, 255, 128));
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //faire qqch
          }
        }

        else {
          sasuke.setFillColor(sf::Color(255, 255, 255));
        }

          if((mx>=80) && (mx<160) && (my>=500) && (my<580)) {
            sakura.setFillColor(sf::Color(255, 255, 255, 128));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              //faire qqch
            }
          }
          else {
            sakura.setFillColor(sf::Color(255, 255, 255));
          }
            if((mx>=80) && (mx<160) && (my>=600) && (my<680)) {
              minato.setFillColor(sf::Color(255, 255, 255, 128));
              if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                //faire qqch
              }
            }
            else {
              minato.setFillColor(sf::Color(255, 255, 255));
            }

  }

  if (affichePersoSuna==1) {
    //va sur naruto
    if((mx>=480) && (mx<560) && (my>=200) && (my<280)) {
      gaara.setFillColor(sf::Color(255, 255, 255, 128));
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        //faire qqch
      }
    }
    else {
      gaara.setFillColor(sf::Color(255, 255, 255));
    }



      if((mx>=480) && (mx<560) && (my>=300) && (my<380)) {
        temari.setFillColor(sf::Color(255, 255, 255, 128));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          //faire qqch
        }
      }
      else {
        temari.setFillColor(sf::Color(255, 255, 255));
      }

        if((mx>=480) && (mx<560) && (my>=400) && (my<480)) {
          kankuro.setFillColor(sf::Color(255, 255, 255, 128));
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //faire qqch
          }
        }

        else {
          kankuro.setFillColor(sf::Color(255, 255, 255));
        }

          if((mx>=480) && (mx<560) && (my>=500) && (my<580)) {
            shiyo.setFillColor(sf::Color(255, 255, 255, 128));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              //faire qqch
            }
          }
          else {
            shiyo.setFillColor(sf::Color(255, 255, 255));
          }
            if((mx>=480) && (mx<560) && (my>=600) && (my<680)) {
              sasori.setFillColor(sf::Color(255, 255, 255, 128));
              if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                //faire qqch
              }
            }
            else {
              sasori.setFillColor(sf::Color(255, 255, 255));
            }

  }

  if (affichePersoKiri==1) {
    //va sur naruto
    if((mx>=880) && (mx<960) && (my>=200) && (my<280)) {
      haku.setFillColor(sf::Color(255, 255, 255, 128));
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        //faire qqch
      }
    }
    else {
      haku.setFillColor(sf::Color(255, 255, 255));
    }



      if((mx>=880) && (mx<960) && (my>=300) && (my<380)) {
        zabuza.setFillColor(sf::Color(255, 255, 255, 128));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          //faire qqch
        }
      }
      else {
        zabuza.setFillColor(sf::Color(255, 255, 255));
      }

        if((mx>=880) && (mx<960) && (my>=400) && (my<480)) {
          kisame.setFillColor(sf::Color(255, 255, 255, 128));
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //faire qqch
          }
        }

        else {
          kisame.setFillColor(sf::Color(255, 255, 255));
        }

          if((mx>=880) && (mx<960) && (my>=500) && (my<580)) {
            hinata.setFillColor(sf::Color(255, 255, 255, 128));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              //faire qqch
            }
          }
          else {
            hinata.setFillColor(sf::Color(255, 255, 255));
          }
            if((mx>=880) && (mx<960) && (my>=600) && (my<680)) {
              shikamaru.setFillColor(sf::Color(255, 255, 255, 128));
              if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                //faire qqch
              }
            }
            else {
              shikamaru.setFillColor(sf::Color(255, 255, 255));
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

    //Creation Personnages
    CreationPersoKonoha();
    CreationPersoSuna();
    CreationPersoKiri();

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
    // Game game;
    // game.run();
    return EXIT_SUCCESS;
}


/*  // Create a graphical text to display
  sf::Font font;
  if (!font.loadFromFile("Amatic-Bold.ttf"))
      return EXIT_FAILURE;
  sf::Text text("Life is Smoke", font, 150);
  text.setPosition(650,350);*/
