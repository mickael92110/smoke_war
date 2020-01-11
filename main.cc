#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

//Variables Globales
sf::RenderWindow window;
sf::Image icon;
sf::Texture menu, jouer;
sf::Sprite sprite_menu, sprite_jouer;
sf::Music music;
sf::Vector2i positionSouris;

int AfficheMenu() {
  // Load a sprite to display
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
int Musique(){

  if (!music.openFromFile("naruto_theme.ogg"))
      return EXIT_FAILURE;
  // Play the music
  music.play();
  music.setLoop(true);

  return 0;
}

void gestionSouris() {
    positionSouris = sf::Mouse::getPosition(window);
    int mx = positionSouris.x;
    int my = positionSouris.y;
    printf("Mx = %d et My = %d\n",mx,my );
  if((mx>=420) && (mx<770) && (my>=500) && (my<619)){
    sprite_jouer.setColor(sf::Color(0, 0, 255));
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
    //Afficher le menu
    AfficheMenu();
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

        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite_menu);
        window.draw(sprite_jouer);
        // Draw the string
        //window.draw(text);
        // Update the window
        window.display();
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
