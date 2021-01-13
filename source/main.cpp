#include "config.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFMLCPPBoilerplate");
    // Try creating entity (Test all dependencies compiling)
    Entity test();
    // Assign resource path
    std::string source_dir = RESOURCE_PATH;
    // Try to load texture
    sf::Texture texture;
    if (!texture.loadFromFile(source_dir + "turtle.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite;
    sprite.setTexture(texture, true);
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw image
        window.draw(sprite);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}