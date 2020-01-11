#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

//Variables Globales
sf::RenderWindow window;
sf::Image icon;
sf::Texture menu, jouer, choix;
sf::Sprite sprite_menu, sprite_jouer,sprite_choix;
sf::Music music;
sf::Vector2i positionSouris;

int affiche_menu, affiche_choix;

int CreationMenu() {
  // Load a sprite to display
  affiche_menu = 1;
  if (!menu.loadFromFile("menu.png"))
      return EXIT_FAILURE;
  sprite_menu = Sprite(menu);

  if (!jouer.loadFromFile("jouer.png", sf::IntRect(0,0,352,119)))
      return EXIT_FAILURE;
  sprite_jouer = Sprite(jouer);
  sprite_jouer.setPosition(420,500);
  sprite_jouer.setScale(1.5,1.5);

  return 0;
}
void AfficheIcon() {
  icon.loadFromFile("icon.jpeg"); // File/Image/Pixel
  window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
int CreationChoix() {
  // Load a sprite to display
  affiche_choix = 0;
  if (!choix.loadFromFile("Choix.jpg"))
      return EXIT_FAILURE;
  sprite_choix = Sprite(choix);

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
    printf("Mx = %d et My = %d\n",mx,my );

  //Si la souris va sur bouton jouer
  if((mx>=420) && (mx<770) && (my>=500) && (my<619)){
    sprite_jouer.setColor(sf::Color(0, 0, 255));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      affiche_menu = 0;
      affiche_choix = 1;
    }
  }
  else
    sprite_jouer.setColor(sf::Color(255, 255, 255));


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
