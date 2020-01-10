#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1312, 700), "Life is Smoke");
    //Icon
    sf::Image icon;
    icon.loadFromFile("icon.jpeg"); // File/Image/Pixel
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture menu, jouer;
    if (!menu.loadFromFile("menu.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite_menu(menu);

    jouer.loadFromFile("jouer.png");
    sf::Sprite sprite_jouer(jouer);
    sprite_jouer.setPosition(420,500);
    sprite_jouer.setScale(1.5,1.5);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("naruto_theme.ogg"))
        return EXIT_FAILURE;
    // Play the music
    music.play();
    music.setLoop(true);

  /*  // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("Amatic-Bold.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Life is Smoke", font, 150);
    text.setPosition(650,350);*/


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

            case sf::Event::MouseMoved : // Mouvement de la souris

                 break;

             // touche pressée
             case sf::Event::MouseButtonPressed:
             {
               //int MouseX =  event.mouseMove.x;
               //int MouseY =  event.mouseMove.y;

               break;
             }

             // on ne traite pas les autres types d'évènements
             default:
                 break;
         }





        }
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
