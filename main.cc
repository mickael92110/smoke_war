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
sf::Sprite sprite_choix;
sf::RectangleShape vil1, vil2,vil3, sasuke,sakura,naruto,minato,tsunade;


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

    }
  if (affichePersoKiri==1) {

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


}
int CreationPerso() {

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
    CreationPerso();

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
